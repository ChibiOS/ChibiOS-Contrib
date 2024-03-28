/*
    ChibiOS - Copyright (C) 2006..2016 Giovanni Di Sirio
              Copyright (C) 2020 Yaotian Feng

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/**
 * @file    hal_usb_lld.c
 * @brief   ES32 USB subsystem low level driver source.
 *
 * @addtogroup USB
 * @{
 */

#include "hal.h"
#include "ald_usb.h"
#include "md_utils.h"

#if (HAL_USE_USB == TRUE) || defined(__DOXYGEN__)

#define ES_USB_PERH_EP_MAX_INDEX     (6U)

#define USB_CTRL_EP_MPS 64

#ifndef MIN
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#endif

#define USB_EP_DIR_MASK 0x80U
#define USB_EP_DIR_IN   0x80U
#define USB_EP_DIR_OUT  0x00U

/** Get endpoint index (number) from endpoint address */
#define USB_EP_GET_IDX(ep) ((ep) & ~USB_EP_DIR_MASK)
/** Get direction from endpoint address */
#define USB_EP_GET_DIR(ep) ((ep)&USB_EP_DIR_MASK)
/** Get endpoint address from endpoint index and direction */
#define USB_EP_GET_ADDR(idx, dir) ((idx) | ((dir)&USB_EP_DIR_MASK))
/** True if the endpoint is an IN endpoint */
#define USB_EP_DIR_IS_IN(ep) (USB_EP_GET_DIR(ep) == USB_EP_DIR_IN)
/** True if the endpoint is an OUT endpoint */
#define USB_EP_DIR_IS_OUT(ep) (USB_EP_GET_DIR(ep) == USB_EP_DIR_OUT)


extern char g_num_to_char_tx_buf[32];
extern const char g_num_to_char_table[16];
extern void ffffff(uint32_t data);

/**
 * @brief   EP0 state.
 * @note    It is an union because IN and OUT endpoints are never used at the
 *          same time for EP0.
 */
static union {
  /**
   * @brief   IN EP0 state.
   */
  USBInEndpointState in;
  /**
   * @brief   OUT EP0 state.
   */
  USBOutEndpointState out;
} ep0_state;

/**
 * @brief   Buffer for the EP0 setup packets.
 */
static uint8_t ep0setup_buffer[8];

/**
 * @brief   EP0 initialization structure.
 */
static const USBEndpointConfig ep0config = {
  .ep_mode          = USB_EP_MODE_TYPE_CTRL,
  .setup_cb         = _usb_ep0setup,
  .in_cb            = _usb_ep0in,
  .out_cb           = _usb_ep0out,
  .in_maxsize       = 0x40U,
  .out_maxsize      = 0x40U,
  .in_state         = &ep0_state.in,
  .out_state        = &ep0_state.out,
  .ep_buffers       = 1U,
  .setup_buf        = ep0setup_buffer
};

typedef enum {
    USB_EP0_STATE_SETUP = 0x0,      /**< SETUP DATA */
    USB_EP0_STATE_IN_DATA = 0x1,    /**< IN DATA */
    USB_EP0_STATE_OUT_DATA = 0x3,   /**< OUT DATA */
    USB_EP0_STATE_IN_STATUS = 0x4,  /**< IN status */
    USB_EP0_STATE_OUT_STATUS = 0x5, /**< OUT status */
    USB_EP0_STATE_IN_ZLP = 0x6,     /**< OUT status */
    USB_EP0_STATE_STALL = 0x7,      /**< STALL status */
} ep0_state_t;

/* Endpoint state */
struct musb_ep_state {
    uint16_t ep_mps;    /* Endpoint max packet size */
    uint8_t ep_type;    /* Endpoint type */
    uint8_t ep_stalled; /* Endpoint stall flag */
    uint8_t ep_enable;  /* Endpoint enable */
    uint8_t *xfer_buf;
    uint32_t xfer_len;
    uint32_t actual_xfer_len;
};

/* Setup packet definition used to read raw data from USB line */
struct usb_setup_packet {
    /** Request type. Bits 0:4 determine recipient, see
	 * \ref usb_request_recipient. Bits 5:6 determine type, see
	 * \ref usb_request_type. Bit 7 determines data transfer direction, see
	 * \ref usb_endpoint_direction.
	 */
    uint8_t bmRequestType;

    /** Request. If the type bits of bmRequestType are equal to
	 * \ref usb_request_type::LIBUSB_REQUEST_TYPE_STANDARD
	 * "USB_REQUEST_TYPE_STANDARD" then this field refers to
	 * \ref usb_standard_request. For other cases, use of this field is
	 * application-specific. */
    uint8_t bRequest;

    /** Value. Varies according to request */
    uint16_t wValue;

    /** Index. Varies according to request, typically used to pass an index
	 * or offset */
    uint16_t wIndex;

    /** Number of bytes to transfer */
    uint16_t wLength;
};

/* Driver state */
struct musb_udc {
    volatile uint8_t dev_addr;
    volatile uint32_t fifo_size_offset;
    __attribute__((aligned(32))) struct usb_setup_packet setup;
    struct musb_ep_state in_ep[ES_USB_PERH_EP_MAX_INDEX + 1];  /*!< IN endpoint parameters*/
    struct musb_ep_state out_ep[ES_USB_PERH_EP_MAX_INDEX + 1]; /*!< OUT endpoint parameters */
} g_musb_udc;

struct musb_udc g_musb_udc;
static volatile uint8_t usb_ep0_state = USB_EP0_STATE_SETUP;
volatile bool zlp_flag = 0;

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   USB1 driver identifier.
 */

USBDriver USBD1;

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

static uint32_t es_usbd_get_fifo_size16_log2_min8(uint16_t need_size, uint16_t *used)
{
    uint16_t size;
    uint8_t i;

    for (i = 3; i <= 15; i++) 
    {
        size = (1U << i);
        if (need_size <= size) 
        {
            *used = size;
            return i;
        }
    }

    *used = 0;
    return 0;
}

static void es_usbd_ep_write_packet_8bit(uint8_t ep_idx, uint8_t *buffer, uint16_t len)
{
    uint32_t i;
    uint8_t* buf8 = (uint8_t*)(((uint32_t)(&(USB->EP0FIFO))) + ((ep_idx) << 2));

    for(i = 0;i < len;i++)
        *buf8 = buffer[i];
}

static void es_usbd_ep_read_packet_8bit(uint8_t ep_idx, uint8_t *buffer, uint16_t len)
{
    uint32_t i;
    uint8_t* buf8 = (uint8_t*)(((uint32_t)(&(USB->EP0FIFO))) + ((ep_idx) << 2));

    for(i = 0;i < len;i++)
        buffer[i] = *buf8;
}

/* get current active ep */
static inline uint8_t musb_get_active_ep(void)
{
    return USB->INDEX;
}

/* set the active ep */
static inline void musb_set_active_ep(uint8_t ep_index)
{
    USB->INDEX = ep_index;
}

void ald_usb_fifo_config_set_no_assert(uint32_t ep_idx, uint32_t addr, uint32_t size, uint32_t flags)
{
	USB->INDEX = ep_idx;
	
	if (flags & (ALD_USB_EP_HOST_OUT | ALD_USB_EP_DEV_IN)) {
		USB->TXFIFO1 = (uint8_t)((addr & 0xFFFF) >> 3);
		USB->TXFIFO2 |= (uint8_t)((((addr & 0xFFFF) >> 3) >> 8) & 0x0F);
		USB->TXFIFO2 |= (uint8_t)(size << USB_TXFIFO2_MAXPKTSIZE_POSS);
		
		USB->CSR0L_TXCSRL |= (uint8_t)ALD_USB_TXCSRL_FLUSH;
	}
	else {
		USB->RXFIFO1 = (uint8_t)((addr & 0xFFFF) >> 3);
		USB->RXFIFO2 |= (uint8_t)((((addr & 0xFFFF) >> 3) >> 8) & 0x0F);
		USB->RXFIFO2 |= (uint8_t)(size << USB_RXFIFO2_MAXPKTSIZE_POSS);
		
		USB->RXCSRL |= (uint8_t)ALD_USB_RXCSRL_FLUSH;
	}

	return;
}

int usbd_ep_set_stall(const uint8_t ep)
{
    uint8_t ep_idx = USB_EP_GET_IDX(ep);
    uint8_t old_ep_idx;

    old_ep_idx = musb_get_active_ep();
    musb_set_active_ep(ep_idx);

    if (ep_idx == 0x00)
        usb_ep0_state = USB_EP0_STATE_STALL;
   
    if (USB_EP_DIR_IS_OUT(ep))
        ald_usb_dev_ep_stall(ep_idx,ALD_USB_EP_DEV_OUT);
    else
        ald_usb_dev_ep_stall(ep_idx,ALD_USB_EP_DEV_IN);

    musb_set_active_ep(old_ep_idx);
    return 0;
}

int usbd_ep_clear_stall(const uint8_t ep)
{
    uint8_t ep_idx = USB_EP_GET_IDX(ep);
    uint8_t old_ep_idx;

    old_ep_idx = musb_get_active_ep();
    musb_set_active_ep(ep_idx);

    if (USB_EP_DIR_IS_OUT(ep))
        ald_usb_dev_ep_stall_clear(ep_idx,ALD_USB_EP_DEV_OUT);
    else
        ald_usb_dev_ep_stall_clear(ep_idx,ALD_USB_EP_DEV_IN);

    musb_set_active_ep(old_ep_idx);
    return 0;
}

int usbd_ep_is_stalled(const uint8_t ep, uint8_t *stalled)
{
    return 0;
}

int es_usb_ep_out_data_avail(uint8_t ep_addr)
{
    return ald_usb_ep_data_avail(USB_EP_GET_IDX(ep_addr));
}

int usb_ep_out_data_avail(uint8_t ep_addr)
{
	uint16_t conut; 
	uint8_t ep_idx = USB_EP_GET_IDX(ep_addr);
    uint8_t old_ep_idx;

    old_ep_idx = musb_get_active_ep();
    musb_set_active_ep(ep_idx);
    
	conut = ald_usb_ep_data_avail(USB_EP_GET_IDX(ep_idx));
	
    musb_set_active_ep(old_ep_idx);
	
	return conut;
}

static inline uint32_t es_usbd_ep_tx_ready_state(uint8_t ep_addr)
{
    if (ep_addr == 0U) 
    {
		if (USB->CSR0L_TXCSRL & ALD_USB_CSR0L_TXRDY)
			return 1;
	}
	else 
    {
		if (USB->CSR0L_TXCSRL & ALD_USB_TXCSRL_TXRDY)
			return 2;
	}
    
    return 0;
}

int usb_ep_in_data_avail(uint8_t ep_addr)
{
    uint16_t old_ep_idx, length;
    uint8_t ep_idx = USB_EP_GET_IDX(ep_addr);
    
    old_ep_idx = musb_get_active_ep();
    musb_set_active_ep(ep_idx);
    
    if(es_usbd_ep_tx_ready_state(ep_idx))
        length = 0;
    else
    {
        if(ep_idx == 0)
            length = 64;
        else
            length = USB->TXMAXP;
    }
    
    musb_set_active_ep(old_ep_idx);
    return length;
}

int usb_ep_wait_in_data_avail(uint8_t ep_addr)
{
    uint32_t cnt;
    
    for (cnt = 0; cnt < 3000; cnt++){
        if (usb_ep_in_data_avail(ep_addr))
            return cnt;
    }
    return 0;
}

int usbd_read_packet(uint8_t ep_addr, uint8_t *buffer, uint16_t len)
{
    uint16_t old_ep_idx, cnt;
    uint8_t ep_idx = USB_EP_GET_IDX(ep_addr);
    
    old_ep_idx = musb_get_active_ep();
    musb_set_active_ep(ep_idx);
    
    cnt = es_usb_ep_out_data_avail(ep_idx);
    if (cnt)
    {
		cnt = MIN(cnt,len);
        es_usbd_ep_read_packet_8bit(ep_idx, buffer, cnt);
		USB->RXCSRL &= ~(ALD_USB_RXCSRL_OVERRUN | ALD_USB_RXCSRL_DATAERR | ALD_USB_RXCSRL_STALL| ALD_USB_RXCSRL_STALLED);
		USB->RXCSRL &= ~(ALD_USB_RXCSRL_RXRDY);
    }
    
    musb_set_active_ep(old_ep_idx);
    return cnt;
}

int usbd_write_packet(uint8_t ep_addr, uint8_t *buffer, uint16_t len)
{
    uint16_t old_ep_idx, cnt;
    uint8_t ep_idx = USB_EP_GET_IDX(ep_addr);
    
    if (!buffer && len){
        return -2;
    }
    
    old_ep_idx = musb_get_active_ep();
    musb_set_active_ep(ep_idx);
    
    if((USB->CSR0L_TXCSRL) & USB_TXCSRL_UNDRUN_MSK)
        USB->CSR0L_TXCSRL &= ~USB_TXCSRL_UNDRUN_MSK;

    if((USB->CSR0L_TXCSRL) & USB_TXCSRL_TXRDY_MSK)
    {
        musb_set_active_ep(old_ep_idx);
        return -1;
    }  
    
    if (!len)
    {
        USB->CSR0L_TXCSRL |= USB_TXCSRL_TXRDY_MSK;                   
        musb_set_active_ep(old_ep_idx);
        return 0;
    }
    
    cnt = usb_ep_in_data_avail(ep_idx);
    if (cnt)
    {
        cnt = MIN(cnt, len);
        es_usbd_ep_write_packet_8bit(ep_idx, buffer, cnt);
    }                                                   
    
    USB->CSR0L_TXCSRL |= USB_TXCSRL_TXRDY_MSK;
    
    musb_set_active_ep(old_ep_idx);
    return cnt;
}

int usbd_ep_start_write(const uint8_t ep, const uint8_t *data, uint32_t data_len)
{
    uint8_t ep_idx = USB_EP_GET_IDX(ep);
    uint8_t old_ep_idx;
//    uint32_t wait_cnt;

//    if(ep_idx == 1)
//    {
//        ep_idx = 1;
//    }
    
    if (!g_musb_udc.in_ep[ep_idx].ep_enable)
        return -2;
                              
    old_ep_idx = musb_get_active_ep();
    musb_set_active_ep(ep_idx);
    
    if((USB->CSR0L_TXCSRL) & USB_TXCSRL_TXRDY_MSK)
    {
        musb_set_active_ep(old_ep_idx);
        return -3;
    }
    
    g_musb_udc.in_ep[ep_idx].xfer_buf = (uint8_t *)data;
    g_musb_udc.in_ep[ep_idx].xfer_len = data_len;
    g_musb_udc.in_ep[ep_idx].actual_xfer_len = 0;
	
	USB->TXIER = 1U << ep_idx;

    if (data_len == 0) 
    {  
        if (ep_idx == 0x00) 
        {
            if (g_musb_udc.setup.wLength == 0) 
                usb_ep0_state = USB_EP0_STATE_IN_STATUS;
            else
                usb_ep0_state = USB_EP0_STATE_IN_ZLP;
            
            USB->CSR0L_TXCSRL = (ALD_USB_CSR0L_TXRDY | ALD_USB_CSR0L_DATAEND);
        } 
        else 
        {
            USB->CSR0L_TXCSRL = ALD_USB_TXCSRL_TXRDY;
        }
        musb_set_active_ep(old_ep_idx);
        return 0;
    }
    
    if (!data)
        return -1;
    
    data_len = MIN(data_len, g_musb_udc.in_ep[ep_idx].ep_mps);

    usbd_write_packet(ep_idx, (uint8_t *)data, data_len);

    if (ep_idx == 0x00) 
    {
        usb_ep0_state = USB_EP0_STATE_IN_DATA;
        
        if (data_len < g_musb_udc.in_ep[ep_idx].ep_mps)
            USB->CSR0L_TXCSRL = (ALD_USB_CSR0L_TXRDY | ALD_USB_CSR0L_DATAEND);
        else
            USB->CSR0L_TXCSRL = ALD_USB_CSR0L_TXRDY;
    } 
    else
        USB->CSR0L_TXCSRL = ALD_USB_TXCSRL_TXRDY;
    
    musb_set_active_ep(old_ep_idx);
    
    return 0;
}

int usbd_ep_start_read(const uint8_t ep, uint8_t *data, uint32_t data_len)
{
    uint8_t ep_idx = USB_EP_GET_IDX(ep);
    uint8_t old_ep_idx;

    if (!g_musb_udc.out_ep[ep_idx].ep_enable) {
        return -2;
    }

    old_ep_idx = musb_get_active_ep();
    musb_set_active_ep(ep_idx);

    if (data_len == 0) {
        if (ep_idx == 0) {
            usb_ep0_state = USB_EP0_STATE_SETUP;
        }
        musb_set_active_ep(old_ep_idx);
        return 0;
    }
       
    if (!data) {
        return -1;
    }     
    
    g_musb_udc.out_ep[ep_idx].xfer_buf = data;
    g_musb_udc.out_ep[ep_idx].xfer_len = data_len;
    g_musb_udc.out_ep[ep_idx].actual_xfer_len = 0;

    if (ep_idx == 0) {
        usb_ep0_state = USB_EP0_STATE_OUT_DATA;
    } else {
        USB->RXIER = 1U << ep_idx;
    }
    musb_set_active_ep(old_ep_idx);
    return 0;
}

void handle_ep0(void)
{
    uint8_t ep0_status = USB->CSR0L_TXCSRL;
    uint16_t read_count;

    if (ep0_status & ALD_USB_CSR0L_STALLED) {
        USB->CSR0L_TXCSRL &= ~ALD_USB_CSR0L_STALLED;
        usb_ep0_state = USB_EP0_STATE_SETUP;
        return;
    }

    if (ep0_status & ALD_USB_CSR0L_SETEND) {
        USB->CSR0L_TXCSRL = ALD_USB_CSR0L_SETENDC;
    }

    switch (usb_ep0_state) {
        case USB_EP0_STATE_SETUP:
            if (ep0_status & ALD_USB_CSR0L_RXRDY) {
                read_count = es_usb_ep_out_data_avail(0x0);

                if (read_count != 8) {
                    return;
                }

                usbd_read_packet(0, (uint8_t *)&g_musb_udc.setup, 8);
                if (g_musb_udc.setup.wLength) {
                    USB->CSR0L_TXCSRL = ALD_USB_CSR0L_RXRDYC;
                } else {
                    USB->CSR0L_TXCSRL = (ALD_USB_CSR0L_RXRDYC | ALD_USB_CSR0L_DATAEND);
                }

                _usb_ep0setup(&USBD1, 0);
            }
            break;

        case USB_EP0_STATE_IN_DATA:
            if (g_musb_udc.in_ep[0].xfer_len > g_musb_udc.in_ep[0].ep_mps) {
                g_musb_udc.in_ep[0].actual_xfer_len += g_musb_udc.in_ep[0].ep_mps;
                g_musb_udc.in_ep[0].xfer_len -= g_musb_udc.in_ep[0].ep_mps;   
                g_musb_udc.in_ep[0].xfer_buf += g_musb_udc.in_ep[0].ep_mps;
                
                usbd_ep_start_write(0, g_musb_udc.in_ep[0].xfer_buf, g_musb_udc.in_ep[0].xfer_len);
                
            } else {
                g_musb_udc.in_ep[0].actual_xfer_len += g_musb_udc.in_ep[0].xfer_len;
                g_musb_udc.in_ep[0].xfer_len = 0;
                
            _usb_ep0in(&USBD1, 0);
            }
                              
            break;
        case USB_EP0_STATE_OUT_DATA:
            if (ep0_status & ALD_USB_CSR0L_RXRDY) {
                read_count = es_usb_ep_out_data_avail(0x0);

                usbd_read_packet(0, g_musb_udc.out_ep[0].xfer_buf, read_count);
                g_musb_udc.out_ep[0].xfer_buf += read_count;
                g_musb_udc.out_ep[0].actual_xfer_len += read_count;

                if (read_count < g_musb_udc.out_ep[0].ep_mps) {

                    _usb_ep0out(&USBD1, 0);
                    
                    USB->CSR0L_TXCSRL = (ALD_USB_CSR0L_RXRDYC | ALD_USB_CSR0L_DATAEND);
                    usb_ep0_state = USB_EP0_STATE_IN_STATUS;
                } else {
                    USB->CSR0L_TXCSRL = ALD_USB_CSR0L_RXRDYC;
                }
            }
            break;
        case USB_EP0_STATE_IN_STATUS:
        case USB_EP0_STATE_IN_ZLP:
            usb_ep0_state = USB_EP0_STATE_SETUP;

            _usb_ep0in(&USBD1, 0);
            
            break;
    }
}

const uint8_t __lowest_bit_bitmap[] =
{
    /* 00 */ 0, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    /* 10 */ 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    /* 20 */ 5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    /* 30 */ 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    /* 40 */ 6, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    /* 50 */ 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    /* 60 */ 5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    /* 70 */ 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    /* 80 */ 7, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    /* 90 */ 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    /* A0 */ 5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    /* B0 */ 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    /* C0 */ 6, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    /* D0 */ 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    /* E0 */ 5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    /* F0 */ 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0
};

/*===========================================================================*/
/* Driver interrupt handlers and threads.                                    */
/*===========================================================================*/

/**
 * @brief USB interrupt handler.
 * @isr
 */
OSAL_IRQ_HANDLER(VectorBC)
{
    volatile uint32_t i;
    uint8_t old_ep_idx;
    uint8_t ep_idx;
    uint16_t write_count, read_count;
    uint8_t status;

    USBDriver *usbp = &USBD1;

    OSAL_IRQ_PROLOGUE();

	status = USB->IFM & 0x7F;
	USB->ICR = status;

    old_ep_idx = musb_get_active_ep();

    /* Receive a reset signal from the USB bus */
    if (status & USB_IFM_RESTIFM_MSK) 
    {                      
        for(i = 0;i < 9999;i++){}
        
		//md_delay_1us(20);
        
        memset(&g_musb_udc, 0, sizeof(struct musb_udc));
        g_musb_udc.fifo_size_offset = USB_CTRL_EP_MPS;
        
        usb_ep0_state = USB_EP0_STATE_SETUP;
        
        USBD1.epc[0] = &ep0config;
        g_musb_udc.in_ep[0].ep_enable = 1;
        g_musb_udc.out_ep[0].ep_enable = 1;
    g_musb_udc.in_ep[0].ep_mps = 64;          ;
    g_musb_udc.out_ep[0].ep_mps = 64;

        _usb_reset(usbp);
    }

    if (status & (USB_IFM_SOFIFM_MSK)) 
    {
//        _usb_isr_invoke_sof_cb(usbp);
    }

    if (status & USB_IFM_RESIFM_MSK) 
    {
    }

    if (status & USB_IFM_SESREQIFM_MSK) 
    {
    }
                              
    if (status & USB_IFM_DISCONIFM_MSK) 
    {
    }
                                
    if (status & USB_IFM_SUSPDIFM_MSK) 
    {
//        _usb_suspend(usbp);
    }

    while (USB->TXIFM) 
    {                                      
        ep_idx = __lowest_bit_bitmap[USB->TXIFM];
        USB->TXICR = 1U << ep_idx;  
        musb_set_active_ep(ep_idx);
        
        if(ep_idx == 0U)
            handle_ep0();
        else
        {   
            if((USB->CSR0L_TXCSRL) & USB_TXCSRL_UNDRUN_MSK)
                USB->CSR0L_TXCSRL &= ~USB_TXCSRL_UNDRUN_MSK;

            if(g_musb_udc.in_ep[ep_idx].xfer_len)
            {
                if (g_musb_udc.in_ep[ep_idx].xfer_len > g_musb_udc.in_ep[ep_idx].ep_mps) 
                {
                    g_musb_udc.in_ep[ep_idx].xfer_buf += g_musb_udc.in_ep[ep_idx].ep_mps;
                    g_musb_udc.in_ep[ep_idx].actual_xfer_len += g_musb_udc.in_ep[ep_idx].ep_mps;
                    g_musb_udc.in_ep[ep_idx].xfer_len -= g_musb_udc.in_ep[ep_idx].ep_mps;
                } 
                else 
                {
                    g_musb_udc.in_ep[ep_idx].xfer_buf += g_musb_udc.in_ep[ep_idx].xfer_len;
                    g_musb_udc.in_ep[ep_idx].actual_xfer_len += g_musb_udc.in_ep[ep_idx].xfer_len;
                    g_musb_udc.in_ep[ep_idx].xfer_len = 0;
                }
            }

            if (g_musb_udc.in_ep[ep_idx].xfer_len == 0) 
            {   
                USB->TXIDR = 1U << ep_idx; 

      /* Transfer completed, invokes the callback.*/
        usbp->epc[ep_idx]->in_state->txcnt = g_musb_udc.in_ep[ep_idx].actual_xfer_len;
      _usb_isr_invoke_in_cb(usbp, ep_idx);
            } 
            else 
            {
                write_count = MIN(g_musb_udc.in_ep[ep_idx].xfer_len, g_musb_udc.in_ep[ep_idx].ep_mps);

                usbd_write_packet(ep_idx, g_musb_udc.in_ep[ep_idx].xfer_buf, write_count);
            }
        }
    }

    while (USB->RXIFM) 
    {                    
        ep_idx = __lowest_bit_bitmap[USB->RXIFM];  
        USB->RXICR = 1U << ep_idx;  
        musb_set_active_ep(ep_idx);
        
        if((USB->RXCSRL) & USB_RXCSRL_RXRDY_MSK)
        {
            read_count = es_usb_ep_out_data_avail(ep_idx);

            if(read_count <= g_musb_udc.out_ep[ep_idx].xfer_len)
            {
                es_usbd_ep_read_packet_8bit(ep_idx, g_musb_udc.out_ep[ep_idx].xfer_buf, read_count);

                g_musb_udc.out_ep[ep_idx].xfer_buf += read_count;
                g_musb_udc.out_ep[ep_idx].actual_xfer_len += read_count;
                g_musb_udc.out_ep[ep_idx].xfer_len -= read_count;
				
				
				USB->RXCSRL &= ~(ALD_USB_RXCSRL_OVERRUN | ALD_USB_RXCSRL_DATAERR | ALD_USB_RXCSRL_STALL| ALD_USB_RXCSRL_STALLED);
				USB->RXCSRL &= ~USB_RXCSRL_RXRDY_MSK;
            }                                    
            /*else
                USB_LOG_ERR("[ep %d]read_count(%d) > xfer_len(%d)\r\n",ep_idx,read_count,g_musb_udc.out_ep[ep_idx].xfer_len);*/
            
            
            if ((read_count < g_musb_udc.out_ep[ep_idx].ep_mps) || (g_musb_udc.out_ep[ep_idx].xfer_len < g_musb_udc.out_ep[ep_idx].ep_mps)) 
            {
                USB->RXIDR = 1U << ep_idx;
        /* Transfer complete, invokes the callback.*/
        usbp->epc[ep_idx]->out_state->rxcnt = g_musb_udc.out_ep[ep_idx].actual_xfer_len;
        _usb_isr_invoke_out_cb(usbp, ep_idx);
            }
        }
    }

    musb_set_active_ep(old_ep_idx);

    OSAL_IRQ_EPILOGUE();
}

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level USB driver initialization.
 *
 * @notapi
 */
void usb_lld_init(void)
{
    /* Driver initialization.*/
      usbObjectInit(&USBD1);  
        g_musb_udc.in_ep[0].ep_enable = 1;
        g_musb_udc.out_ep[0].ep_enable = 1;
    g_musb_udc.in_ep[0].ep_mps = 64;          ;
    g_musb_udc.out_ep[0].ep_mps = 64;
    
      USBD1.epc[0] = &ep0config;
}

/**
 * @brief   Configures and activates the USB peripheral.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 *
 * @notapi
 */
void usb_lld_start(USBDriver *usbp)
{
    volatile uint32_t i;
    
    if (usbp->state == USB_STOP) 
    {                   
        ald_usb_device_components_init();
                 
        for(i = 0;i < 9999;i++){}
        
        ald_usb_int_status_get();
        ald_usb_int_status_ep_get();

        /* Enable software connect */
        for(i = 0;i < 9999;i++){}
        
        
        /* Enable USB interrupts */  
        ald_usb_int_enable(ALD_USB_INTCTRL_RESET | ALD_USB_INTCTRL_DISCONNECT | ALD_USB_INTCTRL_RESUME |ALD_USB_INTCTRL_SUSPEND);/*未开启SOF中断*/
        ald_usb_int_enable_ep(ALD_USB_INTEP_ALL);
        ald_usb_int_register();
    }

}

/**
 * @brief   Deactivates the USB peripheral.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 *
 * @notapi
 */
void usb_lld_stop(USBDriver *usbp)
{
    if (usbp->state != USB_STOP) 
    {
        ald_usb_int_unregister();
    }
}

/**
 * @brief   USB low level reset routine.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 *
 * @notapi
 */
void usb_lld_reset(USBDriver *usbp)
{
  /* EP0 initialization.*/
  usbp->epc[0] = &ep0config; 
        g_musb_udc.in_ep[0].ep_enable = 1;
        g_musb_udc.out_ep[0].ep_enable = 1;
    g_musb_udc.in_ep[0].ep_mps = 64;          ;
    g_musb_udc.out_ep[0].ep_mps = 64;
}

/**
 * @brief   Sets the USB address.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 *
 * @notapi
 */
void usb_lld_set_address(USBDriver *usbp)
{
    volatile uint32_t i;
    
    for(i = 0;i < 9999;i++){}
    
    USB->FADDR = usbp->address;
}

/**
 * @brief   Enables an endpoint.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 *
 * @notapi
 */
void usb_lld_init_endpoint(USBDriver *usbp, usbep_t ep)
{
  const USBEndpointConfig *epcp = usbp->epc[ep];

    uint16_t used = 0;
    uint16_t fifo_index = 0;
    uint8_t ep_idx = USB_EP_GET_IDX(ep);
    uint8_t old_ep_idx;
    uint32_t ep_conf_flags = 0;

    if (ep == 0) {
        g_musb_udc.out_ep[0].ep_mps = USB_CTRL_EP_MPS;
        g_musb_udc.out_ep[0].ep_type = 0x00;
        g_musb_udc.out_ep[0].ep_enable = true;
        g_musb_udc.in_ep[0].ep_mps = USB_CTRL_EP_MPS;
        g_musb_udc.in_ep[0].ep_type = 0x00;
        g_musb_udc.in_ep[0].ep_enable = true;
        return;
    }

    if (ep_idx > (ES_USB_PERH_EP_MAX_INDEX)) {
        es_test_printf("Ep addr overflow\r\n",sizeof("Ep addr overflow\r\n"));
        return;
    }

  switch (epcp->ep_mode & USB_EP_MODE_TYPE) 
{
  case USB_EP_MODE_TYPE_BULK:
        ep_conf_flags |= ALD_USB_EP_MODE_BULK;
    break;
  case USB_EP_MODE_TYPE_INTR:
        ep_conf_flags |= ALD_USB_EP_MODE_INT;
    break;
  case USB_EP_MODE_TYPE_ISOC:
        ep_conf_flags |= ALD_USB_EP_MODE_ISOC;
    break;
  default:
        ep_conf_flags |= ALD_USB_EP_MODE_CTRL;
    break;
  }

    old_ep_idx = musb_get_active_ep();
    musb_set_active_ep(ep_idx);
                 
    if (epcp->out_state != NULL)
    {
        g_musb_udc.out_ep[ep_idx].ep_mps = epcp->out_maxsize;
        g_musb_udc.out_ep[ep_idx].ep_type = (epcp->ep_mode) & USB_EP_MODE_TYPE;
        g_musb_udc.out_ep[ep_idx].ep_enable = true;
            
        ep_conf_flags |= ALD_USB_EP_DEV_OUT;

        ald_usb_dev_ep_config(ep_idx , epcp->out_maxsize , ep_conf_flags);
        fifo_index = es_usbd_get_fifo_size16_log2_min8(epcp->out_maxsize , &used);
    } 

    if (epcp->in_state != NULL)
    {
        g_musb_udc.in_ep[ep_idx].ep_mps = epcp->in_maxsize;
        g_musb_udc.in_ep[ep_idx].ep_type = (epcp->ep_mode) & USB_EP_MODE_TYPE;
        g_musb_udc.in_ep[ep_idx].ep_enable = true;
                                 
        ep_conf_flags |= ALD_USB_EP_DEV_IN;

        ald_usb_dev_ep_config(ep_idx , epcp->in_maxsize , ep_conf_flags);
        fifo_index = es_usbd_get_fifo_size16_log2_min8(epcp->in_maxsize , &used);
    }
    
    if((10 >= fifo_index))
    {
        fifo_index -= 3;
        
        if (epcp->out_state != NULL)
            ald_usb_fifo_config_set_no_assert(ep_idx , g_musb_udc.fifo_size_offset , fifo_index , ALD_USB_EP_DEV_OUT);

        if (epcp->in_state != NULL)                                                                       
            ald_usb_fifo_config_set_no_assert(ep_idx , g_musb_udc.fifo_size_offset , fifo_index , ALD_USB_EP_DEV_IN);
    }
    
    g_musb_udc.fifo_size_offset += used;
    
    musb_set_active_ep(old_ep_idx);
}

/**
 * @brief   Disables all the active endpoints except the endpoint zero.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 *
 * @notapi
 */
void usb_lld_disable_endpoints(USBDriver *usbp)
{
    es_test_printf("usb_lld_disable_endpoints\r\n",sizeof("usb_lld_disable_endpoints\r\n"));
}

/**
 * @brief   Returns the status of an OUT endpoint.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 * @return              The endpoint status.
 * @retval EP_STATUS_DISABLED The endpoint is not active.
 * @retval EP_STATUS_STALLED  The endpoint is stalled.
 * @retval EP_STATUS_ACTIVE   The endpoint is active.
 *
 * @notapi
 */
usbepstatus_t usb_lld_get_status_out(USBDriver *usbp, usbep_t ep)
{

    es_test_printf("usb_lld_get_status_out\r\n",sizeof("usb_lld_get_status_out\r\n"));

    return EP_STATUS_ACTIVE;
}

/**
 * @brief   Returns the status of an IN endpoint.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 * @return              The endpoint status.
 * @retval EP_STATUS_DISABLED The endpoint is not active.
 * @retval EP_STATUS_STALLED  The endpoint is stalled.
 * @retval EP_STATUS_ACTIVE   The endpoint is active.
 *
 * @notapi
 */
usbepstatus_t usb_lld_get_status_in(USBDriver *usbp, usbep_t ep)
{
    es_test_printf("usb_lld_get_status_in\r\n",sizeof("usb_lld_get_status_in\r\n"));

    return EP_STATUS_ACTIVE;
}

/**
 * @brief   Reads a setup packet from the dedicated packet buffer.
 * @details This function must be invoked in the context of the @p setup_cb
 *          callback in order to read the received setup packet.
 * @pre     In order to use this function the endpoint must have been
 *          initialized as a control endpoint.
 * @post    The endpoint is ready to accept another packet.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 * @param[out] buf      buffer where to copy the packet data
 *
 * @notapi
 */
void usb_lld_read_setup(USBDriver *usbp, usbep_t ep, uint8_t *buf)
{
    uint8_t i,*setup_buf;
    
    setup_buf = (uint8_t *)(&g_musb_udc.setup);

    for(i = 0;i < 8;i++)
        buf[i] = setup_buf[i];
}

/**
 * @brief   Starts a receive operation on an OUT endpoint.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 *
 * @notapi
 */
void usb_lld_start_out(USBDriver *usbp, usbep_t ep)
{
    USBOutEndpointState *osp = usbp->epc[ep]->out_state;
    usbd_ep_start_read(ep,osp->rxbuf,osp->rxsize);
}

/**
 * @brief   Starts a transmit operation on an IN endpoint.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 *
 * @notapi
 */
void usb_lld_start_in(USBDriver *usbp, usbep_t ep)
{
    USBInEndpointState *isp = usbp->epc[ep]->in_state;
    usbd_ep_start_write(ep,isp->txbuf,isp->txsize);
}

/**
 * @brief   Brings an OUT endpoint in the stalled state.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 *
 * @notapi
 */
void usb_lld_stall_out(USBDriver *usbp, usbep_t ep)
{
    uint8_t ep_idx = USB_EP_GET_IDX(ep);
    uint8_t old_ep_idx;

    old_ep_idx = musb_get_active_ep();
    musb_set_active_ep(ep_idx);

    if (ep_idx == 0x00)
        usb_ep0_state = USB_EP0_STATE_STALL;
   
    ald_usb_dev_ep_stall(ep_idx,ALD_USB_EP_DEV_OUT);
    
    musb_set_active_ep(old_ep_idx);
}

/**
 * @brief   Brings an IN endpoint in the stalled state.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 *
 * @notapi
 */
void usb_lld_stall_in(USBDriver *usbp, usbep_t ep)
{
    uint8_t ep_idx = USB_EP_GET_IDX(ep);
    uint8_t old_ep_idx;

    old_ep_idx = musb_get_active_ep();
    musb_set_active_ep(ep_idx);

    if (ep_idx == 0x00)
        usb_ep0_state = USB_EP0_STATE_STALL;
   
    ald_usb_dev_ep_stall(ep_idx,ALD_USB_EP_DEV_IN);

    musb_set_active_ep(old_ep_idx);
}

/**
 * @brief   Brings an OUT endpoint in the active state.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 *
 * @notapi
 */
void usb_lld_clear_out(USBDriver *usbp, usbep_t ep)
{
    uint8_t ep_idx = USB_EP_GET_IDX(ep);
    uint8_t old_ep_idx;

    old_ep_idx = musb_get_active_ep();
    musb_set_active_ep(ep_idx);

    ald_usb_dev_ep_stall_clear(ep_idx,ALD_USB_EP_DEV_OUT);

    musb_set_active_ep(old_ep_idx);
}

/**
 * @brief   Brings an IN endpoint in the active state.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 *
 * @notapi
 */
void usb_lld_clear_in(USBDriver *usbp, usbep_t ep)
{
    uint8_t ep_idx = USB_EP_GET_IDX(ep);
    uint8_t old_ep_idx;

    old_ep_idx = musb_get_active_ep();
    musb_set_active_ep(ep_idx);

    ald_usb_dev_ep_stall_clear(ep_idx,ALD_USB_EP_DEV_IN);

    musb_set_active_ep(old_ep_idx);
}

void usb_lld_end_setup(USBDriver *usbp, usbep_t ep)
{
    
}

#endif /* HAL_USE_USB == TRUE */

/** @} */

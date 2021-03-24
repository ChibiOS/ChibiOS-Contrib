/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio

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
 * @file    OTG/gd32_otg.h
 * @brief   STM32 OTG registers layout header.
 *
 * @addtogroup USB
 * @{
 */

#ifndef GD32_USBFS_H
#define GD32_USBFS_H

/**
 * @brief   USBFS FIFO memory size in words.
 */
#define GD32_USBFS_FIFO_MEM_SIZE        320

/**
 * @brief   Host channel registers group.
 */
typedef struct {
  volatile uint32_t HCHCTL;     /**< @brief Host channel characteristics
                                            register.                       */
  volatile uint32_t resvd8;
  volatile uint32_t HCHINTF;      /**< @brief Host channel interrupt register.*/
  volatile uint32_t HCHINTEN;   /**< @brief Host channel interrupt mask
                                            register.                       */
  volatile uint32_t HCHLEN;     /**< @brief Host channel transfer size
                                            register.                       */
  volatile uint32_t resvd14;
  volatile uint32_t resvd18;
  volatile uint32_t resvd1c;
} gd32_usbfs_host_chn_t;

/**
 * @brief   Device input endpoint registers group.
 */
typedef struct {
  volatile uint32_t DIEPCTL;    /**< @brief Device control IN endpoint
                                            control register.               */
  volatile uint32_t resvd4;
  volatile uint32_t DIEPINT;    /**< @brief Device IN endpoint interrupt
                                            register.                       */
  volatile uint32_t resvdC;
  volatile uint32_t DIEPTSIZ;   /**< @brief Device IN endpoint transfer size
                                            register.                       */
  volatile uint32_t resvd14;
  volatile uint32_t DTXFSTS;    /**< @brief Device IN endpoint transmit FIFO
                                            status register.                */
  volatile uint32_t resvd1C;
} gd32_usbfs_in_ep_t;

/**
 * @brief   Device output endpoint registers group.
 */
typedef struct {
  volatile uint32_t DOEPCTL;    /**< @brief Device control OUT endpoint
                                            control register.               */
  volatile uint32_t resvd4;
  volatile uint32_t DOEPINT;    /**< @brief Device OUT endpoint interrupt
                                            register.                       */
  volatile uint32_t resvdC;
  volatile uint32_t DOEPTSIZ;   /**< @brief Device OUT endpoint transfer
                                            size register.                  */
  volatile uint32_t resvd14;
  volatile uint32_t resvd18;
  volatile uint32_t resvd1C;
} gd32_usbfs_out_ep_t;

/**
 * @brief   USB registers memory map.
 */
typedef struct {
  volatile uint32_t GOTGCS;    /**< @brief OTG control and status register.*/
  volatile uint32_t GOTGINTF;    /**< @brief OTG interrupt register.         */
  volatile uint32_t GAHBCS;    /**< @brief AHB configuration register.     */
  volatile uint32_t GUSBCS;    /**< @brief USB configuration register.     */
  volatile uint32_t GRSTCTL;    /**< @brief Reset register size.            */
  volatile uint32_t GINTF;    /**< @brief Interrupt register.             */
  volatile uint32_t GINTEN;    /**< @brief Interrupt mask register.        */
  volatile uint32_t GRSTATR;    /**< @brief Receive status debug read
                                            register.                       */
  volatile uint32_t GRSTATP;    /**< @brief Receive status read/pop
                                            register.                       */
  volatile uint32_t GRFLEN;    /**< @brief Receive FIFO size register.     */
  volatile uint32_t DIEPTFLEN0;   /**< @brief Endpoint 0 transmit FIFO size
                                            register.                       */
  volatile uint32_t HNPTFQSTAT;   /**< @brief Non-periodic transmit FIFO/queue
                                            status register.                */
  volatile uint32_t resvd30;
  volatile uint32_t resvd34;
  volatile uint32_t GCCFG;      /**< @brief General core configuration.     */
  volatile uint32_t CID;        /**< @brief Core ID register.               */
  volatile uint32_t resvd58[48];
  volatile uint32_t HPTFLEN;   /**< @brief Host periodic transmit FIFO size
                                            register.                       */
  volatile uint32_t DIEPTFLEN[15];/**< @brief Device IN endpoint transmit FIFO
                                            size registers.                 */
  volatile uint32_t resvd140[176];
  volatile uint32_t HCTL;       /**< @brief Host configuration register.    */
  volatile uint32_t HFT;       /**< @brief Host frame interval register.   */
  volatile uint32_t HFNUM;      /**< @brief Host frame number/frame time
                                            Remaining register.             */
  volatile uint32_t resvd40C;
  volatile uint32_t HPTFQSTAT;    /**< @brief Host periodic transmit FIFO/queue
                                            status register.                */
  volatile uint32_t HACHINT;      /**< @brief Host all channels interrupt
                                            register.                       */
  volatile uint32_t HACHINTEN;   /**< @brief Host all channels interrupt mask
                                            register.                       */
  volatile uint32_t resvd41C[9];
  volatile uint32_t HPCS;       /**< @brief Host port control and status
                                            register.                       */
  volatile uint32_t resvd444[47];
  gd32_usbfs_host_chn_t hc[16];  /**< @brief Host channels array.            */
  volatile uint32_t resvd700[64];
  volatile uint32_t DCFG;       /**< @brief Device configuration register.  */
  volatile uint32_t DCTL;       /**< @brief Device control register.        */
  volatile uint32_t DSTS;       /**< @brief Device status register.         */
  volatile uint32_t resvd80C;
  volatile uint32_t DIEPMSK;    /**< @brief Device IN endpoint common
                                            interrupt mask register.        */
  volatile uint32_t DOEPMSK;    /**< @brief Device OUT endpoint common
                                            interrupt mask register.        */
  volatile uint32_t DAINT;      /**< @brief Device all endpoints interrupt
                                            register.                       */
  volatile uint32_t DAINTMSK;   /**< @brief Device all endpoints interrupt
                                            mask register.                  */
  volatile uint32_t resvd820;
  volatile uint32_t resvd824;
  volatile uint32_t DVBUSDIS;   /**< @brief Device VBUS discharge time
                                            register.                       */
  volatile uint32_t DVBUSPULSE; /**< @brief Device VBUS pulsing time
                                            register.                       */
  volatile uint32_t resvd830;
  volatile uint32_t DIEPEMPMSK; /**< @brief Device IN endpoint FIFO empty
                                            interrupt mask register.        */
  volatile uint32_t resvd838;
  volatile uint32_t resvd83C;
  volatile uint32_t resvd840[16];
  volatile uint32_t resvd880[16];
  volatile uint32_t resvd8C0[16];
  gd32_usbfs_in_ep_t ie[16];     /**< @brief Input endpoints.                */
  gd32_usbfs_out_ep_t oe[16];    /**< @brief Output endpoints.               */
  volatile uint32_t resvdD00[64];
  volatile uint32_t PCGCCTL;    /**< @brief Power and clock gating control
                                            register.                       */
  volatile uint32_t resvdE04[127];
  volatile uint32_t FIFO[16][1024];
} gd32_usbfs_t;

/**
 * @name GOTGCS register bit definitions
 * @{
 */
#define GOTGCS_BSV           (1U<<19)    /**< B-Session Valid.           */
#define GOTGCS_ASV           (1U<<18)    /**< A-Session Valid.           */
#define GOTGCS_DI            (1U<<17)    /**< Long/Short debounce time.  */
#define GOTGCS_IDPS          (1U<<16)    /**< Connector ID status.       */
#define GOTGCS_DHNPEN          (1U<<11)    /**< Device HNP enabled.        */
#define GOTGCS_HHNPEN         (1U<<10)    /**< Host Set HNP enable.       */
#define GOTGCS_HNPREQ           (1U<<9)     /**< HNP request.               */
#define GOTGCS_HNPS          (1U<<8)     /**< Host negotiation success.  */
#define GOTGCS_SRPREQ             (1U<<1)     /**< Session request.           */
#define GOTGCS_SRPREQSCS          (1U<<0)     /**< Session request success.   */
/** @} */

/**
 * @name GOTGINTF register bit definitions
 * @{
 */
#define GOTGINTF_DF          (1U<<19)    /**< Debounce done.             */
#define GOTGINTF_ADTO         (1U<<18)    /**< A-Device timeout change.   */
#define GOTGINTF_HNPDET          (1U<<17)    /**< Host negotiation detected. */
#define GOTGINTF_HNPEND         (1U<<9)     /**< Host negotiation success
                                                 status change.             */
#define GOTGINTF_SRPEND         (1U<<8)     /**< Session request success
                                                 status change.             */
#define GOTGINTF_SESEND           (1U<<2)     /**< Session end detected.      */
/** @} */

/**
 * @name GAHBCS register bit definitions
 * @{
 */
#define GAHBCS_PTXFTH        (1U<<8)     /**< Periodic TxFIFO empty
                                                 level.                     */
#define GAHBCS_TXFTH         (1U<<7)     /**< Non-periodic TxFIFO empty
                                                 level.                     */
#define GAHBCS_GINTEN         (1U<<0)     /**< Global interrupt mask.     */
/** @} */

/**
 * @name GUSBCS register bit definitions
 * @{
 */
#define GUSBCS_FDM           (1U<<30)    /**< Force Device Mode.         */
#define GUSBCS_FHM           (1U<<29)    /**< Force Host Mode.           */
#define GUSBCS_UTT_MASK       (15U<<10)   /**< USB Turnaround time field
                                                 mask.                      */
#define GUSBCS_UTT(n)         ((n)<<10)   /**< USB Turnaround time field
                                                 value.                     */
#define GUSBCS_HNPCEN          (1U<<9)     /**< HNP-Capable.               */
#define GUSBCS_SRPCEN          (1U<<8)     /**< SRP-Capable.               */
#define GUSBCS_TOC_MASK      (7U<<0)     /**< HS/FS timeout calibration
                                                 field mask.                */
#define GUSBCS_TOC(n)        ((n)<<0)    /**< HS/FS timeout calibration
                                                 field value.               */
/** @} */

/**
 * @name GRSTCTL register bit definitions
 * @{
 */
#define GRSTCTL_TXFNUM_MASK     (31U<<6)    /**< TxFIFO number field mask.  */
#define GRSTCTL_TXFNUM(n)       ((n)<<6)    /**< TxFIFO number field value. */
#define GRSTCTL_TXFF         (1U<<5)     /**< TxFIFO flush.              */
#define GRSTCTL_RXFF         (1U<<4)     /**< RxFIFO flush.              */
#define GRSTCTL_HFCRST           (1U<<2)     /**< Host frame counter reset.  */
#define GRSTCTL_HCSRST           (1U<<1)     /**< HClk soft reset.           */
#define GRSTCTL_CSRST           (1U<<0)     /**< Core soft reset.           */
/** @} */

/**
 * @name GINTF register bit definitions
 * @{
 */
#define GINTF_WKUPIF         (1U<<31)    /**< Resume/Remote wakeup
                                                 detected interrupt.        */
#define GINTF_SESIF          (1U<<30)    /**< Session request/New session
                                                 detected interrupt.        */
#define GINTF_DISCIF         (1U<<29)    /**< Disconnect detected
                                                 interrupt.                 */
#define GINTF_IDPSC         (1U<<28)    /**< Connector ID status change.*/
#define GINTF_PTXFEIF           (1U<<26)    /**< Periodic TxFIFO empty.     */
#define GINTF_HCIF           (1U<<25)    /**< Host channels interrupt.   */
#define GINTF_HPIF         (1U<<24)    /**< Host port interrupt.       */
#define GINTF_PXNCIF           (1U<<21)    /**< Incomplete periodic
                                                 transfer.                  */
#define GINTF_ISOONCIF        (1U<<21)    /**< Incomplete isochronous OUT
                                                 transfer.                  */
#define GINTF_ISOINCIF        (1U<<20)    /**< Incomplete isochronous IN
                                                 transfer.                  */
#define GINTF_OEPIF          (1U<<19)    /**< OUT endpoints interrupt.   */
#define GINTF_IEPIF          (1U<<18)    /**< IN endpoints interrupt.    */
#define GINTF_EOPFIF            (1U<<15)    /**< End of periodic frame
                                                 interrupt.                 */
#define GINTF_ISOOPDIF         (1U<<14)    /**< Isochronous OUT packet
                                                 dropped interrupt.         */
#define GINTF_ENUMF         (1U<<13)    /**< Enumeration done.          */
#define GINTF_RST          (1U<<12)    /**< USB reset.                 */
#define GINTF_SP         (1U<<11)    /**< USB suspend.               */
#define GINTF_ESP           (1U<<10)    /**< Early suspend.             */
#define GINTF_GONAK        (1U<<7)     /**< Global OUT NAK effective.  */
#define GINTF_GNPINAK        (1U<<6)     /**< Global IN non-periodic NAK
                                                 effective.                 */
#define GINTF_NPTXFEIF          (1U<<5)     /**< Non-periodic TxFIFO empty. */
#define GINTF_RXFNEIF          (1U<<4)     /**< RxFIFO non-empty.          */
#define GINTF_SOF             (1U<<3)     /**< Start of frame.            */
#define GINTF_OTGIF          (1U<<2)     /**< OTG interrupt.             */
#define GINTF_MFIF            (1U<<1)     /**< Mode Mismatch interrupt.   */
#define GINTF_COPM            (1U<<0)     /**< Current mode of operation. */
/** @} */

/**
 * @name GINTEN register bit definitions
 * @{
 */
#define GINTEN_WKUPIE            (1U<<31)    /**< Resume/remote wakeup
                                                 detected interrupt mask.   */
#define GINTEN_SESIE            (1U<<30)    /**< Session request/New session
                                                 detected interrupt mask.   */
#define GINTEN_DISCIE           (1U<<29)    /**< Disconnect detected
                                                 interrupt mask.            */
#define GINTEN_IDPSCIE        (1U<<28)    /**< Connector ID status change
                                                 mask.                      */
#define GINTEN_PTXFEIFE          (1U<<26)    /**< Periodic TxFIFO empty mask.*/
#define GINTEN_HCIE             (1U<<25)    /**< Host channels interrupt
                                                 mask.                      */
#define GINTEN_HPIE           (1U<<24)    /**< Host port interrupt mask.  */
#define GINTEN_PXNCIE          (1U<<21)    /**< Incomplete periodic
                                                 transfer mask.             */
#define GINTEN_ISOONCIE       (1U<<21)    /**< Incomplete isochronous OUT
                                                 transfer mask.             */
#define GINTEN_ISOINCIE       (1U<<20)    /**< Incomplete isochronous IN
                                                 transfer mask.             */
#define GINTEN_OEPIE            (1U<<19)    /**< OUT endpoints interrupt
                                                 mask.                      */
#define GINTEN_IEPIE            (1U<<18)    /**< IN endpoints interrupt
                                                 mask.                      */
#define GINTEN_EOPFIE           (1U<<15)    /**< End of periodic frame
                                                 interrupt mask.            */
#define GINTEN_ISOOPDIE        (1U<<14)    /**< Isochronous OUT packet
                                                 dropped interrupt mask.    */
#define GINTEN_ENUMFIE        (1U<<13)    /**< Enumeration done mask.     */
#define GINTEN_RSTIE         (1U<<12)    /**< USB reset mask.            */
#define GINTEN_SPIE        (1U<<11)    /**< USB suspend mask.          */
#define GINTEN_ESPIE          (1U<<10)    /**< Early suspend mask.        */
#define GINTEN_GONAKIE       (1U<<7)     /**< Global OUT NAK effective
                                                 mask.                      */
#define GINTEN_GNPINAKIE       (1U<<6)     /**< Global non-periodic IN NAK
                                                 effective mask.            */
#define GINTEN_NPTXFEIE         (1U<<5)     /**< Non-periodic TxFIFO empty
                                                 mask.                      */
#define GINTEN_RXFNEIE         (1U<<4)     /**< Receive FIFO non-empty
                                                 mask.                      */
#define GINTEN_SOFIE            (1U<<3)     /**< Start of (micro)frame mask.*/
#define GINTEN_OTGIE            (1U<<2)     /**< OTG interrupt mask.        */
#define GINTEN_MFIE           (1U<<1)     /**< Mode Mismatch interrupt
                                                 mask.                      */
/** @} */

/**
 * @name GRSTATR register bit definitions
 * @{
 */
#define GRSTATR_RPCKST_MASK     (15U<<17)   /**< Packet status mask.        */
#define GRSTATR_RPCKST(n)       ((n)<<17)   /**< Packet status value.       */
#define GRSTATR_OUT_GLOBAL_NAK  GRSTATR_RPCKST(1)
#define GRSTATR_OUT_DATA        GRSTATR_RPCKST(2)
#define GRSTATR_OUT_COMP        GRSTATR_RPCKST(3)
#define GRSTATR_SETUP_COMP      GRSTATR_RPCKST(4)
#define GRSTATR_SETUP_DATA      GRSTATR_RPCKST(6)
#define GRSTATR_DPID_MASK       (3U<<15)    /**< Data PID mask.             */
#define GRSTATR_DPID(n)         ((n)<<15)   /**< Data PID value.            */
#define GRSTATR_BCOUNT_MASK       (0x7FF<<4)  /**< Byte count mask.           */
#define GRSTATR_BCOUNT(n)         ((n)<<4)    /**< Byte count value.          */
#define GRSTATR_CNUM_MASK      (15U<<0)    /**< Channel number mask.       */
#define GRSTATR_CNUM(n)        ((n)<<0)    /**< Channel number value.      */
#define GRSTATR_EPNUM_MASK      (15U<<0)    /**< Endpoint number mask.      */
#define GRSTATR_EPNUM(n)        ((n)<<0)    /**< Endpoint number value.     */
/** @} */

/**
 * @name GRSTATP register bit definitions
 * @{
 */
#define GRSTATP_RPCKST_MASK     (15<<17)    /**< Packet status mask.        */
#define GRSTATP_RPCKST(n)       ((n)<<17)   /**< Packet status value.       */
#define GRSTATP_OUT_GLOBAL_NAK  GRSTATP_RPCKST(1)
#define GRSTATP_OUT_DATA        GRSTATP_RPCKST(2)
#define GRSTATP_OUT_COMP        GRSTATP_RPCKST(3)
#define GRSTATP_SETUP_COMP      GRSTATP_RPCKST(4)
#define GRSTATP_SETUP_DATA      GRSTATP_RPCKST(6)
#define GRSTATP_DPID_MASK       (3U<<15)    /**< Data PID mask.             */
#define GRSTATP_DPID(n)         ((n)<<15)   /**< Data PID value.            */
#define GRSTATP_BCOUNT_MASK       (0x7FF<<4)  /**< Byte count mask.           */
#define GRSTATP_BCOUNT_OFF        4           /**< Byte count offset.         */
#define GRSTATP_BCOUNT(n)         ((n)<<4)    /**< Byte count value.          */
#define GRSTATP_CNUM_MASK      (15U<<0)    /**< Channel number mask.       */
#define GRSTATP_CNUM(n)        ((n)<<0)    /**< Channel number value.      */
#define GRSTATP_EPNUM_MASK      (15U<<0)    /**< Endpoint number mask.      */
#define GRSTATP_EPNUM_OFF       0           /**< Endpoint number offset.    */
#define GRSTATP_EPNUM(n)        ((n)<<0)    /**< Endpoint number value.     */
/** @} */

/**
 * @name GRFLEN register bit definitions
 * @{
 */
#define GRFLEN_RXFD_MASK       (0xFFFF<<0) /**< RxFIFO depth mask.         */
#define GRFLEN_RXFD(n)         ((n)<<0)    /**< RxFIFO depth value.        */
/** @} */

/**
 * @name DIEPTFLENx register bit definitions
 * @{
 */
#define DIEPTFLEN_IEPTXFD_MASK   (0xFFFFU<<16)/**< IN endpoint TxFIFO depth
                                                 mask.                      */
#define DIEPTFLEN_IEPTXFD(n)     ((n)<<16)   /**< IN endpoint TxFIFO depth
                                                 value.                     */
#define DIEPTFLEN_IEPTXRSAR_MASK   (0xFFFF<<0) /**< IN endpoint FIFOx transmit
                                                 RAM start address mask.    */
#define DIEPTFLEN_IEPTXRSAR(n)     ((n)<<0)    /**< IN endpoint FIFOx transmit
                                                 RAM start address value.   */
/** @} */

/**
 * @name GCCFG register bit definitions
 * @{
 */
/* Definitions for stepping 1.*/
#define GCCFG_VBUSIG        (1U<<21)    /**< VBUS sensing disable.      */
#define GCCFG_SOFOEN          (1U<<20)    /**< SOF output enable.         */
#define GCCFG_VBUSBCEN          (1U<<19)    /**< Enable the VBUS sensing "B"
                                                 device.                    */
#define GCCFG_VBUSACEN          (1U<<18)    /**< Enable the VBUS sensing "A"
                                                 device.                    */
#define GCCFG_PWRON            (1U<<16)    /**< Power down.                */
/** @} */

/**
 * @name HPTFLEN register bit definitions
 * @{
 */
#define HPTFLEN_HPTXFD_MASK     (0xFFFFU<<16)/**< Host periodic TxFIFO
                                                 depth mask.                */
#define HPTFLEN_HPTXFD(n)       ((n)<<16)   /**< Host periodic TxFIFO
                                                 depth value.               */
#define HPTFLEN_HPTXRSAR_MASK     (0xFFFFU<<0)/**< Host periodic TxFIFO
                                                 Start address mask.        */
#define HPTFLEN_HPTXRSAR(n)       ((n)<<0)    /**< Host periodic TxFIFO
                                                 start address value.       */
/** @} */

/**
 * @name HCTL register bit definitions
 * @{
 */
#define HCTL_CLKSEL              (1U<<2)     /**< FS- and LS-only support.   */
#define HCTL_CLKSELPCS_MASK       (3U<<0)     /**< FS/LS PHY clock select
                                                 mask.                      */
#define HCTL_CLKSELPCS_48         (1U<<0)     /**< PHY clock is running at
                                                 48 MHz.                    */
/** @} */

/**
 * @name HFT register bit definitions
 * @{
 */
#define HFT_FRI_MASK         (0xFFFFU<<0)/**< Frame interval mask.       */
#define HFT_FRI(n)           ((n)<<0)    /**< Frame interval value.      */
/** @} */

/**
 * @name HFNUM register bit definitions
 * @{
 */
#define HFNUM_FTREM_MASK        (0xFFFFU<<16)/**< Frame time Remaining mask.*/
#define HFNUM_FTREM(n)          ((n)<<16)   /**< Frame time Remaining value.*/
#define HFNUM_FRNUM_MASK        (0xFFFFU<<0)/**< Frame number mask.         */
#define HFNUM_FRNUM(n)          ((n)<<0)    /**< Frame number value.        */
/** @} */

/**
 * @name HPTFQSTAT register bit definitions
 * @{
 */
#define HPTFQSTAT_PTXREQT_MASK    (0xFFU<<24) /**< Top of the periodic
                                                 transmit request queue
                                                 mask.                      */
#define HPTFQSTAT_PTXREQT(n)      ((n)<<24)   /**< Top of the periodic
                                                 transmit request queue
                                                 value.                     */
#define HPTFQSTAT_PTXREQS_MASK    (0xFF<<16)  /**< Periodic transmit request
                                                 queue Space Available
                                                 mask.                      */
#define HPTFQSTAT_PTXREQS(n)      ((n)<<16)   /**< Periodic transmit request
                                                 queue Space Available
                                                 value.                     */
#define HPTFQSTAT_PTXFS_MASK   (0xFFFF<<0) /**< Periodic transmit Data
                                                 FIFO Space Available
                                                 mask.                      */
#define HPTFQSTAT_PTXFS(n)     ((n)<<0)    /**< Periodic transmit Data
                                                 FIFO Space Available
                                                 value.                     */
/** @} */

/**
 * @name HACHINT register bit definitions
 * @{
 */
#define HACHINT_HACHINT_MASK        (0xFFFFU<<0)/**< Channel interrupts mask.   */
#define HACHINT_HACHINT(n)          ((n)<<0)    /**< Channel interrupts value.  */
/** @} */

/**
 * @name HACHINTEN register bit definitions
 * @{
 */
#define HACHINTEN_CINTEN_MASK    (0xFFFFU<<0)/**< Channel interrupt mask
                                                 mask.                      */
#define HACHINTEN_CINTEN(n)      ((n)<<0)    /**< Channel interrupt mask
                                                 value.                     */
/** @} */

/**
 * @name HPCS register bit definitions
 * @{
 */
#define HPCS_PS_MASK          (3U<<17)    /**< Port speed mask.           */
#define HPCS_PS_FS            (1U<<17)    /**< Full speed value.          */
#define HPCS_PS_LS            (2U<<17)    /**< Low speed value.           */
#define HPCS_PP               (1U<<12)    /**< Port power.                */
#define HPCS_PLST_MASK         (3U<<11)    /**< Port Line status mask.     */
#define HPCS_PLST_DM           (1U<<11)    /**< Logic level of D-.         */
#define HPCS_PLST_DP           (1U<<10)    /**< Logic level of D+.         */
#define HPCS_PRST               (1U<<8)     /**< Port reset.                */
#define HPCS_PSP              (1U<<7)     /**< Port suspend.              */
#define HPCS_PREM               (1U<<6)     /**< Port Resume.               */
#define HPCS_PEDC            (1U<<3)     /**< Port enable/disable change.*/
#define HPCS_PE               (1U<<2)     /**< Port enable.               */
#define HPCS_PCD              (1U<<1)     /**< Port Connect detected.     */
#define HPCS_PCST              (1U<<0)     /**< Port connect status.       */
/** @} */

/**
 * @name HCHCTL register bit definitions
 * @{
 */
#define HCHCTL_CEN            (1U<<31)    /**< Channel enable.            */
#define HCHCTL_CDIS            (1U<<30)    /**< Channel Disable.           */
#define HCHCTL_ODDFRM           (1U<<29)    /**< Odd frame.                 */
#define HCHCTL_DAR_MASK         (0x7FU<<22) /**< Device Address mask.       */
#define HCHCTL_DAR(n)           ((n)<<22)   /**< Device Address value.      */
#define HCHCTL_EPTYP_MASK       (3U<<18)    /**< Endpoint type mask.        */
#define HCHCTL_EPTYP(n)         ((n)<<18)   /**< Endpoint type value.       */
#define HCHCTL_EPTYP_CTL        (0U<<18)    /**< Control endpoint value.    */
#define HCHCTL_EPTYP_ISO        (1U<<18)    /**< Isochronous endpoint value.*/
#define HCHCTL_EPTYP_BULK       (2U<<18)    /**< Bulk endpoint value.       */
#define HCHCTL_EPTYP_INTR       (3U<<18)    /**< Interrupt endpoint value.  */
#define HCHCTL_LSD            (1U<<17)    /**< Low-Speed device.          */
#define HCHCTL_EPDIR            (1U<<15)    /**< Endpoint direction.        */
#define HCHCTL_EPNUM_MASK       (15U<<11)   /**< Endpoint number mask.      */
#define HCHCTL_EPNUM(n)         ((n)<<11)   /**< Endpoint number value.     */
#define HCHCTL_MPL_MASK         (0x7FFU<<0) /**< Maximum packet size mask.  */
#define HCHCTL_MPL(n)           ((n)<<0)    /**< Maximum packet size value. */
/** @} */

/**
 * @name HCHINTF register bit definitions
 * @{
 */
#define HCHINTF_DTER             (1U<<10)    /**< Data toggle error.         */
#define HCHINTF_REQOVR             (1U<<9)     /**< Frame overrun.             */
#define HCHINTF_BBER             (1U<<8)     /**< Babble error.              */
#define HCHINTF_USBER             (1U<<7)     /**< Transaction Error.         */
#define HCHINTF_ACK               (1U<<5)     /**< ACK response
                                                 received/transmitted
                                                 interrupt.                 */
#define HCHINTF_NAK               (1U<<4)     /**< NAK response received
                                                 interrupt.                 */
#define HCHINTF_STALL             (1U<<3)     /**< STALL response received
                                                 interrupt.                 */
#define HCHINTF_CH               (1U<<1)     /**< Channel halted.            */
#define HCHINTF_TF              (1U<<0)     /**< Transfer completed.        */
/** @} */

/**
 * @name HCHINTEN register bit definitions
 * @{
 */
#define HCHINTEN_DTERIE         (1U<<10)    /**< Data toggle error mask.    */
#define HCHINTEN_REQOVRIE         (1U<<9)     /**< Frame overrun mask.        */
#define HCHINTEN_BBERIE         (1U<<8)     /**< Babble error mask.         */
#define HCHINTEN_USBERIE         (1U<<7)     /**< Transaction error mask.    */
#define HCHINTEN_ACKIE           (1U<<5)     /**< ACK Response
                                                 received/transmitted
                                                 interrupt mask.            */
#define HCHINTEN_NAKIE           (1U<<4)     /**< NAK response received
                                                 interrupt mask.            */
#define HCHINTEN_STALLIE         (1U<<3)     /**< STALL response received
                                                 interrupt mask.            */
#define HCHINTEN_CHIE           (1U<<1)     /**< Channel halted mask.       */
#define HCHINTEN_TFIE          (1U<<0)     /**< Transfer completed mask.   */
/** @} */

/**
 * @name HCHLEN register bit definitions
 * @{
 */
#define HCHLEN_DPID_MASK        (3U<<29)    /**< PID mask.                  */
#define HCHLEN_DPID_DATA0       (0U<<29)    /**< DATA0.                     */
#define HCHLEN_DPID_DATA2       (1U<<29)    /**< DATA2.                     */
#define HCHLEN_DPID_DATA1       (2U<<29)    /**< DATA1.                     */
#define HCHLEN_DPID_MDATA       (3U<<29)    /**< MDATA.                     */
#define HCHLEN_DPID_SETUP       (3U<<29)    /**< SETUP.                     */
#define HCHLEN_PCNT_MASK      (0x3FFU<<19)/**< Packet count mask.         */
#define HCHLEN_PCNT(n)        ((n)<<19)   /**< Packet count value.        */
#define HCHLEN_TLEN_MASK      (0x7FFFF<<0)/**< Transfer size mask.        */
#define HCHLEN_TLEN(n)        ((n)<<0)    /**< Transfer size value.       */
/** @} */

/**
 * @name DCFG register bit definitions
 * @{
 */
#define DCFG_PFIVL_MASK         (3U<<11)    /**< Periodic frame interval
                                                 mask.                      */
#define DCFG_PFIVL(n)           ((n)<<11)   /**< Periodic frame interval
                                                 value.                     */
#define DCFG_DAD_MASK           (0x7FU<<4)  /**< Device address mask.       */
#define DCFG_DAD(n)             ((n)<<4)    /**< Device address value.      */
#define DCFG_NZLSOHSK           (1U<<2)     /**< Non-Zero-Length status
                                                 OUT handshake.             */
#define DCFG_DSPD_MASK          (3U<<0)     /**< Device speed mask.         */
#define DCFG_DSPD_HS            (0U<<0)     /**< High speed (USB 2.0).      */
#define DCFG_DSPD_HS_FS         (1U<<0)     /**< High speed (USB 2.0) in FS
                                                 mode.                      */
#define DCFG_DSPD_FS11          (3U<<0)     /**< Full speed (USB 1.1
                                                 transceiver clock is 48
                                                 MHz).                      */
/** @} */

/**
 * @name DCTL register bit definitions
 * @{
 */
#define DCTL_POPRGDNE           (1U<<11)    /**< Power-on programming done. */
#define DCTL_CGONAK             (1U<<10)    /**< Clear global OUT NAK.      */
#define DCTL_SGONAK             (1U<<9)     /**< Set global OUT NAK.        */
#define DCTL_CGINAK             (1U<<8)     /**< Clear global non-periodic
                                                 IN NAK.                    */
#define DCTL_SGINAK             (1U<<7)     /**< Set global non-periodic
                                                 IN NAK.                    */
#define DCTL_TCTL_MASK          (7U<<4)     /**< Test control mask.         */
#define DCTL_TCTL(n)            ((n)<<4     /**< Test control value.        */
#define DCTL_GONSTS             (1U<<3)     /**< Global OUT NAK status.     */
#define DCTL_GINSTS             (1U<<2)     /**< Global non-periodic IN
                                                 NAK status.                */
#define DCTL_SDIS               (1U<<1)     /**< Soft disconnect.           */
#define DCTL_RWUSIG             (1U<<0)     /**< Remote wakeup signaling.   */
/** @} */

/**
 * @name DSTS register bit definitions
 * @{
 */
#define DSTS_FNSOF_MASK         (0x3FFU<<8) /**< Frame number of the received
                                                 SOF mask.                  */
#define DSTS_FNSOF(n)           ((n)<<8)    /**< Frame number of the received
                                                 SOF value.                 */
#define DSTS_FNSOF_ODD          (1U<<8)     /**< Frame parity of the received
                                                 SOF value.                 */
#define DSTS_EERR               (1U<<3)     /**< Erratic error.             */
#define DSTS_ENUMSPD_MASK       (3U<<1)     /**< Enumerated speed mask.     */
#define DSTS_ENUMSPD_FS_48      (3U<<1)     /**< Full speed (PHY clock is
                                                 running at 48 MHz).        */
#define DSTS_ENUMSPD_HS_480     (0U<<1)     /**< High speed.                */
#define DSTS_SUSPSTS            (1U<<0)     /**< Suspend status.            */
/** @} */

/**
 * @name DIEPMSK register bit definitions
 * @{
 */
#define DIEPMSK_TXFEM           (1U<<6)     /**< Transmit FIFO empty mask.  */
#define DIEPMSK_INEPNEM         (1U<<6)     /**< IN endpoint NAK effective
                                                 mask.                      */
#define DIEPMSK_ITTXFEMSK       (1U<<4)     /**< IN token received when
                                                 TxFIFO empty mask.         */
#define DIEPMSK_TOCM            (1U<<3)     /**< Timeout condition mask.    */
#define DIEPMSK_EPDM            (1U<<1)     /**< Endpoint disabled
                                                 interrupt mask.            */
#define DIEPMSK_XFRCM           (1U<<0)     /**< Transfer completed
                                                 interrupt mask.            */
/** @} */

/**
 * @name DOEPMSK register bit definitions
 * @{
 */
#define DOEPMSK_OTEPDM          (1U<<4)     /**< OUT token received when
                                                 endpoint disabled mask.    */
#define DOEPMSK_STUPM           (1U<<3)     /**< SETUP phase done mask.     */
#define DOEPMSK_EPDM            (1U<<1)     /**< Endpoint disabled
                                                 interrupt mask.            */
#define DOEPMSK_XFRCM           (1U<<0)     /**< Transfer completed
                                                 interrupt mask.            */
/** @} */

/**
 * @name DAINT register bit definitions
 * @{
 */
#define DAINT_OEPINT_MASK       (0xFFFFU<<16)/**< OUT endpoint interrupt
                                                 bits mask.                 */
#define DAINT_OEPINT(n)         ((n)<<16)   /**< OUT endpoint interrupt
                                                 bits value.                */
#define DAINT_IEPINT_MASK       (0xFFFFU<<0)/**< IN endpoint interrupt
                                                 bits mask.                 */
#define DAINT_IEPINT(n)         ((n)<<0)    /**< IN endpoint interrupt
                                                 bits value.                */
/** @} */

/**
 * @name DAINTMSK register bit definitions
 * @{
 */
#define DAINTMSK_OEPM_MASK      (0xFFFFU<<16)/**< OUT EP interrupt mask
                                                 bits mask.                 */
#define DAINTMSK_OEPM(n)        (1U<<(16+(n)))/**< OUT EP interrupt mask
                                                 bits value.                */
#define DAINTMSK_IEPM_MASK      (0xFFFFU<<0)/**< IN EP interrupt mask
                                                 bits mask.                 */
#define DAINTMSK_IEPM(n)        (1U<<(n))   /**< IN EP interrupt mask
                                                 bits value.                */
/** @} */

/**
 * @name DVBUSDIS register bit definitions
 * @{
 */
#define DVBUSDIS_VBUSDT_MASK    (0xFFFFU<<0)/**< Device VBUS discharge
                                                 time mask.                 */
#define DVBUSDIS_VBUSDT(n)      ((n)<<0)    /**< Device VBUS discharge
                                                 time value.                */
/** @} */

/**
 * @name DVBUSPULSE register bit definitions
 * @{
 */
#define DVBUSPULSE_DVBUSP_MASK  (0xFFFU<<0) /**< Device VBUSpulsing time
                                                 mask.                      */
#define DVBUSPULSE_DVBUSP(n)    ((n)<<0)    /**< Device VBUS pulsing time
                                                 value.                     */
/** @} */

/**
 * @name DIEPEMPMSK register bit definitions
 * @{
 */
#define DIEPEMPMSK_INEPTXFEM(n) (1U<<(n))   /**< IN EP Tx FIFO empty
                                                 interrupt mask bit.        */
/** @} */

/**
 * @name DIEPCTL register bit definitions
 * @{
 */
#define DIEPCTL_EPENA           (1U<<31)    /**< Endpoint enable.           */
#define DIEPCTL_EPDIS           (1U<<30)    /**< Endpoint disable.          */
#define DIEPCTL_SD1PID          (1U<<29)    /**< Set DATA1 PID.             */
#define DIEPCTL_SODDFRM         (1U<<29)    /**< Set odd frame.             */
#define DIEPCTL_SD0PID          (1U<<28)    /**< Set DATA0 PID.             */
#define DIEPCTL_SEVNFRM         (1U<<28)    /**< Set even frame.            */
#define DIEPCTL_SNAK            (1U<<27)    /**< Set NAK.                   */
#define DIEPCTL_CNAK            (1U<<26)    /**< Clear NAK.                 */
#define DIEPCTL_TXFNUM_MASK     (15U<<22)   /**< TxFIFO number mask.        */
#define DIEPCTL_TXFNUM(n)       ((n)<<22)   /**< TxFIFO number value.       */
#define DIEPCTL_STALL           (1U<<21)    /**< STALL handshake.           */
#define DIEPCTL_SNPM            (1U<<20)    /**< Snoop mode.                */
#define DIEPCTL_EPTYP_MASK      (3<<18)     /**< Endpoint type mask.        */
#define DIEPCTL_EPTYP_CTRL      (0U<<18)    /**< Control.                   */
#define DIEPCTL_EPTYP_ISO       (1U<<18)    /**< Isochronous.               */
#define DIEPCTL_EPTYP_BULK      (2U<<18)    /**< Bulk.                      */
#define DIEPCTL_EPTYP_INTR      (3U<<18)    /**< Interrupt.                 */
#define DIEPCTL_NAKSTS          (1U<<17)    /**< NAK status.                */
#define DIEPCTL_EONUM           (1U<<16)    /**< Even/odd frame.            */
#define DIEPCTL_DPID            (1U<<16)    /**< Endpoint data PID.         */
#define DIEPCTL_USBAEP          (1U<<15)    /**< USB active endpoint.       */
#define DIEPCTL_MPSIZ_MASK      (0x3FFU<<0) /**< Maximum Packet size mask.  */
#define DIEPCTL_MPSIZ(n)        ((n)<<0)    /**< Maximum Packet size value. */
/** @} */

/**
 * @name DIEPINT register bit definitions
 * @{
 */
#define DIEPINT_TXFE            (1U<<7)     /**< Transmit FIFO empty.       */
#define DIEPINT_INEPNE          (1U<<6)     /**< IN endpoint NAK effective. */
#define DIEPINT_ITTXFE          (1U<<4)     /**< IN Token received when
                                                 TxFIFO is empty.           */
#define DIEPINT_TOC             (1U<<3)     /**< Timeout condition.         */
#define DIEPINT_EPDISD          (1U<<1)     /**< Endpoint disabled
                                                 interrupt.                 */
#define DIEPINT_XFRC            (1U<<0)     /**< Transfer completed.        */
/** @} */

/**
 * @name DIEPTSIZ register bit definitions
 * @{
 */
#define DIEPTSIZ_MCNT_MASK      (3U<<29)    /**< Multi count mask.          */
#define DIEPTSIZ_MCNT(n)        ((n)<<29)   /**< Multi count value.         */
#define DIEPTSIZ_PKTCNT_MASK    (0x3FF<<19) /**< Packet count mask.         */
#define DIEPTSIZ_PKTCNT(n)      ((n)<<19)   /**< Packet count value.        */
#define DIEPTSIZ_XFRSIZ_MASK    (0x7FFFFU<<0)/**< Transfer size mask.       */
#define DIEPTSIZ_XFRSIZ(n)      ((n)<<0)    /**< Transfer size value.       */
/** @} */

/**
 * @name DTXFSTS register bit definitions.
 * @{
 */
#define DTXFSTS_INEPTFSAV_MASK  (0xFFFF<<0) /**< IN endpoint TxFIFO space
                                                 available.                 */
/** @} */

/**
 * @name DOEPCTL register bit definitions.
 * @{
 */
#define DOEPCTL_EPENA           (1U<<31)    /**< Endpoint enable.           */
#define DOEPCTL_EPDIS           (1U<<30)    /**< Endpoint disable.          */
#define DOEPCTL_SD1PID          (1U<<29)    /**< Set DATA1 PID.             */
#define DOEPCTL_SODDFRM         (1U<<29)    /**< Set odd frame.             */
#define DOEPCTL_SD0PID          (1U<<28)    /**< Set DATA0 PID.             */
#define DOEPCTL_SEVNFRM         (1U<<28)    /**< Set even frame.            */
#define DOEPCTL_SNAK            (1U<<27)    /**< Set NAK.                   */
#define DOEPCTL_CNAK            (1U<<26)    /**< Clear NAK.                 */
#define DOEPCTL_STALL           (1U<<21)    /**< STALL handshake.           */
#define DOEPCTL_SNPM            (1U<<20)    /**< Snoop mode.                */
#define DOEPCTL_EPTYP_MASK      (3U<<18)    /**< Endpoint type mask.        */
#define DOEPCTL_EPTYP_CTRL      (0U<<18)    /**< Control.                   */
#define DOEPCTL_EPTYP_ISO       (1U<<18)    /**< Isochronous.               */
#define DOEPCTL_EPTYP_BULK      (2U<<18)    /**< Bulk.                      */
#define DOEPCTL_EPTYP_INTR      (3U<<18)    /**< Interrupt.                 */
#define DOEPCTL_NAKSTS          (1U<<17)    /**< NAK status.                */
#define DOEPCTL_EONUM           (1U<<16)    /**< Even/odd frame.            */
#define DOEPCTL_DPID            (1U<<16)    /**< Endpoint data PID.         */
#define DOEPCTL_USBAEP          (1U<<15)    /**< USB active endpoint.       */
#define DOEPCTL_MPSIZ_MASK      (0x3FFU<<0) /**< Maximum Packet size mask.  */
#define DOEPCTL_MPSIZ(n)        ((n)<<0)    /**< Maximum Packet size value. */
/** @} */

/**
 * @name DOEPINT register bit definitions
 * @{
 */
#define DOEPINT_SETUP_RCVD      (1U<<15)    /**< SETUP packet received.     */
#define DOEPINT_B2BSTUP         (1U<<6)     /**< Back-to-back SETUP packets
                                                 received.                  */
#define DOEPINT_OTEPDIS         (1U<<4)     /**< OUT token received when
                                                 endpoint disabled.         */
#define DOEPINT_STUP            (1U<<3)     /**< SETUP phase done.          */
#define DOEPINT_EPDISD          (1U<<1)     /**< Endpoint disabled
                                                 interrupt.                 */
#define DOEPINT_XFRC            (1U<<0)     /**< Transfer completed
                                                 interrupt.                 */
/** @} */

/**
 * @name DOEPTSIZ register bit definitions
 * @{
 */
#define DOEPTSIZ_RXDPID_MASK    (3U<<29)    /**< Received data PID mask.    */
#define DOEPTSIZ_RXDPID(n)      ((n)<<29)   /**< Received data PID value.   */
#define DOEPTSIZ_STUPCNT_MASK   (3U<<29)    /**< SETUP packet count mask.   */
#define DOEPTSIZ_STUPCNT(n)     ((n)<<29)   /**< SETUP packet count value.  */
#define DOEPTSIZ_PKTCNT_MASK    (0x3FFU<<19)/**< Packet count mask.         */
#define DOEPTSIZ_PKTCNT(n)      ((n)<<19)   /**< Packet count value.        */
#define DOEPTSIZ_XFRSIZ_MASK    (0x7FFFFU<<0)/**< Transfer size mask.       */
#define DOEPTSIZ_XFRSIZ(n)      ((n)<<0)    /**< Transfer size value.       */
/** @} */

/**
 * @name PCGCCTL register bit definitions
 * @{
 */
#define PCGCCTL_PHYSUSP         (1U<<4)     /**< PHY Suspended.             */
#define PCGCCTL_GATEHCLK        (1U<<1)     /**< Gate HCLK.                 */
#define PCGCCTL_STPPCLK         (1U<<0)     /**< Stop PCLK.                 */
/** @} */

#define USBFS_ADDR                 0x50000000

/**
 * @brief   Accesses to the USBFS registers block.
 */
#define USBFS                      ((gd32_usbfs_t *)USBFS_ADDR)

#endif /* GD32_USBFS_H */

/** @} */

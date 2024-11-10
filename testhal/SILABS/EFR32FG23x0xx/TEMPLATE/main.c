/*
    ChibiOS - Copyright (C) 2024 Xael South

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

#include <string.h>
#include "cmsis_os.h"
#include "hal.h"

#include <xmlmbus_chibios.h>
#include <xmlmbus_util.h>
#include <xmlmbus_server.h>
#include <xmlmbus_mbus_frame.h>

static void led_on(void) {

  /* PB2 = LED */
  palSetPadMode(GPIOB, 2, PAL_MODE_OUTPUT_PUSHPULL);
  palSetPad(GPIOB, 2);
}

static void led_off(void) {

  /* PB2 = LED */
  palSetPadMode(GPIOB, 2, PAL_MODE_OUTPUT_PUSHPULL);
  palClearPad(GPIOB, 2);
}

static void led_toggle(void) {

  /* PB2 = LED */
  palTogglePad(GPIOB, 2);
}

/* Must return XMLMBUS_SERVER_OK if no error. */
static int req_ud2_handler(struct xmlmbus_server_ctx *ctx, void *arg) {

  (void)arg;
  int rc;

  if (XMLMBUS_SERVER_OK != (rc = xmlmbus_server_write_fixed_header(ctx)))
    return rc;

  return XMLMBUS_SERVER_OK;
}

/* Must return XMLMBUS_SERVER_OK if no error. */
static int snd_ud_read_memory(struct xmlmbus_server_ctx *ctx, void *arg, const uint8_t *in, uint32_t inlen, void *out, uint32_t *outlen) {

  (void)ctx;
  (void)arg;

  const uint32_t outlen_max = *outlen;

  static uint8_t simulated_memory[256];

  MemoryBlock_t memory_block;
  if (inlen != sizeof(memory_block))
    return XMLMBUS_SERVER_ERROR_WRONG_DATA_LENGTH;

  memcpy(&memory_block, in, sizeof(memory_block));

  *outlen = MIN(outlen_max, MIN(memory_block.size, sizeof(simulated_memory)));
  memcpy(out, simulated_memory, *outlen);

  return XMLMBUS_SERVER_OK;
}

static int snd_nke_handler(struct xmlmbus_server_ctx *ctx) {

  if (0 != xmlmbus_buffer_write_cfield(&ctx->buffer, MBUS_ACK))
    return (-1);

  return 0;
}

static const struct ctrl_cmd ctrl_cmd_table[] = {
  { MBUS_REQ_UD2 | MBUS_CFIELD_FCB | MBUS_CFIELD_FCV, req_ud2_handler, NULL },
  { MBUS_REQ_UD2 |                   MBUS_CFIELD_FCV, req_ud2_handler, NULL },
  { MBUS_REQ_UD2 | MBUS_CFIELD_FCB, req_ud2_handler, NULL },
  { MBUS_REQ_UD2, req_ud2_handler, NULL },
};

static const struct appl_cmd appl_cmd_table[] = {
  { VIFE_LAYER1_APPLICATION & VIFE_LAYER_MASK,
    VIFE_REQUEST_TYPE_MEMORY & VIFE_REQUEST_MASK,
    VIFE_FUNCTION_READ_MEMORY & VIFE_FUNCTION_MASK,
    snd_ud_read_memory, NULL },
};

static const struct ci_cmd ci_cmd_table[] = {
  { MBUS_SND_UD  | MBUS_CFIELD_FCB | MBUS_CFIELD_FCV, MBUS_CI_DATA_SEND, xmlmbus_server_snd_ud_handler, NULL },
  { MBUS_SND_UD  |                   MBUS_CFIELD_FCV, MBUS_CI_DATA_SEND, xmlmbus_server_snd_ud_handler, NULL },
  { MBUS_SND_UD  | MBUS_CFIELD_FCB, MBUS_CI_DATA_SEND, xmlmbus_server_snd_ud_handler, NULL },
  { MBUS_SND_UD, MBUS_CI_DATA_SEND, xmlmbus_server_snd_ud_handler, NULL },
};

static const SIOConfig sio_config = {
  .baud = 2400U,       /* Baudrate (2400 max. for LF operation) */
  .cfg0 = (0U <<  0) | /* ASYNC operation */
  (4U <<  5),  /* Disable oversampling (for LF operation) */
  .framecfg = EFR32_SIO_LLD_EUSART_8E1,
};

static struct xmlmbus_server_ctx server_ctx = {

  .address = MBUS_ADDRESS_UNCONFIGURED,
  .ident_no = 0x12345678, /* BCD number. */
  .manufacturer = 0xAABB,
  .version = 0,
  .medium = 0xFF,

  .ctrl_cmd_table = ctrl_cmd_table,
  .ctrl_cmd_table_size = ARRAY_SIZE(ctrl_cmd_table),
  .ci_cmd_table = ci_cmd_table,
  .ci_cmd_table_size = ARRAY_SIZE(ci_cmd_table),
  .appl_cmd_table = appl_cmd_table,
  .appl_cmd_table_size = ARRAY_SIZE(appl_cmd_table),
  .single_character_handler = snd_nke_handler,
};

static int cmd_read_timeout = 5000; /* Milliseconds. */
static int cmd_write_timeout = 5000; /* Milliseconds. */
static uint8_t buffer[MBUS_FRAME_SIZE_MAX];

static int server_iface_open(struct xmlmbus_interface *iface, int flags) {

  (void)flags;

  #if EFR32_SIO_USE_EUSART1 == TRUE
  palSetPadMode(GPIOA, 7, PAL_MODE_OUTPUT_PUSHPULL | PAL_MODE_ALTERNATE(CLKOUT2_LFXO));

  palSetPadMode(GPIOA, 9, PAL_MODE_OUTPUT_PUSHPULL | PAL_MODE_ALTERNATE(EUSART0_TX));
  palSetPadMode(GPIOA, 10, PAL_MODE_INPUT_PULLUP | PAL_MODE_ALTERNATE(EUSART0_RX));

  sioStart(iface->siop, &sio_config);
  #else
  #error "EUSART1 disabled!"
  #endif

  return 0;
}

static int server_iface_close(struct xmlmbus_interface *iface) {

  sioStop(iface->siop);

  palSetPadMode(GPIOA, 9, PAL_MODE_ALTERNATE(EUSART0_TX_DIS));
  palSetPadMode(GPIOA, 10, PAL_MODE_ALTERNATE(EUSART0_RX_DIS));

  return 0;
}

static int server_iface_read(struct xmlmbus_interface *iface, void *buf, unsigned long len, int flags, int timeout_msec) {

  (void)flags;

  msg_t msg = sioSynchronizeRX(iface->siop, TIME_MS2I(timeout_msec));
  if (msg == MSG_OK) {
    return (sioAsyncRead(iface->siop, buf, len));
  }

  return (-1);
}

static int server_iface_write(struct xmlmbus_interface *iface, const void *buf, unsigned long len, int flags, int timeout_msec) {

  (void)flags;

  msg_t msg = sioSynchronizeTX(iface->siop, TIME_MS2I(timeout_msec));
  if (msg == MSG_OK) {
    return (sioAsyncWrite(iface->siop, buf, len));
  }

  return (-1);
}

static struct xmlmbus_interface server_iface = {
  .siop = &SIOD1,
  .open = server_iface_open,
  .close = server_iface_close,
  .read = server_iface_read,
  .write = server_iface_write,
};

/*
 * Application entry point.
 */
int main(void) {

  int rc;

  /* HAL initialization, this also initializes the configured device drivers
     and performs the board-specific initializations.*/
  halInit();

  /* The kernel is initialized but not started yet, this means that
     main() is executing with absolute priority but interrupts are
     already enabled.*/
  osKernelInitialize();

  /* Kernel started, the main() thread has priority osPriorityNormal
     by default.*/
  osKernelStart();

  xmlmbus_interface_open(&server_iface, 0);

  /*
   * Normal main() thread activity, in this demo it does nothing except
   * sleeping in a loop and check the button state.
   */
  while (true) {
    led_off();

    int mbus_packet_size = xmlmbus_interface_read(&server_iface, buffer, sizeof(buffer), 0, cmd_read_timeout);

    if (mbus_packet_size > 0) {
      led_on();

      //log_buffer("REQUEST >>", buffer, mbus_packet_size);

      rc = xmlmbus_server_process_client_request(&server_ctx, buffer, mbus_packet_size);
      if (rc != XMLMBUS_SERVER_OK) {
        //fprintf(stderr, "Error processing client request: %d.\n", rc);
        continue;
      }

      unsigned long response_len = xmlmbus_server_get_response_buffer_used(&server_ctx);
      if (response_len == 0) {
        /* It must have been SND-NKE - don't respond at all. */
        continue;
      }

      unsigned long buffer_used = 0;
      rc = xmlmbus_interface_create_packet(&server_iface, buffer, &buffer_used,
                                           xmlmbus_server_get_response_buffer(&server_ctx),
                                           response_len);
      if (rc != 0) {
        //fprintf(stderr, "Error creating packet: %d.\n", rc);
        continue;
      }

      //log_buffer("RESPOND <<", buffer, buffer_used);

      if ((int)buffer_used != xmlmbus_interface_write(&server_iface, buffer, buffer_used, 0, cmd_write_timeout)) {
        //fprintf(stderr, "Error writing response: %d.\n", rc);
        continue;
      }

      led_toggle();
    }
    else if (mbus_packet_size < 0) {
      rc = XMLMBUS_SERVER_ERROR;
      //fprintf(stderr, "Error reading request: %d.\n", rc);
      break;
    }
    else {
      /* Nothing read. */
    }
  }

  xmlmbus_interface_close(&server_iface);
}


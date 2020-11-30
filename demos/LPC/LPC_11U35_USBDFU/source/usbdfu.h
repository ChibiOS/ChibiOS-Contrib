#pragma once

#include "stdint.h"

extern const USBConfig usbcfg;


#define MAX_FLASH_ADDR 0x10000
#define FLASH_BASE 0x0
#define BL_SIZE 0x3000
#define APP_BASE (FLASH_BASE + BL_SIZE)
#define FLASH_PAGE_SIZE 4096

#define FW_BUFFER_SIZE 1024
extern uint8_t fw_buffer[FW_BUFFER_SIZE];
extern volatile uint8_t dfu_need_flush;
extern volatile uint32_t buffer_fill;
extern volatile uint32_t global_offset;
extern size_t currentAddress;
extern volatile enum dfu_state currentState;

enum dfu_req {
    DFU_DETACH,
    DFU_DNLOAD,
    DFU_UPLOAD,
    DFU_GETSTATUS,
    DFU_CLRSTATUS,
    DFU_GETSTATE,
    DFU_ABORT,
};

enum dfu_state {
    STATE_APP_IDLE,
    STATE_APP_DETACH,
    STATE_DFU_IDLE,
    STATE_DFU_DNLOAD_SYNC,
    STATE_DFU_DNBUSY,
    STATE_DFU_DNLOAD_IDLE,
    STATE_DFU_MANIFEST_SYNC,
    STATE_DFU_MANIFEST,
    STATE_DFU_MANIFEST_WAIT_RESET,
    STATE_DFU_UPLOAD_IDLE,
    STATE_DFU_ERROR,
};


enum dfu_status {
    DFU_STATUS_OK,
    DFU_STATUS_ERR_TARGET,
    DFU_STATUS_ERR_FILE,
    DFU_STATUS_ERR_WRITE,
    DFU_STATUS_ERR_ERASE,
    DFU_STATUS_ERR_CHECK_ERASED,
    DFU_STATUS_ERR_PROG,
    DFU_STATUS_ERR_VERIFY,
    DFU_STATUS_ERR_ADDRESS,
    DFU_STATUS_ERR_NOTDONE,
    DFU_STATUS_ERR_FIRMWARE,
    DFU_STATUS_ERR_VENDOR,
    DFU_STATUS_ERR_USBR,
    DFU_STATUS_ERR_POR,
    DFU_STATUS_ERR_UNKNOWN,
    DFU_STATUS_ERR_STALLEDPKT,
};


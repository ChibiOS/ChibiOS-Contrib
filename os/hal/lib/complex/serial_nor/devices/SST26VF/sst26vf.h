#ifndef SST26VF_H
#define SST26VF_H


/**
 * @name    Device capabilities
 * @{
 */
#define SNOR_DEVICE_SUPPORTS_XIP            TRUE
/** @} */

/**
 * @name    Device identification
 * @{
 */
#define SST26VF_SUPPORTED_MANUFACTURE_IDS      {0xBF, 0x26, 0x43}

#define SIZE_64MB 0x3FFFFFFU


/**
 * @name    Command codes
 * @{
 */
#define SST26VF_CMD_RESET_ENABLE                       0x66
#define SST26VF_CMD_RESET_MEMORY                       0x99

#define SST26VF_CMD_CHIP_ERASE_1                       0xC7

#define SST26VF_CMD_4KB_BLOCK_ERASE                    0x20
#define SST26VF_CMD_64KB_BLOCK_ERASE                   0xD8
#define SST26VF_CMD_PROGRAM_ERASE_RESUME               0x30
#define SST26VF_CMD_PROGRAM_ERASE_SUSPEND              0xB0
#define SST26VF_CMD_SECTOR_ERASE                       SST26VF_CMD_64KB_BLOCK_ERASE
#define SST26VF_CMD_SUBSECTOR_ERASE                    SST26VF_CMD_4KB_BLOCK_ERASE

#define SST26VF_CMD_WRITE_ENABLE                       0x06
#define SST26VF_CMD_WRITE_DISABLE                      0x04
#define SST26VF_CMD_READ                               0x03
#define SST26VF_CMD_FAST_READ                          0x0B
#define SST26VF_CMD_READ_DUAL                          0x3B
#define SST26VF_CMD_READ_QUAD                          0x6B
#define SST26VF_CMD_READ_DISCOVERY_PARAMETER           0x5A
#define SST26VF_CMD_MULTIPLE_IO_READ_ID                0xAF
#define SST26VF_CMD_READ_JEDEC_ID                      0x9F

#define SST26VF_CMD_READ_CFG_REGISTER                  0x35
#define SST26VF_CMD_READ_STATUS_REGISTER               0x05
#define SST26VF_CMD_WRITE_STATUS_REGISTER              0x01
#define SST26VF_CMD_PAGE_PROGRAM                       0x02
#define SST26VF_CMD_PAGE_PROGRAM_QUAD                  0x32

#define SST26VF_CMD_WRITE_SUSPEND                      0xB0
#define SST26VF_CMD_WRITE_RESUME                       0x30
#define SST26VF_CMD_READ_BLOCK_PROTECTION_REGISTER     0x72
#define SST26VF_CMD_WRITE_BLOCK_PROTECTION_REGISTER    0x42
#define SST26VF_CMD_LOCKDOWN_BLOCK_PROTECTION          0x8D
#define SST26VF_CMD_NONVOLATILE_WRITE_LOCKDOWN         0xE8
#define SST26VF_CMD_GLOBAL_BLOCK_PROTECTION_UNLOCK     0x98
#define SST26VF_CMD_READ_SECURITY_ID                   0x88
#define SST26VF_CMD_PROGRAM_SECURITY_ID                0xA5
#define SST26VF_CMD_LOCKOUT_SECURITY_ID                0x85

// Status REG
#define SST26VF_REG_BUSY_POS        7U
#define SST26VF_REG_RSVD_POS        6U
#define SST26VF_REG_SEC_POS         5U
#define SST26VF_REG_WPLD_POS        4U
#define SST26VF_REG_WSP_POS         3U
#define SST26VF_REG_WSE_POS         2U
#define SST26VF_REG_WEL_POS         1U
#define SST26VF_REG_BUSY_2_POS      0U

#define SST26VF_REG_BUSY            (1U << SST26VF_REG_BUSY_POS)
#define SST26VF_REG_RSVD            (1U << SST26VF_REG_RSVD_POS)
#define SST26VF_REG_SEC             (1U << SST26VF_REG_SEC_POS)
#define SST26VF_REG_WPLD            (1U << SST26VF_REG_WPLD_POS)
#define SST26VF_REG_WSP             (1U << SST26VF_REG_WSP_POS)
#define SST26VF_REG_WSE             (1U << SST26VF_REG_WSE_POS)
#define SST26VF_REG_WEL             (1U << SST26VF_REG_WEL_POS)
#define SST26VF_REG_BUSY_2          (1U << SST26VF_REG_BUSY_2_POS)

// Config REG
#define SST26VF_REG_WPEN_POS        7U
#define SST26VF_REG_RSVD_POS        6U
#define SST26VF_REG_RSVD_1_POS      5U
#define SST26VF_REG_RSVD_2_POS      4U
#define SST26VF_REG_BPNV_POS        3U
#define SST26VF_REG_RSVD_3_POS      2U
#define SST26VF_REG_IOC_POS         1U
#define SST26VF_REG_RSVD_4_POS      0U

#define SST26VF_REG_WPEN            (1U << SST26VF_REG_WPEN_POS)
#define SST26VF_REG_RSVD            (1U << SST26VF_REG_RSVD_POS)
#define SST26VF_REG_RSVD_1          (1U << SST26VF_REG_RSVD_1_POS)
#define SST26VF_REG_RSVD_2          (1U << SST26VF_REG_RSVD_2_POS)
#define SST26VF_REG_RSVD_3          (1U << SST26VF_REG_RSVD_3_POS)
#define SST26VF_REG_BPNV            (1U << SST26VF_REG_BPNV_POS)
#define SST26VF_REG_IOC             (1U << SST26VF_REG_IOC_POS)
#define SST26VF_REG_RSVD_4          (1U << SST26VF_REG_RSVD_4_POS)

// Adding new command definitions for block protection and security ID operations
#define SST26VF_CMD_READ_BLOCK_PROTECTION_REGISTER    0x72
#define SST26VF_CMD_WRITE_BLOCK_PROTECTION_REGISTER   0x42
#define SST26VF_CMD_LOCKDOWN_BLOCK_PROTECTION         0x8D
#define SST26VF_CMD_NONVOLATILE_WRITE_LOCKDOWN        0xE8
#define SST26VF_CMD_GLOBAL_BLOCK_PROTECTION_UNLOCK    0x98
#define SST26VF_CMD_READ_SECURITY_ID                  0x88
#define SST26VF_CMD_PROGRAM_SECURITY_ID               0xA5
#define SST26VF_CMD_LOCKOUT_SECURITY_ID               0x85

#endif // SST26VF_H
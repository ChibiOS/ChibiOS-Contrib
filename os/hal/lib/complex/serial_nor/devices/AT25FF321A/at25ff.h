#ifndef AT25FF_H
#define AT25FF_H


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
#define AT25FF_SUPPORTED_MANUFACTURE_IDS      {0x1F, 0x47, 0x46, 0x45, 0x44, 0x8, 0x1, 0x0}

typedef enum 
{
  SIZE_32MBIT = 0x7,
  SIZE_16MBIT = 0x6,
  SIZE_8MBIT  = 0x5,
  SIZE_4MBIT  = 0x4,
} jedec_id_size_map;
/** @} */

#define SIZE_4MB 0x400000U
#define SIZE_2MB 0x200000U
#define SIZE_1MB 0x100000U
#define SIZE_500KB 0x80000U
/**
 * @name    Command codes
 * @{
 */
#define AT25FF_CMD_RESET_ENABLE                       0x66
#define AT25FF_CMD_RESET_MEMORY                       0x99
#define AT25FF_CMD_TERMINATE                          0xF0
#define AT25FF_CMD_CHIP_ERASE_1                       0x60
#define AT25FF_CMD_4KB_BLOCK_ERASE                    0x20
#define AT25FF_CMD_32KB_BLOCK_ERASE                   0x52
#define AT25FF_CMD_64KB_BLOCK_ERASE                   0xD8
#define AT25FF_CMD_PROGRAM_ERASE_RESUME               0x7A
#define AT25FF_CMD_PROGRAM_ERASE_SUSPEND              0x75
#define AT25FF_CMD_SECTOR_ERASE                       AT25FF_CMD_64KB_BLOCK_ERASE
#define AT25FF_CMD_SUBSECTOR_ERASE                    AT25FF_CMD_4KB_BLOCK_ERASE
#define AT25FF_CMD_WRITE_ENABLE                       0x06
#define AT25FF_CMD_WRITE_DISABLE                      0x04
#define AT25FF_CMD_READ                               0x03
#define AT25FF_CMD_FAST_READ                          0x0B
#define AT25FF_CMD_READ_DUAL                          0x3B
#define AT25FF_CMD_READ_QUAD                          0x6B
#define AT25FF_CMD_READ_DISCOVERY_PARAMETER           0x5A
#define AT25FF_CMD_READ_MFG_ID                        0x90
#define AT25FF_CMD_MULTIPLE_IO_READ_ID                0x94
#define AT25FF_CMD_READ_JEDEC_ID                      0x9F
#define AT25FF_CMD_READ_STATUS_REGISTERS              0x65
#define AT25FF_CMD_WRITE_STATUS_REGISTERS             0x71
#define AT25FF_CMD_READ_LOCK_REGISTER                 0xE8
#define AT25FF_CMD_WRITE_LOCK_REGISTER                0xE5
#define AT25FF_CMD_PAGE_PROGRAM                       0x02
#define AT25FF_CMD_PAGE_PROGRAM_DUAL                  0xA2
#define AT25FF_CMD_PAGE_PROGRAM_QUAD                  0x32
#define AT25FF_CMD_SEQ_PROGRAM                        0xAD
#define AT25FF_CMD_READ_OTP                           0x4B
#define AT25FF_CMD_PROGRAM_OTP                        0x9B

// CFG REG 1
#define AT25FF_REG_SRP0_POS        7U
#define AT25FF_REG_BPSIZE_POS      6U
#define AT25FF_REG_TB_POS          5U
#define AT25FF_REG_BP2_POS         4U
#define AT25FF_REG_BP1_POS         3U
#define AT25FF_REG_BP0_POS         2U
#define AT25FF_REG_WEL_POS         1U
#define AT25FF_REG_RDY_BSY_POS     0U

#define AT25FF_REG_SRP0            (1U << AT25FF_REG_SRP0_POS)
#define AT25FF_REG_BPSIZE          (1U << AT25FF_REG_BPSIZE_POS)
#define AT25FF_REG_TB              (1U << AT25FF_REG_TB_POS)
#define AT25FF_REG_BP2             (1U << AT25FF_REG_BP2_POS)
#define AT25FF_REG_BP1             (1U << AT25FF_REG_BP1_POS)
#define AT25FF_REG_BP0             (1U << AT25FF_REG_BP0_POS)
#define AT25FF_REG_WEL             (1U << AT25FF_REG_WEL_POS)
#define AT25FF_REG_RDY_BSY         (1U << AT25FF_REG_RDY_BSY_POS)

// CFG REG 2
#define AT25FF_REG_SUSP_POS        7U
#define AT25FF_REG_CMPRT_POS       6U
#define AT25FF_REG_SL3_POS         5U
#define AT25FF_REG_SL2_POS         4U
#define AT25FF_REG_SL1_POS         3U
#define AT25FF_REG_RSVD_2_POS      2U
#define AT25FF_REG_QE_POS          1U
#define AT25FF_REG_SRP1_POS        0U

#define AT25FF_REG_SUSP            (1U << AT25FF_REG_SUSP_POS)
#define AT25FF_REG_CMPRT           (1U << AT25FF_REG_CMPRT_POS)
#define AT25FF_REG_SL3             (1U << AT25FF_REG_SL3_POS)
#define AT25FF_REG_SL2             (1U << AT25FF_REG_SL2_POS)
#define AT25FF_REG_SL1             (1U << AT25FF_REG_SL1_POS)
#define AT25FF_REG_RSVD_2          (1U << AT25FF_REG_RSVD_2_POS)
#define AT25FF_REG_QE              (1U << AT25FF_REG_QE_POS)
#define AT25FF_REG_SRP1            (1U << AT25FF_REG_SRP1_POS)

// CFG REG 3
#define AT25FF_REG_RST_POS         7U
#define AT25FF_REG_DRV1_POS        6U
#define AT25FF_REG_DRV0_POS        5U
#define AT25FF_REG_WPS_POS         2U

#define AT25FF_REG_RST             (1U << AT25FF_REG_RST_POS)
#define AT25FF_REG_DRV1            (1U << AT25FF_REG_DRV1_POS)
#define AT25FF_REG_DRV0            (1U << AT25FF_REG_DRV0_POS)
#define AT25FF_REG_WPS             (1U << AT25FF_REG_WPS_POS)
#define AT25FF_REG_RSVD_3          ((1U << 0U) | (1U << 1U) | (1U << 3U) | (1U << 4U))

// CFG REG 4
#define AT25FF_REG_PDM_POS         7U
#define AT25FF_REG_SPM_POS         6U
#define AT25FF_REG_XIP_POS         3U
#define AT25FF_REG_BWS2_POS        2U
#define AT25FF_REG_BWS1_POS        1U
#define AT25FF_REG_BWS0_POS        0U

#define AT25FF_REG_PDM             (1U << AT25FF_REG_PDM_POS)
#define AT25FF_REG_SPM             (1U << AT25FF_REG_SPM_POS)
#define AT25FF_REG_XIP             (1U << AT25FF_REG_XIP_POS)
#define AT25FF_REG_BWS2            (1U << AT25FF_REG_BWS2_POS)
#define AT25FF_REG_BWS1            (1U << AT25FF_REG_BWS1_POS)
#define AT25FF_REG_BWS0            (1U << AT25FF_REG_BWS0_POS)
#define AT25FF_REG_RSVD_4          ((1U << 4U) | (1U << 5U))

// CFG REG 5
#define AT25FF_REG_SRLOCK_POS      7U
#define AT25FF_REG_DC2_POS         6U
#define AT25FF_REG_DC1_POS         5U
#define AT25FF_REG_DC0_POS         4U
#define AT25FF_REG_ES_POS          3U
#define AT25FF_REG_PS_POS          2U
#define AT25FF_REG_TERE_POS        1U
#define AT25FF_REG_DWA_POS         0U

#define AT25FF_REG_SRLOCK          (1U << AT25FF_REG_SRLOCK_POS)
#define AT25FF_REG_DC2             (1U << AT25FF_REG_DC2_POS)
#define AT25FF_REG_DC1             (1U << AT25FF_REG_DC1_POS)
#define AT25FF_REG_DC0             (1U << AT25FF_REG_DC0_POS)
#define AT25FF_REG_ES              (1U << AT25FF_REG_ES_POS)
#define AT25FF_REG_PS              (1U << AT25FF_REG_PS_POS)
#define AT25FF_REG_TERE            (1U << AT25FF_REG_TERE_POS)
#define AT25FF_REG_DWA             (1U << AT25FF_REG_DWA_POS)


/**
 * @name    Quad Enable Mode
 * @{
 */
#define AT25FF_QUAD_ENABLE_POS                        1UL
#define AT25FF_QUAD_ENABLE_MSK                        (1UL << AT25FF_QUAD_ENABLE_POS)
#define AT25FF_QUAD_ENABLE(value)                     ((value << AT25FF_QUAD_ENABLE_POS) & AT25FF_QUAD_ENABLE_MSK)

// /** useful macros */
// #define BIT_POS(x) (__builtin_ctz(x))


#endif // HAL_FLASH_DEVICE_H
#ifndef SERCOM_CFG_H_
#define SERCOM_CFG_H_

#if SAM_I2C_USE_SERCOM0 == TRUE
#if SAM_SPI_USE_SERCOM0 == TRUE || SAM_SIO_USE_SERCOM0 == TRUE
#error "SERCOM0: Can only configured as one function only"
#endif
#endif

#if SAM_SPI_USE_SERCOM0 == TRUE
#if SAM_SIO_USE_SERCOM0 == TRUE || SAM_I2C_USE_SERCOM0 == TRUE
#error "SERCOM0: Can only configured as one function only"
#endif
#endif



#endif
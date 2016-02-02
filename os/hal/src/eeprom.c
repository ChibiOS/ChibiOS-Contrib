/*
  Copyright (c) 2013 Timon Wong

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
*/

/*
  Copyright 2012 Uladzimir Pylinski aka barthess.
  You may use this work without restrictions, as long as this notice is included.
  The work is provided "as is" without warranty of any kind, neither express nor implied.
*/

#if defined(HAL_USE_EEPROM) && HAL_USE_EEPROM

#include "eeprom_driver.h"
#include <string.h>

extern EepromDevice eepdev_24xx;
extern EepromDevice eepdev_25xx;

EepromDevice *__eeprom_drv_table[] = {
  /* I2C related. */
#if HAL_USE_I2C

# if EEPROM_DRV_USE_24XX
  &eepdev_24xx,
# endif

#endif /* HAL_USE_I2C */

  /* SPI related. */
#if HAL_USE_SPI

# if EEPROM_DRV_USE_25XX
  &eepdev_25xx,
# endif

#endif /* HAL_USE_SPI */
};


/**
 * @breif  Find low level EEPROM device by id.
 */
const EepromDevice *EepromFindDevice(const char *name) {

  int i;
  const EepromDevice *drv;

  osalDbgCheck(name != NULL);

  for (i = 0; i < EEPROM_DRV_TABLE_SIZE; i++) {
    drv = __eeprom_drv_table[i];
    if (drv->name != NULL && strcmp(drv->name, name) == 0) {
      return drv;
    }
  }

  return NULL;
}

/**
 * Open EEPROM IC as file and return pointer to the file stream object
 * @note      Fucntion allways successfully open file. All checking makes
 *            in read/write functions.
 */
EepromFileStream *EepromFileOpen(EepromFileStream *efs,
                                 const EepromFileConfig *eepcfg,
                                 const EepromDevice *eepdev) {

  osalDbgAssert((efs != NULL) && (eepcfg != NULL) && (eepdev != NULL) &&
             (eepdev->efsvmt != NULL), "EepromFileOpen");
  osalDbgAssert(efs->vmt != eepdev->efsvmt, "file allready opened");
  osalDbgAssert(eepcfg->barrier_hi > eepcfg->barrier_low, "wrong barriers");
  osalDbgAssert(eepcfg->pagesize < eepcfg->size, "pagesize can not be lager than EEPROM size");
  osalDbgAssert(eepcfg->barrier_hi <= eepcfg->size, "barrier out of bounds");

  efs->vmt      = eepdev->efsvmt;
  efs->cfg      = eepcfg;
  efs->errors   = FILE_OK;
  efs->position = 0;
  return (EepromFileStream *)efs;
}

uint8_t EepromReadByte(EepromFileStream *efs) {

  uint8_t buf;
  chFileStreamRead(efs, &buf, sizeof(buf));
  return buf;
}

uint16_t EepromReadHalfword(EepromFileStream *efs) {

  uint16_t buf;
  chFileStreamRead(efs, (uint8_t *)&buf, sizeof(buf));
  return buf;
}

uint32_t EepromReadWord(EepromFileStream *efs) {

  uint32_t buf;
  chFileStreamRead(efs, (uint8_t *)&buf, sizeof(buf));
  return buf;
}

size_t EepromWriteByte(EepromFileStream *efs, uint8_t data) {

  return chFileStreamWrite(efs, &data, sizeof(data));
}

size_t EepromWriteHalfword(EepromFileStream *efs, uint16_t data) {

  return chFileStreamWrite(efs, (uint8_t *)&data, sizeof(data));
}

size_t EepromWriteWord(EepromFileStream *efs, uint32_t data) {

  return chFileStreamWrite(efs, (uint8_t *)&data, sizeof(data));
}

fileoffset_t eepfs_getsize(void *ip) {

  uint32_t h, l;

  osalDbgCheck((ip != NULL) && (((EepromFileStream *)ip)->vmt != NULL) &&
             (((EepromFileStream *)ip)->cfg != NULL));

  h = ((EepromFileStream *)ip)->cfg->barrier_hi;
  l = ((EepromFileStream *)ip)->cfg->barrier_low;
  return  h - l;
}

fileoffset_t eepfs_getposition(void *ip) {

  osalDbgCheck((ip != NULL) && (((EepromFileStream *)ip)->vmt != NULL));

  return ((EepromFileStream *)ip)->position;
}

fileoffset_t eepfs_lseek(void *ip, fileoffset_t offset) {

  uint32_t size;

  osalDbgCheck((ip != NULL) && (((EepromFileStream *)ip)->vmt != NULL));

  size = eepfs_getsize(ip);
  if (offset > size)
    offset = size;
  ((EepromFileStream *)ip)->position = offset;
  return offset;
}

uint32_t eepfs_close(void *ip) {

  osalDbgCheck((ip != NULL) && (((EepromFileStream *)ip)->vmt != NULL));

  ((EepromFileStream *)ip)->errors   = FILE_OK;
  ((EepromFileStream *)ip)->position = 0;
  ((EepromFileStream *)ip)->vmt      = NULL;
  ((EepromFileStream *)ip)->cfg      = NULL;
  return FILE_OK;
}

int eepfs_geterror(void *ip) {

  osalDbgCheck((ip != NULL) && (((EepromFileStream *)ip)->vmt != NULL));
  return ((EepromFileStream *)ip)->errors;
}

msg_t eepfs_put(void *ip, uint8_t b) {

  (void)ip;
  (void)b;
  return 0;
}

msg_t eepfs_get(void *ip) {

  (void)ip;
  return 0;
}

#endif /* #if defined(HAL_USE_EEPROM) && HAL_USE_EEPROM */

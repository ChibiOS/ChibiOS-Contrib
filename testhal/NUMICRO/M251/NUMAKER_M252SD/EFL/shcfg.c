/*
    Copyright (C) 2021 Alex Lewontin
    Modifications copyright (C) 2026 Belonit

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

#include "shcfg.h"

#include "chprintf.h"

#include <string.h>

#define MFS_BANK_SECTORS 4U
#define MFS_BANK_SIZE    2048U
#define MFS_BANK0_START  120U
#define MFS_BANK1_START  124U

/**
 * @brief   Managed flash storage driver object.
 */
MFSDriver mfsd;

/**
 * @brief   Managed flash storage no-cache buffer.
 */
mfs_nocache_buffer_t mfsbuf;

/**
 * @brief   Managed flash storage configuration.
 */
const MFSConfig mfsd_config = {
    .flashp = (BaseFlash *)&EFLD1,
    .erased = 0xFFFFFFFFU,
    .bank_size = MFS_BANK_SIZE,
    .bank0_start = MFS_BANK0_START,
    .bank0_sectors = MFS_BANK_SECTORS,
    .bank1_start = MFS_BANK1_START,
    .bank1_sectors = MFS_BANK_SECTORS,
};

static bool parse_key(BaseSequentialStream *chp, const char *text,
                      mfs_id_t *key) {
  uint32_t value = 0U;
  const char *p = text;

  if (*p == '\0') {
    chprintf(chp, "Key must be in [1, %u].\r\n", MFS_CFG_MAX_RECORDS);
    return false;
  }
  while (*p != '\0') {
    if ((*p < '0') || (*p > '9')) {
      chprintf(chp, "Key must be in [1, %u].\r\n", MFS_CFG_MAX_RECORDS);
      return false;
    }
    value = value * 10U + (uint32_t)(*p - '0');
    if (value > MFS_CFG_MAX_RECORDS) {
      chprintf(chp, "Key must be in [1, %u].\r\n", MFS_CFG_MAX_RECORDS);
      return false;
    }
    p++;
  }

  if (value == 0U) {
    chprintf(chp, "Key must be in [1, %u].\r\n", MFS_CFG_MAX_RECORDS);
    return false;
  }

  *key = (mfs_id_t)value;
  return true;
}

static void cmd_kvs_put(BaseSequentialStream *chp, int argc, char *argv[]) {
  mfs_id_t key;

  if (argc != 2) {
    shellUsage(chp, "kvs_put key value");
    return;
  }
  if (!parse_key(chp, argv[0], &key)) {
    return;
  }

  size_t size = strlen(argv[1]);
  mfs_error_t err = mfsWriteRecord(&mfsd, key, size, (const uint8_t *)argv[1]);
  chprintf(chp, MFS_IS_ERROR(err) ? "Write failed: %d\r\n" : "OK\r\n", err);
}

static void cmd_kvs_get(BaseSequentialStream *chp, int argc, char *argv[]) {
  mfs_id_t key;
  uint8_t buffer[MFS_CFG_MAX_RECORD_SIZE + 1U];
  size_t size = MFS_CFG_MAX_RECORD_SIZE;

  if (argc != 1) {
    shellUsage(chp, "kvs_get key");
    return;
  }
  if (!parse_key(chp, argv[0], &key)) {
    return;
  }

  mfs_error_t err = mfsReadRecord(&mfsd, key, &size, buffer);
  if (err == MFS_ERR_NOT_FOUND) {
    chprintf(chp, "Record not found\r\n");
  }
  else if (MFS_IS_ERROR(err)) {
    chprintf(chp, "Read failed: %d\r\n", err);
  }
  else {
    buffer[size] = '\0';
    chprintf(chp, "%s\r\n", buffer);
  }
}

static void cmd_kvs_erase(BaseSequentialStream *chp, int argc, char *argv[]) {
  mfs_error_t err;

  if (argc != 1) {
    shellUsage(chp, "kvs_erase {--all|key}");
    return;
  }

  if (strcmp(argv[0], "--all") == 0) {
    err = mfsErase(&mfsd);
  }
  else {
    mfs_id_t key;
    if (!parse_key(chp, argv[0], &key)) {
      return;
    }
    err = mfsEraseRecord(&mfsd, key);
  }

  chprintf(chp, MFS_IS_ERROR(err) ? "Erase failed: %d\r\n" : "OK\r\n", err);
}

static const ShellCommand commands[] = {
    {"kvs_put", cmd_kvs_put},
    {"kvs_get", cmd_kvs_get},
    {"kvs_erase", cmd_kvs_erase},
    {NULL, NULL},
};

/**
 * @brief   Shell configuration.
 */
const ShellConfig shell_cfg = {
    .sc_channel = (BaseSequentialStream *)&SD0,
    .sc_commands = commands,
};

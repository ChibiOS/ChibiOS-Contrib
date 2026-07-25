/*
    Copyright (C) 2026 Belonit

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
 * @file    board.h
 * @brief   I2C test-specific NuMaker-M252SD board definitions.
 *
 * @addtogroup I2C_TEST_BOARD
 * @{
 */

#ifndef BOARD_H
#define BOARD_H

/** @brief NuMaker-M252SD board identifier.*/
#define BOARD_NUMAKER_M252SD
/** @brief Board name.*/
#define BOARD_NAME "NuMaker-M252SD"

#if !defined(M252SD2AE)
#define M252SD2AE
#endif

/** @brief On-board LED line.*/
#define LINE_LED PAL_LINE(PB, 14U)

#if !defined(_FROM_ASM_)
/** @brief Forward declaration of the I2C driver type.*/
typedef struct I2CDriver I2CDriver;

#ifdef __cplusplus
extern "C" {
#endif
  void boardInit(void);
  bool boardI2cRecover(I2CDriver *i2cp);
#ifdef __cplusplus
}
#endif
#endif /* !defined(_FROM_ASM_) */

#endif /* BOARD_H */

/** @}*/

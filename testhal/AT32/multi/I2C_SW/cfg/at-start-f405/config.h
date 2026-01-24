/*
    ChibiOS - Copyright (C) 2023..2025 HorrorTroll
    ChibiOS - Copyright (C) 2023..2025 Zhaqian

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

/*
 * CRC driver system settings.
 */
#define AT32_CRC_USE_CRC1                   FALSE

#define CRC_USE_DMA                         FALSE
#define AT32_CRC_CRC1_DMA_PRIORITY          2
#define AT32_CRC_CRC1_IRQ_PRIORITY          5
#define AT32_CRC_CRC1_DMA_STREAM            AT32_DMA_STREAM_ID_ANY

/*
 * I2C fallback driver system settings.
 */
#define SW_I2C_USE_I2C1                     TRUE
#define SW_I2C_USE_I2C2                     FALSE
#define SW_I2C_USE_I2C3                     FALSE
#define SW_I2C_USE_I2C4                     FALSE

/*
 * Other settings.
 */
#define BOARD_OTG_VBUSIG

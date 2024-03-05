/*
 * def.h
 *
 *  Created on: Feb 28, 2024
 *      Author: mok07
 */

#ifndef API_HW_DEF_H_
#define API_HW_DEF_H_


#include "common.h"



#define _USE_HW_CDC
#define _USE_HW_FLASH
#define _USE_HW_FATFS

#define _USE_HW_LED
#define HW_LED_MAX_CH			1

#define _USE_HW_UART
#define HW_UART_MAX_CH		2

#define _USE_HW_GPIO
#define HW_GPIO_MAX_CH		1

#define _USE_HW_SD
#define _PIN_GPIO_SDCARD_DETECT     0

#define _USE_HW_CLI
#define HW_CLI_CMD_LIST_MAX		16
#define HW_CLI_CMD_NAME_MAX		16
#define HW_CLI_LINE_HIS_MAX		5
#define HW_CLI_LINE_BUF_MAX		64


// GPIO mode set
#define _DEF_LOW              0
#define _DEF_HIGH             1

#define _DEF_INPUT            0
#define _DEF_INPUT_PULLUP     1
#define _DEF_INPUT_PULLDOWN   2
#define _DEF_OUTPUT           3
#define _DEF_OUTPUT_PULLUP    4
#define _DEF_OUTPUT_PULLDOWN  5


#endif /* API_HW_DEF_H_ */

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
#define HW_GPIO_MAX_CH		4

#define _USE_HW_SD
#define _PIN_GPIO_SDCARD_DETECT     0

#define _USE_HW_CLI
#define HW_CLI_CMD_LIST_MAX		16
#define HW_CLI_CMD_NAME_MAX		16
#define HW_CLI_LINE_HIS_MAX		5
#define HW_CLI_LINE_BUF_MAX		64

#define _USE_HW_SPI
#define HW_SPI_MAX_CH		1

#define _USE_HW_LCD
#define HW_LCD_MODEL		0
#if HW_LCD_MODEL == 0
#define _USE_HW_ST7735
#define      HW_ST7735_MODEL        0
#define      HW_LCD_WIDTH           160
#define      HW_LCD_HEIGHT          80
#endif
#if HW_LCD_MODEL == 1
#define _USE_HW_SSD1306
#define      HW_SSD1306_MODEL       0
#define      HW_LCD_WIDTH           128
#define      HW_LCD_HEIGHT          64
#endif
#if HW_LCD_MODEL == 2
#define _USE_HW_ST7735
#define      HW_ST7735_MODEL        1
#define      HW_LCD_WIDTH           160
#define      HW_LCD_HEIGHT          128
#endif

// GPIO mode set
#define _DEF_LOW              0
#define _DEF_HIGH             1

#define _DEF_INPUT            0
#define _DEF_INPUT_PULLUP     1
#define _DEF_INPUT_PULLDOWN   2
#define _DEF_OUTPUT           3
#define _DEF_OUTPUT_PULLUP    4
#define _DEF_OUTPUT_PULLDOWN  5


#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))

#ifndef max
#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))
#endif

#ifndef map
#define map(value, in_min, in_max, out_min, out_max) ((value - in_min) * (out_max - out_min) / (in_max - in_min) + out_min)
#endif


#endif /* API_HW_DEF_H_ */

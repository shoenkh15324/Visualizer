/*
 * ssd1306.h
 *
 *  Created on: Mar 21, 2024
 *      Author: mok07
 */

#ifndef API_LCD_SSD1306_H_
#define API_LCD_SSD1306_H_

#include "hw_def.h"

#ifdef _USE_HW_SSD1306

#include "lcd.h"

bool ssd1306Init(void);
bool ssd1306InitDriver(lcd_driver_t *p_driver);

#endif

#endif /* API_LCD_SSD1306_H_ */

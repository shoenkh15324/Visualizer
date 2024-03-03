/*
 * gpio.h
 *
 *  Created on: Mar 3, 2024
 *      Author: mok07
 */

#ifndef API_INCLUDE_GPIO_API_H_
#define API_INCLUDE_GPIO_API_H_

#include "hw_def.h"


#ifdef _USE_HW_GPIO

#define GPIO_MAX_CH			HW_GPIO_MAX_CH

bool gpioInit(void);
bool gpioPinMode(uint8_t ch, uint8_t mode);
void gpioPinWrite(uint8_t ch, bool value);
bool gpioPinRead(uint8_t ch);
void gpioPinToggle(uint8_t ch);


#endif

#endif /* API_INCLUDE_GPIO_API_H_ */

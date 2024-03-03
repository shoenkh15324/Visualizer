/*
 * led.h
 *
 *  Created on: Mar 2, 2024
 *      Author: mok07
 */

#ifndef API_INCLUDE_LED_H_
#define API_INCLUDE_LED_H_


#include "hw_def.h"


#ifdef _USE_HW_LED


#define _DEF_LED1             0
#define _DEF_LED2             1
#define _DEF_LED3             2
#define _DEF_LED4             3


#define LED_MAX_CH		HW_LED_MAX_CH


bool ledInit(void);
void ledOn(uint8_t ch);
void ledOff(uint8_t ch);
void ledToggle(uint8_t ch);


#endif


#endif /* API_INCLUDE_LED_H_ */

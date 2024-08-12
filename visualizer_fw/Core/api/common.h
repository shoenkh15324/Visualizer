/*
 * common.h
 *
 *  Created on: Feb 27, 2024
 *      Author: mok07
 */

#ifndef API_COMMON_H_
#define API_COMMON_H_



#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

#include "stm32f4xx_hal.h"
#include "arm_math.h"
#include "arm_const_structs.h"
#include "cmsis_os.h"

void delay(uint32_t ms);
uint32_t millis(void);



#endif /* API_COMMON_H_ */

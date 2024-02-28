/*
 * common.c
 *
 *  Created on: Feb 27, 2024
 *      Author: mok07
 */


#include "common.h"



void delay(uint32_t ms)
{
	HAL_Delay(ms);
}


uint32_t millis(void)
{
	return HAL_GetTick();
}

/*
 * uart.h
 *
 *  Created on: Feb 28, 2024
 *      Author: mok07
 */

#ifndef API_INCLUDE_UART_H_
#define API_INCLUDE_UART_H_


#include "hw_def.h"


#ifdef _USE_HW_UART


#define UART_MAX_CH		HW_UART_MAX_CH



bool uartInit(void);




#endif


#endif /* API_INCLUDE_UART_H_ */

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

#define _DEF_UART1		0
#define _DEF_UART2		1
#define _DEF_UART3		2
#define _DEF_UART4		3


bool uartInit(void);
bool uartOpen(uint8_t ch, uint32_t baud);
uint32_t uartAvailable(uint8_t ch);
uint8_t uartRead(uint8_t ch);
uint32_t uartWrite(uint8_t ch, uint8_t *p_data, uint32_t length);
uint32_t uartPrintf(uint8_t ch, char *fmt, ...);
uint32_t uartGetBaud(uint8_t ch);


#endif


#endif /* API_INCLUDE_UART_H_ */

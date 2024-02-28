/*
 * uart.c
 *
 *  Created on: Feb 28, 2024
 *      Author: mok07
 */


#include "uart.h"
#include "cdc.h"
#include "qbuffer.h"
#include "usart.h"


#ifdef _USE_HW_UART


#define _USE_UART1


static bool is_open[UART_MAX_CH]; // check channel number

#ifdef _USE_UART2

static qbuffer_t qbuffer[UART_MAX_CH]; // Make qbuffer as number of uart channels
static uint8_t rx_buf[256]; // Size of qbuffer

//UART_HandleTypeDef huart1;
DMA_HandleTypeDef  hdma_usart1_rx;

#endif



bool uartInit(void)
{
	return true;
}

bool uartOpen(uint8_t ch, uint32_t baud)
{
	bool ret = false;

	switch(ch)
	{
		case _DEF_UART1:
			is_open[ch] = true;
			ret = true;
			break;

		case _DEF_UART2:
			#ifdef _USE_UART2
			ret = true;
			is_open[ch] = true;

			qbufferCreate(&qbuffer[ch], &rx_buf[0], 256);

			if(HAL_UART_Receive_DMA(&huart1, (uint8_t *)&rx_buf[0], 256) != HAL_OK)
				{
					 ret = false;
			  }

			qbuffer[ch].in = qbuffer[ch].len - hdma_usart1_rx.Instance->NDTR;
			qbuffer[ch].out = qbuffer[ch].in;
			break;
			#endif
	}

	return ret;
}

uint32_t uartAvailable(uint8_t ch)
{
	uint32_t ret;

	switch(ch)
	{
		case _DEF_UART1:
			ret = cdcAvailable();
			break;

		case _DEF_UART2:
			#ifdef _USE_UART2
			qbuffer[ch].in = (qbuffer[ch].len - hdma_usart1_rx.Instance->NDTR);
			ret = qbufferAvailable(&qbuffer[ch]);
			#endif
			break;
	}

	return ret;
}

uint8_t uartRead(uint8_t ch)
{
	uint8_t ret;

	switch(ch)
	{
		case _DEF_UART1:
			ret = cdcRead();
			break;

		case _DEF_UART2:
			#ifdef _USE_UART2
			qbufferRead(&qbuffer[_DEF_UART2], &ret, 1);
			#endif
			break;
	}

	return ret;
}

uint32_t uartWrite(uint8_t ch, uint8_t *p_data, uint32_t length)
{
	uint32_t ret;

	#ifdef _USE_UART2
	HAL_StatusTypeDef status;
	#endif

	switch(ch)
	{
		case _DEF_UART1:
			ret = cdcWrite(p_data, length);
			break;

		case _DEF_UART2:
			#ifdef _USE_UART2
			status = HAL_UART_Transmit(&huart1, p_data, length, 100);
			if(status == HAL_OK)
			{
				ret = length;
			}
			#endif
			break;
	}

	return ret;
}

uint32_t uartPrintf(uint8_t ch, char *fmt, ...)
{
	char buf[256];
	va_list args;
	int len;
	uint32_t ret;

	va_start(args, fmt);
	len = vsnprintf(buf, 256, fmt, args);

	ret = uartWrite(ch, (uint8_t *)buf, len);

	va_end(args);

	return ret;
}

/*uint32_t uartGetBaud(uint8_t ch)
{
	uint32_t ret = 0;

	switch(ch)
	{
		case _DEF_UART1:
			ret = cdcGetRead();
			break;

		case _DEF_UART2:
			#ifdef _USE_UART2
			ret = huart1.Init.BaudRate;
			#endif
			break;
	}

	return ret;
}*/


#endif

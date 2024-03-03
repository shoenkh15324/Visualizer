/*
 * cdc.c
 *
 *  Created on: Feb 27, 2024
 *      Author: mok07
 */


#include "cdc.h"


#ifdef _USE_HW_CDC


#define BUF_SIZE 512


// circular queue
uint8_t rx_buf[BUF_SIZE];
uint32_t rx_in=0;
uint32_t rx_out=0;
bool rx_full=false;



uint32_t cdcAvailable(void)
{
	uint32_t ret;

	ret = (rx_in - rx_out) % BUF_SIZE;

	return ret;
}

uint8_t cdcRead(void)
{
	uint8_t ret = 0;

	ret = rx_buf[rx_out];

	if(rx_out != rx_in)
	{
		rx_out = (rx_out + 1) % BUF_SIZE;
	}

	return ret;
}

void cdcDataIn(uint8_t rx_data)
{
	rx_buf[rx_in] = rx_data;

	uint8_t next_rx_in = (rx_in + 1) % BUF_SIZE;

	if(next_rx_in != rx_out)
	{
		rx_in = next_rx_in;
	}
}

uint32_t cdcWrite(uint8_t *p_data, uint32_t len)
{
	uint32_t pre_time = 0;
	uint8_t ret;

	pre_time = millis();
	while(1)
	{
		ret = CDC_Transmit_FS(p_data, len);

		if(ret == USBD_OK)
			{
				return len;
			}
			else if(ret == USBD_FAIL)
			{
				return 0;
			}

			if(millis() - pre_time >= 100)
			{
				break;
			}
	}

	return 0;
}

uint32_t cdcPrintf(char *fmt, ...)
{
	char buf[256];
	va_list args;
	int len;
	uint32_t ret;

	va_start(args, fmt);
	len = vsnprintf(buf, 256, fmt, args);

	ret = cdcWrite((uint8_t *)buf, len);

	va_end(args);

	return ret;
}

/*uint8_t cdcGetRead()
{
	return Linecoding.bitrate;
}*/

#endif

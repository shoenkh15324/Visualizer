/*
 * qbuffer.c
 *
 *  Created on: Feb 28, 2024
 *      Author: mok07
 */


#include "qbuffer.h"




void qbufferInit(void)
{

}

bool qbufferCreate(qbuffer_t *p_node, uint8_t *p_buf, uint32_t len)
{
	bool ret = true;

	p_node->in = 0;
	p_node->out = 0;
	p_node->len = len;
	p_node->p_buf = p_buf;

	return ret;
}

void qbufferWrite(qbuffer_t *p_node, uint8_t *p_data, uint32_t len)
{
	bool ret = true;
	uint32_t next_in;

	for(int i=0; i<len; i++)
	{
		next_in = (p_node->in + 1) % p_node->len;

		if(next_in != p_node->out)
		{
			if(p_node->p_buf != NULL)
			{
				p_node->p_buf[p_node->in] = p_data[i];
			}
			p_node->in = next_in;
		}
		else
		{
			ret = false;
			break;
		}
	}

	return ret;
}

bool qbufferRead(qbuffer_t *p_node, uint8_t *p_data, uint32_t len)
{
	bool ret = true;

	for(int i=0; i<len; i++)
	{
		if(p_node->p_buf != NULL)
		{
			p_data[i] = p_node->p_buf[p_node->out];
		}

		if(p_node->out != p_node->in)
		{
			p_node->out = (p_node->out + 1) % p_node->len;
		}
		else
		{
			ret = false;
			break;
		}
	}

	return ret;
}
uint32_t qbufferAvailable(qbuffer_t *p_node)
{
	uint32 ret = (p_node->in - p_node->out) % p_node->len;
	return ret;
}

void qbufferFlush(qbuffer_t *p_node)
{
	p_node->in = 0;
	p_node->out = 0;
}

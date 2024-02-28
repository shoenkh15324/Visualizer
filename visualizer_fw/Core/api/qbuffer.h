/*
 * qbuffer.h
 *
 *  Created on: Feb 28, 2024
 *      Author: mok07
 */

#ifndef API_QBUFFER_H_
#define API_QBUFFER_H_


#include "common.h"


typedef struct
{
	uint32_t in;
	uint32_t out;
	uint32_t len; // length of array
	uint8_t *p_buf; // First address of array
} qbuffer_t;


void qbufferInit(void);
bool qbufferCreate(qbuffer_t *p_node, uint8_t *p_buf, uint32_t len);
bool qbufferWrite(qbuffer_t *p_node, uint8_t *p_data, uint32_t len);
bool qbufferRead(qbuffer_t *p_node, uint8_t *p_data, uint32_t len);
uint32_t qbufferAvailable(qbuffer_t *p_node);
void qbufferFlush(qbuffer_t *p_node);


#endif /* API_QBUFFER_H_ */

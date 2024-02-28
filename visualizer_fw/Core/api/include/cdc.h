/*
 * cdc.h
 *
 *  Created on: Feb 27, 2024
 *      Author: mok07
 */

#ifndef API_INCLUDE_CDC_H_
#define API_INCLUDE_CDC_H_


#include "hw_def.h"
#include "usbd_cdc_if.h"


#ifdef _USE_HW_CDC


uint32_t cdcAvailable(void);
uint8_t cdcRead(void);
void cdcDataIn(uint8_t rx_data);
uint32_t cdcWrite(uint8_t *p_data, uint32_t len);
uint32_t cdcPrintf(char *fmt, ...);

#endif


#endif /* API_INCLUDE_CDC_H_ */

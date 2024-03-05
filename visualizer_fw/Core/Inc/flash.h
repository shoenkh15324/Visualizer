/*
 * flash.h
 *
 *  Created on: Mar 5, 2024
 *      Author: mok07
 */

#ifndef INC_FLASH_H_
#define INC_FLASH_H_

#include "hw_def.h"

#ifdef _USE_HW_FLASH

bool flashInit(void);
bool flashErase(uint32_t addr, uint32_t length);
bool flashWrite(uint32_t addr, uint8_t *p_data, uint32_t length);
bool flashRead(uint32_t addr, uint8_t *p_data, uint32_t length);

#endif

#endif /* INC_FLASH_H_ */

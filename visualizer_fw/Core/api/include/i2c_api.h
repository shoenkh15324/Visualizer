/*
 * i2c_api.h
 *
 *  Created on: Mar 21, 2024
 *      Author: mok07
 */

#ifndef API_INCLUDE_I2C_API_H_
#define API_INCLUDE_I2C_API_H_

#include "hw_def.h"

#ifdef _USE_HW_I2C

#define I2C_MAX_CH		HW_I2C_MAX_CH

#define _DEF_I2C1			0
#define _DEF_I2C2			1
#define _DEF_I2C3			2
#define _DEF_I2C4			3

bool i2cInit(void);
bool i2cIsInit(void);
bool i2cBegin(uint8_t ch, uint32_t freq_khz);
bool i2cIsBegin(uint8_t ch);
void i2cReset(uint8_t ch);
bool i2cIsDeviceReady(uint8_t ch, uint8_t dev_addr);
bool i2cRecovery(uint8_t ch);

bool i2cReadByte(uint8_t ch, uint16_t dev_addr, uint16_t reg_addr, uint8_t *p_data, uint32_t timeout);
bool i2cReadBytes(uint8_t ch, uint16_t dev_addr, uint16_t reg_addr, uint8_t *p_data, uint32_t length, uint32_t timeout);

bool i2cWriteByte(uint8_t ch, uint16_t dev_addr, uint16_t reg_addr, uint8_t data, uint32_t timeout);
bool i2cWriteBytes(uint8_t ch, uint16_t dev_addr, uint16_t reg_addr, uint8_t *p_data, uint32_t length, uint32_t timeout);

bool i2cReadData(uint8_t ch, uint16_t dev_addr, uint8_t *p_data, uint32_t length, uint32_t timeout);
bool i2cWriteData(uint8_t ch, uint16_t dev_addr, uint8_t *p_data, uint32_t length, uint32_t timeout);

void i2cSetTimeout(uint8_t ch, uint32_t timeout);
uint32_t i2cGetTimeout(uint8_t ch);

void i2cClearErrCount(uint8_t ch);
uint32_t i2cGetErrCount(uint8_t ch);

#endif

#endif /* API_INCLUDE_I2C_API_H_ */

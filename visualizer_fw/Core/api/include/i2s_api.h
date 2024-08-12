/*
 * i2s.h
 *
 *  Created on: Mar 23, 2024
 *      Author: mok07
 */

#ifndef API_INCLUDE_I2S_API_H_
#define API_INCLUDE_I2S_API_H_

#include "hw_def.h"

#ifdef _USE_HW_I2S

#define I2S_MAX_CH		HW_I2S_MAX_CH

#define _DEF_I2S0			1
#define _DEF_I2S1			2
#define _DEF_I2S2			3
#define _DEF_I2S3			4

bool i2sInit(void);
bool i2sIsInit(void);
bool i2sStart(void);
bool i2sStop(void);

void Error_Handler(void);

#endif

#endif /* API_INCLUDE_I2S_API_H_ */

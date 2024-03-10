/*
 * spi.h
 *
 *  Created on: Mar 10, 2024
 *      Author: mok07
 */

#ifndef API_INCLUDE_SPI_API_H_
#define API_INCLUDE_SPI_API_H_

#include "hw_def.h"

#ifdef _USE_HW_SPI

#define SPI_MAX_CH		HW_SPI_MAX_CH

#define SPI_MODE0			0
#define SPI_MODE1			1
#define SPI_MODE2			2
#define SPI_MODE3			3

#define _DEF_SPI1             0
#define _DEF_SPI2             1
#define _DEF_SPI3             2
#define _DEF_SPI4             3

bool spiInit(void);
bool spiBegin(uint8_t ch);
void spiSetDataMode(uint8_t ch, uint8_t dataMode);
void spiBitWidth(uint8_t ch, uint8_t bit_width);

bool spiTransfer(uint8_t ch, uint8_t *tx_buf, uint8_t *rx_buf, uint32_t length, uint32_t timeout);
uint8_t spiTransfer8(uint8_t ch, uint8_t data);
uint16_t spiTransfer16(uint8_t ch, uint16_t data);

void spiDmaTxStart(uint8_t ch, uint8_t *p_buf, uint32_t length);
bool spiDmaTxTransfer(uint8_t ch, uint8_t *buf, uint32_t length, uint32_t timeout);
bool spiDmaTxIsDone(uint8_t ch);
void spiAttachTxInterrupt(uint8_t ch, void (*func)());

#endif

#endif /* API_INCLUDE_SPI_API_H_ */

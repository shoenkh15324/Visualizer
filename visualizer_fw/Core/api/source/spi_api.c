/*
 * spi_api.c
 *
 *  Created on: Mar 10, 2024
 *      Author: mok07
 */


#include "spi_api.h"
#include "cli.h"

#ifdef _USE_HW_SPI

#include "spi.h"

typedef struct
{
	bool is_open;
	bool is_tx_done;
	bool is_error;

	void (*func_tx)(void);

	SPI_HandleTypeDef *h_spi;
	DMA_HandleTypeDef *h_dma_tx;
	DMA_HandleTypeDef *h_dma_rx;
} spi_t;

spi_t spi_tbl[SPI_MAX_CH];

#ifdef _USE_HW_CLI
	static void cliSpi(cli_args_t *agrs);
#endif

bool spiInit(void)
{
	bool ret = true;

	for(int i=0; i<SPI_MAX_CH; i++)
	{
		spi_tbl[i].is_open = false;
		spi_tbl[i].is_tx_done = false;
		spi_tbl[i].is_error = false;
		spi_tbl[i].func_tx = NULL;
		spi_tbl[i].h_dma_tx = NULL;
		spi_tbl[i].h_dma_rx = NULL;
	}

#ifdef _USE_HW_CLI
	cliAdd("spi", cliSpi);
#endif

	return ret;
}

bool spiBegin(uint8_t ch)
{
	bool ret = false;
	spi_t *p_spi = &spi_tbl[ch];

	switch(ch)
	{
		case _DEF_SPI1:
			p_spi->h_spi = &hspi4;
			p_spi->h_dma_tx = &hdma_spi4_tx;
			p_spi->is_open = true;
			ret = true;
			break;

		//case _DEF_SPI2:
	}

	return ret;
}

void spiSetDataMode(uint8_t ch, uint8_t dataMode)
{
	spi_t *p_spi = &spi_tbl[ch];

	if(p_spi->is_open == false) return;

	switch(dataMode)
	{
		// CPOL=0, CPHA=0
		case SPI_MODE0:
			p_spi->h_spi->Init.CLKPolarity = SPI_POLARITY_LOW;
			p_spi->h_spi->Init.CLKPhase = SPI_PHASE_1EDGE;
			HAL_SPI_Init(p_spi->h_spi);
			break;

		// CPOL=0, CPHA=1
		case SPI_MODE1:
			p_spi->h_spi->Init.CLKPolarity = SPI_POLARITY_LOW;
			p_spi->h_spi->Init.CLKPhase = SPI_PHASE_2EDGE;
			HAL_SPI_Init(p_spi->h_spi);
			break;

		// CPOL=1, CPHA=0
		case SPI_MODE2:
			p_spi->h_spi->Init.CLKPolarity = SPI_POLARITY_HIGH;
			p_spi->h_spi->Init.CLKPhase = SPI_PHASE_1EDGE;
			HAL_SPI_Init(p_spi->h_spi);
			break;

		// CPOL=1, CPHA=1
		case SPI_MODE3:
			p_spi->h_spi->Init.CLKPolarity = SPI_POLARITY_HIGH;
			p_spi->h_spi->Init.CLKPhase = SPI_PHASE_2EDGE;
			HAL_SPI_Init(p_spi->h_spi);
			break;
	}
}

void spiSetBitWidth(uint8_t ch, uint8_t bit_width)
{
	spi_t *p_spi = &spi_tbl[ch];

	if(p_spi->is_open == false) return;

	p_spi->h_spi->Init.DataSize = SPI_DATASIZE_8BIT;

	if(bit_width == 16)
	{
		p_spi->h_spi->Init.DataSize = SPI_DATASIZE_16BIT;
	}
	HAL_SPI_Init(p_spi->h_spi);
}

uint8_t spiTransfer8(uint8_t ch, uint8_t data)
{
	uint8_t ret;
	spi_t *p_spi = &spi_tbl[ch];

	if(p_spi->is_open == false) return 0;

	HAL_SPI_TransmitReceive(p_spi->h_spi, &data, &ret, 1, 10);

	return ret;
}

uint16_t spiTransfer16(uint8_t ch, uint16_t data)
{
	uint8_t tBuf[2];
	uint8_t rBuf[2];
	uint16_t ret;
	spi_t *p_spi = &spi_tbl[ch];

	if(p_spi->is_open == false) return 0;

	if(p_spi->h_spi->Init.DataSize == SPI_DATASIZE_8BIT)
	{
		tBuf[1] = (uint8_t)data;
		tBuf[0] = (uint8_t)(data>>8);

		HAL_SPI_TransmitReceive(p_spi->h_spi, (uint8_t *)&tBuf, (uint8_t *)&rBuf, 2, 10);

		ret = rBuf[0];
		ret <<= 8;
		ret += rBuf[1];
	}
	else
	{
		HAL_SPI_TransmitReceive(p_spi->h_spi, (uint8_t *)&data, (uint8_t *)&ret, 1, 10);
	}

	return ret;
}

bool spiTransfer(uint8_t ch, uint8_t *tx_buf, uint8_t *rx_buf, uint32_t length, uint32_t timeout)
{
	bool ret = true;
	HAL_StatusTypeDef status;
	spi_t *p_spi = &spi_tbl[ch];

	if(p_spi->is_open == false) return false;

	if(rx_buf == NULL)
	{
		status = HAL_SPI_Transmit(p_spi->h_spi, tx_buf, length, timeout);
	}
	else if(tx_buf == NULL)
	{
		status = HAL_SPI_Receive(p_spi->h_spi, rx_buf, length, timeout);
	}
	else
	{
		status = HAL_SPI_TransmitReceive(p_spi->h_spi, tx_buf, rx_buf, length, timeout);
	}

	if(status != HAL_OK)
	{
		return false;
	}

	return ret;
}

void spiDmaTxStart(uint8_t ch, uint8_t *p_buf, uint32_t length)
{
	spi_t *p_spi = &spi_tbl[ch];

	if(p_spi->is_open == false) return;

	p_spi->is_tx_done = false;
	HAL_SPI_Transmit_DMA(p_spi->h_spi, p_buf, length);
}

bool spiDmaTxTransfer(uint8_t ch, uint8_t *buf, uint32_t length, uint32_t timeout)
{
	bool ret = true;
	uint32_t t_time;

	spiDmaTxStart(ch, (uint8_t *)buf, length);

	t_time = millis();

	if(timeout == 0) return true;

	while(1)
	{
		if(spiDmaTxIsDone(ch))
		{
			break;
		}
		if((millis() - t_time) > timeout)
		{
			ret = false;
			break;
		}
	}

	return ret;
}

bool spiDmaTxIsDone(uint8_t ch)
{
	spi_t *p_spi = &spi_tbl[ch];

	if(p_spi->is_open == false) return false;

	return p_spi->is_tx_done;
}

void spiAttachTxInterrupt(uint8_t ch, void (*func)())
{
	spi_t *p_spi = &spi_tbl[ch];

	if(p_spi->is_open == false) return;

	p_spi->func_tx = func;
}

void HAL_SPI_ErrorCallback(SPI_HandleTypeDef *hspi)
{
	if(hspi->Instance == spi_tbl[_DEF_SPI1].h_spi->Instance)
	{
		spi_tbl[_DEF_SPI1].is_error = true;
	}
}

void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef *hspi)
{
	spi_t *p_spi;

	if(hspi->Instance == spi_tbl[_DEF_SPI1].h_spi->Instance)
	{
		p_spi = &spi_tbl[_DEF_SPI1];
		p_spi->is_tx_done = true;

		if(p_spi->func_tx != NULL)
		{
			(*p_spi->func_tx)();
		}
	}
}

void HAL_SPI_TxRxCpltCallback(SPI_HandleTypeDef *hspi)
{
	spi_t *p_spi;

	if(hspi->Instance == spi_tbl[_DEF_SPI2].h_spi->Instance)
	{
    p_spi = &spi_tbl[_DEF_SPI2];
    p_spi->is_tx_done = true;

    if (p_spi->func_tx != NULL)
    {
      (*p_spi->func_tx)();
    }
	}
}

#ifdef _USE_HW_CLI

void cliSpi(cli_args_t *args)
{
	bool ret = false;

	if(args->argc == 2 && args->isStr(0, "info") == true)
	{
		uint8_t ch;
		ch = args->getData(1);

		spi_t *spi_info = &spi_tbl[ch];

		cliPrintf("spi init : %d\n", spi_info->is_open);

		ret = true;
	}

	if(ret != true)
	{
		cliPrintf("spi info ch[1~%d]\n", SPI_MAX_CH);
	}
}

#endif

#endif


/*
 * sd.c
 *
 *  Created on: Mar 3, 2024
 *      Author: mok07
 */


#include "sd.h"
#include "gpio_api.h"
#include "cli.h"


#ifdef _USE_HW_SD

#include "sdio.h"


static bool is_init = false;
static bool is_detected = false;
static volatile bool is_rx_done = false;
static volatile bool is_tx_done = false;



#ifdef _USE_HW_CLI
static void cliSd(cli_args_t *args);
#endif


bool sdInit(void)
{
	bool ret = false;

	is_detected = false;
	if(gpioPinRead(_PIN_GPIO_SDCARD_DETECT) == true)
	{
		is_detected = true;
	}

	if(is_detected == true)
	{
		if(HAL_SD_Init(&hsd) == HAL_OK)
		{
			if(HAL_SD_ConfigWideBusOperation(&hsd, SDIO_BUS_WIDE_4B) == HAL_OK)
			{
				ret = true;
			}
		}
	}

	is_init = ret;

	#ifdef _USE_HW_CLI
		cliAdd("sd", cliSd);
	#endif

	return ret;
}

bool sdDeInit(void)
{
	bool ret = false;

	if(is_init == true)
	{
		if(HAL_SD_DeInit(&hsd) == HAL_OK)
		{
			ret = true;
		}
	}

	return ret;
}

bool sdIsInit(void)
{
	return is_init;
}

bool sdIsDetected(void)
{
	if(gpioPinRead(_PIN_GPIO_SDCARD_DETECT) == true)
	{
		is_detected = true;
	}
	else
	{
		is_detected = false;
	}

	return is_detected;
}

bool sdGetInfo(sd_info_t *p_info)
{
	bool ret = false;
	sd_info_t *p_sd_info = (sd_info_t *)p_info;

	HAL_SD_CardInfoTypeDef card_info;

	if(is_init == true)
	{
		HAL_SD_GetCardInfo(&hsd, &card_info);

		p_sd_info->card_type 					= card_info.CardType;
    p_sd_info->card_version       = card_info.CardVersion;
    p_sd_info->card_class         = card_info.Class;
    p_sd_info->rel_card_Add       = card_info.RelCardAdd;
    p_sd_info->block_numbers      = card_info.BlockNbr;
    p_sd_info->block_size         = card_info.BlockSize;
    p_sd_info->log_block_numbers  = card_info.LogBlockNbr;
    p_sd_info->log_block_size     = card_info.LogBlockSize;
    p_sd_info->card_size          =  (uint32_t)((uint64_t)p_sd_info->block_numbers * (uint64_t) p_sd_info->block_size / (uint64_t)1024 / (uint64_t)1024);

    ret = true;
	}

	return ret;
}

bool sdIsBusy(void)
{
	bool is_busy;

	if(HAL_SD_GetCardState(&hsd) == HAL_SD_CARD_TRANSFER)
	{
		is_busy = false;
	}
	else
	{
		is_busy = true;
	}

	return is_busy;
}

bool sdIsReady(uint32_t timeout)
{
	uint32_t pre_time;

	pre_time = millis();
	while(millis() - pre_time < timeout)
	{
		if(sdIsBusy() == false)
		{
			return true;
		}
	}

	return false;
}

bool sdReadBlocks(uint32_t block_addr, uint8_t *p_data, uint32_t num_of_blocks, uint32_t timeout_ms)
{
	bool ret = false;
	uint32_t pre_time;

	is_rx_done = false;
	if(HAL_SD_ReadBlocks_DMA(&hsd, (uint8_t *)p_data, block_addr, num_of_blocks) == HAL_OK)
	{
		pre_time = millis();
		while(is_rx_done == false)
		{
			if(millis() - pre_time >= timeout_ms)
			{
				break;
			}
		}

		while(sdIsBusy() == true)
			{
				if(millis() - pre_time >= timeout_ms)
				{
					is_rx_done = false;
					break;
				}
			}

			ret = is_rx_done;
	}

	return ret;
}

bool sdWriteBlocks(uint32_t block_addr, uint8_t *p_data, uint32_t num_of_blocks, uint32_t timeout_ms)
{
	bool ret = false;
	uint32_t pre_time;

	is_tx_done = false;
	if(HAL_SD_WriteBlocks_DMA(&hsd, (uint8_t *)p_data, block_addr, num_of_blocks) == HAL_OK)
	{
		pre_time = millis();
		while(is_tx_done == false)
		{
			if(millis() - pre_time >= timeout_ms)
			{
				break;
			}
		}

		pre_time = millis();
		while(sdIsBusy() == true)
		{
			if(millis() - pre_time >= timeout_ms)
			{
				is_tx_done = false;
				break;
			}
		}

		ret = is_tx_done;
	}

	return ret;
}

bool sdEraseBlocks(uint32_t start_addr, uint32_t end_addr)
{
	bool ret;

	if(HAL_SD_Erase(&hsd, start_addr, end_addr) == HAL_OK)
	{
		ret = true;
	}

	return ret;
}


__weak void HAL_SD_TxCpltCallback(SD_HandleTypeDef *hsd)
{
	is_tx_done = true;
}

__weak void HAL_SD_RxCpltCallback(SD_HandleTypeDef *hsd)
{
	is_rx_done = true;
}

#ifdef _USE_HW_CLI

void cliSd(cli_args_t *args)
{
	bool ret = false;

	if(args->argc == 1 && args->isStr(0, "info") == true)
	{
		sd_info_t sd_info;

		cliPrintf("sd init : %d\n", is_init);
		cliPrintf("sd connected : %d\n", is_detected);

		if(is_init == true)
		{
			if(sdGetInfo(&sd_info) == true)
			{
        cliPrintf("   card_type            : %d\n", sd_info.card_type);
        cliPrintf("   card_version         : %d\n", sd_info.card_version);
        cliPrintf("   card_class           : %d\n", sd_info.card_class);
        cliPrintf("   rel_card_Add         : %d\n", sd_info.rel_card_Add);
        cliPrintf("   block_numbers        : %d\n", sd_info.block_numbers);
        cliPrintf("   block_size           : %d\n", sd_info.block_size);
        cliPrintf("   log_block_numbers    : %d\n", sd_info.log_block_numbers);
        cliPrintf("   log_block_size       : %d\n", sd_info.log_block_size);
        cliPrintf("   card_size            : %d MB, %d.%d GB\n", sd_info.card_size, sd_info.card_size/1024, ((sd_info.card_size * 10)/1024) % 10);
			}
		}

		ret = true;
	}

	if(args->argc == 2 && args->isStr(0, "read") == true)
	{
		uint32_t number;
		uint32_t buf[512/4];

		number = args->getData(1);

		if(sdReadBlocks(number, (uint8_t *)buf, 1, 1000) == true)
		{
			for(int i=0; i<512/4; i++)
			{
				cliPrintf("%d:%04d : 0x%08X\n", number, i*4, buf[i]);
			}
		}
		else
		{
			cliPrintf("sdRead Fail\n");
		}

		ret = true;
	}

	if(ret != true)
	{
		cliPrintf("sd info\n");

		if(is_init == true)
		{
			cliPrintf("sd read block_number\n");
		}
	}
}


#endif

#endif

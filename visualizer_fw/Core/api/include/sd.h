/*
 * sd.h
 *
 *  Created on: Mar 3, 2024
 *      Author: mok07
 */

#ifndef API_INCLUDE_SD_H_
#define API_INCLUDE_SD_H_

#include "hw_def.h"


#ifdef _USE_HW_SD

typedef struct
{
	uint32_t card_type;					// card type
	uint32_t card_version;			// card version
	uint32_t card_class;				// class of the card class
	uint32_t rel_card_Add;			// relative card address
	uint32_t block_numbers;			// card capacity in blocks
	uint32_t block_size;				// one block size in bytes
	uint32_t log_block_numbers;	// card logical capacity in blocks
	uint32_t log_block_size; 		// logical block size in bytes
	uint32_t card_size;
} sd_info_t;

bool sdInit(void);
bool sdDeInit(void);
bool sdIsInit(void);
bool sdIsDetected(void);
bool sdGetInfo(sd_info_t *p_info);
bool sdIsBusy(void);
bool sdIsReady(uint32_t timeout);

bool sdReadBlocks(uint32_t block_addr, uint8_t *p_data, uint32_t num_of_blocks, uint32_t timeout_ms);
bool sdWriteBlocks(uint32_t block_addr, uint8_t *p_data, uint32_t num_of_blocks, uint32_t timeout_ms);
bool sdEraseBlocks(uint32_t start_addr, uint32_t end_addr);


#endif

#endif /* API_INCLUDE_SD_H_ */

/*
 * cli.h
 *
 *  Created on: Feb 28, 2024
 *      Author: mok07
 */

#ifndef API_INCLUDE_CLI_H_
#define API_INCLUDE_CLI_H_



#include "hw_def.h"



#ifdef _USE_HW_CLI

#define CLI_CMD_LIST_MAX			HW_CLI_CMD_LIST_MAX // Number of lists
#define CLI_CMD_NAME_MAX			HW_CLI_CMD_NAME_MAX // Length of command
#define CLI_LINE_HIS_MAX      HW_CLI_LINE_HIS_MAX // Number of commands remembered
#define CLI_LINE_BUF_MAX      HW_CLI_LINE_BUF_MAX // Number of strings received by the command line


typedef struct
{
	uint16_t argc; // Number of arguments in cli commands
	char **argv; // An array of pointers pointing to a string for each argument

	int32_t (*getData)(uint8_t index); // Function pointers for obtaining data from the CLI
	float (*getFloat)(uint8_t index); // Function pointer to get floating point format data from the CLI
	char *(*getStr)(uint8_t index); // Function pointer to get string data from the CLI
	bool (*isStr)(uint8_t index, char *p_str); // Function pointer to determine if data from a particular index matches a given string in the CLI
} cli_args_t;


bool cliInit(void);
bool cliOpen(uint8_t ch, uint32_t baud);
bool cliOpenLog(uint8_t ch, uint32_t baud);
bool cliMain(void);
void cliPrintf(const char *fmt, ...);
bool cliAdd(const char *cmd_str, void (*p_func)(cli_args_t *));
bool cliKeepLoop(void);
uint32_t cliAvailable(void);
uint8_t cliRead(void);
uint32_t cliWrite(uint8_t *p_data, uint32_t lenght);

#endif


#endif /* API_INCLUDE_CLI_H_ */

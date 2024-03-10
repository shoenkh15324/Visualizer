/*
 * han.h
 *
 *  Created on: Mar 10, 2024
 *      Author: mok07
 */

#ifndef API_HANGUL_HAN_H_
#define API_HANGUL_HAN_H_

#include <stdint.h>
#include <string.h>

#define PHAN_NULL_CODE    0	// NULL code
#define PHAN_HANGUL_CODE  1 // hangeul code
#define PHAN_ENG_CODE     2 // eng code
#define PHAN_SPEC_CODE    3 // Special Character Code
#define PHAN_END_CODE     4 // end code

typedef struct
{
  uint16_t HanCode;
  uint16_t Size_Char;  // 글자 1개의 바이트수(한글:2 영문:1)
  uint16_t Code_Type;  // 한/영/특수 문자인지 감별

  uint8_t  FontBuffer[32]; // save font data
} han_font_t;

uint16_t hanFontLoad(char *HanCode, han_font_t *FontPtr);

#endif /* API_HANGUL_HAN_H_ */

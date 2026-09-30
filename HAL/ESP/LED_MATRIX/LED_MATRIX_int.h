/*
 * LED_MATRIX_int.h
 *
 *  Created on: Sep 14, 2023
 *      Author: admin
 */
#include "LED_MATRIX_cfg.h"
#ifndef HAL_LED_MATRIX_LED_MATRIX_INT_H_
#define HAL_LED_MATRIX_LED_MATRIX_INT_H_

enum{
	TurnOff=0,
	TurnOn
};
void HLEDMATRIX_vInit(void);
void HLEDMATRIX_vDisplay(u32 *arr,u32 A_u32FrameDelay);
void HLEDMATRIX_vDisableAllColumn(void);
void HLED_MATRIX_vColumnRow(u32 A_u32arr[][NUM_OF_COL],u32 A_u8NumberOfColum,u8 A_u8NumberOfRow,u8 A_u8TurnOn);
void HLEDLEDMARTIX_vDisplayPicture(u32  arr[][NUM_OF_COL],u32 A_u32FrameDelay);
void HLEDMATRIX_vScrollData(u32 *A_pu8data, u8 A_u8NumberOfCharacter);
#endif /* HAL_LED_MATRIX_LED_MATRIX_INT_H_ */

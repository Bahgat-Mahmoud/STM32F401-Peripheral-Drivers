/*
 * RCC_prg.c
 *
 *  Created on: Aug 8, 2023
 *      Author: admin
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "RCC_int.h"
#include "RCC_cfg.h"
#include "RCC_prv.h"



void MRCC_vInit(void)
{
	/*1- CSS (ON/OFF)*/
	CLR_BIT(RCC->CR,CSS_ON);
	/*2- HSE_BYP */
	CLR_BIT(RCC->CR,HSEBYP);
	/*Select clock switch (HSI/HSE/PLL)*/
	SET_BIT(RCC->CFGR, SW0);
	/*4- Bus prescalers */
	/*5-PLL config */
	/*6-Enable The Selected clock (HSI/HSE/PLL)*/
#if RCC_HSE_ENABLE == ENABLE
	SET_BIT(RCC->CR,HSE_ON);
#endif
}

void MRCC_vEnableClock (u32 A_u32BusId,u32 A_u32PeripheralId)
{
	switch(A_u32BusId)
	{
	case RCC_AHB1:
		SET_BIT(RCC->AHB1ENR,A_u32PeripheralId);
		break;
	case RCC_AHB2:
		SET_BIT(RCC->AHB2ENR,A_u32PeripheralId);
		break;
	case RCC_APB1:
		SET_BIT(RCC->APB1ENR,A_u32PeripheralId);
		break;
	case RCC_APB2:
		SET_BIT(RCC->APB2ENR,A_u32PeripheralId);
		break;
	}
}

void MRCC_vDisableClock(u32 A_u32BusId,u32 A_u32PeripheralId)
{
	switch(A_u32BusId)
	{
	case RCC_AHB1:
		CLR_BIT(RCC->AHB1ENR,A_u32PeripheralId);
		break;
	case RCC_AHB2:
		CLR_BIT(RCC->AHB2ENR,A_u32PeripheralId);
		break;
	case RCC_APB1:
		CLR_BIT(RCC->APB1ENR,A_u32PeripheralId);
		break;
	case RCC_APB2:
		CLR_BIT(RCC->APB2ENR,A_u32PeripheralId);
		break;
	}
}





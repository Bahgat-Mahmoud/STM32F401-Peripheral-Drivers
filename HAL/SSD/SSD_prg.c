/*
 * SSD_prg.c
 *
 *  Created on: Aug 11, 2023
 *      Author: admin
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include  "../../MCAL/GPIO/GPIO_int.h"
#include "../../MCAL/RCC/RCC_int.h"
#include "SSD_int.h"
#include "SSD_cfg.h"
#include "SSD_ prv.h"


static u8 G_u8SsdArr[10] = {
		0x3F,     // 0
		0x06,     // 1
		0x5B,
		0x4f,
		0x66,
		0x6D,
		0x7D,
		0x07,
		0x7F,
		0x6F       //9
};

void HSSD_vInit(SSD_cfg_t *A_xptr)
{
#if SSD_USED   == SSD_NORMAL
	for(u8 L_u8Iterator=0;L_u8Iterator<7;L_u8Iterator++)
	{
		MGPIO_vSetPinMode(A_xptr[L_u8Iterator].port,A_xptr[L_u8Iterator].pin,GPIO_MODE_OUTPUT);
		MGPIO_vSetPinOutputType(A_xptr[L_u8Iterator].port,A_xptr[L_u8Iterator].pin,GPIO_OUTPUTTYPE_PUSHPULL);
		MGPIO_vSetPinOutputSpeed(A_xptr[L_u8Iterator].port,A_xptr[L_u8Iterator].pin,GPIO_OUTSPEED_LOW);
	}
#elif SSD_USED   == SSD_BCD
	for(u8 L_u8Iterator=0;L_u8Iterator<4;L_u8Iterator++)
	{
		MGPIO_vSetPinMode(A_xptr[L_u8Iterator].port,A_xptr[L_u8Iterator].pin,GPIO_MODE_OUTPUT);
		MGPIO_vSetPinOutputType(A_xptr[L_u8Iterator].port,A_xptr[L_u8Iterator].pin,GPIO_OUTPUTTYPE_PUSHPULL);
		MGPIO_vSetPinOutputSpeed(A_xptr[L_u8Iterator].port,A_xptr[L_u8Iterator].pin,GPIO_OUTSPEED_LOW);
	}
#endif
}

void HSSD_vDisplay(SSD_cfg_t *A_xptr,u8 A_u8Val,u8 A_u8Type)
{
#if SSD_USED   == SSD_NORMAL
	if(A_u8Val<=9)
	{
		switch(A_u8Type)
		{
		case SSD_COMMEN_CATHOD:
			for(int L_u8Iterator = 0; L_u8Iterator<7 ;L_u8Iterator++) //
			{
				MGPIO_vSetPinValFast(A_xptr[L_u8Iterator].port,A_xptr[L_u8Iterator].pin,GET_BIT(G_u8SsdArr[A_u8Val],L_u8Iterator));
			}
			break;
		case SSD_COMMEN_ANODE:
			for(int L_u8Iterator = 0; L_u8Iterator<7 ;L_u8Iterator++)
			{
				MGPIO_vSetPinValFast(A_xptr[L_u8Iterator].port,A_xptr[L_u8Iterator].pin,!GET_BIT(G_u8SsdArr[A_u8Val],L_u8Iterator));
			}
			break;
		}
	}
#elif SSD_USED   == SSD_BCD
	if(A_u8Val<=9)
	{
		switch(A_u8Type)
		{
		case SSD_COMMEN_CATHOD:
			for(int L_u8Iterator = 0; L_u8Iterator<4 ;L_u8Iterator++)
			{
				MGPIO_vSetPinValFast(A_xptr[L_u8Iterator].port,A_xptr[L_u8Iterator].pin,GET_BIT(A_u8Val,L_u8Iterator));
			}
			break;
		case SSD_COMMEN_ANODE:
			for(int L_u8Iterator = 0; L_u8Iterator<4 ;L_u8Iterator++)
			{
				MGPIO_vSetPinValFast(A_xptr[L_u8Iterator].port,A_xptr[L_u8Iterator].pin,!GET_BIT(A_u8Val,L_u8Iterator));
			}
			break;
		}
	}

#endif

}
//
void HSSD_vTurnOff(SSD_cfg_t *A_xptr,u8 A_u8Type)
{
	switch(A_u8Type)
	{
	case SSD_COMMEN_CATHOD:
		for(int L_u8Iterator = 0; L_u8Iterator<8 ;L_u8Iterator++)
		{
			MGPIO_vSetPinValue(A_xptr[L_u8Iterator].port,A_xptr[L_u8Iterator].pin,GET_BIT(0,L_u8Iterator));
		}
		break;
	case SSD_COMMEN_ANODE:
		for(int L_u8Iterator = 0; L_u8Iterator<8 ;L_u8Iterator++)
		{
			MGPIO_vSetPinValue(A_xptr[L_u8Iterator].port,A_xptr[L_u8Iterator].pin,!GET_BIT(0,L_u8Iterator));
		}
		break;
	}
}

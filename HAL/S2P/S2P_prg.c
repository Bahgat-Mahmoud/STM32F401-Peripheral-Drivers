/*
 * S2P_prg.c
 *
 *  Created on: Sep 12, 2023
 *      Author: admin
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "S2P_cfg.h"
#include "S2P_int.h"
#include "../../MCAL/GPIO/GPIO_int.h"
#include "../../MCAL/SYSTICK/STK_int.h"
extern MGPIO_Config_t DataSerial ;
extern MGPIO_Config_t Shift ;
extern MGPIO_Config_t Latch ;
void HS2P_vInit(void)
{
	/*port SD, pin,out*/
	MGPIO_vInit(&DataSerial);
	MGPIO_vInit(&Shift);
	MGPIO_vInit(&Latch);
}

static void S2P_svShift(void)
{
	MGPIO_vSetPinVal(Shift.port,Shift.pin,1);
	/*delay*/
//	MSTK_vSetBusyWait(1);
	MGPIO_vSetPinVal(Shift.port,Shift.pin,0);
	/*delay*/
//	MSTK_vSetBusyWait(1);
}
static void S2P_svLatch(void)
{
	MGPIO_vSetPinVal(Latch.port,Latch.pin,1);
	/*delay*/
//	MSTK_vSetBusyWait(1);
	MGPIO_vSetPinVal(Latch.port,Latch.pin,0);
	/*delay*/
//	MSTK_vSetBusyWait(1);
}
void HS2P_vSendData(u8 * A_pu8Data, u8 A_u8Size)
{
	for(u8 j=0;j<A_u8Size;j++)
	{
		for(u8 i=0;i<8;i++) //0 1 2 i
			{
				/*SD*/
				MGPIO_vSetPinVal(DataSerial.port,DataSerial.pin,GET_BIT(A_pu8Data[j],i));
				/*shift*/
				S2P_svShift();

			}
	}
		/*latch*/
		S2P_svLatch();
		//////////////////////another method/////////////////////////
//		for(u8 i=0;i<8*Size;i++) //0 1 2 i //i=8,9,
//			{
//				/*SD*/
//				MGPIO_vSetPinVal(DataSerial.port,DataSerial.pin,GET_BIT(A_pu8Data[i/8],i%8));
//				/*shift*/
//				S2P_svShift();
//
//			}
//		   S2P_svLatch();
}

// 0b  0101 10 1 1
void HS2P_vSendData_(u32 A_pu8Data)//0x3F
{
    /*Serial Data Send*/
	for(u8 i=0;i<8*NUMBER_OF_REGISTER;i++) //0 1 2 i
	{
		/*SD Bit*/
		MGPIO_vSetPinVal(DataSerial.port,DataSerial.pin,GET_BIT(A_pu8Data,i));
		/*shift*/
		S2P_svShift();

	}
	/*latch*/
	S2P_svLatch();
}











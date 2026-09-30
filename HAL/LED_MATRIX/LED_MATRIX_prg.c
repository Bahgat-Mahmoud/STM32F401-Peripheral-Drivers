/*
 * LED_MATRIX_prg.c
 *
 *  Created on: Sep 14, 2023
 *      Author: admin
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/GPIO/GPIO_int.h"
#include "../../MCAL/SYSTICK/STK_int.h"


#include "LED_MATRIX_cfg.h"
#include "LED_MATRIX_int.h"

extern MGPIO_Config_t row[NUM_OF_ROW]  ;
extern MGPIO_Config_t col[NUM_OF_COL]  ;

void HLEDMATRIX_vInit(void)
{
	for(u8 i=0;i<NUM_OF_COL;i++)
	{
		MGPIO_vInit(&col[i]);
	}
	for(u8 i=0;i<NUM_OF_ROW;i++)
	{
		MGPIO_vInit(&row[i]);
	}
	MSTK_vInit();
}
void HLEDMATRIX_vDisableAllColumn(void)
{
	for(u8 i=0;i<NUM_OF_COL;i++)
	{
		MGPIO_vSetPinVal(col[i].port,col[i].pin,GPIO_HIGH);
	}
}
//0x0001 0000
static void HLEDMATRIX_svSetRowData(u32 A_u8Value)
{
	for(u8 i=0;i<NUM_OF_ROW;i++)
	{
		MGPIO_vSetPinVal(row[i].port,row[i].pin,GET_BIT(A_u8Value,i));
	}
}
static void HLEDMATRIX_svSetColumnEnable(u32 A_u32columnNumber)
{
	MGPIO_vSetPinVal(col[A_u32columnNumber].port,col[A_u32columnNumber].pin,GPIO_LOW);
}
//  0      1      2    3      4    5      6     7
// {0x10, 0x20, 0x44, 0x50, 0x44, 0x40, 0x20, 0x10}
void HLEDMATRIX_vDisplay(u32 *arr, u32 A_u32FrameDelay )
{

	for(u32 j=0;j<A_u32FrameDelay;j++)
	{
		for(u32 i=0;i<NUM_OF_COL;i++)
		{
			/*disable all Column */
			HLEDMATRIX_vDisableAllColumn();
			/*set data on row pin*/
			HLEDMATRIX_svSetRowData(arr[i]);
			/*set column for Enable */
			HLEDMATRIX_svSetColumnEnable(i);
			/*delay */
			MSTK_vSetBusyWait(2500);//2.5ms //20*1000/NUM_OF_COL
		}
	}
	HLEDMATRIX_vDisableAllColumn();

}
void HLED_MATRIX_vColumnRow(u32 A_u32arr[][NUM_OF_COL],u32 A_u8NumberOfColum,u8 A_u8NumberOfRow,u8 A_u8TurnOn)
{
	switch(A_u8TurnOn)
	{
	case TurnOff: A_u32arr[A_u8NumberOfRow][A_u8NumberOfColum] = 0 ; break;
	case TurnOn : A_u32arr[A_u8NumberOfRow][A_u8NumberOfColum] = 1 ; break;
	}
}
static void HLED_MATRIX_vConvertTwoDimintionArrayToOneDimintionArray(u32 A_u32arr[][NUM_OF_COL],u32 *A_pu8OneDimintionArray)
{
//	for(u32 j=0;j<NUM_OF_COL;j++)
//	{
//		for(u32 i=0;i<NUM_OF_ROW;i++)
//		{
//			A_pu8OneDimintionArray[j] &= ~(0b1<<i);
//			A_pu8OneDimintionArray[j] |= (A_u32arr[i][j]<<i);
//		}
//	}
	for(u32 i=0;i<NUM_OF_ROW*NUM_OF_COL;i++)
	{
		A_pu8OneDimintionArray[i/NUM_OF_ROW] &= ~(0b1<<(i%NUM_OF_ROW));
		A_pu8OneDimintionArray[i/NUM_OF_ROW] |= (A_u32arr[i%NUM_OF_ROW][i/NUM_OF_ROW]<<(i%NUM_OF_ROW));
	}
}
void HLEDLEDMARTIX_vDisplayPicture(u32  arr[][NUM_OF_COL],u32 A_u32FrameDelay)
{
	u32 A_u32Picture[NUM_OF_COL] ={0};
		/*convert two dimension array two one dimension array*/
		HLED_MATRIX_vConvertTwoDimintionArrayToOneDimintionArray(arr,A_u32Picture);
		/*display photo*/
		HLEDMATRIX_vDisplay(A_u32Picture,A_u32FrameDelay);
}
void HLEDMATRIX_vScrollData(u32 *A_pu8data, u8 A_u8NumberOfCharacter)
{
	u8 temp ;
	for(u8 j=0;j<A_u8NumberOfCharacter-1;j++)
	{
	temp=A_pu8data[0];
	for(u32 i=0;i<A_u8NumberOfCharacter*NUM_OF_COL;i++)
	{
		A_pu8data[i-1] = A_pu8data[i];
	}
	A_pu8data[6*8-1] = temp;
	HLEDMATRIX_vDisplay(A_pu8data,10);
	}
}


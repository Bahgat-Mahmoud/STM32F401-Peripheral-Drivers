/*
 * TFT_prg.c
 *
 *  Created on: Sep 20, 2023
 *      Author: admin
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/GPIO/GPIO_int.h"
#include "../../MCAL/SPI/SPI_int.h"
#include "../../MCAL/SYSTICK/STK_int.h"

#include "TFT_cfg.h"
#include "TFT_int.h"
#include "TFT_prv.h"

extern MGPIO_Config_t   RESET_PIN  ;
extern MGPIO_Config_t   A0_PIN  ;

static void TFT_svReset(void)
{
	MGPIO_vSetPinVal(RESET_PIN.port,RESET_PIN.pin,GPIO_HIGH);
	MSTK_vSetBusyWait(100);
	MGPIO_vSetPinVal(RESET_PIN.port,RESET_PIN.pin,GPIO_LOW);
	MSTK_vSetBusyWait(10);
	MGPIO_vSetPinVal(RESET_PIN.port,RESET_PIN.pin,GPIO_HIGH);
	MSTK_vSetBusyWait(100);
	MGPIO_vSetPinVal(RESET_PIN.port,RESET_PIN.pin,GPIO_LOW);
	MSTK_vSetBusyWait(100);
	MGPIO_vSetPinVal(RESET_PIN.port,RESET_PIN.pin,GPIO_HIGH);
	MSTK_vSetBusyWait(120000);
}
static void TFT_svWriteCommand(u8 A_u8Command)
{
	MGPIO_vSetPinVal(A0_PIN.port,A0_PIN.pin,GPIO_LOW);
	(void)MSPI_u16Transceive(A_u8Command,SPI_1);
}
static void TFT_svWriteData(u8 A_u8Data)
{
	MGPIO_vSetPinVal(A0_PIN.port,A0_PIN.pin,GPIO_HIGH);
	(void)MSPI_u16Transceive(A_u8Data,SPI_1);
}
void HTFT_vInit(void)
{
	/*init your pins*/
	MGPIO_vInit(&RESET_PIN);
	MGPIO_vInit(&A0_PIN);
	MSPI_vInit();
	MSTK_vInit();
	/*Reset sequence */
	TFT_svReset();
	/*Sleep out*/
	TFT_svWriteCommand(COMMAND_SLEAPOUT);
	/*delay(10ms)*/
	MSTK_vSetBusyWait(10000);
	/*Color Mode*/
	TFT_svWriteCommand(COMMAND_COLOR_MODE);
	TFT_svWriteData(DATA_COLOR); // RGB565
	/*Display on*/
	TFT_svWriteCommand(COMMAND_DISPLAY_ON);
}
void HTFT_vDisplayPicture(u16 *ptr)
{
	/*X*/
	TFT_svWriteCommand(COMMAND_X);
	/*start x*/
	TFT_svWriteData(0); //High
	TFT_svWriteData(0); //Low
	/*end x*/
	TFT_svWriteData(0); //High
	TFT_svWriteData(127); //Low
	/*Y*/
	TFT_svWriteCommand(COMMAND_Y);
	/*start x*/
	TFT_svWriteData(0); //High
	TFT_svWriteData(0); //Low
	/*end x*/
	TFT_svWriteData(0); //High
	TFT_svWriteData(159); //Low
	/*Command write Data*/
	TFT_svWriteCommand(COMMAND_MEM_WRITE);

	for(u32 i=0;i<20480;i++)
	{
		TFT_svWriteData((u8)(ptr[i]>>8)); //High
		TFT_svWriteData((u8)ptr[i]); //Low
	}
}


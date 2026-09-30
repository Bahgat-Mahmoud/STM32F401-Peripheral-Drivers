/*
 * HEXPARSER_prg.c
 *
 *  Created on: Sep 3, 2023
 *      Author: admin
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/FMI/FMI_int.h"

#include "HEXPARSER_int.h"

#define FLASH_BASE_ADDR   0x08000000   //Sector0
//0x10   0b0001 0000 --> 16 bytes
//78   01  EOF   04  high part address
// ":10 0000 00 0000 0120 C502 0008 CB02 0008 CF02 0008  52"
//  012 3456 78 9
u8 Higher_address=0x800;



static u8 HEXPARSER_u8AsciiToHex(u8 A_u8Ascii) // '1'  --> 1
{
	u8 RetirnVal=0;
	if(A_u8Ascii>='0' && A_u8Ascii<='9')
	{
		RetirnVal = A_u8Ascii - '0' ;
	}
	else if (A_u8Ascii>='A' && A_u8Ascii<='F') // 0b001010
	{
		RetirnVal = A_u8Ascii- 'A' + 10 ;
	}
	return  RetirnVal ;
}
// ": 10 0000 00 0000 0120 C502 0008 CB02 0008 CF02 0008  52"
//  0 12 3456 78 9
// CC              bit1,2   size   CC =  (CC_H<<4) |  CC_L ;
// lower_address   bit3,4,5,6
// address = lower_address | (Higher_address<<4) ;
// Data in u16  u16 buffer[100];
// Flash  (address,array of data,size);

void HEXPARSER_vParseData(u8 A_pu8Data[])
{
	/*Character count*/
	u8 CC_L,CC_H,CC;
	u8 digit0,digit1,digit2,digit3;
	u32 Address;
	u16 DataBuffer[50];
	CC_H = HEXPARSER_u8AsciiToHex(A_pu8Data[1]); // 1
	CC_L = HEXPARSER_u8AsciiToHex(A_pu8Data[2]);
	CC = CC_L | (CC_H<<4);  // size of data (byte)
	/*higher address*/
	digit0 = HEXPARSER_u8AsciiToHex(A_pu8Data[3]); //  0000 0000 0000 0000
	digit1 = HEXPARSER_u8AsciiToHex(A_pu8Data[4]);
	digit2 = HEXPARSER_u8AsciiToHex(A_pu8Data[5]);
	digit3 = HEXPARSER_u8AsciiToHex(A_pu8Data[6]);
	Address = (digit0<<12) | (digit1<<8) | (digit2<<4) | digit3 | FLASH_BASE_ADDR ;
	//0000 0120 C502 0008 CB02 0008 CF02 0008   CC=16  size 16/2=8
	//9 10 11 12, 13 14 15 16,17
	for(u8 i=0 ; i<(CC/2) ;i++) //0 1
	{
		digit0 = HEXPARSER_u8AsciiToHex(A_pu8Data[i*4+9]); //  0000 0000 0000 0000
		digit1 = HEXPARSER_u8AsciiToHex(A_pu8Data[i*4+10]);
		digit2 = HEXPARSER_u8AsciiToHex(A_pu8Data[i*4+11]);
		digit3 = HEXPARSER_u8AsciiToHex(A_pu8Data[i*4+12]);
		DataBuffer[i] = (digit0<<12) | (digit1<<8) | (digit2<<4) | digit3 ;
	}
	MFMI_vFlashWrite(Address,DataBuffer,CC/2);
}







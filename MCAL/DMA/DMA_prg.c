/*
 * DMA_prg.c
 *
 *  Created on: Aug 28, 2023
 *      Author: admin
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"


#include "DMA_int.h"
#include "DMA_prv.h"
#include "../../MCAL/GPIO/GPIO_int.h"
static void (*MDMA_SetCallBack[8]) (void);
static void MDMA_svClearFlagCh0(void) ;
void MDMA_vInit(u8 A_u8StreamId)
{
	/*1-disable DMA*/
	CLR_BIT(DMA2->S[A_u8StreamId].CR,0);
	/*2-Select channel ch0*/
	/*3-set sw priority leve low ... very high*/
	SET_BIT(DMA2->S[A_u8StreamId].CR,16);
	SET_BIT(DMA2->S[A_u8StreamId].CR,17);
	/*4-PSIZE  source */
	SET_BIT(DMA2->S[A_u8StreamId].CR,12);
	/*5- MSIZE destination*/
	SET_BIT(DMA2->S[A_u8StreamId].CR,14);
	/*6-mem inc & Peripheral inc*/
	SET_BIT(DMA2->S[A_u8StreamId].CR,10);
	SET_BIT(DMA2->S[A_u8StreamId].CR,9);
	/*7-disable Circular */
	CLR_BIT(DMA2->S[A_u8StreamId].CR,8);
	/*8- Data transfer memory to memory*/
	SET_BIT(DMA2->S[A_u8StreamId].CR,7);
	CLR_BIT(DMA2->S[A_u8StreamId].CR,6);
	/*9-FIFO Selection*/
	SET_BIT(DMA2->S[A_u8StreamId].FCR,0);
	SET_BIT(DMA2->S[A_u8StreamId].FCR,1);
	/*10-disable Direct Mode */
	SET_BIT(DMA2->S[A_u8StreamId].FCR,2);
	/*11-enable Transfer complete interrupt*/
	SET_BIT(DMA2->S[A_u8StreamId].CR,4);

}

void MDMA_vSetAddress(u8 A_u8StreamId,u32 *A_u32SourceAddress,u32 *A_u32DestAddress,u32 A_u32Length)
{
	DMA2->S[A_u8StreamId].NDTR = A_u32Length;
	DMA2->S[A_u8StreamId].PAR  = (u32)A_u32SourceAddress;
	DMA2->S[A_u8StreamId].M0AR = (u32)A_u32DestAddress;

}

/*Start*/
void MDMA_vStramEnable(u8 A_u8StreamId)
{
	SET_BIT(DMA2->S[A_u8StreamId].CR,0);
}
void MDMA_vStramDisable(u8 A_u8StreamId)
{
	CLR_BIT(DMA2->S[A_u8StreamId].CR,0);
}
void MDMA_vSetCallBack(u8 A_u8StreamId, void (*Fptr)(void))
{
	MDMA_SetCallBack[A_u8StreamId] = Fptr ;
}

static void MDMA_svClearFlagCh0(void)
{
	SET_BIT(DMA2->LIFCR,5);
}

void DMA2_Stream0_IRQHandler(void)
{
	MDMA_svClearFlagCh0();
	if(MDMA_SetCallBack[0]!= 0)
	{
		MDMA_SetCallBack[0]();
	}
}




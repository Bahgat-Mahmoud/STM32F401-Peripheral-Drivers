/*
 * DMA_int.h
 *
 *  Created on: Aug 28, 2023
 *      Author: admin
 */

#ifndef MCAL_DMA_DMA_INT_H_
#define MCAL_DMA_DMA_INT_H_

enum
{
	DMA_stream0,
	DMA_stream1
};
void MDMA_vInit(u8 A_u8StreamId);

void MDMA_vSetAddress(u8 A_u8StreamId,u32 *A_u32SourceAddress,u32 *A_u32DestAddress,u32 A_u32Length);

/*Start*/
void MDMA_vStramEnable(u8 A_u8StreamId);
void MDMA_vStramDisable(u8 A_u8StreamId);
void MDMA_vSetCallBack(u8 A_u8StreamId, void (*Fptr)(void));



#endif /* MCAL_DMA_DMA_INT_H_ */

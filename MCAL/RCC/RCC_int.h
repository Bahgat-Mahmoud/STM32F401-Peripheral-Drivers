/*
 * RCC_int.h
 *
 *  Created on: Aug 8, 2023
 *      Author: admin
 */

#ifndef MCAL_RCC_RCC_INT_H_
#define MCAL_RCC_RCC_INT_H_

#define RCC_AHB1   1
#define RCC_AHB2   2
#define RCC_APB1   3
#define RCC_APB2   4
/*RCC_AHB1 */
#define RCC_GPIOA_EN   0
#define RCC_GPIOB_EN   1

#define RCC_SYSCFG_EN    14
/*RCC_AHB2*/

/* RCC_APB1 */


void MRCC_vInit(void) ;

void MRCC_vEnableClock (u32 A_u32BusId,u32 A_u32PeripheralId);

void MRCC_vDisableClock (u32 A_u32BusId,u32 A_u32PeripheralId);

#endif /* MCAL_RCC_RCC_INT_H_ */

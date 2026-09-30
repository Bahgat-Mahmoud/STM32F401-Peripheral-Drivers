/*
 * RCC_prv.h
 *
 *  Created on: Aug 8, 2023
 *      Author: admin
 */

#ifndef MCAL_RCC_RCC_PRV_H_
#define MCAL_RCC_RCC_PRV_H_

#define  RCC_BASE_ADDR     0x40023800

typedef struct
{
	u32 CR ;      //0x00
	u32 PLLCFGR ; //0x04
	u32 CFGR ;
	u32 CIR ;
	u32 AHB1RSTR ;
	u32 AHB2RSTR ;
	u32 Reserved_1 ;
	u32 Reserved_2 ; // 0x1C
	u32 APB1RSTR ;
	u32 APB2RSTR ;
	u32 Reserved_3 ;
	u32 Reserved_4 ;
	u32 AHB1ENR  ;
	u32 AHB2ENR  ;
	u32 Reserved_5 ;
	u32 Reserved_6 ;
	u32 APB1ENR  ; //
	u32 APB2ENR ;

}RCC_MemMap_t;

#define RCC       ((volatile RCC_MemMap_t*)(RCC_BASE_ADDR))


/* Reg_BITS  RCC_CR*/
#define HSEBYP   17   //bit17
#define CSS_ON   19

#define HSE_ON   16

/*Reg   RCC_CFGR*/
#define SW0      0


#define ENABLE    1
#define DISABLE   0


#endif /* MCAL_RCC_RCC_PRV_H_ */

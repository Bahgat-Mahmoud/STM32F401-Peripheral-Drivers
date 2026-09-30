/*
 * SSD_int.h
 *
 *  Created on: Aug 11, 2023
 *      Author: admin
 */

#ifndef HAL_SSD_SSD_INT_H_
#define HAL_SSD_SSD_INT_H_

typedef struct
{
	u8 port;
	u8 pin ;
}SSD_cfg_t;

#define  SSD_COMMEN_CATHOD   1
#define  SSD_COMMEN_ANODE    2

void HSSD_vInit(SSD_cfg_t *A_xptr);

void HSSD_vDisplay(SSD_cfg_t *A_xptr,u8 A_u8Val,u8 A_u8Type);

void HSSD_vTurnOff(SSD_cfg_t *A_xptr,u8 A_u8Type);

#endif /* HAL_SSD_SSD_INT_H_ */

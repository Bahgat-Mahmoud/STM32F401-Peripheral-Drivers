/*
 * S2P_int.h
 *
 *  Created on: Sep 12, 2023
 *      Author: admin
 */

#ifndef HAL_S2P_S2P_INT_H_
#define HAL_S2P_S2P_INT_H_




void HS2P_vInit(void);

void HS2P_vSendData(u8 * A_pu8Data, u8 A_u8Size);

void HS2P_vSendData_(u32 A_pu8Data);

#endif /* HAL_S2P_S2P_INT_H_ */

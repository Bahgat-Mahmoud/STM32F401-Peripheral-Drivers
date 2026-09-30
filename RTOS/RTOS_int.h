/*
 * RTOS_int.h
 *
 *  Created on: Aug 17, 2023
 *      Author: admin
 */

#ifndef RTOS_RTOS_INT_H_
#define RTOS_RTOS_INT_H_

u8 RTOS_u8CreateTask(void (*A_Handler)(void),u8 A_u8Periodicity,u8 A_u8Priority,u8 A_u8FiretD);


void RTOS_vStartOS(void);
u8 RTOS_u8DeleteTask(u8 A_u8Priority);
u8 RTOS_u8SuspendTask(u8 A_u8Priority);
u8 RTOS_u8ResumeTask(u8 A_u8Priority);

#endif /* RTOS_RTOS_INT_H_ */

/*
 * RTOS_prv.h
 *
 *  Created on: Aug 17, 2023
 *      Author: admin
 */

#ifndef RTOS_RTOS_PRV_H_
#define RTOS_RTOS_PRV_H_


typedef enum
{
	Suspend,
	Running
}RunState;
typedef struct{
	void (*TaskHandler) (void);
	u8    Periodicity;
	RunState    TaskRunState ;
}Task;



#endif /* RTOS_RTOS_PRV_H_ */

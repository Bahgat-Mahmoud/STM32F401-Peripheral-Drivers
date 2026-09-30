/*
 * RTOS_prg.c
 *
 *  Created on: Aug 17, 2023
 *      Author: admin
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"


#include "../MCAL/SYSTICK/STK_int.h"

#include "RTOS_int.h"
#include "RTOS_cfg.h"
#include "RTOS_prv.h"

Task  SystemTasks[MAX_NO_TASKS] = {0} ;
u8 G_u8TaskTiming[MAX_NO_TASKS] ;
 void RTOS_vSchaduler(void);
void RTOS_vStartOS(void)
{
	MSTK_vSetInterval_Periodic(TICK_TIME,RTOS_vSchaduler);
}

u8 RTOS_u8CreateTask(void (*A_Handler)(void),u8 A_u8Periodicity,u8 A_u8Priority,u8 A_u8FiretD) //LED1 , 3 , 0 // LED2 , 4 , 1
{
	u8 L_u8ErrorState = 0 ;
	if(A_u8Priority<MAX_NO_TASKS)
	{
		if(SystemTasks[A_u8Priority].TaskHandler == 0)
		{
			SystemTasks[A_u8Priority].TaskHandler = A_Handler;//LED1
			SystemTasks[A_u8Priority].Periodicity = A_u8Periodicity;//3
			G_u8TaskTiming[A_u8Priority]          = A_u8FiretD ;//3
			SystemTasks[A_u8Priority].TaskRunState = Running ;
		}
		else
		{
			L_u8ErrorState = 2 ;
		}
	}
	else
	{
		L_u8ErrorState = 1;
	}

	return  L_u8ErrorState ;
}

 void RTOS_vSchaduler(void) //Task1  3Tick  0
{
	for(u8 L_u8Count=0 ; L_u8Count<MAX_NO_TASKS;L_u8Count++ )
	{
		if(SystemTasks[L_u8Count].TaskHandler != 0 && SystemTasks[L_u8Count].TaskRunState==Running)
		{
			if(G_u8TaskTiming[L_u8Count] == 0)
			{
				SystemTasks[L_u8Count].TaskHandler();
				G_u8TaskTiming[L_u8Count] = SystemTasks[L_u8Count].Periodicity ;
			}
			else
			{
				G_u8TaskTiming[L_u8Count]--; // 2  1 0
			}
		}
	}
}

u8 RTOS_u8DeleteTask(u8 A_u8Priority)
{
	u8 L_u8ErrorState = 0 ;

	if(SystemTasks[A_u8Priority].TaskHandler!=0)
	{
		SystemTasks[A_u8Priority].TaskHandler = 0;
		SystemTasks[A_u8Priority].Periodicity = 0;
	}
	else
	{
		L_u8ErrorState = 3;
	}
	return  L_u8ErrorState ;
}

u8 RTOS_u8SuspendTask(u8 A_u8Priority)
{
	u8 L_u8ErrorState = 0 ;

	if(SystemTasks[A_u8Priority].TaskHandler!=0)
	{
		SystemTasks[A_u8Priority].TaskRunState = Suspend ;
	}
	else
	{
		L_u8ErrorState = 3;
	}
	return  L_u8ErrorState ;
}

u8 RTOS_u8ResumeTask(u8 A_u8Priority)
{
	u8 L_u8ErrorState = 0 ;

	if(SystemTasks[A_u8Priority].TaskHandler!=0)
	{
		SystemTasks[A_u8Priority].TaskRunState = Running ;
	}
	else
	{
		L_u8ErrorState = 3;
	}
	return  L_u8ErrorState ;
}


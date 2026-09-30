/*
 * S2P_cfg.c
 *
 *  Created on: Sep 12, 2023
 *      Author: admin
 */

#include "../../LIB/STD_TYPES.h"


#include "../../MCAL/GPIO/GPIO_int.h"

MGPIO_Config_t DataSerial ={
		.mode = GPIO_MODE_OUTPUT,
		.port = GPIO_PORTA,
		.pin  = GPIO_PIN0,
		.speed = GPIO_OUTSPEED_LOW,
		.out_type = GPIO_PUSH_PULL,

};

MGPIO_Config_t Shift ={
		.mode = GPIO_MODE_OUTPUT,
		.port = GPIO_PORTA,
		.pin  = GPIO_PIN1,
		.speed = GPIO_OUTSPEED_LOW,
		.out_type = GPIO_PUSH_PULL,

};
MGPIO_Config_t Latch ={
		.mode = GPIO_MODE_OUTPUT,
		.port = GPIO_PORTA,
		.pin  = GPIO_PIN2,
		.speed = GPIO_OUTSPEED_LOW,
		.out_type = GPIO_PUSH_PULL,

};

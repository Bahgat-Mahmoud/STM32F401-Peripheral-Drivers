/*
 * TFT_cfg.c
 *
 *  Created on: Sep 20, 2023
 *      Author: admin
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/GPIO/GPIO_int.h"



MGPIO_Config_t   RESET_PIN  ={
		.mode = GPIO_MODE_OUTPUT,
		.port = GPIO_PORTA,
		.pin=GPIO_PIN0,
		.speed = GPIO_OUTSPEED_HIGH,
		.out_type = GPIO_PUSH_PULL
};
MGPIO_Config_t   A0_PIN  ={
		.mode = GPIO_MODE_OUTPUT,
		.port = GPIO_PORTA,
		.pin=GPIO_PIN1,
		.speed = GPIO_OUTSPEED_HIGH,
		.out_type = GPIO_PUSH_PULL
};



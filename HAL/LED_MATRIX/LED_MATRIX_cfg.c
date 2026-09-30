/*
 * LED_MATRIX_cfg.c
 *
 *  Created on: Sep 14, 2023
 *      Author: admin
 */

#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/GPIO/GPIO_int.h"
#include "LED_MATRIX_cfg.h"
#include "LED_MATRIX_int.h"

/*
 * please don`t use  pins (PA13,PA14,PA15)  or (PB2,PB3,PB4)
 */
MGPIO_Config_t col[NUM_OF_COL]={
		{.port=GPIO_PORTA  ,.pin=GPIO_PIN0  ,.mode=GPIO_MODE_OUTPUT  ,.out_type=GPIO_OUTSPEED_LOW},
		{.port=GPIO_PORTA  ,.pin=GPIO_PIN1  ,.mode=GPIO_MODE_OUTPUT  ,.out_type=GPIO_OUTSPEED_LOW},
		{.port=GPIO_PORTA  ,.pin=GPIO_PIN2  ,.mode=GPIO_MODE_OUTPUT  ,.out_type=GPIO_OUTSPEED_LOW},
		{.port=GPIO_PORTA  ,.pin=GPIO_PIN3  ,.mode=GPIO_MODE_OUTPUT  ,.out_type=GPIO_OUTSPEED_LOW},
		{.port=GPIO_PORTA  ,.pin=GPIO_PIN4  ,.mode=GPIO_MODE_OUTPUT  ,.out_type=GPIO_OUTSPEED_LOW},
		{.port=GPIO_PORTA  ,.pin=GPIO_PIN5  ,.mode=GPIO_MODE_OUTPUT  ,.out_type=GPIO_OUTSPEED_LOW},
		{.port=GPIO_PORTA  ,.pin=GPIO_PIN6  ,.mode=GPIO_MODE_OUTPUT  ,.out_type=GPIO_OUTSPEED_LOW},
		{.port=GPIO_PORTA  ,.pin=GPIO_PIN7  ,.mode=GPIO_MODE_OUTPUT  ,.out_type=GPIO_OUTSPEED_LOW}

};

MGPIO_Config_t row[NUM_OF_ROW]={
		{.port=GPIO_PORTB  ,.pin=GPIO_PIN0  ,.mode=GPIO_MODE_OUTPUT  ,.out_type=GPIO_OUTSPEED_LOW},
		{.port=GPIO_PORTB  ,.pin=GPIO_PIN1  ,.mode=GPIO_MODE_OUTPUT  ,.out_type=GPIO_OUTSPEED_LOW},
		{.port=GPIO_PORTB  ,.pin=GPIO_PIN5  ,.mode=GPIO_MODE_OUTPUT  ,.out_type=GPIO_OUTSPEED_LOW},
		{.port=GPIO_PORTB  ,.pin=GPIO_PIN6  ,.mode=GPIO_MODE_OUTPUT  ,.out_type=GPIO_OUTSPEED_LOW},
		{.port=GPIO_PORTB  ,.pin=GPIO_PIN7  ,.mode=GPIO_MODE_OUTPUT  ,.out_type=GPIO_OUTSPEED_LOW},
		{.port=GPIO_PORTB  ,.pin=GPIO_PIN8  ,.mode=GPIO_MODE_OUTPUT  ,.out_type=GPIO_OUTSPEED_LOW},
		{.port=GPIO_PORTB  ,.pin=GPIO_PIN9  ,.mode=GPIO_MODE_OUTPUT  ,.out_type=GPIO_OUTSPEED_LOW},
		{.port=GPIO_PORTB  ,.pin=GPIO_PIN10 ,.mode=GPIO_MODE_OUTPUT  ,.out_type=GPIO_OUTSPEED_LOW}

};



u32 picture[NUM_OF_ROW][NUM_OF_COL]={
		{1,0,0,0,0,0,0,1},
		{1,1,0,0,0,0,1,1},
		{1,1,1,0,0,1,1,1},
		{1,1,1,1,1,1,1,1},
		{1,1,0,1,1,0,1,1},
		{1,1,0,0,0,0,1,1},
		{1,1,0,0,0,0,1,1},
		{1,1,0,0,0,0,1,1}
};




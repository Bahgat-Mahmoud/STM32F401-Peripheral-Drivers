/*
 * SSD_cfg.c
 *
 *  Created on: Aug 11, 2023
 *      Author: admin
 */


#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO_int.h"
#include "SSD_cfg.h"
#include "SSD_int.h"
SSD_cfg_t   SSD_1[7]={
		{.port = SSD1_PORTA ,.pin = SSD1_PINA}, //a
		{.port = SSD1_PORTB, .pin = SSD1_PINB}, //b
		{.port = SSD1_PORTC, .pin = SSD1_PINC}, //c
		{.port = SSD1_PORTD, .pin = SSD1_PIND}, //d
		{.port = SSD1_PORTE, .pin = SSD1_PINE}, //e
		{.port = SSD1_PORTF, .pin = SSD1_PINF}, //f
		{.port = SSD1_PORTG, .pin = SSD1_PING}  //g
};

SSD_cfg_t   SSD_2[7]={
		{.port = GPIO_PORTA , .pin = GPIO_PIN7},
		{.port = GPIO_PORTA , .pin = GPIO_PIN8},
		{.port = GPIO_PORTA , .pin = GPIO_PIN9},
		{.port = GPIO_PORTA , .pin = GPIO_PIN10},
		{.port = GPIO_PORTA , .pin = GPIO_PIN11},
		{.port = GPIO_PORTB , .pin = GPIO_PIN0},
		{.port = GPIO_PORTB , .pin = GPIO_PIN1}
};
//

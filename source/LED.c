/*
 * @File		LED.c
 * @Brief		LED on-off functionality for pothole detection
 *
 * @Author		Vaishnavi Patekar;
 * @resources used: Deans's git repo; Prof. Lalit Pandit's Lecture slides
 * @Date		05th Dec., 2022
 *
 * @Institute	University of Colorado, Boulder
 * @Course		ECEN 8513: Principles of Embedded Software
 *
 * @Attribute
 */

#include <MKL25Z4.h>
#include <stdio.h>
//#include "UART.h"
//#include "gpio_defs.h"
#include "delay.h"
//#include "log.h"
#include "LED.h"

#define MASK(x) (1UL << (x))

#define RED_LED_SHIFT   (18)	// on port B
#define GREEN_LED_SHIFT (19)	// on port B
#define BLUE_LED_SHIFT  (1)		// on port D


//COnfiguration of GPIOs
void LED_Init()
{
		// Enable clock to Port B and Port D
		SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK | SIM_SCGC5_PORTD_MASK;

		// Make LED pins GPIO
		PORTB->PCR[RED_LED_SHIFT] &= ~PORT_PCR_MUX_MASK;
		PORTB->PCR[RED_LED_SHIFT] |= PORT_PCR_MUX(1);

		PORTB->PCR[GREEN_LED_SHIFT] &= ~PORT_PCR_MUX_MASK;
		PORTB->PCR[GREEN_LED_SHIFT] |= PORT_PCR_MUX(1);

		PORTD->PCR[BLUE_LED_SHIFT] &= ~PORT_PCR_MUX_MASK;
		PORTD->PCR[BLUE_LED_SHIFT] |= PORT_PCR_MUX(1);

		// Set ports to outputs
		PTB->PDDR |= MASK(RED_LED_SHIFT) | MASK(GREEN_LED_SHIFT);
		PTD->PDDR |= MASK(BLUE_LED_SHIFT);

		PTB->PCOR |= MASK(RED_LED_SHIFT) | MASK(GREEN_LED_SHIFT);
		PTD->PCOR |= MASK(BLUE_LED_SHIFT);
}


void LED_OFF()
{
		PTB->PSOR = MASK(GREEN_LED_SHIFT);
		PTB->PSOR = MASK(RED_LED_SHIFT);
		PTD->PSOR = MASK(BLUE_LED_SHIFT);
//		LOG("Delay for 100ms \n\r");
}

void Red_ON()
{
	PTD->PSOR = MASK(BLUE_LED_SHIFT);
	PTB->PSOR = MASK(GREEN_LED_SHIFT);
	PTB->PCOR = MASK(RED_LED_SHIFT);
}

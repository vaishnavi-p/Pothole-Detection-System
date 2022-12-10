/*
 * @File		delay.c
 * @Brief		Delay function
 *
 * @Author		Vaishnavi Patekar;
 * @resources used: Deans's git repo: https://github.com/alexander-g-dean/ESF/blob/master/NXP/Code/Chapter_8/I2C-Demo/src/i2c.c
 * 					Prof. Lalit Pandit's Lecture slides
 * @Date		01st Dec., 2022
 *
 * @Institute	University of Colorado, Boulder
 * @Course		ECEN 8513: Principles of Embedded Software
 *
 * @Attribute: Dean's github, https://github.com/alexander-g-dean/ESF/blob/master/NXP/Code/Chapter_8/I2C-Demo/src/Delay.c
 */

#include <MKL25Z4.H>

void Delay (uint32_t dly) {
  volatile uint32_t t;

	for (t=dly*10000; t>0; t--)
		;
}

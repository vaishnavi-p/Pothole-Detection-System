/*
 * @File		cbfifo.c
 * @Brief		Circular Buffer Implementation & popthole detection algorithm
 *
 * @Author		Vaishnavi Patekar;
 * @resources used: Deans's git repo; Prof. Lalit Pandit's Lecture slides
 * @Date		06th Dec., 2022
 *
 * @Institute	University of Colorado, Boulder
 * @Course		ECEN 8513: Principles of Embedded Software
 *
 * @Attribute
 */


#include "cbfifo.h"
#include "LED.h"
#include "fsl_debug_console.h"
#include "delay.h"

//x-axix threshold value to detect the pothole
int Threshold = 5;

int16_t Array[CAPACITY];
int RIndex = 0;
int WIndex = 0;


/*
* @Function pothole_detector
* @Param:  none
* @Returns avg
* @Description: Function to calculate the average of deviation of filtered output
*/

int pothole_detector()
{
	int low_filter_out[CAPACITY];
	float fc = 0.5;
	float temp_float;
	int sum = 0;
	int diff;
	int avg;

	low_filter_out[0] = Array[0];

	for(int i=1; i < CAPACITY; i++)
	{
	//	low_filter_out[i] = (q->Array[i] - low_filter_out[i-1]) * fc;
		temp_float = (float)(Array[i] - low_filter_out[i-1]) * fc + (float)low_filter_out[i-1];

		low_filter_out[i] = (int)temp_float;
	}

	for(int i = 0; i < CAPACITY; i++)
	{
		diff = abs(low_filter_out[i] - Array[i]);

		sum = sum + diff;
	}

	avg = sum / CAPACITY;

	PRINTF("Sum = %d ", sum);
	PRINTF("Avg = %d \n\r", avg);

//	if(avg > 2)
//	{
//		printf("Pothole detected \n\r");
//	}
	return avg;
}


/*
* @Function PotholeModeValue
* @Param:  none
* @Returns count
* @Description: Filter Logic Output==> Filter_Pothole
*/

int PotholeModeValue()
{
//	int Pothole_mod=0;
	int count=0;

	for(int i=0; i<CAPACITY; i++)
	{
		if(abs(Array[i]) > Threshold)
			count = count+1;
	}

	//if(count>10)
	//	Pothole_mod=1;
	return count;
}


/*
* @Function Final_pothole
* @Param:  none
* @Returns none
* @Description: outputs the final pothole detection decision
*/
void Final_pothole()
{
	int P1, P2;

	P1 = PotholeModeValue();
	P2 = pothole_detector();		//Call the filter function here and return the avarage

	if(P1>10 && P2>2)
	{
		PRINTF("Pothole Detected \n\n\r");
		Red_ON();
		Delay(800);
	}
	else if((P1>20 && P2>2)||(P1>10 && P2>4))
	{
		PRINTF("High Confident That it's a pothole \n\r");
		Red_ON();
		Delay(800);
	}
	else
	{
		PRINTF("No Pothole Detected \n\n\r");
		LED_OFF();
		//Delay(100);
	}

}


/*
* @Function cbfifo_enqueue
* @Param:  buf
* nbytes - Number of bytes to be enqueued/written in fifo
* @Returns The number of bytes enqueued
* @Description Enqueues data to the buffer
*/

void cbfifo_enqueue(int16_t buf, int sysinit)
{
	if(sysinit)
	{
		Array[WIndex] = buf;

		WIndex = WIndex+1;

	//	q->WIndex = q->WIndex+1;

		if(WIndex >= CAPACITY)
		{
			//pothole_detector();
			Final_pothole();
			WIndex = 0;
		}

		return;
	}
}


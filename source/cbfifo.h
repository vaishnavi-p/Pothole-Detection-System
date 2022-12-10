/*
 * @File		cbfifo.h
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

#ifndef __CBFIFO_H__
#define __CBFIFO_H__

#include <MKL25Z4.h>

#include <stdio.h>
#include <stdint.h>

#include <stdlib.h>
#include <string.h>


//#define CAPACITY 256
#define CAPACITY 30

//typedef struct CBfifo
//{
//	 unsigned int RIndex; // Index of oldest data element
//	  unsigned int WIndex; // Index of next free space
//	  unsigned int length; // Number of elements in use
//	  uint8_t Array[CAPACITY];
//}CBfifo;



//void cbfifo_Init(CBfifo *queue);

//size_t cbfifo_capacity();

//int cbfifo_empty(CBfifo *queue);
//
//int cbfifo_full(CBfifo *queue);

//size_t cbfifo_enqueue(CBfifo *queue, const void *buf, size_t nbyte);

//CBfifo *cbfifo_create();

void cbfifo_enqueue(int16_t buf, int sysinit);

//size_t cbfifo_dequeue(CBfifo *queue, void *buf, size_t nbyte);

//size_t cbfifo_length();

//int cbfifo_size(CBfifo *queue);

#endif /* __CBFIFO_H__ */

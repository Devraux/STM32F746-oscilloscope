#ifndef _Data_Buffer_
#define _Data_Buffer_

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct
{
    uint32_t *dataBuffer; //ring buffer data
    uint32_t Counter;   // counter counts data in buffer
    uint32_t Head;
    uint32_t Tail;
    uint32_t Buffer_Size;
}dataBuffer;

bool data_bufferInit(dataBuffer *ringbuffer, uint32_t *RingBuffer_data, uint32_t buffer_size); 	// return true if initialization was successful
bool data_bufferClear(dataBuffer *ringbuffer); 													// return true if RingBuffer was cleared
bool data_bufferIsEmpty(dataBuffer *ringbuffer); 												// return true if ring buffer is empty
bool data_bufferGetData(dataBuffer *ringbuffer, uint32_t *c); 									// return true if char was read successfully
bool data_bufferPushData(dataBuffer *ringbuffer, uint32_t c); 									// return true if char added successfully
uint32_t data_bufferGetCapacity(dataBuffer *ringbuffer); 										// return data counter


#endif

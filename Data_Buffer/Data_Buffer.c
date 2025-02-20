#include "Data_Buffer.h"

bool data_bufferInit(dataBuffer *dataBuffer, uint32_t *dataBuffer_data, uint32_t buffer_size)
{
    if((dataBuffer) && (dataBuffer_data) && (buffer_size > 0))
    {
        dataBuffer->Buffer_Size = buffer_size;
        dataBuffer->Counter = 0;
        dataBuffer->Head    = 0;
        dataBuffer->Tail    = 0;
        dataBuffer->dataBuffer = dataBuffer_data;
        return true;
    }
    return false;
}

bool data_bufferClear(dataBuffer *dataBuffer)
{
    if(dataBuffer)
    {
        dataBuffer->Counter = 0;
        dataBuffer->Head    = 0;
        dataBuffer->Tail    = 0;
        return true;
    }
    return false;
}

bool data_bufferIsEmpty(dataBuffer *dataBuffer)
{
    if(dataBuffer->Counter == 0)
    {
        return true;
    }
    return false;
}

uint32_t data_bufferGetCapacity(dataBuffer *dataBuffer)
{
    return dataBuffer->Counter;
}

bool data_bufferGetData(dataBuffer *dataBuffer, uint32_t *c)
{
    if(dataBuffer)
    {
        if(dataBuffer->Counter != 0)
        {
            *c = dataBuffer->dataBuffer[dataBuffer->Tail];
            dataBuffer->Tail = (dataBuffer->Tail + 1) % dataBuffer->Buffer_Size;
            dataBuffer->Counter--;

            if(dataBuffer->Counter < 0)
            	dataBuffer->Counter = 0;

            return true;
        }
    }
    return false;

}

bool data_bufferPushData(dataBuffer *dataBuffer, uint32_t c)
{
    if(dataBuffer != NULL)
    {
        dataBuffer->dataBuffer[dataBuffer->Head] = c;
        dataBuffer->Head = (dataBuffer->Head + 1) % dataBuffer->Buffer_Size;
        dataBuffer->Counter++;
        if(dataBuffer->Counter >= dataBuffer->Buffer_Size)
            dataBuffer->Counter = dataBuffer->Buffer_Size; // counter can't be bigger than buffer size
        return true;
    }
    return false;

}

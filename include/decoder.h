#ifndef DECODER_H
#define DECODER_H

#include <stdint.h>

typedef struct
{
    uint8_t output0;
    uint8_t output1;
    uint8_t output2;
    uint8_t output3;
} Decoder2to4;

typedef struct
{
    uint8_t output[16];
} Decoder4to16;


Decoder2to4 decoder2to4(uint8_t a, uint8_t b);
Decoder4to16 decoder4to16(uint8_t a, uint8_t b, uint8_t c, uint8_t d);

#endif
#ifndef ADDER_H
#define ADDER_H

#include <stdint.h>

typedef struct
{
    uint8_t sum;
    uint8_t carry;
} HalfAdder;

typedef struct
{
    uint8_t sum;
    uint8_t carry;
} FullAdder;

HalfAdder half_adder(uint8_t a, uint8_t b);

FullAdder full_adder(uint8_t a, uint8_t b, uint8_t carry_in);

#endif
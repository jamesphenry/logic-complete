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

typedef struct
{
    uint8_t sum;
    uint8_t carry;
} Adder8;

typedef struct
{
    uint8_t difference;
    uint8_t borrow;
} Subtractor8;

Subtractor8 subtractor8(uint8_t a, uint8_t b);
HalfAdder half_adder(uint8_t a, uint8_t b);
FullAdder full_adder(uint8_t a, uint8_t b, uint8_t carry_in);
Adder8 adder8(uint8_t a, uint8_t b, uint8_t carry_in);

#endif
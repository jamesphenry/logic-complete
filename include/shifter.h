#ifndef SHIFTER_H
#define SHIFTER_H

#include <stdint.h>

typedef struct
{
    uint8_t value;
    uint8_t shifted_out;
} Shift8;

Shift8 shift_left8(uint8_t value);
Shift8 shift_right8(uint8_t value);

#endif
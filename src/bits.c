#include "bits.h"

uint8_t get_bit(uint8_t value, uint8_t bit)
{
    return (value >> bit) & 1;
}

void set_bit(uint8_t *value, uint8_t bit, uint8_t state)
{
    uint8_t mask = (uint8_t)(1 << bit);

    if (state == 1)
    {
        *value |= mask;
    }
    else
    {
        *value &= (uint8_t)~mask;
    }
}


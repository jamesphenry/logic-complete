#ifndef COMPARATOR_H
#define COMPARATOR_H

#include <stdint.h>

typedef struct
{
    uint8_t equal;
    uint8_t less;
    uint8_t greater;
} Comparator8;

Comparator8 comparator8(uint8_t a, uint8_t b);

#endif
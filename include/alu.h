#ifndef ALU_H
#define ALU_H

#include <stdint.h>

#define ALU_ADD  0
#define ALU_SUB  1
#define ALU_AND  2
#define ALU_OR   3
#define ALU_XOR  4
#define ALU_SHL  5
#define ALU_SHR  6

typedef struct
{
    uint8_t result;

    uint8_t zero;
    uint8_t carry;
    uint8_t negative;
    uint8_t overflow;
    uint8_t borrow;
} ALU8;

ALU8 alu8(uint8_t a, uint8_t b, uint8_t operation);

#endif
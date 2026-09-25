#include "alu.h"
#include "adder.h"

ALU8 alu8(uint8_t a, uint8_t b, uint8_t operation)
{
    ALU8 result;

    result.result = 0;

    if (operation == ALU_ADD)
    {
        Adder8 add = adder8(a, b, 0);
        result.result = add.sum;
    }

    return result;
}
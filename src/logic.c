#include "logic.h"

uint8_t logic_not(uint8_t a)
{
    return a == 0 ? 1 : 0;
}

uint8_t logic_and(uint8_t a, uint8_t b)
{
    return (a == 1 && b == 1) ? 1 : 0;
}

uint8_t logic_or(uint8_t a, uint8_t b)
{
    return (a == 1 || b == 1) ? 1 : 0;
}

uint8_t logic_xor(uint8_t a, uint8_t b)
{
    if (a == b)
    {
        return 0;
    }

    return 1;
}

uint8_t logic_nand(uint8_t a, uint8_t b)
{
    return logic_not(logic_and(a, b));
}

uint8_t logic_nor(uint8_t a, uint8_t b)
{
    return logic_not(logic_or(a, b));
}
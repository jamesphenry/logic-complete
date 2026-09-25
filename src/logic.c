#include "logic.h"
#include "bits.h"

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

uint8_t logic_equal(uint8_t a, uint8_t b)
{
    return logic_not(logic_xor(a, b));
}

uint8_t logic_greater(uint8_t a, uint8_t b)
{
    return logic_and(a, logic_not(b));
}

uint8_t logic_less(uint8_t a, uint8_t b)
{
    return logic_and(logic_not(a), b);
}

uint8_t logic_not8(uint8_t value)
{
    uint8_t result = 0;

    for (uint8_t bit = 0; bit < 8; bit++)
    {
        uint8_t state = get_bit(value, bit);
        uint8_t inverted = logic_not(state);

        set_bit(&result, bit, inverted);
    }

    return result;
}


#include "zero.h"
#include "bits.h"
#include "logic.h"

uint8_t zero_flag8(uint8_t value)
{
    uint8_t result = 1;

    for (uint8_t bit = 0; bit < 8; bit++)
    {
        uint8_t state = get_bit(value, bit);

        result = logic_and(result, logic_not(state));
    }

    return result;
}
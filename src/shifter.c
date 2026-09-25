#include "shifter.h"
#include "bits.h"

Shift8 shift_left8(uint8_t value)
{
    Shift8 result;

    result.value = 0;
    result.shifted_out = get_bit(value, 7);

    for (uint8_t bit = 7; bit > 0; bit--)
    {
        uint8_t state = get_bit(value, bit - 1);
        set_bit(&result.value, bit, state);
    }

    return result;
}

Shift8 shift_right8(uint8_t value)
{
    Shift8 result;

    result.value = 0;
    result.shifted_out = get_bit(value, 0);

    for (uint8_t bit = 0; bit < 7; bit++)
    {
        uint8_t state = get_bit(value, bit + 1);
        set_bit(&result.value, bit, state);
    }

    return result;
}
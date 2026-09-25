#include "adder.h"
#include "logic.h"

HalfAdder half_adder(uint8_t a, uint8_t b)
{
    HalfAdder result;

    result.sum = logic_xor(a, b);
    result.carry = logic_and(a, b);

    return result;
}

FullAdder full_adder(uint8_t a, uint8_t b, uint8_t carry_in)
{
    HalfAdder first;
    HalfAdder second;
    FullAdder result;

    first = half_adder(a, b);
    second = half_adder(first.sum, carry_in);

    result.sum = second.sum;
    result.carry = logic_or(first.carry, second.carry);

    return result;
}

Adder8 adder8(uint8_t a, uint8_t b, uint8_t carry_in)
{
    Adder8 result;
    uint8_t carry = carry_in;

    result.sum = 0;

    for (uint8_t bit = 0; bit < 8; bit++)
    {
        uint8_t a_bit = (a >> bit) & 1;
        uint8_t b_bit = (b >> bit) & 1;

        FullAdder current = full_adder(a_bit, b_bit, carry);

        if (current.sum == 1)
        {
            result.sum |= (uint8_t)(1 << bit);
        }

        carry = current.carry;
    }

    result.carry = carry;

    return result;
}
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
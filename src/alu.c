#include "alu.h"
#include "adder.h"
#include "logic.h"
#include "shifter.h"
#include "zero.h"
#include "negative.h"

ALU8 alu8(uint8_t a, uint8_t b, uint8_t operation)
{
    ALU8 result;

    result.result = 0;
    result.negative = 0;
    if (operation == ALU_ADD)
    {
        Adder8 add = adder8(a, b, 0);
        result.result = add.sum;
        result.carry = add.carry;
    }
    else if (operation == ALU_SUB)
    {
        Subtractor8 sub = subtractor8(a, b);
        result.result = sub.difference;
        result.borrow = sub.borrow;
    }
        else if (operation == ALU_AND)
        {
            result.result = logic_and8(a, b);
            result.carry = 0;
        }
        else if (operation == ALU_OR)
        {
            result.result = logic_or8(a, b);
            result.carry = 0;
        }
        else if (operation == ALU_XOR)
        {
            result.result = logic_xor8(a, b);
            result.carry = 0;
        }
        else if (operation == ALU_SHL)
        {
            Shift8 shift = shift_left8(a);
            result.result = shift.value;
            result.carry = 0;
        }
        else if (operation == ALU_SHR)
        {
            Shift8 shift = shift_right8(a);
            result.result = shift.value;
            result.carry = 0;
        }
        result.zero = zero_flag8(result.result);
        result.negative = negative_flag8(result.result);

        result.zero = zero_flag8(result.result);
        return result;
    }

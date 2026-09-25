#include "alu.h"
#include "adder.h"
#include "logic.h"
#include "shifter.h"

ALU8 alu8(uint8_t a, uint8_t b, uint8_t operation)
{
    ALU8 result;

    result.result = 0;

    if (operation == ALU_ADD)
    {
        Adder8 add = adder8(a, b, 0);
        result.result = add.sum;
    }
    else if (operation == ALU_SUB)
    {
        Subtractor8 sub = subtractor8(a, b);
        result.result = sub.difference;
    }
    else if (operation == ALU_AND)
    {
        result.result = logic_and8(a, b);
    }
    else if (operation == ALU_OR)
    {
        result.result = logic_or8(a, b);
    }
    else if (operation == ALU_XOR)
    {
        result.result = logic_xor8(a, b);
    }
    else if (operation == ALU_SHL)
    {
        Shift8 shift = shift_left8(a);
        result.result = shift.value;
    }
    else if (operation == ALU_SHR)
    {
        Shift8 shift = shift_right8(a);
        result.result = shift.value;
    }
    
    return result;
}

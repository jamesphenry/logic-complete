#include "decoder.h"
#include "logic.h"

Decoder2to4 decoder2to4(uint8_t a, uint8_t b)
{
    Decoder2to4 result;

    uint8_t not_a = logic_not(a);
    uint8_t not_b = logic_not(b);

    result.output0 = logic_and(not_a, not_b);
    result.output1 = logic_and(not_a, b);
    result.output2 = logic_and(a, not_b);
    result.output3 = logic_and(a, b);

    return result;
}
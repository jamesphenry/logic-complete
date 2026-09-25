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

Decoder4to16 decoder4to16(uint8_t a, uint8_t b, uint8_t c, uint8_t d)
{
    Decoder4to16 decoder;

    Decoder2to4 high = decoder2to4(a, b);
    Decoder2to4 low  = decoder2to4(c, d);

    decoder.output[0]  = logic_and(high.output0, low.output0);
    decoder.output[1]  = logic_and(high.output0, low.output1);
    decoder.output[2]  = logic_and(high.output0, low.output2);
    decoder.output[3]  = logic_and(high.output0, low.output3);

    decoder.output[4]  = logic_and(high.output1, low.output0);
    decoder.output[5]  = logic_and(high.output1, low.output1);
    decoder.output[6]  = logic_and(high.output1, low.output2);
    decoder.output[7]  = logic_and(high.output1, low.output3);

    decoder.output[8]  = logic_and(high.output2, low.output0);
    decoder.output[9]  = logic_and(high.output2, low.output1);
    decoder.output[10] = logic_and(high.output2, low.output2);
    decoder.output[11] = logic_and(high.output2, low.output3);

    decoder.output[12] = logic_and(high.output3, low.output0);
    decoder.output[13] = logic_and(high.output3, low.output1);
    decoder.output[14] = logic_and(high.output3, low.output2);
    decoder.output[15] = logic_and(high.output3, low.output3);

    return decoder;
}
#include "comparator.h"
#include "bits.h"
#include "logic.h"

Comparator8 comparator8(uint8_t a, uint8_t b)
{
    Comparator8 result;

    uint8_t equal_so_far = 1;

    result.equal = 0;
    result.less = 0;
    result.greater = 0;

    for (int8_t bit = 7; bit >= 0; bit--)
    {
        uint8_t a_bit = get_bit(a, bit);
        uint8_t b_bit = get_bit(b, bit);

        uint8_t this_equal = logic_equal(a_bit, b_bit);
        uint8_t this_less = logic_less(a_bit, b_bit);
        uint8_t this_greater = logic_greater(a_bit, b_bit);

        result.less =
            logic_or(result.less,
                     logic_and(equal_so_far, this_less));

        result.greater =
            logic_or(result.greater,
                     logic_and(equal_so_far, this_greater));

        equal_so_far =
            logic_and(equal_so_far, this_equal);
    }

    result.equal = equal_so_far;

    return result;
}
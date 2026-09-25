#include "overflow.h"
#include "bits.h"
#include "logic.h"

uint8_t overflow_add8(uint8_t a, uint8_t b, uint8_t result)
{
    uint8_t a_sign = get_bit(a, 7);
    uint8_t b_sign = get_bit(b, 7);
    uint8_t result_sign = get_bit(result, 7);

    uint8_t same_sign = logic_equal(a_sign, b_sign);
    uint8_t result_changed = logic_xor(a_sign, result_sign);

    return logic_and(same_sign, result_changed);
}
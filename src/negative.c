#include "negative.h"
#include "bits.h"

uint8_t negative_flag8(uint8_t value)
{
    return get_bit(value, 7);
}
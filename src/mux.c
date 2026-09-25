#include "mux.h"
#include "bits.h"

uint8_t mux2(uint8_t a, uint8_t b, uint8_t select)
{
    return select ? b : a;
}

uint8_t mux4(
    uint8_t a,
    uint8_t b,
    uint8_t c,
    uint8_t d,
    uint8_t select
)
{
    uint8_t low = mux2(a, b, get_bit(select, 0));
    uint8_t high = mux2(c, d, get_bit(select, 0));

    return mux2(
        low,
        high,
        get_bit(select, 1)
    );
}
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

uint8_t mux16(
    const uint8_t inputs[16],
    uint8_t select)
{
    uint8_t low = select & 0b0011;
    uint8_t high = (select >> 2) & 0b0011;

    uint8_t group0 = mux4(
        inputs[0],
        inputs[1],
        inputs[2],
        inputs[3],
        low);

    uint8_t group1 = mux4(
        inputs[4],
        inputs[5],
        inputs[6],
        inputs[7],
        low);

    uint8_t group2 = mux4(
        inputs[8],
        inputs[9],
        inputs[10],
        inputs[11],
        low);

    uint8_t group3 = mux4(
        inputs[12],
        inputs[13],
        inputs[14],
        inputs[15],
        low);

    return mux4(
        group0,
        group1,
        group2,
        group3,
        high);
}

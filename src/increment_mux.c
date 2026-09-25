#include "increment_mux.h"

#include "adder.h"
#include "mux.h"

uint8_t increment_mux(
    uint8_t current,
    uint8_t alternate,
    uint8_t select
)
{
    Adder8 increment = adder8(current, 1, 0);

    return mux2(
        increment.sum,
        alternate,
        select
    );
}
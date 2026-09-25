#include "bus.h"
#include "mux.h"

uint8_t bus_select(
    uint8_t source0,
    uint8_t source1,
    uint8_t source2,
    uint8_t source3,
    uint8_t select
)
{
    return mux4(
        source0,
        source1,
        source2,
        source3,
        select
    );
}
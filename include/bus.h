#ifndef BUS_H
#define BUS_H

#include <stdint.h>

uint8_t bus_select(
    uint8_t source0,
    uint8_t source1,
    uint8_t source2,
    uint8_t source3,
    uint8_t select
);

#endif

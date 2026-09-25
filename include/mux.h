#ifndef MUX_H
#define MUX_H

#include <stdint.h>

uint8_t mux2(uint8_t a, uint8_t b, uint8_t select);
uint8_t mux4(
    uint8_t a,
    uint8_t b,
    uint8_t c,
    uint8_t d,
    uint8_t select
);

#endif
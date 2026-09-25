#include "mux.h"

uint8_t mux2(uint8_t a, uint8_t b, uint8_t select)
{
    return select ? b : a;
}
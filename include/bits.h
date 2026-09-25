#ifndef BITS_H
#define BITS_H

#include <stdint.h>

uint8_t get_bit(uint8_t value, uint8_t bit);
void set_bit(uint8_t *value, uint8_t bit, uint8_t state);

#endif
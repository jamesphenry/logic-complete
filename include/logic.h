#ifndef LOGIC_H
#define LOGIC_H

#include <stdint.h>

uint8_t logic_not(uint8_t a);
uint8_t logic_and(uint8_t a, uint8_t b);
uint8_t logic_or(uint8_t a, uint8_t b);
uint8_t logic_xor(uint8_t a, uint8_t b);
uint8_t logic_nand(uint8_t a, uint8_t b);
uint8_t logic_nor(uint8_t a, uint8_t b);

#endif
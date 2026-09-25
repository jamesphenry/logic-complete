#ifndef LOGIC_H
#define LOGIC_H

#include <stdint.h>

uint8_t logic_not(uint8_t a);
uint8_t logic_and(uint8_t a, uint8_t b);
uint8_t logic_or(uint8_t a, uint8_t b);
uint8_t logic_xor(uint8_t a, uint8_t b);
uint8_t logic_nand(uint8_t a, uint8_t b);
uint8_t logic_nor(uint8_t a, uint8_t b);
uint8_t logic_equal(uint8_t a, uint8_t b);
uint8_t logic_greater(uint8_t a, uint8_t b);
uint8_t logic_less(uint8_t a, uint8_t b);
uint8_t logic_not8(uint8_t value);
uint8_t logic_and8(uint8_t a, uint8_t b);
uint8_t logic_or8(uint8_t a, uint8_t b);
uint8_t logic_xor8(uint8_t a, uint8_t b);
uint8_t logic_nand8(uint8_t a, uint8_t b);
uint8_t logic_nor8(uint8_t a, uint8_t b);
#endif
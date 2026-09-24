#ifndef REGISTER_H
#define REGISTER_H

#include <stdint.h>

typedef struct
{
    uint8_t value;
} Register;

void register_init(Register *reg);
void register_write(Register *reg, uint8_t value);
uint8_t register_read(const Register *reg);

#endif
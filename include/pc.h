#ifndef PC_H
#define PC_H

#include <stdint.h>

#include "register.h"

typedef struct
{
    Register value;
} ProgramCounter;

void pc_init(ProgramCounter *pc);

uint8_t pc_read(const ProgramCounter *pc);

void pc_write(
    ProgramCounter *pc,
    uint8_t value,
    uint8_t enable
);

#endif
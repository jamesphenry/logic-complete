#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>

#include "ram.h"
#include "rom.h"

typedef struct
{
    ROM *rom;
    RAM *ram;
} Memory;

void memory_init(
    Memory *memory,
    ROM *rom,
    RAM *ram
);

uint8_t memory_read(
    const Memory *memory,
    uint8_t address
);

void memory_write(
    Memory *memory,
    uint8_t address,
    uint8_t value
);

#endif
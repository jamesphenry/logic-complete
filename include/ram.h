#ifndef RAM_H
#define RAM_H

#include <stddef.h>
#include <stdint.h>

typedef struct
{
    uint8_t *data;
    size_t size;
} RAM;

void ram_init(
    RAM *ram,
    size_t size
);

uint8_t ram_read(
    const RAM *ram,
    size_t address
);

void ram_write(
    RAM *ram,
    size_t address,
    uint8_t value
);

void ram_destroy(
    RAM *ram
);

#endif

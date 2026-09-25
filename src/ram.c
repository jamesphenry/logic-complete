#include "ram.h"

#include <stdlib.h>

void ram_init(
    RAM *ram,
    size_t size
)
{
    ram->data = calloc(size, sizeof(uint8_t));
    ram->size = size;
}

uint8_t ram_read(
    const RAM *ram,
    size_t address
)
{
    return ram->data[address];
}

void ram_write(
    RAM *ram,
    size_t address,
    uint8_t value
)
{
    ram->data[address] = value;
}

void ram_destroy(
    RAM *ram
)
{
    free(ram->data);

    ram->data = NULL;
    ram->size = 0;
}

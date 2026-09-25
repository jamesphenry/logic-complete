#ifndef ADDRESS_MAP_H
#define ADDRESS_MAP_H

#include <stdint.h>
#include <stddef.h>

typedef uint8_t (*AddressMapRead)(
    void *context,
    size_t address);

typedef void (*AddressMapWrite)(
    void *context,
    size_t address,
    uint8_t value);

typedef struct
{
    size_t start;
    size_t size;

    void *context;

    AddressMapRead read;
    AddressMapWrite write;
} AddressMapEntry;

uint8_t address_map_read(
    const AddressMapEntry *entry,
    size_t address);

void address_map_write(
    const AddressMapEntry *entry,
    size_t address,
    uint8_t value);

#endif
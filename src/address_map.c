#include "address_map.h"

uint8_t address_map_read(
    const AddressMapEntry *entry,
    size_t address)
{
    if (address < entry->start)
    {
        return 0;
    }

    if (address >= entry->start + entry->size)
    {
        return 0;
    }

    if (entry->read == NULL)
    {
        return 0;
    }

    size_t local_address = address - entry->start;

    return entry->read(
        entry->context,
        local_address);
}

void address_map_write(
    const AddressMapEntry *entry,
    size_t address,
    uint8_t value)
{
    if (address < entry->start)
    {
        return;
    }

    if (address >= entry->start + entry->size)
    {
        return;
    }

    if (entry->write == NULL)
    {
        return;
    }

    size_t local_address = address - entry->start;

    entry->write(
        entry->context,
        local_address,
        value);
}
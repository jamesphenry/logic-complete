#include <stdlib.h>
#include <stddef.h>
#include "register_file.h"
#include "decoder.h"
#include "mux.h"
#include "bits.h"
#include "logic.h"

int register_file_init(RegisterFile *file, size_t count)
{
    if (count > REGISTER_FILE_MAX)
    {
        return REGISTER_FILE_MAX_EXCEEDED;
    }

    file->registers = malloc(count * sizeof(Register));
    if (file->registers == NULL)
    {
        return REGISTER_FILE_ALLOCATION_FAILED;
    }

    file->count = count;

    for (size_t i = 0; i < count; i++)
    {
        register_init(&file->registers[i]);
    }

    return REGISTER_INIT_SUCCESS;
}

uint8_t register_file_read(
    const RegisterFile *file,
    uint8_t address)
{
    uint8_t values[REGISTER_FILE_MAX];

    for (size_t i = 0; i < REGISTER_FILE_MAX; i++)
    {
        if (i < file->count)
        {
            values[i] = register_read(&file->registers[i]);
        }
        else
        {
            values[i] = 0;
        }
    }

    return mux16(values, address);
}

void register_file_write(
    RegisterFile *file,
    uint8_t address,
    uint8_t value,
    uint8_t enable)
{
    Decoder4to16 decoder = decoder4to16(
        get_bit(address, 3),
        get_bit(address, 2),
        get_bit(address, 1),
        get_bit(address, 0));

    for (size_t i = 0; i < file->count; i++)
    {
        uint8_t write_enable = logic_and(
            decoder.output[i],
            enable);

        register_write(
            &file->registers[i],
            value,
            write_enable);
    }
}

void register_file_destroy(RegisterFile *file)
{
    free(file->registers);
    file->registers = NULL;
    file->count = 0;
}
#include "register_file.h"
#include "decoder.h"
#include "mux.h"
#include "bits.h"
#include "logic.h"

void register_file_init(RegisterFile *file)
{
    for (uint8_t i = 0; i < REGISTER_FILE_COUNT; i++)
    {
        register_init(&file->registers[i]);
    }
}

uint8_t register_file_read(
    const RegisterFile *file,
    uint8_t address
)
{
    return mux4(
        register_read(&file->registers[0]),
        register_read(&file->registers[1]),
        register_read(&file->registers[2]),
        register_read(&file->registers[3]),
        address
    );
}

void register_file_write(
    RegisterFile *file,
    uint8_t address,
    uint8_t value,
    uint8_t enable
)
{
    Decoder2to4 decoder = decoder2to4(
        get_bit(address, 1),
        get_bit(address, 0)
    );

    uint8_t write0 = logic_and(decoder.output0, enable);
    uint8_t write1 = logic_and(decoder.output1, enable);
    uint8_t write2 = logic_and(decoder.output2, enable);
    uint8_t write3 = logic_and(decoder.output3, enable);

    if (write0)
    {
        register_write(&file->registers[0], value);
    }

    if (write1)
    {
        register_write(&file->registers[1], value);
    }

    if (write2)
    {
        register_write(&file->registers[2], value);
    }

    if (write3)
    {
        register_write(&file->registers[3], value);
    }
}
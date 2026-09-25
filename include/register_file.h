#ifndef REGISTER_FILE_H
#define REGISTER_FILE_H

#include <stdint.h>
#include "register.h"

#define REGISTER_FILE_COUNT 4

typedef struct
{
    Register registers[REGISTER_FILE_COUNT];
} RegisterFile;

void register_file_init(RegisterFile *file);

uint8_t register_file_read(
    const RegisterFile *file,
    uint8_t address
);

void register_file_write(
    RegisterFile *file,
    uint8_t address,
    uint8_t value,
    uint8_t enable
);

#endif
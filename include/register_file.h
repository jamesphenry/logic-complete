#ifndef REGISTER_FILE_H
#define REGISTER_FILE_H

#include <stdint.h>
#include <stddef.h>
#include "register.h"

#define REGISTER_FILE_MAX 16

#define REGISTER_INIT_SUCCESS 0
#define REGISTER_FILE_INVALID_SIZE -1
#define REGISTER_FILE_MAX_EXCEEDED -2
#define REGISTER_FILE_ALLOCATION_FAILED -3

typedef struct
{
    Register *registers;
    size_t count;
} RegisterFile;

int register_file_init(
    RegisterFile *file,
    size_t count);

uint8_t register_file_read(
    const RegisterFile *file,
    uint8_t address);

void register_file_write(
    RegisterFile *file,
    uint8_t address,
    uint8_t value,
    uint8_t enable);

void register_file_destroy(RegisterFile *file);

#endif
#include "unity.h"
#include "register_file.h"
#include "bus.h"

void test_register_to_bus_to_register(void)
{
    RegisterFile file;

    register_file_init(&file);

    register_file_write(&file, 1, 42, 1);

    uint8_t source = register_file_read(&file, 1);

    uint8_t bus = bus_select(
        source,
        0,
        0,
        0,
        0
    );

    register_file_write(&file, 2, bus, 1);

    TEST_ASSERT_EQUAL_UINT8(42, register_file_read(&file, 2));
}
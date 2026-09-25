#include "unity.h"
#include "ram.h"

void test_ram_init(void)
{
    RAM ram;

    ram_init(&ram, 4);

    TEST_ASSERT_EQUAL_UINT32(4, ram.size);

    TEST_ASSERT_EQUAL_UINT8(0, ram_read(&ram, 0));
    TEST_ASSERT_EQUAL_UINT8(0, ram_read(&ram, 1));
    TEST_ASSERT_EQUAL_UINT8(0, ram_read(&ram, 2));
    TEST_ASSERT_EQUAL_UINT8(0, ram_read(&ram, 3));

    ram_destroy(&ram);
}

void test_ram_write(void)
{
    RAM ram;

    ram_init(&ram, 4);

    ram_write(&ram, 0, 42);
    ram_write(&ram, 1, 64);
    ram_write(&ram, 2, 128);
    ram_write(&ram, 3, 255);

    TEST_ASSERT_EQUAL_UINT8(42, ram_read(&ram, 0));
    TEST_ASSERT_EQUAL_UINT8(64, ram_read(&ram, 1));
    TEST_ASSERT_EQUAL_UINT8(128, ram_read(&ram, 2));
    TEST_ASSERT_EQUAL_UINT8(255, ram_read(&ram, 3));

    ram_destroy(&ram);
}

void test_ram_destroy(void)
{
    RAM ram;

    ram_init(&ram, 4);
    ram_destroy(&ram);

    TEST_ASSERT_NULL(ram.data);
    TEST_ASSERT_EQUAL_UINT32(0, ram.size);
}

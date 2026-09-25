#include "unity.h"
#include "register.h"

void test_register_initializes_to_zero(void)
{
    Register reg;

    register_init(&reg);

    TEST_ASSERT_EQUAL_UINT8(0, register_read(&reg));
}

void test_register_can_store_value(void)
{
    Register reg;

    register_init(&reg);
    register_write(&reg, 0x42,1);

    TEST_ASSERT_EQUAL_UINT8(0x42, register_read(&reg));
}

void test_register_can_store_maximum_value(void)
{
    Register reg;

    register_init(&reg);
    register_write(&reg, 0xFF,1);

    TEST_ASSERT_EQUAL_UINT8(0xFF, register_read(&reg));
}

void test_register_overwrites_previous_value(void)
{
    Register reg;

    register_init(&reg);

    register_write(&reg, 0x12,1);
    register_write(&reg, 0x34,1);

    TEST_ASSERT_EQUAL_UINT8(0x34, register_read(&reg));
}

void test_register_write_disabled(void)
{
    Register reg;

    register_init(&reg);

    register_write(&reg, 42, 1);
    register_write(&reg, 99, 0);

    TEST_ASSERT_EQUAL_UINT8(42, register_read(&reg));
}


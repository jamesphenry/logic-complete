#include "unity.h"
#include "register_file.h"

void test_register_file_init(void)
{
    RegisterFile file;

    register_file_init(&file);

    TEST_ASSERT_EQUAL_UINT8(0, register_file_read(&file, 0));
    TEST_ASSERT_EQUAL_UINT8(0, register_file_read(&file, 1));
    TEST_ASSERT_EQUAL_UINT8(0, register_file_read(&file, 2));
    TEST_ASSERT_EQUAL_UINT8(0, register_file_read(&file, 3));
}

void test_register_file_write_register0(void)
{
    RegisterFile file;

    register_file_init(&file);
    register_file_write(&file, 0, 42, 1);

    TEST_ASSERT_EQUAL_UINT8(42, register_file_read(&file, 0));
}

void test_register_file_write_register1(void)
{
    RegisterFile file;

    register_file_init(&file);
    register_file_write(&file, 1, 42, 1);

    TEST_ASSERT_EQUAL_UINT8(42, register_file_read(&file, 1));
}

void test_register_file_write_register2(void)
{
    RegisterFile file;

    register_file_init(&file);
    register_file_write(&file, 2, 42, 1);

    TEST_ASSERT_EQUAL_UINT8(42, register_file_read(&file, 2));
}

void test_register_file_write_register3(void)
{
    RegisterFile file;

    register_file_init(&file);
    register_file_write(&file, 3, 42, 1);

    TEST_ASSERT_EQUAL_UINT8(42, register_file_read(&file, 3));
}

void test_register_file_write_disabled(void)
{
    RegisterFile file;

    register_file_init(&file);
    register_file_write(&file, 2, 42, 0);

    TEST_ASSERT_EQUAL_UINT8(0, register_file_read(&file, 2));
}
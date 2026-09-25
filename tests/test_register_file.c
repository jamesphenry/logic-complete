#include "unity.h"
#include "register_file.h"

void test_register_file_init(void)
{
    RegisterFile file;

    register_file_init(&file,4);

    TEST_ASSERT_EQUAL_UINT8(0, register_file_read(&file, 0));
    TEST_ASSERT_EQUAL_UINT8(0, register_file_read(&file, 1));
    TEST_ASSERT_EQUAL_UINT8(0, register_file_read(&file, 2));
    TEST_ASSERT_EQUAL_UINT8(0, register_file_read(&file, 3));
    register_file_destroy(&file);
}

void test_register_file_write_register0(void)
{
    RegisterFile file;

    register_file_init(&file,4);
    register_file_write(&file, 0, 42, 1);

    TEST_ASSERT_EQUAL_UINT8(42, register_file_read(&file, 0));
    register_file_destroy(&file);
}

void test_register_file_write_register1(void)
{
    RegisterFile file;

    register_file_init(&file,4);
    register_file_write(&file, 1, 42, 1);

    TEST_ASSERT_EQUAL_UINT8(42, register_file_read(&file, 1));
    register_file_destroy(&file);

}

void test_register_file_write_register2(void)
{
    RegisterFile file;

    register_file_init(&file,4);
    register_file_write(&file, 2, 42, 1);

    TEST_ASSERT_EQUAL_UINT8(42, register_file_read(&file, 2));
    register_file_destroy(&file);

}

void test_register_file_write_register3(void)
{
    RegisterFile file;

    register_file_init(&file,4);
    register_file_write(&file, 3, 42, 1);

    TEST_ASSERT_EQUAL_UINT8(42, register_file_read(&file, 3));
    register_file_destroy(&file);

}

void test_register_file_write_disabled(void)
{
    RegisterFile file;

    register_file_init(&file,4);
    register_file_write(&file, 2, 42, 0);

    TEST_ASSERT_EQUAL_UINT8(0, register_file_read(&file, 2));
    register_file_destroy(&file);

}

void test_register_file_one_register(void)
{
    RegisterFile file;

    TEST_ASSERT_EQUAL_INT(
        REGISTER_INIT_SUCCESS,
        register_file_init(&file, 1));

    register_file_write(&file, 0, 42, 1);

    TEST_ASSERT_EQUAL_UINT8(42, register_file_read(&file, 0));

    register_file_destroy(&file);
}

void test_register_file_eight_registers(void)
{
    RegisterFile file;

    TEST_ASSERT_EQUAL_INT(
        REGISTER_INIT_SUCCESS,
        register_file_init(&file, 8));

    register_file_write(&file, 7, 42, 1);

    TEST_ASSERT_EQUAL_UINT8(42, register_file_read(&file, 7));

    register_file_destroy(&file);
}

void test_register_file_sixteen_registers(void)
{
    RegisterFile file;

    TEST_ASSERT_EQUAL_INT(
        REGISTER_INIT_SUCCESS,
        register_file_init(&file, 16));

    register_file_write(&file, 15, 42, 1);

    TEST_ASSERT_EQUAL_UINT8(42, register_file_read(&file, 15));

    register_file_destroy(&file);
}

void test_register_file_registers_are_isolated(void)
{
    RegisterFile file;

    register_file_init(&file, 16);

    register_file_write(&file, 15, 42, 1);

    TEST_ASSERT_EQUAL_UINT8(0,  register_file_read(&file, 0));
    TEST_ASSERT_EQUAL_UINT8(0,  register_file_read(&file, 1));
    TEST_ASSERT_EQUAL_UINT8(0,  register_file_read(&file, 14));
    TEST_ASSERT_EQUAL_UINT8(42, register_file_read(&file, 15));

    register_file_destroy(&file);
}

void test_register_file_max_registers(void)
{
    RegisterFile file;

    TEST_ASSERT_EQUAL_INT(
        REGISTER_INIT_SUCCESS,
        register_file_init(&file, REGISTER_FILE_MAX));

    register_file_destroy(&file);
}
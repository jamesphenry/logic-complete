#include "unity.h"
#include "overflow.h"
#include "alu.h"

void test_overflow_add8_positive(void)
{
    uint8_t result = 0x7F + 0x01;

    TEST_ASSERT_EQUAL_UINT8(1,
        overflow_add8(0x7F, 0x01, result));
}

void test_overflow_add8_negative(void)
{
    uint8_t result = (uint8_t)(0x80 + 0xFF);

    TEST_ASSERT_EQUAL_UINT8(1,
        overflow_add8(0x80, 0xFF, result));
}

void test_overflow_add8_no_overflow_positive(void)
{
    uint8_t result = 0x40 + 0x10;

    TEST_ASSERT_EQUAL_UINT8(0,
        overflow_add8(0x40, 0x10, result));
}

void test_alu_add_no_overflow(void)
{
    ALU8 result = alu8(0x40, 0x10, ALU_ADD);

    TEST_ASSERT_EQUAL_UINT8(0x50, result.result);
    TEST_ASSERT_EQUAL_UINT8(0, result.overflow);
}

void test_overflow_add8_no_overflow_negative(void)
{
    uint8_t result = (uint8_t)(0xC0 + 0xF0);

    TEST_ASSERT_EQUAL_UINT8(
        0,
        overflow_add8(0xC0, 0xF0, result)
    );
}
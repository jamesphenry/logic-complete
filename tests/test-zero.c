#include "unity.h"
#include "zero.h"

void test_zero_flag8_zero(void)
{
    TEST_ASSERT_EQUAL_UINT8(1, zero_flag8(0x00));
}

void test_zero_flag8_nonzero(void)
{
    TEST_ASSERT_EQUAL_UINT8(0, zero_flag8(0x01));
}

void test_zero_flag8_high_bit(void)
{
    TEST_ASSERT_EQUAL_UINT8(0, zero_flag8(0x80));
}

void test_zero_flag8_middle_bit(void)
{
    TEST_ASSERT_EQUAL_UINT8(0, zero_flag8(0x40));
}
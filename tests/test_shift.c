#include "shifter.h"
#include "unity.h"

void test_shift_left8(void)
{
    Shift8 result = shift_left8(0x55);

    TEST_ASSERT_EQUAL_UINT8(0xAA, result.value);
    TEST_ASSERT_EQUAL_UINT8(0, result.shifted_out);
}

void test_shift_left8_carry(void)
{
    Shift8 result = shift_left8(0x80);

    TEST_ASSERT_EQUAL_UINT8(0x00, result.value);
    TEST_ASSERT_EQUAL_UINT8(1, result.shifted_out);
}

void test_shift_right8(void)
{
    Shift8 result = shift_right8(0xAA);

    TEST_ASSERT_EQUAL_UINT8(0x55, result.value);
    TEST_ASSERT_EQUAL_UINT8(0, result.shifted_out);
}

void test_shift_right8_carry(void)
{
    Shift8 result = shift_right8(0x01);

    TEST_ASSERT_EQUAL_UINT8(0x00, result.value);
    TEST_ASSERT_EQUAL_UINT8(1, result.shifted_out);
}
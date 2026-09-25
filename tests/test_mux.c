#include "unity.h"
#include "mux.h"

void test_mux_selects_a_when_select_is_zero(void)
{
    uint8_t result = mux2(0x12, 0x34, 0);

    TEST_ASSERT_EQUAL_UINT8(0x12, result);
}

void test_mux_selects_b_when_select_is_one(void)
{
    uint8_t result = mux2(0x12, 0x34, 1);

    TEST_ASSERT_EQUAL_UINT8(0x34, result);
}

void test_mux_can_select_zero(void)
{
    uint8_t result = mux2(0x00, 0xFF, 0);

    TEST_ASSERT_EQUAL_UINT8(0x00, result);
}

void test_mux_can_select_maximum_value(void)
{
    uint8_t result = mux2(0x00, 0xFF, 1);

    TEST_ASSERT_EQUAL_UINT8(0xFF, result);
}

void test_mux_inputs_are_independent(void)
{
    TEST_ASSERT_EQUAL_UINT8(0xAA, mux2(0xAA, 0x55, 0));
    TEST_ASSERT_EQUAL_UINT8(0x55, mux2(0xAA, 0x55, 1));

    TEST_ASSERT_EQUAL_UINT8(0x55, mux2(0x55, 0xAA, 0));
    TEST_ASSERT_EQUAL_UINT8(0xAA, mux2(0x55, 0xAA, 1));
}

void test_mux16(void)
{
    uint8_t inputs[16];

    for (uint8_t i = 0; i < 16; i++)
    {
        inputs[i] = i;
    }

    for (uint8_t select = 0; select < 16; select++)
    {
        TEST_ASSERT_EQUAL_UINT8(
            select,
            mux16(inputs, select));
    }
}

void test_mux4_select_a(void)
{
    uint8_t result = mux4(10, 20, 30, 40, 0);

    TEST_ASSERT_EQUAL_UINT8(10, result);
}

void test_mux4_select_b(void)
{
    uint8_t result = mux4(10, 20, 30, 40, 1);

    TEST_ASSERT_EQUAL_UINT8(20, result);
}

void test_mux4_select_c(void)
{
    uint8_t result = mux4(10, 20, 30, 40, 2);

    TEST_ASSERT_EQUAL_UINT8(30, result);
}

void test_mux4_select_d(void)
{
    uint8_t result = mux4(10, 20, 30, 40, 3);

    TEST_ASSERT_EQUAL_UINT8(40, result);
}

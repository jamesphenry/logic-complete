#include "unity.h"
#include "adder.h"

void test_half_adder_zero_zero(void)
{
    HalfAdder result = half_adder(0, 0);

    TEST_ASSERT_EQUAL_UINT8(0, result.sum);
    TEST_ASSERT_EQUAL_UINT8(0, result.carry);
}

void test_half_adder_zero_one(void)
{
    HalfAdder result = half_adder(0, 1);

    TEST_ASSERT_EQUAL_UINT8(1, result.sum);
    TEST_ASSERT_EQUAL_UINT8(0, result.carry);
}

void test_half_adder_one_zero(void)
{
    HalfAdder result = half_adder(1, 0);

    TEST_ASSERT_EQUAL_UINT8(1, result.sum);
    TEST_ASSERT_EQUAL_UINT8(0, result.carry);
}

void test_half_adder_one_one(void)
{
    HalfAdder result = half_adder(1, 1);

    TEST_ASSERT_EQUAL_UINT8(0, result.sum);
    TEST_ASSERT_EQUAL_UINT8(1, result.carry);
}
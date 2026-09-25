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

void test_full_adder_zero_zero_zero(void)
{
    FullAdder result = full_adder(0, 0, 0);

    TEST_ASSERT_EQUAL_UINT8(0, result.sum);
    TEST_ASSERT_EQUAL_UINT8(0, result.carry);
}

void test_full_adder_zero_zero_one(void)
{
    FullAdder result = full_adder(0, 0, 1);

    TEST_ASSERT_EQUAL_UINT8(1, result.sum);
    TEST_ASSERT_EQUAL_UINT8(0, result.carry);
}

void test_full_adder_zero_one_zero(void)
{
    FullAdder result = full_adder(0, 1, 0);

    TEST_ASSERT_EQUAL_UINT8(1, result.sum);
    TEST_ASSERT_EQUAL_UINT8(0, result.carry);
}

void test_full_adder_zero_one_one(void)
{
    FullAdder result = full_adder(0, 1, 1);

    TEST_ASSERT_EQUAL_UINT8(0, result.sum);
    TEST_ASSERT_EQUAL_UINT8(1, result.carry);
}

void test_full_adder_one_zero_zero(void)
{
    FullAdder result = full_adder(1, 0, 0);

    TEST_ASSERT_EQUAL_UINT8(1, result.sum);
    TEST_ASSERT_EQUAL_UINT8(0, result.carry);
}

void test_full_adder_one_zero_one(void)
{
    FullAdder result = full_adder(1, 0, 1);

    TEST_ASSERT_EQUAL_UINT8(0, result.sum);
    TEST_ASSERT_EQUAL_UINT8(1, result.carry);
}

void test_full_adder_one_one_zero(void)
{
    FullAdder result = full_adder(1, 1, 0);

    TEST_ASSERT_EQUAL_UINT8(0, result.sum);
    TEST_ASSERT_EQUAL_UINT8(1, result.carry);
}

void test_full_adder_one_one_one(void)
{
    FullAdder result = full_adder(1, 1, 1);

    TEST_ASSERT_EQUAL_UINT8(1, result.sum);
    TEST_ASSERT_EQUAL_UINT8(1, result.carry);
}

void test_adder8_zero(void)
{
    Adder8 result = adder8(0x00, 0x00, 0);

    TEST_ASSERT_EQUAL_UINT8(0x00, result.sum);
    TEST_ASSERT_EQUAL_UINT8(0, result.carry);
}

void test_adder8_simple_addition(void)
{
    Adder8 result = adder8(0x01, 0x01, 0);

    TEST_ASSERT_EQUAL_UINT8(0x02, result.sum);
    TEST_ASSERT_EQUAL_UINT8(0, result.carry);
}

void test_adder8_carry_across_nibble(void)
{
    Adder8 result = adder8(0x0F, 0x01, 0);

    TEST_ASSERT_EQUAL_UINT8(0x10, result.sum);
    TEST_ASSERT_EQUAL_UINT8(0, result.carry);
}

void test_adder8_carry_out(void)
{
    Adder8 result = adder8(0xFF, 0x01, 0);

    TEST_ASSERT_EQUAL_UINT8(0x00, result.sum);
    TEST_ASSERT_EQUAL_UINT8(1, result.carry);
}

void test_adder8_pattern_addition(void)
{
    Adder8 result = adder8(0x55, 0xAA, 0);

    TEST_ASSERT_EQUAL_UINT8(0xFF, result.sum);
    TEST_ASSERT_EQUAL_UINT8(0, result.carry);
}

void test_adder8_example_addition(void)
{
    Adder8 result = adder8(0x42, 0x37, 0);

    TEST_ASSERT_EQUAL_UINT8(0x79, result.sum);
    TEST_ASSERT_EQUAL_UINT8(0, result.carry);
}

void test_adder8_with_carry_in(void)
{
    Adder8 result = adder8(0x00, 0x00, 1);

    TEST_ASSERT_EQUAL_UINT8(0x01, result.sum);
    TEST_ASSERT_EQUAL_UINT8(0, result.carry);
}

void test_adder8_carry_in_and_carry_out(void)
{
    Adder8 result = adder8(0xFF, 0x00, 1);

    TEST_ASSERT_EQUAL_UINT8(0x00, result.sum);
    TEST_ASSERT_EQUAL_UINT8(1, result.carry);
}

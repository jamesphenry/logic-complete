#include "unity.h"
#include "alu.h"

void test_alu_add(void)
{
    ALU8 result = alu8(5, 3, ALU_ADD);

    TEST_ASSERT_EQUAL_UINT8(8, result.result);
}

void test_alu_add_overflow(void)
{
    ALU8 result = alu8(0xFF, 1, ALU_ADD);

    TEST_ASSERT_EQUAL_UINT8(0, result.result);
}

void test_alu_sub(void)
{
    ALU8 result = alu8(5, 3, ALU_SUB);

    TEST_ASSERT_EQUAL_UINT8(2, result.result);
}

void test_alu_sub_borrow(void)
{
    ALU8 result = alu8(3, 5, ALU_SUB);

    TEST_ASSERT_EQUAL_UINT8(0xFE, result.result);
}
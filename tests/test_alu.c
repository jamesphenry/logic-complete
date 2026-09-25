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

void test_alu_and(void)
{
    ALU8 result = alu8(0xF0, 0x0F, ALU_AND);

    TEST_ASSERT_EQUAL_UINT8(0x00, result.result);
}

void test_alu_and_partial(void)
{
    ALU8 result = alu8(0xF0, 0xCC, ALU_AND);

    TEST_ASSERT_EQUAL_UINT8(0xC0, result.result);
}

void test_alu_or(void)
{
    ALU8 result = alu8(0xF0, 0x0F, ALU_OR);

    TEST_ASSERT_EQUAL_UINT8(0xFF, result.result);
}

void test_alu_or_partial(void)
{
    ALU8 result = alu8(0xA0, 0x0C, ALU_OR);

    TEST_ASSERT_EQUAL_UINT8(0xAC, result.result);
}

void test_alu_xor(void)
{
    ALU8 result = alu8(0xF0, 0x0F, ALU_XOR);

    TEST_ASSERT_EQUAL_UINT8(0xFF, result.result);
}

void test_alu_xor_partial(void)
{
    ALU8 result = alu8(0xAA, 0x0F, ALU_XOR);

    TEST_ASSERT_EQUAL_UINT8(0xA5, result.result);
}

void test_alu_shl(void)
{
    ALU8 result = alu8(0x15, 0x00, ALU_SHL);

    TEST_ASSERT_EQUAL_UINT8(0x2A, result.result);
}

void test_alu_shl_overflow(void)
{
    ALU8 result = alu8(0x80, 0x00, ALU_SHL);

    TEST_ASSERT_EQUAL_UINT8(0x00, result.result);
}

void test_alu_shr(void)
{
    ALU8 result = alu8(0xAA, 0x00, ALU_SHR);

    TEST_ASSERT_EQUAL_UINT8(0x55, result.result);
}

void test_alu_shr_overflow(void)
{
    ALU8 result = alu8(0x01, 0x00, ALU_SHR);

    TEST_ASSERT_EQUAL_UINT8(0x00, result.result);
}
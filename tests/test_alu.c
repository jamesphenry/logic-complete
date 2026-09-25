#include "unity.h"
#include "alu.h"
#include "flags.h"

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

void test_alu_zero_flag(void)
{
    ALU8 result = alu8(0x01, 0x01, ALU_SUB);

    TEST_ASSERT_EQUAL_UINT8(0x00, result.result);
    TEST_ASSERT_EQUAL_UINT8(1, result.zero);
}

void test_alu_nonzero_flag(void)
{
    ALU8 result = alu8(0x05, 0x03, ALU_SUB);

    TEST_ASSERT_EQUAL_UINT8(0x02, result.result);
    TEST_ASSERT_EQUAL_UINT8(0, result.zero);
}

void test_alu_add_carry(void)
{
    ALU8 result = alu8(0xFF, 0x01, ALU_ADD);

    TEST_ASSERT_EQUAL_UINT8(0x00, result.result);
    TEST_ASSERT_EQUAL_UINT8(1, result.carry);
}

void test_alu_add_no_carry(void)
{
    ALU8 result = alu8(0x05, 0x03, ALU_ADD);

    TEST_ASSERT_EQUAL_UINT8(0x08, result.result);
    TEST_ASSERT_EQUAL_UINT8(0, result.carry);
}

void test_alu_sub_borrow(void)
{
    ALU8 result = alu8(3, 5, ALU_SUB);

    TEST_ASSERT_EQUAL_UINT8(0xFE, result.result);
    TEST_ASSERT_EQUAL_UINT8(1, result.borrow);
}

void test_alu_sub_no_borrow(void)
{
    ALU8 result = alu8(5, 3, ALU_SUB);

    TEST_ASSERT_EQUAL_UINT8(0x02, result.result);
    TEST_ASSERT_EQUAL_UINT8(0, result.borrow);
}

void test_alu_negative_set(void)
{
    ALU8 result = alu8(0x80, 0x00, ALU_OR);

    TEST_ASSERT_EQUAL_UINT8(0x80, result.result);
    TEST_ASSERT_EQUAL_UINT8(1, result.negative);
}

void test_alu_negative_clear(void)
{
    ALU8 result = alu8(0x40, 0x00, ALU_OR);

    TEST_ASSERT_EQUAL_UINT8(0x40, result.result);
    TEST_ASSERT_EQUAL_UINT8(0, result.negative);
}

void test_flags_load(void)
{
    Flags flags;
    ALU8 alu;

    flags_init(&flags);

    alu.result = 0;
    alu.zero = 1;
    alu.carry = 1;
    alu.borrow = 0;
    alu.negative = 0;
    alu.overflow = 1;

    flags_load(&flags, &alu);

    TEST_ASSERT_EQUAL_UINT8(1, flags_read_zero(&flags));
    TEST_ASSERT_EQUAL_UINT8(1, flags_read_carry(&flags));
    TEST_ASSERT_EQUAL_UINT8(0, flags_read_borrow(&flags));
    TEST_ASSERT_EQUAL_UINT8(0, flags_read_negative(&flags));
    TEST_ASSERT_EQUAL_UINT8(1, flags_read_overflow(&flags));
}
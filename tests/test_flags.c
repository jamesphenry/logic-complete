#include "unity.h"
#include "flags.h"

void test_flags_init(void)
{
    Flags flags;

    flags_init(&flags);

    TEST_ASSERT_EQUAL_UINT8(0, flags_read_zero(&flags));
    TEST_ASSERT_EQUAL_UINT8(0, flags_read_carry(&flags));
    TEST_ASSERT_EQUAL_UINT8(0, flags_read_borrow(&flags));
    TEST_ASSERT_EQUAL_UINT8(0, flags_read_negative(&flags));
    TEST_ASSERT_EQUAL_UINT8(0, flags_read_overflow(&flags));
}

void test_flags_write_zero(void)
{
    Flags flags;

    flags_init(&flags);
    flags_write_zero(&flags, 1);

    TEST_ASSERT_EQUAL_UINT8(1, flags_read_zero(&flags));
}

void test_flags_write_carry(void)
{
    Flags flags;

    flags_init(&flags);
    flags_write_carry(&flags, 1);

    TEST_ASSERT_EQUAL_UINT8(1, flags_read_carry(&flags));
}

void test_flags_write_borrow(void)
{
    Flags flags;

    flags_init(&flags);
    flags_write_borrow(&flags, 1);

    TEST_ASSERT_EQUAL_UINT8(1, flags_read_borrow(&flags));
}

void test_flags_write_negative(void)
{
    Flags flags;

    flags_init(&flags);
    flags_write_negative(&flags, 1);

    TEST_ASSERT_EQUAL_UINT8(1, flags_read_negative(&flags));
}

void test_flags_write_overflow(void)
{
    Flags flags;

    flags_init(&flags);
    flags_write_overflow(&flags, 1);

    TEST_ASSERT_EQUAL_UINT8(1, flags_read_overflow(&flags));
}

void test_flags_load_from_alu(void)
{
    Flags flags;

    flags_init(&flags);

    ALU8 alu = alu8(0x7F, 1, ALU_ADD);

    flags_load(&flags, &alu);

    TEST_ASSERT_EQUAL_UINT8(1, flags_read_negative(&flags));
    TEST_ASSERT_EQUAL_UINT8(1, flags_read_overflow(&flags));
}
#ifndef TESTS_H
#define TESTS_H

/* Register tests */
void test_register_initializes_to_zero(void);
void test_register_can_store_value(void);
void test_register_can_store_maximum_value(void);
void test_register_overwrites_previous_value(void);

/* MUX tests */
void test_mux_selects_a_when_select_is_zero(void);
void test_mux_selects_b_when_select_is_one(void);
void test_mux_can_select_zero(void);
void test_mux_can_select_maximum_value(void);
void test_mux_inputs_are_independent(void);

/* Logic tests */

void test_logic_not_zero(void);
void test_logic_not_one(void);

void test_logic_and(void);
void test_logic_or(void);
void test_logic_xor(void);
void test_logic_nand(void);
void test_logic_nor(void);

void test_half_adder_zero_zero(void);
void test_half_adder_zero_one(void);
void test_half_adder_one_zero(void);
void test_half_adder_one_one(void);

void test_full_adder_zero_zero_zero(void);
void test_full_adder_zero_zero_one(void);
void test_full_adder_zero_one_zero(void);
void test_full_adder_zero_one_one(void);
void test_full_adder_one_zero_zero(void);
void test_full_adder_one_zero_one(void);
void test_full_adder_one_one_zero(void);
void test_full_adder_one_one_one(void);

/* 8-bit Adder tests */

void test_adder8_zero(void);
void test_adder8_simple_addition(void);
void test_adder8_carry_across_nibble(void);
void test_adder8_carry_out(void);
void test_adder8_pattern_addition(void);
void test_adder8_example_addition(void);
void test_adder8_with_carry_in(void);
void test_adder8_carry_in_and_carry_out(void);

void test_get_bit_zero(void);
void test_get_bit_one(void);
void test_get_bit_from_middle(void);
void test_get_bit_from_high_bit(void);
void test_get_bit_clear_bit(void);

void test_set_bit_sets_clear_bit(void);
void test_set_bit_sets_high_bit(void);
void test_set_bit_clears_set_bit(void);
void test_set_bit_does_not_change_other_bits(void);
void test_set_bit_can_clear_one_bit_without_affecting_others(void);

void test_logic_equal_zero_zero(void);
void test_logic_equal_zero_one(void);
void test_logic_equal_one_zero(void);
void test_logic_equal_one_one(void);

void test_comparator_equal(void);
void test_comparator_less(void);
void test_comparator_greater(void);

void test_logic_greater(void);

void test_logic_less(void);
void test_logic_not8(void);

void test_subtractor8_zero(void);
void test_subtractor8_simple(void);
void test_subtractor8_borrow(void);
void test_subtractor8_equal(void);

void test_logic_and8(void);
void test_logic_or8(void);
void test_logic_xor8(void);
void test_logic_nand8(void);

void test_shift_left8(void);
void test_shift_left8_carry(void);
void test_shift_right8(void);
void test_shift_right8_carry(void);

void test_alu_add(void);
void test_alu_add_overflow(void);
void test_alu_sub_borrow(void);
void test_alu_sub(void);
void test_alu_sub_borrow(void);
void test_alu_and(void);
void test_alu_and_partial(void);
void test_alu_or(void);
void test_alu_or_partial(void);
void test_alu_xor(void);
void test_alu_xor_partial(void);
void test_alu_shl(void);
void test_alu_shl_overflow(void);
void test_alu_shr(void);
void test_alu_shr_overflow(void);

void test_zero_flag8_zero(void);
void test_zero_flag8_nonzero(void);
void test_zero_flag8_high_bit(void);
void test_zero_flag8_middle_bit(void);

void test_alu_zero_flag(void);
void test_alu_nonzero_flag(void);

void test_alu_add_carry(void);
void test_alu_add_no_carry(void);

void test_alu_sub_borrow(void);
void test_alu_sub_no_borrow(void);

void test_negative_flag8_clear(void);
void test_negative_flag8_set(void);
void test_negative_flag8_max(void);

void test_alu_negative_set(void);
void test_alu_negative_clear(void);


void test_overflow_add8_positive(void);
void test_overflow_add8_negative(void);
void test_overflow_add8_no_overflow_positive(void);
void test_overflow_add8_no_overflow_negative(void);

void test_alu_add_overflow(void);
void test_alu_add_no_overflow(void);
void test_overflow_add8_no_overflow_negative(void);

void test_flags_init(void);
void test_flags_write_zero(void);
void test_flags_write_carry(void);
void test_flags_write_borrow(void);
void test_flags_write_negative(void);
void test_flags_write_overflow(void);

void test_flags_load(void);
void test_flags_load_from_alu(void);

void test_decoder_00(void);
void test_decoder_01(void);
void test_decoder_10(void);
void test_decoder_11(void);


#endif
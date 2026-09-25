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


#endif
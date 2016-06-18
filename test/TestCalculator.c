#include "../src/RomanCalculator.h"
#include <check.h>

START_TEST(test_roman_to_decimal1) {
	ck_assert(roman_to_decimal(NULL) < 0);
} END_TEST

START_TEST(test_roman_to_decimal2) {
	ck_assert(roman_to_decimal("JAMIE") < 0);
} END_TEST

START_TEST(test_roman_to_decimal3) {
	ck_assert(roman_to_decimal("I") == 1);
} END_TEST

START_TEST(test_roman_to_decimal4) {
	ck_assert(roman_to_decimal("MMMMCMXCIX") == MAX_ROMAN_VALUE);
} END_TEST

START_TEST(test_roman_to_decimal5) {
	ck_assert(roman_to_decimal("mmmmcmxcix") == MAX_ROMAN_VALUE);
} END_TEST

START_TEST(test_roman_to_decimal6) {
	ck_assert(roman_to_decimal("CDXLIV") == 444);
} END_TEST

START_TEST(test_roman_to_decimal7) {
	ck_assert(roman_to_decimal("MMMMDCCCLXXXVIII") == 4888);
} END_TEST

START_TEST(test_roman_to_decimal8) {
	ck_assert(roman_to_decimal("IIIIIIIIIIIIIIIIII") < 0);
} END_TEST

START_TEST(test_decimal_to_roman1) {
	char r[MAX_ROMAN_STRLEN];

	ck_assert(decimal_to_roman(1, NULL, sizeof(r)) < 0);
} END_TEST

START_TEST(test_decimal_to_roman2) {
	char r[MAX_ROMAN_STRLEN];

	ck_assert(decimal_to_roman(1, r, 0) < 0);
} END_TEST

START_TEST(test_decimal_to_roman3) {
	char r[MAX_ROMAN_STRLEN];

	ck_assert(decimal_to_roman(0, r, sizeof(r)) < 0);
} END_TEST

START_TEST(test_decimal_to_roman4) {
	char r[MAX_ROMAN_STRLEN];

	ck_assert(decimal_to_roman(1, r, sizeof(r)) == 0);
	ck_assert_str_eq(r, "I");
} END_TEST

START_TEST(test_decimal_to_roman5) {
	char r[MAX_ROMAN_STRLEN];

	ck_assert(decimal_to_roman(4999, r, sizeof(r)) == 0);
	ck_assert_str_eq(r, "MMMMCMXCIX");
} END_TEST

START_TEST(test_decimal_to_roman6) {
	char r[MAX_ROMAN_STRLEN];

	ck_assert(decimal_to_roman(MAX_ROMAN_VALUE + 1, r, sizeof(r)) < 0);
} END_TEST

START_TEST(test_roman_add1) {
	ck_assert(roman_add(NULL, NULL, NULL, 0) < 0);
} END_TEST

START_TEST(test_roman_add2) {
	ck_assert(roman_add("I", "I", NULL, 0) < 0);
} END_TEST

START_TEST(test_roman_add3) {
	char r[MAX_ROMAN_STRLEN];

	ck_assert(roman_add("I", "I", r, 0) < 0);
} END_TEST

START_TEST(test_roman_add4) {
	char r[MAX_ROMAN_STRLEN];

	ck_assert(roman_add("I", "I", r, sizeof(r)) == 0);
	ck_assert_str_eq(r, "II");
} END_TEST

START_TEST(test_roman_add5) {
	char r[MAX_ROMAN_STRLEN];

	ck_assert(roman_add("MMMMCMXCVIII", "I", r, sizeof(r)) == 0);
	ck_assert_str_eq(r, "MMMMCMXCIX");
} END_TEST

START_TEST(test_roman_add6) {
	char r[MAX_ROMAN_STRLEN];

	ck_assert(roman_add("MMMMCMXCIX", "I", r, sizeof(r)) < 0);
} END_TEST

START_TEST(test_roman_subtract1) {
	ck_assert(roman_subtract(NULL, NULL, NULL, 0) < 0);
} END_TEST

START_TEST(test_roman_subtract2) {
	ck_assert(roman_subtract("I", "I", NULL, 0) < 0);
} END_TEST

START_TEST(test_roman_subtract3) {
	char r[MAX_ROMAN_STRLEN];

	ck_assert(roman_subtract("I", "I", r, 0) < 0);
} END_TEST

START_TEST(test_roman_subtract4) {
	char r[MAX_ROMAN_STRLEN];

	ck_assert(roman_subtract("I", "I", r, sizeof(r)) < 0);
} END_TEST

START_TEST(test_roman_subtract5) {
	char r[MAX_ROMAN_STRLEN];

	ck_assert(roman_subtract("MMMMCMXCVIII", "I", r, sizeof(r)) == 0);
	ck_assert_str_eq(r, "MMMMCMXCVII");
} END_TEST

START_TEST(test_roman_subtract6) {
	char r[MAX_ROMAN_STRLEN];

	ck_assert(roman_subtract("I", "MMMMCMXCIX", r, sizeof(r)) < 0);
} END_TEST

Suite* calculator_suite(void) {
	Suite *s;
	TCase *tc_to_decimal;
	TCase *tc_to_roman;
	TCase *tc_add_roman;
	TCase *tc_subtract_roman;

	s = suite_create("Calculator");

	/* To decimal test case */
	tc_to_decimal = tcase_create("ToDecimal");
	tcase_add_test(tc_to_decimal, test_roman_to_decimal1);
	tcase_add_test(tc_to_decimal, test_roman_to_decimal2);
	tcase_add_test(tc_to_decimal, test_roman_to_decimal3);
	tcase_add_test(tc_to_decimal, test_roman_to_decimal4);
	tcase_add_test(tc_to_decimal, test_roman_to_decimal5);
	tcase_add_test(tc_to_decimal, test_roman_to_decimal6);
	tcase_add_test(tc_to_decimal, test_roman_to_decimal7);
	tcase_add_test(tc_to_decimal, test_roman_to_decimal8);
	suite_add_tcase(s, tc_to_decimal);

	/* To roman test case */
	tc_to_roman = tcase_create("ToRoman");
	tcase_add_test(tc_to_roman, test_decimal_to_roman1);
	tcase_add_test(tc_to_roman, test_decimal_to_roman2);
	tcase_add_test(tc_to_roman, test_decimal_to_roman3);
	tcase_add_test(tc_to_roman, test_decimal_to_roman4);
	tcase_add_test(tc_to_roman, test_decimal_to_roman5);
	tcase_add_test(tc_to_roman, test_decimal_to_roman6);
	suite_add_tcase(s, tc_to_roman);

	/* Add roman test case */
	tc_add_roman = tcase_create("AddRoman");
	tcase_add_test(tc_add_roman, test_roman_add1);
	tcase_add_test(tc_add_roman, test_roman_add2);
	tcase_add_test(tc_add_roman, test_roman_add3);
	tcase_add_test(tc_add_roman, test_roman_add4);
	tcase_add_test(tc_add_roman, test_roman_add5);
	tcase_add_test(tc_add_roman, test_roman_add6);
	suite_add_tcase(s, tc_add_roman);

	/* Subtract roman test case */
	tc_subtract_roman = tcase_create("SubtractRoman");
	tcase_add_test(tc_subtract_roman, test_roman_subtract1);
	tcase_add_test(tc_subtract_roman, test_roman_subtract2);
	tcase_add_test(tc_subtract_roman, test_roman_subtract3);
	tcase_add_test(tc_subtract_roman, test_roman_subtract4);
	tcase_add_test(tc_subtract_roman, test_roman_subtract5);
	tcase_add_test(tc_subtract_roman, test_roman_subtract6);
	suite_add_tcase(s, tc_subtract_roman);

	return s;
}

int main(void) {
	int number_failed;
	Suite *s;
	SRunner *sr;

	s = calculator_suite();
	sr = srunner_create(s);
	srunner_set_fork_status(sr, CK_NOFORK);

	srunner_run_all(sr, CK_NORMAL);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);

	return (number_failed == 0) ? 0 :-1;
}

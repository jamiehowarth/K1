#ifndef ROMANCALCULATOR_H_
#define ROMANCALCULATOR_H_

#define MAX_ROMAN_STRLEN 18

#define MAX_ROMAN_VALUE 4999
#define MIN_ROMAN_VALUE 1

int roman_to_decimal(const char* roman);

int decimal_to_roman(int n, char* roman, int length);

int roman_add(const char* num1, const char* num2, char* result, int length);

int roman_subtract(const char* num1, const char* num2, char* result, int length);

#endif /* ROMANCALCULATOR_H_ */

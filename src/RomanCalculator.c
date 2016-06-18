#include "RomanCalculator.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char g_digits[] = "IVXLCDM";

static struct roman_to_decimal {
	char digits[3];
	int  value;
} g_roman_to_decimal[] = {{"CM", 900}, {"CD", 400}, {"XC", 90}, {"XL", 40},
		{"IX", 9}, {"IV", 4}, {"M", 1000}, {"D", 500}, {"C", 100},
		{"L", 50}, {"X", 10}, {"V", 5}, {"I", 1}};

static struct decimal_to_roman {
	char digits[3];
	int  value;
} g_decimal_to_roman[] = {{"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400},
		{"C", 100}, {"XC", 90}, {"L", 50}, {"XL", 40},
		{"X", 10}, {"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1}};

int roman_to_decimal(const char* roman) {
	int n = 0;
	int i = 0;
	char buffer[MAX_ROMAN_STRLEN];

	if (roman == NULL) {
		return -1;
	}

	// Convert to uppercase
	for (i = 0; roman[i] != '\0'; i++) {
		buffer[i] = toupper(roman[i]);

		if (i >= (MAX_ROMAN_STRLEN - 1)) {
			return -1;
		}
	}
	buffer[i] = '\0';

	// Check the digits are correct
	if (strcspn(buffer, g_digits) > 0) {
		return -1;
	}

	// Convert
	for (i = 0; buffer[i] != '\0';) {
		int j = 0;
		char* s = &buffer[i];

		for (j = 0; j < (sizeof(g_roman_to_decimal) / sizeof(struct roman_to_decimal)); j++) {
			if (strstr(s, g_roman_to_decimal[j].digits) == s) {
				n += g_roman_to_decimal[j].value;
				i += strlen(g_roman_to_decimal[j].digits);
				break;
			}
		}
	}

	// Range check the answer
	if ((n < MIN_ROMAN_VALUE) || (n > MAX_ROMAN_VALUE)) {
		return -1;
	}

	return n;
}

int decimal_to_roman(int n, char* roman, int length) {
	int i = 0;
	int p = 0;

	if (roman == NULL) {
		return -1;
	}

	if (length < 1) {
		return -1;
	}

	if ((n < MIN_ROMAN_VALUE) || (n > MAX_ROMAN_VALUE)) {
		return -1;
	}

	for(i = 0; i < ((sizeof(g_decimal_to_roman) / sizeof(struct decimal_to_roman))); ) {
		if (g_decimal_to_roman[i].value <= n) {
			int j = 0;

			for (j = 0; p < length && g_decimal_to_roman[i].digits[j] != '\0'; j++) {
				roman[p++] = g_decimal_to_roman[i].digits[j];

				if (p >= length) {
					return -1;
				}

				roman[p] = '\0';
			}

			n -= g_decimal_to_roman[i].value;

			if (n == 0) {
				break;
			}
		} else {
			i++;
		}
	}

	if (n != 0) {
		return -1;
	}

	return 0;
}

int roman_add(const char* num1, const char* num2, char* result, int length) {
	int n1 = 0;
	int n2 = 0;

	n1 = roman_to_decimal(num1);
	if (n1 <= 0) {
		return -1;
	}

	n2 = roman_to_decimal(num2);
	if (n2 <= 0) {
		return -1;
	}

	return decimal_to_roman(n1 + n2, result, length);
}

int roman_subtract(const char* num1, const char* num2, char* result, int length) {
	int n1 = 0;
	int n2 = 0;

	n1 = roman_to_decimal(num1);
	if (n1 <= 0) {
		return -1;
	}

	n2 = roman_to_decimal(num2);
	if (n2 <= 0) {
		return -1;
	}

	return decimal_to_roman(n1 - n2, result, length);
}

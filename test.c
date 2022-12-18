#include "mod11.h"
#include <stdio.h>
#include <stdbool.h>

#define OK " \033[32mOK\033[0m\n"
#define FAIL " \033[31mFAIL\033[0m\n"

#define test_gen_long(inp, expected) \
	printf("TESTING: generate_account_number(%zu) == %zu", inp, expected); \
	if(generate_account_number(inp) == expected) printf(OK); else {printf(FAIL); result++;}

#define test_check_long(inp, expected) \
    printf("TESTING: validate_num(%zu) == %5s", inp, expected ? "true" : "false"); \
    if(validate_num(inp) == expected) printf(OK); else {printf(FAIL); result++;}

#define test_gen_str(inp, expected) \
    printf("TESTING: generate_check_digit(%s) == %c", inp, expected); \
    if(generate_check_digit(inp) == expected) printf(OK); else {printf(FAIL); result++;}


#define test_check_str(inp, expected) \
    printf("TESTING: validate_str(%s) == %5s", inp, expected ? "true" : "false"); \
    if(validate_str(inp) == expected) printf(OK); else {printf(FAIL); result++;}



static int result = 0;

int main(void)
{
	test_gen_long(1234567l, 12345674l)
	test_gen_long(3344556l, 33445563l)
	test_gen_long(7531642l, 75316429l)

    test_check_long(12345674l, true)
    test_check_long(33445563l, true)
    test_check_long(75316429l, true)

    test_check_long(12345673l, false)
    test_check_long(33445562l, false)
    test_check_long(75316428l, false)

    test_gen_str("1234567", '4')
    test_gen_str("3344556", '3')
    test_gen_str("7531642", '9')

    test_check_str("12345674", true)
    test_check_str("33445563", true)
    test_check_str("75316429", true)

    test_check_str("12345673", false)
    test_check_str("33445562", false)
    test_check_str("75316428", false)

    return result;
}

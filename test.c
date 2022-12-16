#include "mod11.h"
#include <stdio.h>
#include <stdbool.h>

#define OK " \033[32mOK\033[0m\n"
#define FAIL " \033[31mFAIL\033[0m\n"

#define test_gen(inp, expected) \
	printf("TESTING: generate_account_number(%zu) == %zu", inp, expected); \
	if(generate_account_number(inp) == expected) printf(OK); else {printf(FAIL); result++;}

#define test_check(inp, expected) \
    printf("TESTING: validate_num(%zu) == %5s", inp, expected ? "true" : "false"); \
    if(validate_num(inp) == expected) printf(OK); else {printf(FAIL); result++;}

static int result = 0;

int main(void)
{
	test_gen(1234567l, 12345674l)
	test_gen(3344556l, 33445563l)
	test_gen(7531642l, 75316429l)

    test_check(12345674l, true)
    test_check(33445563l, true)
    test_check(75316429l, true)

    test_check(12345673l, false)
    test_check(33445562l, false)
    test_check(75316428l, false)

    return result;
}

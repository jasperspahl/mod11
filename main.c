#include "mod11.h"
#include <stdio.h>

int main(void)
{
    printf("Enter a number: ");
    long input;
    scanf("%zu", &input);
    long result = generate_account_number(input);
    printf("Result: %zu", result);

    if (validate_num(result))
        printf(" Valid");
    else
    {
        printf(" Invalid");
    }

	return 0;
}

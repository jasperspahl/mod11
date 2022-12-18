#include "mod11.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
    if(argc != 2) {
        printf("Usage: %s [l|c]", argv[0]);
        exit(1);
    }
    if(argv[1][0] == 'l') {
        long input;
        printf("Enter a number: ");
        scanf("%ld", &input);
        long result = generate_account_number(input);
        printf("The generated number is: %ld", generate_account_number(input));
        if (validate_num(result))
            printf(" Valid");
        else
        {
            printf(" Invalid");
        }
    } else if(argv[1][0] == 'c') {
        char *input = malloc(30);
        printf("Enter a number: ");
        scanf("%s", input);
        char *result = malloc(strlen(input) + 2);
        sprintf(result, "%s%c", input, generate_check_digit(input));
        printf("The generated number is: %s", result);
        if (validate_str(result))
            printf(" Valid");
        else
        {
            printf(" Invalid");
        }
        free(input);
        free(result);
    } else {
        printf("Usage: %s [l|c]", argv[0]);
        exit(1);
    }

	return 0;
}

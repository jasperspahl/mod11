#include "mod11.h"
#include <string.h>
#include <stdlib.h>

long generate_account_number(long input)
{
	long temp = input;
	int i = 0;
	long res = 0;
	while(temp > 0)
	{
        long factor = i % 6 + 2;
        long ziffer = temp % 10;
        res += ziffer * factor;
		temp /= 10;
		i++;
	}
	res = res % 11;
	res = 11 - res;
	if (res == 11 || res == 0)
        // 1234567 -> 12345670
		return input*10;
    // 1234567 -> 1234567*10 + 4
	return input*10 + res;
}

char generate_check_digit(char* input)
{
    long temp = 0;
    int i = 0;
    while(input[i] != '\0')
    {
        unsigned long factor = (strlen(input) - 1 - i) % 6 + 2;
        long ziffer = input[i] - '0';
        temp += ziffer * factor;
        i++;
    }
    temp = temp % 11;
    temp = 11 - temp;
    if (temp == 11 || temp == 0)
        return '0';
    return temp + '0';
}

bool validate_num(long input)
{
    long check = input % 10;
    long res = generate_account_number(input / 10);
    return res % 10 == check;
}

bool validate_str(char* input)
{
    char check = input[strlen(input) - 1];
    char *temp = malloc(strlen(input));
    stpncpy(temp, input, strlen(input) - 1);
    char res = generate_check_digit(temp);
    free(temp);
    return res == check;
}
#include "mod11.h"

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
		return input*10;
	return input*10 + res;
}

bool validate_num(long input)
{
    long check = input % 10;
    long res = generate_account_number(input / 10);
    if (res % 10 == check)
        return true;
    return false;
}
#ifndef MOD_11_H
#define MOD_11_H
#include <stdbool.h>

long generate_account_number(long input);

char generate_check_digit(char* input);

bool validate_num(long input);
bool validate_str(char* input);
#endif // MOD_11_H

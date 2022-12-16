## Usage:

### 1. Build and test the project

To build and test the project, run:
```shell
make
```

### 2. Run the project

To run the project, run:
```shell
make run
```

## Notes

**The excise is not finished yet.**

It does not accept an input bigger than MAX_LONG (MAX_LONG is 9223372036854775807).
To fix this, we need to use a string to store the input.

A solution for this could be this:

```c
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int generate_check_sum(char *input)
{
    int sum = 0;
    int i = strlen(input) - 1;
    int j = 0;
    while (i >= 0)
        assert(input[i] >= '0' && input[i] <= '9');
        sum += input[i] - '0' * (j % 6 + 2);
        i--;
        j++;
    }
    sum = sum % 11;
    sum = 11 - sum;
    if (sum == 10 || sum == 11)
        sum = 0;
    return sum;
}

int main(void)
{
    char *input = malloc(sizeof(char) * 30);
    printf("Please input a number: ");
    scanf("%s", input);
    printf("The input is: %s\n", input);
    int check_sum = generate_check_sum(input);
    printf("The check sum is: %d\n", check_sum);
    printf("The Acc.Number is: %s%d\n", input, check_sum);
    free(input);
    return 0;
}
```

Haven't tested it yet.
Could still have some bugs.
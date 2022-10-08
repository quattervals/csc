
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

void helloHal(void)
{
    printf("Hi from Hal 1\n");
}

bool hal_1_setupOk(void)
{
    // check configuration
    // ...
    return false;
}

int hal_1_hal_mult(int a, int b)
{
    return a * b;
}

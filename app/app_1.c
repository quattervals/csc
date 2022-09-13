
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "hal_1.h"


int helloApp(void)
{
    printf("Hi from app 1\n");

    helloHal();
}

int app_add(int a, int b)
{
    return a + b;
}

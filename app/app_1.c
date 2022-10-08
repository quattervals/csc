
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

int app_do_calc_using_dep(int a, int b)
{
    if (hal_1_setupOk())
    {
        return hal_1_hal_mult(a, b);
    }
    else
    {
        return app_add(a, b);
    }
}

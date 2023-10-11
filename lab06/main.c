#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include <math.h>
#include "lab06.h"

int main(int argc, const char *argv[])
{
    if (argc < 2)
    {
        printf("Your programm must start with: %s <EPSILON>\n", argv[0]);
        exit(1);
    }
    double epsilon = atof(argv[1]); // Заданная точность
    long double integral_a, integral_b, integral_c, integral_d;
    switch (midpoint_rule_with_precision(a_function, &integral_a, 0, 1, epsilon))
    {
    case OK:
        printf("Result for a_function: %Lf\n", integral_a);
        break;
    case INVALID_PARAMETER:
        printf("Invalid parameter detected!!!\n");
        break;
    case CODE_OVERFLOW:
        printf("Overflow detected!!!\n");
        break;
    }
    switch (midpoint_rule_with_precision(b_function, &integral_b, 0, 1, epsilon))
    {
    case OK:
        printf("Result for b_function: %Lf\n", integral_b);
        break;
    case INVALID_PARAMETER:
        printf("Invalid parameter detected!!!\n");
        break;
    case CODE_OVERFLOW:
        printf("Overflow detected!!!\n");
        break;
    }
    switch (midpoint_rule_with_precision(c_function, &integral_c, 0, 1, epsilon))
    {
    case OK:
        printf("Result for c_function: %Lf\n", integral_c);
        break;
    case INVALID_PARAMETER:
        printf("Invalid parameter detected!!!\n");
        break;
    case CODE_OVERFLOW:
        printf("Overflow detected!!!\n");
        break;
    }
    switch (midpoint_rule_with_precision(d_function, &integral_d, 0, 1, epsilon))
    {
    case OK:
        printf("Result for d_function: %Lf\n", integral_d);
        break;
    case INVALID_PARAMETER:
        printf("Invalid parameter detected!!!\n");
        break;
    case CODE_OVERFLOW:
        printf("Overflow detected!!!\n");
        break;
    }

    return 0;
}
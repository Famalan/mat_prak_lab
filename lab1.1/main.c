#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

enum factorial_status_code
{
    FACTORIAL_OK,
    FACTORIAL_OVERFLOW,
    FACTORIAL_INVALID_PARAMETER
};

enum is_simple_status_code
{
    ISSC_YES,
    ISSC_NO,
    ISSC_INVALID_PARAMETER
};

enum range_sum_status_code
{
    RSSC_OK,
    RSSC_OVERFLOW,
    RSSC_INVALID_PARAMETER
};

enum factorial_status_code factorial(int num, long *result)
{
    if (num < 0)
    {
        return FACTORIAL_INVALID_PARAMETER;
    }
    if (num == 0 || num == 1)
    {
        *result = 1;
        return FACTORIAL_OK;
    }
    *result = 1;
    long previous = 1;
    for (int i = 2; i <= num; ++i)
    {
        *result *= i;
        if (*result < previous)
        {
            return FACTORIAL_OVERFLOW;
        }
        previous = *result;
    }
    return FACTORIAL_OK;
}

enum is_simple_status_code is_simple(int num)
{
    if (num <= 1)
    {
        return ISSC_INVALID_PARAMETER;
    }
    if (num == 2)
    {
        return ISSC_YES;
    }
    for (int i = 2; i * i <= num; ++i)
    {
        if (num % i == 0)
            return ISSC_NO;
    }
    return ISSC_YES;
}

void split_num(const char *num_str)
{
    if (num_str[0] == '0' && num_str[1] == '\0')
    {
        printf("0\n");
        return;
    }

    int i = 0;
    while (num_str[i] == '0')
        ++i;
    if (num_str[0] == '-')
        ++i;

    for (int j = i; j < strlen(num_str); ++j)
    {
        printf("%c ", num_str[j]);
    }
    printf("\n");
}

enum range_sum_status_code range_sum(int num, long *result)
{
    if (num <= 0)
        return RSSC_INVALID_PARAMETER;
    double a = num * 0.5 + 0.5;
    long b = num;
    if (a > LONG_MAX / b)
    {
        return RSSC_OVERFLOW;
    }
    *result = a * b;
    return RSSC_OK;
}

void multiples_nums(int num, bool *is_found)
{
    *is_found = false;
    for (int i = num; i <= 100; i += num)
    {
        *is_found = true;
        printf("%d ", i);
    }
    if (*is_found)
        printf("\n");
}

void degree_table(int num)
{
    for (int base = 1; base <= 10; ++base)
    {
        long long result = 1;
        for (int degree = 1; degree <= num; ++degree)
        {
            result *= base;
            printf("%11lld ", result);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    if (argc > 3)
    {
        printf("invalid number of arguments detected!\n");
        return 1;
    }

    for (int i = 0; i < strlen(argv[2]); ++i)
    {
        if (i == 0 && argv[2][0] == '-')
            continue;
        if ((int)argv[2][i] < 48 || (int)argv[2][i] > 57)
        {
            printf("argument must have int type!\n");
            return 1;
        }
    }

    if ((argv[1][0] != '/' && argv[1][0] != '-') || strlen(argv[1]) != 2)
    {
        printf("invalid flag detected!\n");
        return 1;
    }

    int input_num = atoi(argv[2]);

    long result;
    bool is_found;

    switch (argv[1][1])
    {
    case 'e':
        if (input_num > 10 || input_num < 1)
        {
            printf("invalid parameter detected!\n");
            break;
        }
        degree_table(input_num);
        break;

    case 'h':
        if (input_num <= 0)
        {
            printf("invalid parameter detected!\n");
            break;
        }
        multiples_nums(input_num, &is_found);
        if (!is_found)
        {
            printf("no numbers found\n");
        }
        break;

    case 'a':
        switch (range_sum(input_num, &result))
        {
        case RSSC_OK:
            printf("%ld\n", result);
            break;
        case RSSC_OVERFLOW:
            printf("overflow detected!\n");
            break;
        case RSSC_INVALID_PARAMETER:
            printf("invalid parameter detected!\n");
            break;
        }
        break;

    case 's':
        split_num(argv[2]);
        break;

    case 'p':
        switch (is_simple(input_num))
        {
        case ISSC_YES:
            printf("%d is simple\n", input_num);
            break;
        case ISSC_NO:
            printf("%d is composite\n", input_num);
            break;
        case ISSC_INVALID_PARAMETER:
            printf("invalid parameter detected!\n");
            break;
        }
        break;

    case 'f':
        switch (factorial(input_num, &result))
        {
        case FACTORIAL_OK:
            printf("%d! = %ld\n", input_num, result);
            break;
        case FACTORIAL_OVERFLOW:
            printf("overflow detected!\n");
            break;
        case FACTORIAL_INVALID_PARAMETER:
            printf("invalid parameter detected!\n");
            break;
        }
        break;

    default:
        printf("unknown flag detected!\n");
        break;
    }

    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

enum FactorialStatusCode
{
    FACTORIAL_OK,
    FACTORIAL_OVERFLOW,
    FACTORIAL_INVALID_PARAMETER
};

enum PrimeCheckStatusCode
{
    PRIME_YES,
    PRIME_NO,
    PRIME_INVALID_PARAMETER
};

enum RangeSumStatusCode
{
    RANGESUM_OK,
    RANGESUM_OVERFLOW,
    RANGESUM_INVALID_PARAMETER
};

enum FactorialStatusCode factorial(int number, long *factorial_result)
{
    if (number < 0)
    {
        return FACTORIAL_INVALID_PARAMETER;
    }
    if (number == 0 || number == 1)
    {
        *factorial_result = 1;
        return FACTORIAL_OK;
    }
    *factorial_result = 1;
    long previous_result = 1;
    for (int multiple = 2; multiple <= number; ++multiple)
    {
        *factorial_result *= multiple;
        if (*factorial_result < previous_result)
        {
            return FACTORIAL_OVERFLOW;
        }
        previous_result = *factorial_result;
    }
    return FACTORIAL_OK;
}

enum PrimeCheckStatusCode is_simple(int number)
{
    if (number <= 1)
    {
        return PRIME_INVALID_PARAMETER;
    }
    if (number == 2)
    {
        return PRIME_YES;
    }
    for (int multiple = 2; multiple * multiple <= number; ++multiple)
    {
        if (number % multiple == 0)
            return PRIME_NO;
    }
    return PRIME_YES;
}

void split_num(const char *number_string)
{
    if (number_string[0] == '0' && number_string[1] == '\0')
    {
        printf("0\n");
        return;
    }

    int leading_zeros_index = 0;
    while (number_string[leading_zeros_index] == '0')
        ++leading_zeros_index;
    if (number_string[0] == '-')
        ++leading_zeros_index;

    for (int digit_index = leading_zeros_index; digit_index < strlen(number_string); ++digit_index)
    {
        printf("%c ", number_string[digit_index]);
    }
    printf("\n");
}

enum RangeSumStatusCode range_sum(int number, long *factorial_result)
{
    if (number <= 0)
        return RANGESUM_INVALID_PARAMETER;
    double half_plus_half = number * 0.5 + 0.5;
    long range_end = number;
    if (half_plus_half > LONG_MAX / range_end)
    {
        return RANGESUM_OVERFLOW;
    }
    *factorial_result = half_plus_half * range_end;
    return RANGESUM_OK;
}

void multiples_nums(int number, bool *multiples_found)
{
    *multiples_found = false;
    for (int multiple = number; multiple <= 100; multiple += number)
    {
        *multiples_found = true;
        printf("%d ", multiple);
    }
    if (*multiples_found)
        printf("\n");
}

void degree_table(int number)
{
    for (int degree_base = 1; degree_base <= 10; ++degree_base)
    {
        long long multiple = 1;
        for (int degree = 1; degree <= number; ++degree)
        {
            multiple *= degree_base;
            printf("%11lld ", multiple);
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

    for (int leading_zeros_index = 0; leading_zeros_index < strlen(argv[2]); ++leading_zeros_index)
    {
        if (leading_zeros_index == 0 && argv[2][0] == '-')
            continue;
        if ((int)argv[2][leading_zeros_index] < 48 || (int)argv[2][leading_zeros_index] > 57)
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

    long factorial_result;
    bool multiples_found;

    switch (argv[1][1])
    {
    case 'e':
        if (input_num > 10 || input_num < 1)
        {
            printf("invalid parametr detected!\n");
            break;
        }
        degree_table(input_num);
        break;

    case 'h':
        if (input_num <= 0)
        {
            printf("invalid parametr detected!\n");
            break;
        }
        multiples_nums(input_num, &multiples_found);
        if (!multiples_found)
        {
            printf("no numbers found\n");
        }
        break;

    case 'half_plus_half':
        switch (range_sum(input_num, &factorial_result))
        {
        case RANGESUM_OK:
            printf("%ld\n", factorial_result);
            break;
        case RANGESUM_OVERFLOW:
            printf("overflow detected!\n");
            break;
        case RANGESUM_INVALID_PARAMETER:
            printf("invalid parametr detected!\n");
            break;
        }
        break;

    case 's':
        split_num(argv[2]);
        break;

    case 'p':
        switch (is_simple(input_num))
        {
        case PRIME_YES:
            printf("%d is simple\n", input_num);
            break;
        case PRIME_NO:
            printf("%d is composite\n", input_num);
            break;
        case PRIME_INVALID_PARAMETER:
            printf("invalid parametr detected!\n");
            break;
        }
        break;

    case 'f':
        switch (factorial(input_num, &factorial_result))
        {
        case FACTORIAL_OK:
            printf("%d! = %ld\n", input_num, factorial_result);
            break;
        case FACTORIAL_OVERFLOW:
            printf("overflow detected!\n");
            break;
        case FACTORIAL_INVALID_PARAMETER:
            printf("invalid parametr detected!\n");
            break;
        }
        break;

    default:
        printf("unknown flag detected!\n");
        break;
    }

    return 0;
}
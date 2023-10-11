#include "lab01.h"

status_code h_function(int number)
{
    if (number < 0)
    {
        return INVALID_PARAMETER;
    }
    if (number == 0 || number > 100)
    {
        return INVALID_PARAMETER;
    }
    for (int i = number; i <= 100; i += number)
    {
        printf("%d ", i);
    }
    return OK;
}

status_code p_function(int number, bool *result)
{
    if (number == 0 || number == 1 || number < 0)
    {
        *result = false;
        return INVALID_PARAMETER;
    }
    int count_digits = 2;
    for (int i = 2; i * i <= number; ++i)
    {
        if (number % i == 0)
        {
            count_digits++;
            if (i != number / i)
            {
                count_digits++;
            }
        }
    }
    if (count_digits == 2)
    {
        *result = true;
        return OK;
    }
    else
    {
        *result = false;
        return OK;
    }
}

status_code e_function(int number_pow)
{
    if (number_pow > 10)
    {
        return INVALID_PARAMETER;
    }
    if (number_pow <= 0)
    {
        return INVALID_PARAMETER;
    }
    int arr[10][10];
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= number_pow; j++)
        {
            arr[i - 1][j - 1] = pow(i, j);
        }
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < number_pow; j++)
        {
            printf("%d ^ %d = %d\n", i + 1, j + 1, arr[i][j]);
        }
        printf("\n");
    }
    return OK;
}
status_code a_function(int number, int *result)
{
    if (number == 0)
    {
        result = NULL;
        return INVALID_PARAMETER;
    }
    /* S_n = (2 + (n - 1)) * (n / 2)*/
    int right_factor = number / 2;
    int left_factor = 2 + number - 1;

    {
        result = NULL;
        return CODE_OVERFLOW;
    }
    *result = left_factor * right_factor;
    return OK;
}

status_code f_function(int number, long *res)
{
    if (number < 0)
    {
        // res = NULL;
        return INVALID_PARAMETER;
    }
    if (number == 0 || number == 1)
    {
        *res = 1;
        return OK;
    }
    long prev_res = 1;
    *res = 1;
    for (int i = 2; i <= number; i++)
    {
        *res *= i;
        if (*res < prev_res)
        {
            return CODE_OVERFLOW;
        }
        prev_res = *res;
    }
    return OK;
}

void s_function(const char *number)
{
    int length = strlen(number);
    if (length == 1)
    {
        printf("%s\n", number);
        return;
    }
    int last_index = length - 1;
    while (last_index >= 0 && number[last_index] == '0')
    {
        last_index--;
    }
    for (int i = 0; i <= last_index; i++)
    {
        printf("%c", number[i]);
        if (i != last_index)
        {
            printf(" ");
        }
    }

    printf("\n");
}
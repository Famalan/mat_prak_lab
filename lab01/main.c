#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include "lab01.h"

int main(int argc, const char *argv[])
{
    if (argc != 3)
    {
        printf("Запустите программу следующим образом: %s <ФЛАГ> <ЧИСЛО>\n", argv[0]);
        exit(1);
    }

    int number = atoi(argv[2]);

    if (argv[1][0] != '/' && argv[1][0] != '-')
    {
        printf("Флаг должен начинаться с символа '-' или '/'!\n");
        exit(1);
    }

    char flag = argv[1][1];
    bool result;
    int number_pow;
    int result_progression;
    long result_fact;

    switch (flag)
    {
    case 'h':
        if (h_function(number) == INVALID_PARAMETER)
            printf("Обнаружен неверный параметр!\n");
        break;

    case 'p':
        if (p_function(number, &result) == OK)
            printf(result ? "Ваше число простое\n" : "Ваше число составное\n");
        else
            printf("Обнаружен неверный параметр!\n");
        break;

    case 's':
        s_function(argv[2]);
        break;

    case 'e':
        printf("Введите число для возведения в степень %d\n", number_pow);
        scanf("%d", &number_pow);
        if (e_function(number_pow) != OK)
            printf("Обнаружена ошибка!\n");
        break;

    case 'a':
        if (a_function(number, &result_progression) == OK)
            printf("Результат: %d\n", result_progression);
        else
            printf("Обнаружен неверный параметр!\n");
        break;

    case 'f':
        if (f_function(number, &result_fact) == OK)
            printf("Результат: %ld\n", result_fact);
        else
            printf("Обнаружен неверный параметр!\n");
        break;

    default:
        printf("Неизвестный флаг!\n");
    }

    return 0;
}

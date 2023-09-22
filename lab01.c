#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// вывести в консоль натуральные числа в пределах 100 включительно, кратные
// указанному. Если таковых нету – вывести соответствующее сообщение;
void function_h(long long number)
{
    if (number > 100 || number <= 0)
    {
        printf("function_h: error invalid number\n");
        return;
    }
    for (int natural_number = 1; natural_number <= 100; natural_number++)
    {
        if (natural_number % number == 0)
        {
            printf("%d ", natural_number);
        }
    }
};

// определить является ли введенное число простым; является ли оно составным;
int function_p(long long number)
{
    if (number <= 1)
    {
        printf("function_p: error invalid number\n");
        return 0;
    };
    for (int prime_number = 2; prime_number * prime_number <= number; prime_number++)
    {
        if (number % prime_number == 0)
        {
            printf("%d - составное число\n", number);
            return 0;
        }
        else
        {
            printf("%d - простое число\n", number);
            return 0;
        }
    }
};

// разделить число на отдельные цифры и вывести отдельно каждую цифру числа,
// разделяя их пробелом, от старших разрядов к младшим, без ведущих нулей в
// строковом представлении;
void function_s(long long number)
{
}

// вывести таблицу степеней (для всех показателей в диапазоне от 1 до заданного
// числа) оснований от 1 до 10; для этого флага работает ограничение на вводимое
// число: оно должно быть не больше 10;
void function_e(int x) {}

// вычислить сумму всех натуральных чисел от 1 до указанного числа
// включительно и вывести полученное значение в консоль;
int function_a(long long x) {}

// вычислить факториал указанного числа и вывести полученное значение в
// консоль.
int function_f(long long x) {}

int main(int argc, char **argv)
{

    for (int i = 1; i < argc; i++)
    {
        if (strlen(argv[i]) == 2 && (argv[i][0] == '/' || argv[i][0] == '-'))
        {
            switch (argv[i][1])
            {
            case 'h':
                function_h(18);
                break;
            case 'p':
                function_p(10);
                break;
            case 's':
                function_s(0123333);
                break;
            case 'e':
                function_e(0);
                break;
            case 'a':
                function_a(0);
                break;
            case 'f':
                function_f(0);
                break;
            default:
                break;
            };
        };
    }
}
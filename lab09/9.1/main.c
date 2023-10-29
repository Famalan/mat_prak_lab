#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lab09_1.h"

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Your programm must start with: %s <a> <b>\n", argv[0]);
        exit(1);
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    srand(time(NULL));
    int const size = 10;
    int arr[size];
    fill_array(arr, size, a, b);
    printf("Original array: ");
    print_array(arr, size);
    swap_min_max(arr, size);
    printf("Modified array: ");
    print_array(arr, size);
    return 0;
}
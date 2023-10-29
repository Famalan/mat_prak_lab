#ifndef lab_h
#define lab_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <string.h>

typedef enum
{
    OK,
    CODE_OVERFLOW,
    INVALID_PARAMETER
} status_code;

status_code f_function(int number, long *res);
status_code h_function(int number);
void s_function(const char *number);
status_code p_function(int number, bool *result);
status_code e_function(int number_pow);
status_code a_function(int number, int *result);
#endif
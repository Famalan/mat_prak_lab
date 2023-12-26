#ifndef lab_h
#define lab_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define EPS 10e-4

typedef enum status_code {
    OK,
    INVALID_PARAMETER,
    CODE_OVERFLOW
} status_code;

status_code a_function(double x, long double* result);
status_code b_function(double x, long double* result);
status_code c_function(double x, long double* result);
status_code d_function(double x, long double* result);
status_code midpoint_rule_with_precision(status_code function(double x, long double* res), long double* res, double a, double b, double epsilon);


#endif
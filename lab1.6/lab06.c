#include "lab06.h"

status_code a_function(double x, long double *result)
{
    if (x == 0 || x <= -1)
    {
        result = NULL;
        return INVALID_PARAMETER;
    }
    *result = log(1 + x) / x;
    return OK;
}

status_code b_function(double x, long double *result)
{
    *result = pow(exp(1), -x * x / 2);
    return OK;
}

status_code c_function(double x, long double *result)
{
    if (x >= 1)
    {
        result = NULL;
        return INVALID_PARAMETER;
    }
    *result = log(1 / (1 - x));
    return OK;
}

status_code d_function(double x, long double *result)
{
    *result = pow(x, x);
    return OK;
}

status_code midpoint_rule_with_precision(status_code function(double x, long double *res), long double *res, double a, double b, double epsilon)
{
    int number_intervals = 1;
    long double integral_prev = 0.0;
    long double integral = epsilon + 1.0;

    while (fabs(integral - integral_prev) > epsilon)
    {
        integral_prev = integral;
        double length_interval = (b - a) / number_intervals;
        integral = 0.0;

        for (int i = 0; i < number_intervals; ++i)
        {
            double x_midpoint = a + (i + 0.5) * length_interval;
            long double tmp_res;
            switch (function(x_midpoint, &tmp_res))
            {
            case INVALID_PARAMETER:
                res = NULL;
                return INVALID_PARAMETER;
            case OK:
                break;
            default:
                break;
            }
            integral += tmp_res;
            tmp_res = 0;
        }
        if (number_intervals > INT_MAX / 2)
        {
            return CODE_OVERFLOW;
        }
        integral *= length_interval;
        number_intervals *= 2;
    }
    *res = integral;
    return OK;
}
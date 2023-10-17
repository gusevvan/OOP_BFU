#include <iostream>
#include "integral_solver.h"

namespace igsr {

    answer IntegralCalculator::calc(double a, double b, double (*func)(double)) {
        answer result(0, _points, 0);
        return result;
    }

    answer SimpsonCalculator::calc(double a, double b, double (*func)(double)) {
        double int_value = 0;
        double step = (b - a) / _points;
        for (double x = a; x < b; x += step) {
            int_value += (step) / 6.0 * ((func)(x) + 4.0 * func(0.5 * (2 * x + step)) + func(x + step));
        }
        answer result(int_value, _points, step);
        return result;
    }

    answer TrapezoidCalculator::calc(double a, double b, double (*func)(double)) {
        double step = (b - a) / _points;
        double int_value = 0;
        for (double x = a; x < b; x += step) {
            int_value += 0.5 * (func(x) + func(x + step)) * step;
        }
        answer result(int_value, _points, step);
        return result;
    }

}


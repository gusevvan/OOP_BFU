#include <iostream>
#include <cmath>
#include "integral_solver.h"

double f(double x) {
    return cos(x);
}

int main() {
    igsr::TrapezoidCalculator* sample1 = new igsr::TrapezoidCalculator(1000);
    igsr::SimpsonCalculator* sample2 = new igsr::SimpsonCalculator(1000);
    std::cout << sample1->calc(0, 3, f) << "\n" << sample2->calc(0, 3, f);
}

#include <iostream>
#include "numc.h"

int main() {
    using namespace linalg;
    Array3d<int> x(2, 2, 2);
    x.fill(1);
    Array2d<int> z(2, 2);
    z.fill(2);
    x.setValues2d(0, 1, z);
    x.print();
    std::cout << "\n";
    Array2d<int>* y = x.getValues2d(1, 1);
    y->print();
}

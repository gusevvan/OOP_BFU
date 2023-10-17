#include <iostream>
#include "numc.h"

namespace ui {

    void UI() {
        //Функция, реализующая взаимодействие с пользователем.
        using namespace linalg;

        std::string command;
        while (command != "quite") {
            std::cout
                    << "Input command: (sum, prod, scalar_prod, vec_prod, mixed_prod, len, angle, norm, collinear, coplanar, minus, compare, quit)\n";
            std::cin >> command;
            if (command == "sum") {
                std::cout << "Input 3 numbers (components first vector):\n";
                double x1, x2, x3;
                std::cin >> x1 >> x2 >> x3;
                std::cout << "Input 3 numbers (components second vector):\n";
                double y1, y2, y3;
                std::cin >> y1 >> y2 >> y3;
                Vector *vec1 = new Vector(x1, x2, x3);
                Vector *vec2 = new Vector(y1, y2, y3);
                std::cout << "Result: " << *vec1 + *vec2 << "\n";
                continue;
            }
            if (command == "prod") {
                std::cout << "Input 3 numbers (components vector):\n";
                double x1, x2, x3;
                std::cin >> x1 >> x2 >> x3;
                std::cout << "Input number (multiplication factor):\n";
                double k;
                std::cin >> k;
                Vector *vec = new Vector(x1, x2, x3);
                std::cout << "Result: " << *vec * k << "\n";
                continue;
            }
            if (command == "scalar_prod") {
                std::cout << "Input 3 numbers (components first vector):\n";
                double x1, x2, x3;
                std::cin >> x1 >> x2 >> x3;
                std::cout << "Input 3 numbers (components second vector):\n";
                double y1, y2, y3;
                std::cin >> y1 >> y2 >> y3;
                Vector *vec1 = new Vector(x1, x2, x3);
                Vector *vec2 = new Vector(y1, y2, y3);
                std::cout << "Result: " << *vec1 * *vec2 << "\n";
                continue;
            }
            if (command == "vec_prod") {
                std::cout << "Input 3 numbers (components first vector):\n";
                double x1, x2, x3;
                std::cin >> x1 >> x2 >> x3;
                std::cout << "Input 3 numbers (components second vector):\n";
                double y1, y2, y3;
                std::cin >> y1 >> y2 >> y3;
                Vector *vec1 = new Vector(x1, x2, x3);
                Vector *vec2 = new Vector(y1, y2, y3);
                std::cout << "Result: " << vec1->vec_prod(*vec2) << "\n";
                continue;
            }
            if (command == "mixed_prod") {
                std::cout << "Input 3 numbers (components first vector):\n";
                double x1, x2, x3;
                std::cin >> x1 >> x2 >> x3;
                std::cout << "Input 3 numbers (components second vector):\n";
                double y1, y2, y3;
                std::cin >> y1 >> y2 >> y3;
                std::cout << "Input 3 numbers (components third vector):\n";
                double z1, z2, z3;
                std::cin >> z1 >> z2 >> z3;
                Vector *vec1 = new Vector(x1, x2, x3);
                Vector *vec2 = new Vector(y1, y2, y3);
                Vector *vec3 = new Vector(z1, z2, z3);
                std::cout << "Result: " << vec1->mixed_prod(*vec2, *vec3) << "\n";
                continue;
            }
            if (command == "len") {
                std::cout << "Input 3 numbers (components vector):\n";
                double x1, x2, x3;
                std::cin >> x1 >> x2 >> x3;
                Vector *vec = new Vector(x1, x2, x3);
                std::cout << "Result: " << vec->len() << "\n";
                continue;
            }
            if (command == "angle") {
                std::cout << "Input 3 numbers (components first vector):\n";
                double x1, x2, x3;
                std::cin >> x1 >> x2 >> x3;
                std::cout << "Input 3 numbers (components second vector):\n";
                double y1, y2, y3;
                std::cin >> y1 >> y2 >> y3;
                Vector *vec1 = new Vector(x1, x2, x3);
                Vector *vec2 = new Vector(y1, y2, y3);
                std::cout << "Result: " << vec1->angle(*vec2) << "\n";
                continue;
            }
            if (command == "norm") {
                std::cout << "Input 3 numbers (components vector):\n";
                double x1, x2, x3;
                std::cin >> x1 >> x2 >> x3;
                Vector *vec = new Vector(x1, x2, x3);
                vec->to_norm();
                std::cout << "Result: " << *vec << "\n";
                continue;
            }
            if (command == "collinear") {
                std::cout << "Input 3 numbers (components first vector):\n";
                double x1, x2, x3;
                std::cin >> x1 >> x2 >> x3;
                std::cout << "Input 3 numbers (components second vector):\n";
                double y1, y2, y3;
                std::cin >> y1 >> y2 >> y3;
                Vector *vec1 = new Vector(x1, x2, x3);
                Vector *vec2 = new Vector(y1, y2, y3);
                std::cout << (vec1->is_collinear(*vec2) ? "True" : "False") << "\n";
                continue;
            }
            if (command == "coplanar") {
                std::cout << "Input 3 numbers (components first vector):\n";
                double x1, x2, x3;
                std::cin >> x1 >> x2 >> x3;
                std::cout << "Input 3 numbers (components second vector):\n";
                double y1, y2, y3;
                std::cin >> y1 >> y2 >> y3;
                std::cout << "Input 3 numbers (components third vector):\n";
                double z1, z2, z3;
                std::cin >> z1 >> z2 >> z3;
                Vector *vec1 = new Vector(x1, x2, x3);
                Vector *vec2 = new Vector(y1, y2, y3);
                Vector *vec3 = new Vector(z1, z2, z3);
                std::cout << (vec1->is_coplanar(*vec2, *vec3) ? "True" : "False") << "\n";
                continue;
            }
            if (command == "minus") {
                std::cout << "Input 3 numbers (components vector):\n";
                double x1, x2, x3;
                std::cin >> x1 >> x2 >> x3;
                Vector *vec = new Vector(x1, x2, x3);
                std::cout << "Result: " << -*vec << "\n";
                continue;
            }
            if (command == "compare") {
                std::cout << "Input 3 numbers (components first vector):\n";
                double x1, x2, x3;
                std::cin >> x1 >> x2 >> x3;
                std::cout << "Input 3 numbers (components second vector):\n";
                double y1, y2, y3;
                std::cin >> y1 >> y2 >> y3;
                Vector *vec1 = new Vector(x1, x2, x3);
                Vector *vec2 = new Vector(y1, y2, y3);
                if (*vec1 < *vec2) {
                    std::cout << "<\n";
                }
                if (*vec1 > *vec2) {
                    std::cout << ">\n";
                }
                if (*vec1 == *vec2) {
                    std::cout << "=\n";
                }
                continue;
            }
            if (command == "quit") {
                break;
            }
            std::cout << "unknown command, try again\n";
        }
    }
}

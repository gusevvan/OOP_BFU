#pragma once

namespace igsr {
    struct answer {
        // Структура, для хранения результата вычисления интеграла.
        // Хранит в себе значение интеграла int_value,
        // шаг, используемый при вычислении интеграла step
        // и количество точек в разбиении при вычислении интеграла points.
        double int_value, step;
        int points;
        answer(double value1, int value2, double value3): int_value{value1}, points{value2}, step{value3} {}
        friend std::ostream& operator<<(std::ostream &os, const answer& data) {
            return os << "Integral value: " << data.int_value << " || Number points: "
                            << data.points << " || Step value: " << data.step;
        }
    };

    class IntegralCalculator {
        // Базовый класс, который и будет оберткой для вычисления интегралов.
        // _points - количество точек в разбиении
        // calc - метод для вычисления интеграла от заданной функции func
        // на отрезке [a,b].
    protected:
        int _points;
    public:
        IntegralCalculator(int points): _points{points} {}
        virtual answer calc(double a, double b, double (*func)(double));
    };

    class SimpsonCalculator : public IntegralCalculator {
        // Класс, реализующий метод Симпсона.
    public:
        SimpsonCalculator(int points) : IntegralCalculator(points) {};
        answer calc(double a, double b, double (*func)(double)) override;
    };

    class TrapezoidCalculator : public IntegralCalculator {
        // Класс, реализующий метод трапеции.
    public:
        TrapezoidCalculator(int points) : IntegralCalculator(points) {};
        answer calc(double a, double b, double (*func)(double)) override;
    };

}


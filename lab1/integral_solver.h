#pragma once

namespace igsr {
    struct answer {
        double int_value, step;
        int points;
        answer(double value1, int value2, double value3): int_value{value1}, points{value2}, step{value3} {}
        friend std::ostream& operator<<(std::ostream &os, const answer& data) {
            return os << "Integral value: " << data.int_value << " || Number points: "
                            << data.points << " || Step value: " << data.step;
        }
    };

    class IntegralCalculator {
    protected:
        int _points;
    public:
        IntegralCalculator(int points): _points{points} {}
        virtual answer calc(double a, double b, double (*func)(double));
    };

    class SimpsonCalculator : public IntegralCalculator {
    public:
        SimpsonCalculator(int points) : IntegralCalculator(points) {};
        answer calc(double a, double b, double (*func)(double)) override;
    };

    class TrapezoidCalculator : public IntegralCalculator {
    public:
        TrapezoidCalculator(int points) : IntegralCalculator(points) {};
        answer calc(double a, double b, double (*func)(double)) override;
    };

}


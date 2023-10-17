#pragma once

namespace linalg {
    struct Point{
        // Структура, реализующая точку в пространстве.
        double x, y, z;
        void set_x(double new_x);
        void set_y(double new_y);
        void set_z(double new_z);
        double get_x() const;
        double get_y() const;
        double get_z() const;
    };

    class Vector {
        //Класс вектор.
        //Методы:
        //vec_prod для вычисления векторного произведения.
        //mixed_prod для вычисления смешанного произведения.
        //len для вычисления длины вектора.
        //is_collinear проверка двух векторов на коллинеарность.
        //is_complanar проверка трех векторов на компланарность.
        //to_norm нормирование вектора.
    private:
        double _x, _y, _z;
    public:
        Vector(const Point& first, const Point& second);
        Vector(double x, double y, double z): _x(x), _y(y), _z(z) {};
        Vector operator+(const Vector& vec);
        Vector operator-(const Vector& vec);
        Vector operator*(const double num);
        double operator*(const Vector& vec) const;
        Vector vec_prod(const Vector& vec) const;
        double mixed_prod(const Vector& vec1, const Vector& vec2) const;
        double len() const;
        double operator<(const Vector& vec);
        double operator>(const Vector& vec);
        double operator==(const Vector& vec);
        bool is_collinear(const Vector& vec) const;
        bool is_coplanar(const Vector& vec1, const Vector& vec2) const;
        double angle(const Vector& vec) const;
        void to_norm();
        Vector operator-() const;
        void set_x(double new_x);
        void set_y(double new_y);
        void set_z(double new_z);
        double get_x() const;
        double get_y() const;
        double get_z() const;

        friend std::ostream& operator<<(std::ostream &os, const Vector& vec) {
            return os << vec.get_x() << " " << vec.get_y() << " " << vec.get_z();
        }
    };
}
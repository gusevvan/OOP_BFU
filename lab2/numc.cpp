#include <iostream>
#include <cmath>
#include "numc.h"

namespace linalg {
    void Point::set_x(double new_x) {
        x = new_x;
    }
    void Point::set_y(double new_y)  {
        y = new_y;
    }
    void Point::set_z(double new_z) {
        z = new_z;
    }
    double Point::get_x() const {
        return x;
    }
    double Point::get_y() const {
        return y;
    }
    double Point::get_z() const {
        return z;
    }

    Vector::Vector(const Point &first, const Point &second)  {
        _x = second.get_x() - first.get_x();
        _y = second.get_y() - first.get_y();
        _z = second.get_z() - first.get_z();
    }

    Vector Vector::operator+(const Vector &vec)  {
        Vector* result = new Vector(this->_x + vec._x, this->_y + vec._y, this->_z + vec._z);
        return *result;
    }

    Vector Vector::operator-(const Vector &vec) {
        Vector* result = new Vector(this->_x - vec._x, this->_y - vec._y, this->_z - vec._z);
        return *result;
    }

    Vector Vector::operator*(const double num)  {
        Vector* result = new Vector(this->_x * num, this->_y * num, this->_z * num);
        return *result;
    }

    double Vector::operator*(const linalg::Vector &vec) const  {
        return this->_x * vec._x + this->_y * vec._y + this->_z * vec._z;
    }

    Vector Vector::vec_prod(const linalg::Vector &vec) const  {
        Vector* result = new Vector(this->_z * vec._y - this->_y * vec._z,
                                    this->_x * vec._z - this->_z * vec._x,
                                    this->_y * vec._x - this->_x * vec._y);
        return *result;
    }

    double Vector::mixed_prod(const linalg::Vector &vec1, const linalg::Vector &vec2) const  {
        return (this->_x * vec1._y * vec2._z + this->_y * vec1._z * vec2._x + this->_z * vec1._x * vec2._y -
                this->_z * vec1._y * vec2._x - this->_x * vec1._z * vec2._y - this->_y * vec1._x * vec2._y);
    }

    double Vector::len() const  {
        return std::sqrt(*this * *this);
    }

    double Vector::operator<(const Vector& vec) {
        return this->len() < vec.len();
    }

    double Vector::operator>(const Vector& vec) {
        return this->len() > vec.len();
    }

    double Vector::operator==(const Vector& vec) {
        return (this->_x == vec._x) & (this->_y == vec._y) & (this->_z == vec._z);
    }

    bool Vector::is_collinear(const Vector& vec) const {
        Vector* zero = new Vector(0, 0, 0);
        return vec_prod(vec) == *zero;
    }

    bool Vector::is_coplanar(const Vector& vec1, const Vector& vec2) const {
        return mixed_prod(vec1, vec2) == 0;
    }

    double Vector::angle(const Vector& vec) const {
        if (this->is_collinear(vec)) {
            return 0;
        } else {
            return std::acos((*this * vec) / vec.len() / this->len());
        }
    }

    void Vector::to_norm() {
        double norm = this->len();
        if (norm != 0) {
            _x = _x / norm;
            _y = _y / norm;
            _z = _z / norm;
        }
        return;
    }

    Vector Vector::operator-() const{
        Vector result = Vector(-this->_x, -this->_y, -this->_z);
        return result;
    }

    void Vector::set_x(double new_x) {
        _x = new_x;
    }
    void Vector::set_y(double new_y) {
        _y = new_y;
    }
    void Vector::set_z(double new_z) {
        _z = new_z;
    }

    double Vector::get_x() const {
        return _x;
    }
    double Vector::get_y() const {
        return _y;
    }
    double Vector::get_z() const {
        return _z;
    }
}

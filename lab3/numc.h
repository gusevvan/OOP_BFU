#pragma once

namespace linalg {

    template<class T>
    class Array2d {
    private:
        const int _dim1 = 0, _dim2 = 0;
        T *_storage;
    public:
        Array2d(int dim1, int dim2) : _dim1(dim1), _dim2(dim2) {
            _storage = new T[_dim1 * _dim2];
            for (int i = 0; i < _dim1; ++i) {
                for (int j = 0; j < _dim2; ++j) {
                    _storage[_dim1 * i + j] = 0;
                }
            }
        }

        void setValue(int i, int j, T value);
        T getValue(int i, int j) const;
        T* getValues1d(int index, int axis);
        void setValues1d(int index, int axis, T *arr);
        void fill(T value);
        void print() const;

        ~Array2d() {
            delete[] _storage;
        }
    };

    template<class T>
    class Array3d {
    private:
        const int _dim1 = 0, _dim2 = 0, _dim3 = 0;
        T *_storage;
    public:
        Array3d(int dim1, int dim2, int dim3) : _dim1(dim1), _dim2(dim2), _dim3(dim3) {
            _storage = new T[_dim1 * _dim2 * _dim3];
            for (int i = 0; i < _dim1; ++i) {
                for (int j = 0; j < _dim2; ++j) {
                    for (int k = 0; k < _dim3; ++k) {
                        _storage[_dim1 * i * j + j * _dim2 + k] = 0;
                    }
                }
            }
        }

        void setValue(int i, int j, int k, T value);
        T getValue(int i, int j, int k) const;
        Array2d<T>* getValues2d(int index, int axis) const;
        T *getValues1d(int index1, int index2, int axis1, int axis2) const;
        void setValues2d(int index, int axis, const Array2d<T> &arr2d);
        void setValues1d(int index1, int index2, int axis1, int axis2, T *arr1d);
        void fill(T value);
        void print() const;

        ~Array3d() {
            delete[] _storage;
        }
    };
}

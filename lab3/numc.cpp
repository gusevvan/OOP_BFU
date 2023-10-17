#include <iostream>
#include "numc.h"

namespace linalg {
    template<class T>
    void Array2d<T>::setValue(int i, int j, T value) {
        _storage[i * _dim1 + j] = value;
    }

    template<class T>
    T Array2d<T>::getValue(int i, int j) const  {
        return _storage[i * _dim1 + j];
    }

    template<class T>
    T* Array2d<T>::getValues1d(int index, int axis)  {
        if (axis == 0) {
            T* result = new T[_dim2];
            for (int i = 0; i < _dim2; ++i) {
                result[i] = _storage[index * _dim1 + i];
            }
            return result;
        } else {
            T* result = new T[_dim1];
            for (int i = 0; i < _dim1; ++i) {
                result[i] = _storage[i * _dim1 + index];
            }
            return result;
        }
    }

    template<class T>
    void Array2d<T>::setValues1d(int index, int axis, T *arr)  {
        if (axis == 0) {
            for (int i = 0; i < _dim2; ++i) {
                _storage[index * _dim1 + i] = arr[i];
            }
        } else {
            for (int i = 0; i < _dim1; ++i) {
                _storage[i * _dim1 + index] = arr[i];
            }
        }
    }

    template<class T>
    void Array2d<T>::fill(T value)  {
        for (int i = 0; i < _dim1; ++i) {
            for (int j = 0; j < _dim2; ++j) {
                this->setValue(i, j, value);
            }
        }
    }

    template<class T>
    void Array2d<T>::print() const {
        for (int i = 0; i < _dim1; ++i) {
            std::cout << "[";
            for (int j = 0; j < _dim2; ++j) {
                std::cout << getValue(i, j) << " ";
            }
            std::cout << "\b]";
        }
    }

    template<class T>
    void Array3d<T>::setValue(int i, int j, int k, T value) {
        _storage[i * _dim1 * _dim2 + j * _dim2 + k] = value;
    }

    template<class T>
    T Array3d<T>::getValue(int i, int j, int k) const {
        return _storage[i * _dim1 * _dim2 + j * _dim2 + k];
    }

    template<class T>
    Array2d<T>* Array3d<T>::getValues2d(int index, int axis) const {
        switch (axis) {
            case 0: {
                Array2d<T>* result = new Array2d<T>{_dim2, _dim3};
                for (int i = 0; i < _dim2; ++i) {
                    T tmp_arr[_dim3];
                    for (int j = 0; j < _dim3; ++j) {
                        tmp_arr[j] = _storage[index * _dim1 * _dim2 + i * _dim2 + j];
                    }
                    result->setValues1d(i, 0, tmp_arr);
                }
                return result;
            }
            case 1: {
                Array2d<T>* result = new Array2d<T>{_dim1, _dim3};
                for (int i = 0; i < _dim1; ++i) {
                    T tmp_arr[_dim3];
                    for (int j = 0; j < _dim3; ++j) {
                        tmp_arr[j] = _storage[i * _dim1 * _dim2 + index * _dim2 + j];
                    }
                    result->setValues1d(i, 0, tmp_arr);
                }
                return result;
            }
            case 2: {
                Array2d<T>* result = new Array2d<T>{_dim1, _dim2};
                for (int i = 0; i < _dim1; ++i) {
                    T tmp_arr[_dim2];
                    for (int j = 0; j < _dim2; ++j) {
                        tmp_arr[j] = _storage[i * _dim1 * _dim2 + j * _dim2 + index];
                    }
                    result->setValues1d(i, 0, tmp_arr);
                }
                return result;
            }
        }
    }

    template<class T>
    T* Array3d<T>::getValues1d(int index1, int index2, int axis1, int axis2) const {
        if (axis2 < axis1) {
            std::swap(axis1, axis2);
            std::swap(index1, index2);
        }
        if (axis1 == 0 && axis2 == 1) {
            T* result = new T[_dim3];
            for (int i = 0; i < _dim3; ++i) {
                result[i] = _storage[index1 * _dim1 * _dim2 + index2 * _dim2 + i];
            }
            return result;
        }
        if (axis1 == 0 && axis2 == 2) {
            T* result = new T[_dim2];
            for (int i = 0; i < _dim2; ++i) {
                result[i] = _storage[index1 * _dim1 * _dim2 + i * _dim2 + index2];
            }
            return result;
        }
        if (axis1 == 1 && axis2 == 2) {
            T* result = new T[_dim1];
            for (int i = 0; i < _dim1; ++i) {
                result[i] = _storage[i * _dim1 * _dim2 + index1 * _dim2 + index2];
            }
            return result;
        }
    }

    template<class T>
    void Array3d<T>::setValues2d(int index, int axis, const Array2d<T> &arr2d)  {
        switch (axis) {
            case 0: {
                for (int i = 0; i < _dim2; ++i) {
                    for (int j = 0; j < _dim3; ++j) {
                        _storage[index * _dim1 * _dim2 + i * _dim2 + j] = arr2d.getValue(i, j);
                    }
                }
                return;
            }
            case 1: {
                for (int i = 0; i < _dim1; ++i) {
                    for (int j = 0; j < _dim3; ++j) {
                        _storage[i * _dim1 * _dim2 + index * _dim2 + j] = arr2d.getValue(i, j);
                    }
                }
                return;
            }
            case 2: {
                for (int i = 0; i < _dim1; ++i) {
                    for (int j = 0; j < _dim2; ++j) {
                        _storage[i * _dim1 * _dim2 + j * _dim2 + index] = arr2d.getValue(i, j);
                    }
                }
            }
        }
    }

    template<class T>
    void Array3d<T>::setValues1d(int index1, int index2, int axis1, int axis2, T *arr1d) {
        if (axis2 > axis1) {
            std::swap(axis1, axis2);
            std::swap(index1, index2);
        }
        if (axis1 == 0 && axis2 == 1) {
            for (int i = 0; i < _dim3; ++i) {
                _storage[index1 * _dim1 * _dim2 + index2 * _dim2 + i] = arr1d[i];
            }
        }
        if (axis1 == 0 && axis2 == 2) {
            for (int i = 0; i < _dim2; ++i) {
                _storage[index1 * _dim1 * _dim2 + i * _dim2 + index2] = arr1d[i];
            }
        }
        if (axis1 == 1 && axis2 == 2) {
            for (int i = 0; i < _dim1; ++i) {
                _storage[i * _dim1 * _dim2 + index1 * _dim2 + index2] = arr1d[i];
            }
        }
    }

    template<class T>
    void Array3d<T>::fill(T value) {
        for (int i = 0; i < _dim1; ++i) {
            for (int j = 0; j < _dim2; ++j) {
                for (int k = 0; k < _dim3; ++k) {
                    this->setValue(i, j, k, value);
                }
            }
        }
    }

    template<class T>
    void Array3d<T>::print() const {
        for (int i = 0; i < _dim1; ++i) {
            std::cout << "[";
            for (int j = 0; j < _dim2; ++j) {
                std::cout << "[";
                for (int k = 0; k < _dim3; ++k) {
                    std::cout << getValue(i, j, k) << " ";
                }
                std::cout << "\b]";
            }
            std::cout << "]";
        }
    }

    template class Array2d<int>;
    template class Array3d<int>;
}
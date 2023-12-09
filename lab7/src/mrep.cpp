#include "../inc/mrep.h"

namespace rep {
    template <typename T>
    void MemoryRepository<T>::add(T *item) {
        _items.insert(item);
    }
    template <typename T>
    void MemoryRepository<T>::update(T *item, T *newItem) {
        if (_items.find(item) != _items.end()) {
            _items.erase(item);
            _items.insert(newItem);
        }
    }
    template <typename T>
    std::set<T*> MemoryRepository<T>::get() {
        return _items;
    }
    template <typename T>
    void MemoryRepository<T>::remove(T *item) {
        if (_items.find(item) != _items.end()) {
            _items.erase(item);
        }
    }
    template <typename T>
    T* MemoryUserRepository<T>::getById(int id) {
        for (T* item : _items) {
            if (item->getId() == id) {
                return item;
            }
        }
    }
    template <typename T>
    T* MemoryUserRepository<T>::getByName(const std::string &name) {
        for (T* item : _items) {
            if (item->getName() == name) {
                return item;
            }
        }
    }
    template <typename T>
    T* MemoryUserRepository<T>::getByEmail(const std::string &email) {
        for (T* item : _items) {
            if (item->getEmail() == email) {
                return item;
            }
        }
    }
    template <typename T>
    std::set<T*> MemoryUserRepository<T>::getByCity(const std::string &city) {
        std::set<T*> result;
        for (T* item : _items) {
            if (item->getCity() == city) {
                result.insert(item);
            }
        }
        return result;
    }
    template <typename T>
    std::set<T*> MemoryUserRepository<T>::getByGender(const rep::Gender &gender) {
        std::set<T*> result;
        for (T* item : _items) {
            if (item->getGender() == gender) {
                result.insert(item);
            }
        }
        return result;
    }

    template class MemoryRepository<User>;
    template class MemoryUserRepository<User>;
}
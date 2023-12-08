#include "Data.h"

namespace lrs {
    [[nodiscard]] std::string MyClass::getName() const {
        return _name;
    }

    void MyClass::setName(const std::string &name)  {
        _name = name;
        for (auto listener: _notifyPropertyChangedListeners) {
            listener("name", name);
        }
    }

    [[nodiscard]] int MyClass::getValue() const {
        return _value;
    }

    void MyClass::setValue(const int value) {
        bool cancel = false;
        for (auto listener: _notifyPropertyChangingListeners) {
            listener("value", value, cancel);
        }
        if (!cancel) {
            _value = value;
        }
    }

    [[nodiscard]] std::set<int> MyClass::getNumbers() const {
        return _numbers;
    }

    void MyClass::addValueToNumbers(int value) {
        if (_numbers.find(value) == _numbers.end()) {
            _numbers.insert(value);
            for (auto listener: _notifyCollectionChangingListeners) {
                listener("numbers", ChangeStatus::Added, value, value);
            }
        }
    }

    void MyClass::removeValueFromNumbers(int value) {
        if (_numbers.find(value) != _numbers.end()) {
            _numbers.erase(value);
            for (auto listener: _notifyCollectionChangingListeners) {
                listener("numbers", ChangeStatus::Removed, value, value);
            }
        }
    }

    void MyClass::changeValueInNumbers(int old_value, int new_value) {
        if (_numbers.find(old_value) != _numbers.end()) {
            _numbers.erase(old_value);
            _numbers.insert(new_value);
            for (auto listener: _notifyCollectionChangingListeners) {
                listener("numbers", ChangeStatus::ItemChanged, old_value, new_value);
            }
        }
    }

    void MyClass::addNotifyPropertyChangedListener(void (*listener)(const char *, const std::string &)) {
        _notifyPropertyChangedListeners.insert(listener);
    }

    void MyClass::removeNotifyPropertyChangedListener(void (*listener)(const char *, const std::string &)) {
        _notifyPropertyChangedListeners.erase(listener);
    }

    void MyClass::addNotifyPropertyChangingListener(void (*listener)(const char *, int, bool &))  {
        _notifyPropertyChangingListeners.insert(listener);
    }

    void MyClass::removeNotifyPropertyChangingListener(void (*listener)(const char *, int, bool &))  {
        _notifyPropertyChangingListeners.erase(listener);
    }

    void MyClass::addNotifyCollectionChangedListener(void (*listener)(const char*, ChangeStatus, int, int))  {
        _notifyCollectionChangingListeners.insert(listener);
    }

    void MyClass::removeNotifyCollectionChangedListener(void (*listener)(const char*, ChangeStatus, int, int)) {
        _notifyCollectionChangingListeners.erase(listener);
    }
}



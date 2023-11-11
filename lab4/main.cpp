#include <iostream>
#include "Data.h"

using namespace lrs;

void f(const char* propName, const std::string& new_value);
void validate(const char* propName, int newValue, bool& cancel);
void col_changed(const char* colName, ChangeStatus changeStatus, int newValue, int oldValue);

int main() {
    MyClass cls{};
    cls.addNotifyPropertyChangedListener(f);
    cls.addNotifyPropertyChangingListener(validate);
    cls.addNotifyCollectionChangedListener(col_changed);
    cls.setName("ababa");
    cls.setValue(1);
    cls.setValue(-1);
    cls.addValueToNumbers(1);
    cls.addValueToNumbers(2);
    cls.removeValueFromNumbers(2);
    cls.changeValueInNumbers(1, 3);
    cls.removeValueFromNumbers(4);
}

void f(const char* propName, const std::string& newValue) {
    std::cout << "Property \"" << propName << "\" has changed to " << newValue << "\n";
}

void validate(const char* propName, int newValue, bool& cancel) {
    if (newValue < 0) {
        cancel = true;
        return;
    }
    std::cout << "Property \"" << propName << "\" has changed to " << newValue << "\n";
}

void col_changed(const char* colName, ChangeStatus changeStatus, int oldValue, int newValue) {
    switch(changeStatus) {
        case ChangeStatus::Added: {
            std::cout << "Add " << newValue << " to collection \"" << colName << "\"\n";
            break;
        }
        case ChangeStatus::Removed: {
            std::cout << "Remove " << newValue << " from collection \"" << colName << "\"\n";
            break;
        }
        case ChangeStatus::ItemChanged: {
            std::cout << "Change " << oldValue << " to " << newValue << " in collection\"" << colName << "\"\n";
            break;
        }
    }
}

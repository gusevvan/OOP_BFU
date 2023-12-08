#pragma once
#include <set>
#include <string>

namespace lrs {

    class INotifyPropertyChanged {
    public:
        virtual void addNotifyPropertyChangedListener(void (*listener)(const char *, const std::string&)) = 0;
        virtual void removeNotifyPropertyChangedListener(void (*listener)(const char *, const std::string&)) = 0;
        virtual ~INotifyPropertyChanged() = default;
    };

    class INotifyPropertyChanging {
    public:
        virtual void addNotifyPropertyChangingListener(void (*listener)(const char *, int, bool &)) = 0;
        virtual void removeNotifyPropertyChangingListener(void (*listener)(const char *, int, bool &)) = 0;
        virtual ~INotifyPropertyChanging() = default;
    };

    enum class ChangeStatus {
        Added,
        Removed,
        ItemChanged
    };

    class INotifyCollectionChanged {
    public:
        virtual void addNotifyCollectionChangedListener(void (*listener)(const char*, ChangeStatus, int, int)) = 0;
        virtual void removeNotifyCollectionChangedListener(void (*listener)(const char*, ChangeStatus, int, int)) = 0;
        virtual ~INotifyCollectionChanged() = default;
    };

    class MyClass : public INotifyPropertyChanged, public INotifyPropertyChanging, public INotifyCollectionChanged {
    private:
        std::string _name = "";
        int _value = 0;
        std::set<int> _numbers{};
        std::set<void (*)(const char *, const std::string&)> _notifyPropertyChangedListeners;
        std::set<void (*)(const char *, int, bool &)> _notifyPropertyChangingListeners;
        std::set<void (*)(const char *, ChangeStatus, int, int)> _notifyCollectionChangingListeners;
    public:
        [[nodiscard]] std::string getName() const;
        void setName(const std::string &name);
        [[nodiscard]] int getValue() const;
        void setValue(const int value);
        [[nodiscard]] std::set<int> getNumbers() const;
        void addValueToNumbers(int value);
        void removeValueFromNumbers(int value);
        void changeValueInNumbers(int old_value, int new_value);
        void addNotifyPropertyChangedListener(void (*listener)(const char *, const std::string&)) override;
        void removeNotifyPropertyChangedListener(void (*listener)(const char *, const std::string&)) override;
        void addNotifyPropertyChangingListener(void (*listener)(const char *, int, bool &)) override;
        void removeNotifyPropertyChangingListener(void (*listener)(const char *, int, bool &)) override;
        void addNotifyCollectionChangedListener(void (*listener)(const char *, ChangeStatus, int, int)) override;
        void removeNotifyCollectionChangedListener(void (*listener)(const char *, ChangeStatus, int, int)) override;
        ~MyClass() {
            _notifyPropertyChangedListeners.clear();
            _notifyPropertyChangingListeners.clear();
            _notifyCollectionChangingListeners.clear();
            _numbers.clear();
        }
    };
}
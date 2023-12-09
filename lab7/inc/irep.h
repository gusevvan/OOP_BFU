#pragma once
#include <set>
#include "user.h"

namespace rep {

    template<typename T>
    class IRepository {
    public:
        IRepository() = default;
        virtual void add(T* item) = 0;
        virtual void update(T* item, T* newItem) = 0;
        virtual void remove(T* item) = 0;
        virtual std::set<T*> get() = 0;
    };

    template <typename T>
    class IUserRepository {
    public:
        IUserRepository() = default;
        virtual T* getById(int id) = 0;
        virtual T* getByName(const std::string& name) = 0;
        virtual T* getByEmail(const std::string& email) = 0;
        virtual std::set<T*> getByCity(const std::string& city) = 0;
        virtual std::set<T*> getByGender(const Gender& gender) = 0;
    };
}

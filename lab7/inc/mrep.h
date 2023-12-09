#pragma onceonce
#include "irep.h"

namespace rep {
    template <typename T>
    class MemoryRepository: public IRepository<T> {
    protected:
        std::set<T*> _items;
    public:
        MemoryRepository() = default;
        void add(T* item) override;
        void update(T* item, T* newItem) override;
        void remove(T* item) override;
        std::set<T*> get() override;
        virtual ~MemoryRepository() {
            _items.clear();
        }
    };

    template <typename T>
    class MemoryUserRepository: public MemoryRepository<T>, public IUserRepository<T> {
    public:
        MemoryUserRepository() = default;
        using MemoryRepository<T>::_items;
        T* getById(int id) override;
        T* getByName(const std::string& name) override;
        T* getByEmail(const std::string& email) override;
        std::set<T*> getByCity(const std::string& city) override;
        std::set<T*> getByGender(const Gender& gender) override;
    };
}

#include <iostream>
#include "inc/mrep.h"

using namespace rep;

int main() {
    MemoryUserRepository<User>* repos = new MemoryUserRepository<User>();
    User* user1 = new User(0, "abab", "abab@yandex.ru", "Moscow", Gender::Man);
    repos->add(user1);
    User* user2 = new User(1, "baba", "baba@yandex.ru", "London", Gender::Woman);
    repos->add(user2);
    User* user3 = new User(2, "omom", "omom@yandex.ru", "Warsaw", Gender::Man);
    repos->add(user3);
    std::set<User*> res1 = repos->getByGender(Gender::Man);
    for (User* user : res1) {
        std::cout << user->getName() << " ";
    }
    std::cout << "\n";
    repos->remove(user1);
    std::set<User*> res2 = repos->getByGender(Gender::Man);
    for (User* user : res2) {
        std::cout << user->getName() << " ";
    }
    std::cout << "\n";
    User* user4 = new User(3, "momo", "momo@yandex.ru", "Paris", Gender::Woman);
    repos->update(user3, user4);
    std::set<User*> res3= repos->getByGender(Gender::Woman);
    for (User* user : res3) {
        std::cout << user->getName() << " ";
    }
    std::cout << "\n";
}

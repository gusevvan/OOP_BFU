#include "../inc/user.h"

namespace rep {
    User::User(int id, const std::string &name, const std::string &email, const std::string &city,
               const rep::Gender &gender): _id{id}, _name{name}, _email{email}, _city{city}, _gender{gender} {}

    int User::getId() {
        return _id;
    }
    void User::setId(int id) {
        _id = id;
    }
    std::string User::getName() {
        return _name;
    }
    void User::setName(const std::string &name) {
        _name = name;
    }
    std::string User::getEmail() {
        return _email;
    }
    void User::setEmail(const std::string &email) {
        _email = email;
    }
    std::string User::getCity() {
        return _city;
    }
    void User::setCity(const std::string &city) {
        _city = city;
    }
    Gender User::getGender() {
        return _gender;
    }
    void User::setGender(const rep::Gender &gender) {
        _gender = gender;
    }
}

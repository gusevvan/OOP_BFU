#pragma once
#include<string>

namespace rep {
    enum Gender {
        Man,
        Woman
    };

    class User {
    private:
        int _id;
        std::string _name, _email, _city;
        Gender _gender;
    public:
        User(int id, const std::string& name, const std::string& email, const std::string& city, const Gender& gender);
        int getId();
        void setId(int id);
        std::string getName();
        void setName(const std::string& name);
        std::string getEmail();
        void setEmail(const std::string& email);
        std::string getCity();
        void setCity(const std::string& city);
        Gender getGender();
        void setGender(const Gender& gender);
    };
}

#pragma once
#include <string>

class UserLogin {
    private:
        char _password[20];
        int _id;
        int _userType;
        bool _state;
    public:
        UserLogin();
        UserLogin(std::string, int, int);
        std::string getPassword() const;
        int getId() const;
        int getUserType() const;
        bool getState() const;
        void setPassword(std::string);
        void setId(int);
        void setUserType(int);
        void setState(bool);
};
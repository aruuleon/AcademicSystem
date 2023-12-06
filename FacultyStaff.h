#pragma once
#include <iostream>
#include "Person.h"

class FacultyStaff : public Person {
    private:
        char _email[40];
        char _password[40];
        char _phone[20];
        int _id;
        int _userType;
        bool _state;
    public:
        FacultyStaff();
        FacultyStaff(std::string, std::string, std::string, std::string, std::string, std::string, int, int);
        std::string getEmail() const;
        std::string getPassword() const;
        std::string getPhone() const;
        std::string getUserTypeMessage() const;
        int getId() const;
        int getUserType() const;
        bool getState() const;
        void setEmail(std::string);
        void setPassword(std::string);
        void setPhone(std::string);
        void setId(int);
        void setUserType(int);
        void setState(bool);
        void logout();
        void show();
};
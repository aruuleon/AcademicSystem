#pragma once
#include <string>
#include "SuperAdministrator.h"
#include "Administrator.h"
#include "Teacher.h"
#include "Student.h"
#include "GenericFile.h"

class System {
    private:
        char _name[40];
        char _country[20];
        char _province[20];
        GenericFile <SuperAdministrator> _superAdministratorFile = GenericFile <SuperAdministrator> ("superAdministrators.dat");
        GenericFile <Administrator> _administratorFile = GenericFile <Administrator> ("administrators.dat");
        GenericFile <Teacher> _teacherFile = GenericFile <Teacher> ("teachers.dat");
        GenericFile <Student> _studentFile = GenericFile <Student> ("students.dat");
        int verifyCredentials(int file, std::string password);
        void allowAccess(int, int);
    public:
        System();
        System(std::string, std::string, std::string);
        std::string getName() const;
        std::string getCountry() const;
        std::string getProvince() const;
        std::string getLocation() const;
        void setName(std::string);
        void setCountry(std::string);
        void setProvince(std::string);
        void runProgram();
        void login();
};
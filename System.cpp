#include <iostream>
#include <cstring>
#include "System.h"

System::System() {

};
System::System(std::string name, std::string country, std::string province) {
    setName(name);
    setCountry(country);
    setProvince(province);
};
std::string System::getName() const {
    return _name;
};
std::string System::getCountry() const {
    return _country;
};
std::string System::getProvince() const {
    return _province;
};
std::string System::getLocation() const {
    return getProvince() + ", " + getCountry();
};
void System::setName(std::string name) {
    strcpy(_name, name.c_str());
};
void System::setCountry(std::string country) {
    strcpy(_country, country.c_str());
};
void System::setProvince(std::string province) {
    strcpy(_province, province.c_str());
};
void System::runProgram() {
    login();
};
void System::login() {
    std::string password;
    int id, userType;
    do {
        do {
            system("cls");
            std::cout << "=========================================================================" << std::endl;
            std::cout << "                     " << getName() << "                                 " << std::endl;
            std::cout << "=========================================================================" << std::endl;
            std::cout << std::endl;
            std::cout << "                               INICIAR SESION                            " << std::endl;
            std::cout << std::endl;
            std::cout << "LEGAJO: ";
            std::cin >> id;
            std::cout << "CLAVE: ";
            std::cin >> password;
            userType = verifyCredentials(id, password);
            if(userType == 0) {
                std::cout << std::endl;
                std::cout << "CREDENCIALES INCORRECTAS" << std::endl;
                std::cout << std::endl;
                system("pause");
            }
        } while(userType == 0);
        allowAccess(id, userType);
    } while(true);
};
int System::verifyCredentials(int id, std::string password) {
    GenericFile <UserLogin> userLoginFile ("usersLogin.dat");
    int numberOfRecords = userLoginFile.numberOfRecords();
    int userType = 0;
    int userPosition = 0;
    bool userFound = false;

    while(!userFound && userPosition < numberOfRecords) {
        UserLogin userLogin = userLoginFile.read(userPosition);
        if(userLogin.getState() && userLogin.getId() == id && userLogin.getPassword() == password) {
            userFound = true;
            userType = userLogin.getUserType();
        }
        userPosition++;
    }
    return userType;
};
void System::allowAccess(int id, int userType) {
    switch(userType) {
        case 1: { SuperAdministrator superAdministrator = _superAdministratorFile.read(_superAdministratorFile.searchRecord(id));
                  superAdministrator.showMenu(superAdministrator); }
        break;
        case 2: 
                { Administrator administrator = _administratorFile.read(_administratorFile.searchRecord(id));
                  administrator.showMenu(administrator); }
        break;
        case 3: 
                { Teacher teacher = _teacherFile.read(_teacherFile.searchRecord(id));
                  teacher.showMenu(teacher); }
        break;
        case 4: { Student student = _studentFile.read(_studentFile.searchRecord(id));
                  student.showMenu(student); }
        break;
    }
};
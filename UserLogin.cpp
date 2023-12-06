#include <iostream>
#include <cstring>
#include "UserLogin.h"

UserLogin::UserLogin() {

};
UserLogin::UserLogin(std::string password, int id, int userType) {
    setPassword(password);
    setId(id);
    setUserType(userType);
    setState(true);
};
std::string UserLogin::getPassword() const {
    return _password;
};
int UserLogin::getId() const {
    return _id;
};
int UserLogin::getUserType() const {
    return _userType;
};
bool UserLogin::getState() const {
    return _state;
};
void UserLogin::setPassword(std::string password) {
    strcpy(_password, password.c_str());
};
void UserLogin::setId(int id) {
    _id = id;
};
void UserLogin::setUserType(int userType) {
    _userType = userType;
};
void UserLogin::setState(bool state) {
    _state = state;
};
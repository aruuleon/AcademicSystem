#include <cstring>
#include "Person.h"
#include <iostream>

Person::Person() {

};
Person::Person(std::string name, std::string surname, std::string document) {
    setName(name);
    setSurname(surname);
    setDocument(document);
};
std::string Person::getName() const {
    return _name;
};
std::string Person::getSurname() const {
    return _surname;
};
std::string Person::getDocument() const {
    return _document;
};
std::string Person::getFullName() const {
    return getName() + " " + getSurname(); 
};
void Person::setName(std::string name) {
    strcpy(_name, name.c_str());
};
void Person::setSurname(std::string surname) {
    strcpy(_surname, surname.c_str());
};
void Person::setDocument(std::string document) {
    strcpy(_document, document.c_str());
};
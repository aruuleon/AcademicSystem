#pragma once
#include <string>

class Person {
    private:
        char _name[40];
        char _surname[40];
        char _document[20];
    public:
        Person();
        Person(std::string, std::string, std::string);
        std::string getName() const;
        std::string getSurname() const;
        std::string getDocument() const;
        std::string getFullName() const;
        void setName(std::string name);
        void setSurname(std::string surname);
        void setDocument(std::string document);
};
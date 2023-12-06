#include "Subject.h"
#include <cstring>
#include <iostream>

Subject::Subject() {

};
Subject::Subject(std::string name, int duration, int id, int yearCareer) {
    setName(name);
    setDuration(duration);
    setId(id);
    setYearCareer(yearCareer);
    setState(true);
};
std::string Subject::getName() const {
    return _name;
};
int Subject::getId() const {
    return _id;
};
std::string Subject::getDuration() const {
    return (_duration == 1) ? "CUATRIMESTRAL" : "ANUAL";
};
int Subject::getyearCareer() const {
    return _yearCareer;
};
bool Subject::getState() const {
    return _state;
};
void Subject::setName(std::string name) {
    strcpy(_name, name.c_str());
};
void Subject::setId(int id) {
    _id = id;
};
void Subject::setDuration(int duration) {
    _duration = duration;
};
void Subject::setYearCareer(int yearCareer) {
    _yearCareer = yearCareer;
};
void Subject::setState(bool state) {
    _state = state;
};
void Subject::show(){
    std::cout << std::endl;
    std::cout << "ID      : " << getId() << std::endl;
    std::cout << "NOMBRE  : " << getName() << std::endl;
    std::cout << "DURACION: " << getDuration() << std::endl;
    std::cout << std::endl;
    std::cout << "=========================================================================" << std::endl;
};
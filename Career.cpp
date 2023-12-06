#include "Career.h"
#include <cstring>
#include <iostream>

Career::Career(){

};
Career::Career(std::string name, int studyType, int id, int duration) {
    setName(name);
    setStudyType(studyType);
    setId(id);
    setDuration(duration);
    setState(true);
};
std::string Career::getName() const {
    return _name;
};
int Career::getId() const {
    return _id;
};
std::string Career::getStudyType() const {
    std::string studyType;
    switch(_studyType) {
        case 1: studyType = "TECNICATURA";
            break;
        case 2: studyType = "CARRERA DE GRADO";
            break;
        case 3: studyType = "POSGRADO";
            break;
    }
    return studyType;
};
int Career::getDuration() const {
    return _duration;
};
bool Career::getState() const {
    return _state;
};
void Career::setName(std::string name) {
    strcpy(_name, name.c_str());
};
void Career::setId(int id) {
    _id = id;
};
void Career::setStudyType(int studyType) {
    _studyType = studyType;
};
void Career::setDuration(int duration) {
    _duration = duration;
};
void Career::setState(bool state) {
    _state = state;
};
void Career::show(){
    std::cout << std::endl;
    std::cout << "ID          : " << getId() << std::endl;
    std::cout << "NOMBRE      : " << getName() << std::endl;
    std::cout << "TIPO ESTUDIO: " << getStudyType() << std::endl;
    std::cout << "DURACION    : " << getDuration() << " ANIOS" << std::endl;
    std::cout << std::endl;
    std::cout << "=========================================================================" << std::endl;
};
#include "Comission.h"
#include <cstring>
#include <iostream>

Comission::Comission() {

};
Comission::Comission(int id, int modality, int turn, int year, int fourthQuarter) {
    setId(id);
    setModality(modality);
    setTurn(turn);
    setYear(year);
    setFourthQuarter(fourthQuarter);
    setState(true);
};
int Comission::getId() const {
    return _id;
};
std::string Comission::getModality() const {
    return (_modality == 1) ? "PRESENCIAL" : "VIRTUAL";
};
std::string Comission::getTurn() const {
    return (_turn == 1) ? "MANIANA" : "NOCHE";
};
std::string Comission::getFourthQuarter() const {
    return (_fourthQuarter == 1) ? "PRIMER CUATRIMESTRE" : "SEGUNDO CUATRIMESTRE";
};
std::string Comission::getName() const {
    return std::to_string(getId()) + " - " + getModality() + " - " + getTurn() + " - " + getFourthQuarter();
};
int Comission::getYear() const {
    return _year;
};
bool Comission::getState() const {
    return _state;
};
void Comission::setId(int id) {
    _id = id;
};
void Comission::setModality(int modality) {
    _modality = modality;
};
void Comission::setTurn(int turn) {
    _turn = turn;
};
void Comission::setYear(int year) {
    _year = year;
};
void Comission::setFourthQuarter(int fourthQuarter) {
    _fourthQuarter = fourthQuarter;
};
void Comission::setState(bool state) {
    _state = state;
};
void Comission::show(){
    std::cout << std::endl;
    std::cout << "ID          : " << getId() << std::endl; 
    std::cout << "TURNO       : " << getTurn() << std::endl;
    std::cout << "ANIO        : " << getYear() << std::endl; 
    std::cout << "MODALIDAD   : " << getModality() << std::endl;
    std::cout << "CUATRIMESTRE: " << getFourthQuarter() << std::endl;
    std::cout << std::endl;
    std::cout << "=========================================================================" << std::endl;
};
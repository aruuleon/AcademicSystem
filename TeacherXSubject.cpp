#include <cstring>
#include "TeacherXSubject.h"
#include <iostream>
TeacherXSubject::TeacherXSubject() {

};
TeacherXSubject::TeacherXSubject(int firstResourceId, int secondResourceId) {
    setFirstResourceId(firstResourceId);
    setSecondResourceId(secondResourceId);
    setState(true);
};
int TeacherXSubject::getFirstResourceId() const {
    return _firstResourceId;
};
int TeacherXSubject::getSecondResourceId() const {
    return _secondResourceId;
};
bool TeacherXSubject::getState() const {
    return _state;
};
void TeacherXSubject::setFirstResourceId(int firstResourceId) {
    _firstResourceId = firstResourceId;
};
void TeacherXSubject::setSecondResourceId(int secondResourceId) {
    _secondResourceId = secondResourceId;
};
void TeacherXSubject::setState(bool state) {
    _state = state;
};
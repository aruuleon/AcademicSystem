#include <cstring>
#include "StudentXCareer.h"

StudentXCareer::StudentXCareer() {

};
StudentXCareer::StudentXCareer(int firstResourceId, int secondResourceId) {
    setFirstResourceId(firstResourceId);
    setSecondResourceId(secondResourceId);
    setState(true);
};
int StudentXCareer::getFirstResourceId() const {
    return _firstResourceId;
};
int StudentXCareer::getSecondResourceId() const {
    return _secondResourceId;
};
bool StudentXCareer::getState() const {
    return _state;
};
void StudentXCareer::setFirstResourceId(int firstResourceId) {
    _firstResourceId = firstResourceId;
};
void StudentXCareer::setSecondResourceId(int secondResourceId) {
    _secondResourceId = secondResourceId;
};
void StudentXCareer::setState(bool state) {
    _state = state;
};
#include <cstring>
#include "StudentXSubject.h"

StudentXSubject::StudentXSubject() {

};
StudentXSubject::StudentXSubject(int firstResourceId, int secondResourceId) {
    setFirstResourceId(firstResourceId);
    setSecondResourceId(secondResourceId);
    setState(true);
};
int StudentXSubject::getFirstResourceId() const {
    return _firstResourceId;
};
int StudentXSubject::getSecondResourceId() const {
    return _secondResourceId;
};
bool StudentXSubject::getState() const {
    return _state;
};
void StudentXSubject::setFirstResourceId(int firstResourceId) {
    _firstResourceId = firstResourceId;
};
void StudentXSubject::setSecondResourceId(int secondResourceId) {
    _secondResourceId = secondResourceId;
};
void StudentXSubject::setState(bool state) {
    _state = state;
};
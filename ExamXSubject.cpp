#include <cstring>
#include "ExamXSubject.h"

ExamXSubject::ExamXSubject() {

};
ExamXSubject::ExamXSubject(int firstResourceId, int secondResourceId) {
    setFirstResourceId(firstResourceId);
    setSecondResourceId(secondResourceId);
    setState(true);
};
int ExamXSubject::getFirstResourceId() const {
    return _firstResourceId;
};
int ExamXSubject::getSecondResourceId() const {
    return _secondResourceId;
};
bool ExamXSubject::getState() const {
    return _state;
};
void ExamXSubject::setFirstResourceId(int firstResourceId) {
    _firstResourceId = firstResourceId;
};
void ExamXSubject::setSecondResourceId(int secondResourceId) {
    _secondResourceId = secondResourceId;
};
void ExamXSubject::setState(bool state) {
    _state = state;
};
#include "SubjectXCareer.h"

SubjectXCareer::SubjectXCareer() {

};
SubjectXCareer::SubjectXCareer(int firstResourceId, int secondResourceId) {
    setFirstResourceId(firstResourceId);
    setSecondResourceId(secondResourceId);
    setState(true);
};
int SubjectXCareer::getFirstResourceId() const {
    return _firstResourceId;
};
int SubjectXCareer::getSecondResourceId() const {
    return _secondResourceId;
};
bool SubjectXCareer::getState() const {
    return _state;
};
void SubjectXCareer::setFirstResourceId(int firstResourceId) {
    _firstResourceId = firstResourceId;
};
void SubjectXCareer::setSecondResourceId(int secondResourceId) {
    _secondResourceId = secondResourceId;
};
void SubjectXCareer::setState(bool state) {
    _state = state;
};
#include <cstring>
#include "SubjectXComission.h"

SubjectXComission::SubjectXComission() {

};
SubjectXComission::SubjectXComission(int firstResourceId, int secondResourceId) {
    setFirstResourceId(firstResourceId);
    setSecondResourceId(secondResourceId);
    setState(true);
};
int SubjectXComission::getFirstResourceId() const {
    return _firstResourceId;
};
int SubjectXComission::getSecondResourceId() const {
    return _secondResourceId;
};
bool SubjectXComission::getState() const {
    return _state;
};
void SubjectXComission::setFirstResourceId(int firstResourceId) {
    _firstResourceId = firstResourceId;
};
void SubjectXComission::setSecondResourceId(int secondResourceId) {
    _secondResourceId = secondResourceId;
};
void SubjectXComission::setState(bool state) {
    _state = state;
};
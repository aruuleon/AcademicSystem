#include "ExamXStudentXSubject.h"

ExamXStudentXSubject::ExamXStudentXSubject() {

};
ExamXStudentXSubject::ExamXStudentXSubject(int id, int secondResourceId, int thirdResourceId, int grade, bool attendance, Fecha date) {
    setId(id);
    setSecondResourceId(secondResourceId);
    setThirdResourceId(thirdResourceId);
    setGrade(grade);
    setAttendance(attendance);
    setDate(date);
};
std::string ExamXStudentXSubject::getAttendanceMessage() const {
    return (_attendance) ? "PRESENTE" : "AUSENTE";
};
int ExamXStudentXSubject::getId() const {
    return _id;
};
int ExamXStudentXSubject::getSecondResourceId() const {
    return _secondResourceId;
};
int ExamXStudentXSubject::getThirdResourceId() const {
    return _thirdResourceId;
};
int ExamXStudentXSubject::getGrade() const {
    return _grade;
};
bool ExamXStudentXSubject::getAttendance() const {
    return _attendance;
};
bool ExamXStudentXSubject::getState() const {
    return _state;
};
Fecha ExamXStudentXSubject::getDate() const {
    return _date;
};
void ExamXStudentXSubject::setId(int id) {
    _id = id;
};
void ExamXStudentXSubject::setSecondResourceId(int secondResourceId) {
    _secondResourceId = secondResourceId;
};
void ExamXStudentXSubject::setThirdResourceId(int thirdResourceId) {
    _thirdResourceId = thirdResourceId;
};
void ExamXStudentXSubject::setGrade(int grade) {
    _grade = grade;
};
void ExamXStudentXSubject::setAttendance(bool attendance) {
    _attendance = attendance;
};
void ExamXStudentXSubject::setState(bool state) {
    _state = state;
};
void ExamXStudentXSubject::setDate(Fecha fecha) {
    _date = _date;
};
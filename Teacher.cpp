#include "Teacher.h"

Teacher::Teacher() {

};
Teacher::Teacher(std::string name, std::string surname, std::string document, std::string email, std::string password, std::string phone, int id, int userType)
:FacultyStaff(name, surname, document, email, password, phone, id, userType) {
};
void Teacher::showMenu(Teacher teacher) {
    int selectedOption;
    do {
        system("cls");
        std::cout << "================================ PROFESOR ===============================" << std::endl;
        std::cout << " " << getFullName() << std::endl;
        std::cout << "=========================================================================" << std::endl;
        std::cout << std::endl;
        std::cout << "1 - MATERIAS ASIGNADAS" << std::endl;
        std::cout << "2 - EDICION" << std::endl;
        std::cout << "3 - MI PERFIL" << std::endl;
        std::cout << "0 - CERRAR SESION" << std::endl;
        std::cout << std::endl;
        std::cout << "=========================================================================" << std::endl;
        processValidationForTheFirstCase("SELECCIONAR UNA OPCION", selectedOption, 0, 3);
        system("cls");
        sendRequest(teacher, selectedOption);
    } while(selectedOption != 0);
};
void Teacher::sendRequest(Teacher teacher, int selectedOption) {
    switch(selectedOption) {
        case 1: showAssignedSubjects(teacher);
            break;
        case 2: editInformationRegisterByOption(_teacherFile, teacher);
            break;
        case 3: showInformationRegisterByOption(teacher);
            break;
        case 0: logout();
            break;
    }
};
void Teacher::showAssignedSubjects(Teacher teacher) {
    int numberOfRecordsRelationship = _teacherXSubjectFile.numberOfRecords();
    int numberOfRecordsSubject = _subjectFile.numberOfRecords();
    std::cout << "MATERIAS DEL PROFESOR" << std::endl;
    std::cout << std::endl;
    for(int i = 0; i < numberOfRecordsRelationship; i++) {
        TeacherXSubject teacherXSubject = _teacherXSubjectFile.read(i);
        if(teacherXSubject.getFirstResourceId() == teacher.getId()){
            for(int i = 0; i < numberOfRecordsSubject; i++) {
                Subject subject = _subjectFile.read(i);
                if(subject.getState() && subject.getId() == teacherXSubject.getSecondResourceId()) {
                    subject.show();
                }
            }
        }
    }
    system("pause");
};
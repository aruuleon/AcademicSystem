#include "Administrator.h"
#include "Fecha.h"

Administrator::Administrator() {

};
Administrator::Administrator(std::string name, std::string surname, std::string document, std::string email, std::string password, std::string phone, int file, int userType)
:FacultyStaff(name, surname, document, email, password, phone, file, userType) {
};
void Administrator::showMenu(Administrator administrator) {
    int selectedOption;
    do {
        system("cls");
        std::cout << "============================= ADMINISTRADOR =============================" << std::endl;
        std::cout << " " << getFullName() << std::endl;
        std::cout << "=========================================================================" << std::endl;
        std::cout << std::endl;
        std::cout << "1 - PROFESOR " << std::endl;
        std::cout << "2 - ALUMNO" << std::endl;
        std::cout << "3 - ANUNCIOS" << std::endl;
        std::cout << "4 - COMISION" << std::endl;
        std::cout << "5 - EDICION" << std::endl;
        std::cout << "6 - MI PERFIL" << std::endl;
        std::cout << "0 - CERRAR SESION" << std::endl;
        std::cout << std::endl;
        std::cout << "=========================================================================" << std::endl;
        processValidationForTheFirstCase("SELECCIONAR UNA OPCION", selectedOption, 0, 6);
        system("cls");
        sendRequest(administrator, selectedOption);
    } while(selectedOption != 0);
};
void Administrator::sendRequest(Administrator administrator, int selectedOption) {
    switch(selectedOption) {
        case 1: showGenericMenu(3);
            break;
        case 2: showGenericMenu(4);
            break;
        case 3: showMenuNotice();
            break;
        case 4: showMenuComission();
            break;
        case 5: editInformationRegisterByOption(_administratorFile, administrator);
            break;
        case 6: showInformationRegisterByOption(administrator);
            break;
        case 0: logout();
            break;
    }
};
void Administrator::registerStaff(int userType) {
    std::string name, surname, document, email, phone, password;
    int file;
    inputStaffInformation(name, surname, document, email, phone, password);
    if(userType == 3) {
        file = verifyIdRegisterByOption(_teacherFile);
        _teacherFile.save(Teacher(name, surname, document, email, password, phone, file, userType));
    } else {
        listRegisterByOption(_careerFile, "CARRERA");
        std::cout << "INGRESAR ID CARRERA A LA QUE SE VA A INSCRIBIR EL ESTUDIANTE: ";
        int careerId;
        std::cin >> careerId;
        file = verifyIdRegisterByOption(_studentFile);
        _studentFile.save(Student(name, surname, document, email, password, phone, file, userType));
        _studentXCareerFile.save(StudentXCareer(file, careerId));
    }
    bool userResponse = _userLoginFile.save(UserLogin(password, file, userType));
    system("pause");
};
void Administrator::withdrawStaff(int userType) {
    (userType == 3) ? withdrawRegisterByOption(_teacherFile, "user") : withdrawRegisterByOption(_studentFile, "user");
};
void Administrator::reEnrollStaff(int userType){
    (userType == 3) ? reEnrollRegisterByOption(_teacherFile, "user") : reEnrollRegisterByOption(_studentFile, "user");
};
void Administrator::verifyInformation(int userType) {
    (userType == 3) ? searchRegisterByOption(_teacherFile) : searchRegisterByOption(_studentFile);
};
void Administrator::listStaff(int userType) {
    (userType == 3) ? listRegisterByOption(_teacherFile, "PROFESOR") : listRegisterByOption(_studentFile, "ESTUDIANTE");
};
void Administrator::postNotice() {
    std::string title, content;
    int id, day, month, year;

    inputNoticeInformation(title, content, id, day, month, year);
    _noticeFile.save(Notice(title, content, id, Fecha(day, month, year)));
    system("pause");
};
void Administrator::editNotice(){
    
};
void Administrator::showGenericMenu(int userType){
    int selectedOption;
    std::string sectionUserType = (userType == 3) ? "PROFESOR" : "ALUMNO"; 
    do {
        system("cls");
        std::cout << "=========================================================================" << std::endl;
        std::cout << "                              MENU " << sectionUserType << "             " << std::endl;
        std::cout << "=========================================================================" << std::endl;
        std::cout << std::endl;
        std::cout << "1 - REGISTRAR" << std::endl;
        std::cout << "2 - ELIMINAR" << std::endl;
        std::cout << "3 - DAR DE ALTA" << std::endl;
        std::cout << "4 - BUSCAR" << std::endl;
        std::cout << "5 - MOSTAR LISTA" << std::endl;
        if(userType == 3) {
            std::cout << "6 - ASIGNAR A MATERIA" << std::endl;
        } else {
            std::cout << "6 - ASIGNAR NOTA" << std::endl;
            std::cout << "7 - MODIFICAR NOTA" << std::endl;
        }
        std::cout << "0 - VOLVER" << std::endl;
        std::cout << std::endl;
        std::cout << "=========================================================================" << std::endl;
        processValidationForTheThirdCase("SELECCIONAR UNA OPCION", selectedOption, userType, 3, 4, 0, 6, 7);
        sendUserTypeRequest(selectedOption, userType);
    } while(selectedOption != 0);
};
void Administrator::showMenuNotice(){
    int selectedOption;
    do {
        system("cls");
        std::cout << "=========================================================================" << std::endl;
        std::cout << "                              MENU ANUNCIO                               " << std::endl;
        std::cout << "=========================================================================" << std::endl;
        std::cout << std::endl;
        std::cout << "1 - REGISTRAR" << std::endl;
        std::cout << "2 - EDITAR" << std::endl;
        std::cout << "3 - ELIMINAR" << std::endl;
        std::cout << "4 - MOSTRAR LISTA" << std::endl;
        std::cout << "0 - VOLVER" << std::endl;
        std::cout << std::endl;
        std::cout << "=========================================================================" << std::endl;
        processValidationForTheFirstCase("SELECCIONAR UNA OPCION", selectedOption, 0, 4);
        system("cls");
        sendNoticeRequest(selectedOption);
    } while(selectedOption != 0);
};
void Administrator::showMenuComission(){
    int selectedOption;
    do {
        system("cls");
        std::cout << "=========================================================================" << std::endl;
        std::cout << "                               MENU COMISION                             " << std::endl;
        std::cout << "=========================================================================" << std::endl;
        std::cout << std::endl;
        std::cout << "1 - REGISTRAR" << std::endl;
        std::cout << "2 - EDITAR" << std::endl;
        std::cout << "3 - ELIMINAR" << std::endl;
        std::cout << "4 - RECUPERAR" << std::endl;
        std::cout << "5 - BUSCAR" << std::endl;
        std::cout << "6 - MOSTRAR LISTA" << std::endl;
        std::cout << "7 - ASIGNAR MATERIA A COMISION" << std::endl;
        std::cout << "8 - MOSTRAR MATERIAS SEGUN COMISION" << std::endl;
        std::cout << "0 - VOLVER" << std::endl;
        std::cout << std::endl;
        std::cout << "=========================================================================" << std::endl;
        processValidationForTheFirstCase("SELECCIONAR UNA OPCION", selectedOption, 0, 8);
        system("cls");
        sendComissionRequest(selectedOption);
    } while(selectedOption != 0);
};
void Administrator::sendUserTypeRequest(int selectedOption, int userType) {
    if(selectedOption >= 1 && selectedOption <= 5) {
        sendGenericRequest(selectedOption, userType);
    } else if(userType == 3) {
        sendTeacherRequest(selectedOption);
    } else {
        sendStudentRequest(selectedOption);
    }
};
void Administrator::sendGenericRequest(int selectedOption, int userType) {
    switch(selectedOption) {
        case 1: registerStaff(userType);
            break;
        case 2: withdrawStaff(userType);
            break;
        case 3: reEnrollStaff(userType);
            break;
        case 4: verifyInformation(userType);
            break;
        case 5: listStaff(userType);
            break;
    }
};
void Administrator::sendTeacherRequest(int selectedOption) {
    switch(selectedOption) {
        case 6: assignTeacherToSubject();
            break;
    }
};
void Administrator::sendStudentRequest(int selectedOption) {
    switch(selectedOption) {
        case 6: assignGradeStudent();
            break;
        case 7: modifyGradeStudent();
            break;
    }
};
void Administrator::sendNoticeRequest(int selectedOption){
switch(selectedOption) {
        case 1: postNotice();
            break;
        case 2: editNotice();
            break;
        case 3: withdrawRegisterByOption(_noticeFile, "resource");
            break;
        case 4: listRegisterByOption(_noticeFile, "ANUNCIO");
            break;
    }
};
void Administrator::sendComissionRequest(int selectedOption) {
    switch(selectedOption) {
        case 1: registerComission();
            break;
        case 2: editComission();
            break;
        case 3: withdrawRegisterByOption(_comissionFile, "resource");
            break;
        case 4: reEnrollRegisterByOption(_comissionFile, "resource");
            break;
        case 5: searchRegisterByOption(_comissionFile);
            break;
        case 6: listRegisterByOption(_comissionFile, "COMISION");
            break;
        case 7: setResourceRelationship(_subjectFile, _comissionFile, _subjectXComissionFile, SubjectXComission(), "MATERIA", "COMISION");
            break;
        case 8: showFirstResourcesBySecondResources(_subjectFile, _comissionFile, _subjectXComissionFile, SubjectXComission(), Subject(), Comission(), "MATERIAS", "COMISION");
            break;
    }
};
void Administrator::registerComission(){
    int id, modality, turn, year, fourthQuarter;
    inputComissionInformation(id, modality, turn, year, fourthQuarter);
    bool response = _comissionFile.save(Comission(id, modality, turn, year, fourthQuarter));
    system("pause");
};
void Administrator::editComission(){

};
void Administrator::assignGradeStudent() {
    std::string document;
    std::cout << "SIGNACION DE NOTA DE ALUMNO" << std::endl;
    std::cout << std::endl;
    std::cout << "INGRESAR DOCUMENTO DE ALUMNO: ";
    std::cin >> document;

    int positionStudent = _studentFile.searchRecord(document);
    if(positionStudent != -1) {
        Student studentFound = _studentFile.read(positionStudent);
        showSubjectsByStudent(studentFound.getId());
        finishGradingProcess(studentFound.getId());
    } else {
        std::cout << std::endl;
        std::cout << "EL ALUMNO QUE INTENTA BUSCAR NO SE ENCUENTRA REGISTRADO EN EL SISTEMA" << std::endl;
    }
    system("pause");
};
void Administrator::modifyGradeStudent(){
    
    
    system("pause");
};
void Administrator::assignTeacherToSubject() {
    GenericFile <TeacherXSubject> _teacherXSubjectFile = GenericFile <TeacherXSubject> ("teachersXSubjects.dat");
    int teacherId;
    int subjectId;
    int numberOfRecordsRelationship = _teacherXSubjectFile.numberOfRecords();
    int numberOfRecordsComission = _comissionFile.numberOfRecords();
    int numberOfRecordsSubject = _subjectFile.numberOfRecords();
    
    std::cout << "* ASIGNAR PROFESOR A MATERIA *" << std::endl;
    showSubjects(numberOfRecordsRelationship, numberOfRecordsSubject, numberOfRecordsComission);
    std::cout << "INGRESAR EL ID DE MATERIA A ASIGNAR: ";
    std::cin >> subjectId;
    std::cout << "INGRESAR EL LEGAJO DEL PROFESOR: ";
    std::cin >> teacherId;
    std::cout << std::endl;
    finishAssignmentProcess(numberOfRecordsRelationship, numberOfRecordsSubject, subjectId, teacherId);
    system("pause");
};
void Administrator::showSubjects(int numberOfRecordsRelationship, int numberOfRecordsSubject, int numberOfRecordsComission) {
    for(int i = 0; i < numberOfRecordsSubject; i++) {
        Subject subject = _subjectFile.read(i);
        for(int j = 0; j < numberOfRecordsComission; j++) {
            subject.show();
        }
    }
};
void Administrator::finishAssignmentProcess(int numberOfRecordsRelationship, int numberOfRecordsSubject, int subjectId, int teacherId) {
        GenericFile <TeacherXSubject> _teacherXSubjectFile = GenericFile <TeacherXSubject> ("teachersXSubjects.dat");
        int positionRelationship = 0;
        bool relationshipFound = false;
        while(!relationshipFound && positionRelationship < numberOfRecordsRelationship) {
            TeacherXSubject teacherXSubject = _teacherXSubjectFile.read(positionRelationship);
            if(teacherXSubject.getSecondResourceId() == subjectId) {
                relationshipFound = true;
            }
            positionRelationship++;
        }
        if(!relationshipFound) {
            _teacherXSubjectFile.save(TeacherXSubject(teacherId, subjectId));
            std::cout << "EL PROFESOR FUE ASIGNADO A LA MATERIA CORRECTAMENTE" << std::endl;
        } else {
            std::cout << "ESTA MATERIA YA TIENE UN PROFESOR ASIGNADO A LA MISMA" << std::endl;
        }
};
void Administrator::showSubjectsByStudent(int studentId) {
    int numberOfRecordsRelationship = _studentXSubjectFile.numberOfRecords();
    int numberOfRecordsSubject = _subjectFile.numberOfRecords();
    for(int i = 0; i < numberOfRecordsRelationship; i++) {
        StudentXSubject studentXSubject = _studentXSubjectFile.read(i);
        if(studentXSubject.getFirstResourceId() == studentId) {
            for(int j = 0; j < numberOfRecordsSubject; j++) {
                Subject subject = _subjectFile.read(j);
                if(subject.getState() && subject.getId() == studentXSubject.getSecondResourceId()) {
                    subject.show();
                    std::cout << std::endl;
                }
            }
        }
    }
};
void Administrator::finishGradingProcess(int studentId) {
    int subjectId, selectedOption, grade, examId, day, month, year;
    bool attendance;

    grade = 0;
    attendance = false;
    inputExamGradeInformation(subjectId, selectedOption, grade, examId, day, month, year, attendance);
    _examXStudentXSubject.save(ExamXStudentXSubject(examId, studentId, subjectId, grade, attendance, Fecha(day, month, year)));
};
void Administrator::inputStaffInformation(std::string &name, std::string &surname, std::string &document, std::string &email, std::string &phone, std::string &password) {
    std::cout << "=========================================================================" << std::endl;
    std::cout << "                            INFORMACION USUARIO                          " << std::endl;
    std::cout << "=========================================================================" << std::endl;
    std::cout << "NOMBRE: " ;
    std::cin.ignore();
    getline(std::cin, name);
    std::cout << "APELLIDO: " ;
    getline(std::cin, surname);
    std::cout << "DNI: " ;
    std::cin >>  document; 
    std::cout << "CORREO: " ; 
    std::cin >>  email;
    std::cout << "TELEFONO: " ; 
    std::cin >>  phone;
    std::cout << "CLAVE: " ; 
    std::cin >> password;
};
void Administrator::inputNoticeInformation(std::string &title, std::string &content, int &id, int &day, int &month, int &year) {
    std::cout << "=========================================================================" << std::endl;
    std::cout << "                            INFORMACION ANUNCIO                          " << std::endl;
    std::cout << "=========================================================================" << std::endl;
    std::cout << "TITULO: ";
    std::cin.ignore();
    getline(std::cin, title);
    std::cout << "DESCRIPCION: ";
    getline(std::cin, content);
    std::cout << std::endl;
    std::cout << "FECHA" << std::endl;
    std::cout << "DIA: ";
    std::cin >> day;
    std::cout << "MES: ";
    std::cin >> month;
    std::cout << "ANIO: ";
    std::cin >> year;
    id = verifyIdRegisterByOption(_noticeFile);
};
void Administrator::inputComissionInformation(int &id, int &modality, int &turn, int &year, int &fourthQuarter) {
    std::cout << "=========================================================================" << std::endl;
    std::cout << "                           INFORMACION COMISION                          " << std::endl;
    std::cout << "=========================================================================" << std::endl;
    processValidationForTheFirstCase("TIPO MODALIDAD [1 - PRESENCIAL | 2 - VIRTUAL]", modality, 1, 2);
    processValidationForTheFirstCase("TURNO DE CURSADA [1 - MANIANA | 2 - NOCHE]", turn, 1, 2);
    std::cout << "ANIO DE COMISION: ";
    std::cin >> year;
    processValidationForTheFirstCase("CUATRIMESTRE [1 - PRIMERO | 2 - SEGUNDO]", fourthQuarter, 1, 2);
    id = verifyIdRegisterByOption(_comissionFile);
};
void Administrator::inputExamGradeInformation(int &subjectId, int &selectedOption, int &grade, int &examId, int &day, int &month, int &year, bool &attendance) {
    std::cout << "ID DE MATERIA A LA QUE PERTENECE EL EXAMEN: ";
    std::cin >> subjectId;
    std::cout << "ASISTENCIA DEL ESTUDIANTE [1 - PRESENTE | 2 - AUSENTE]: ";
    std::cin >> selectedOption;
    if(selectedOption == 1) {
        attendance = true;
        std::cout << "NOTA EXAMEN: ";
        std::cin >> grade;
    }
    std::cout << std::endl;
    std::cout << "FECHA" << std::endl;
    std::cout << "DIA: ";
    std::cin >> day;
    std::cout << "MES: ";
    std::cin >> month;
    std::cout << "ANIO: ";
    std::cin >> year;
    examId = verifyIdRegisterByOption(_examXStudentXSubject);
};
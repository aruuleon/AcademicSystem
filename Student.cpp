#include <fstream>
#include "Student.h"
#include "System.h"
#include "Fecha.h"

Student::Student() {

};
Student::Student(std::string name, std::string surname, std::string document, std::string email, std::string password, std::string phone, int id, int userType)
:FacultyStaff(name, surname, document, email, password, phone, id, userType) {
};
void Student::showMenu(Student student) {
    int selectedOption;
    do {
        system("cls");
        std::cout << "================================= ALUMNO ================================" << std::endl;
        std::cout << " " << getFullName() << std::endl;
        std::cout << "=========================================================================" << std::endl;
        std::cout << std::endl;
        std::cout << "1 - INSCRIBIRSE A MATERIA" << std::endl;
        std::cout << "2 - DARSE DE BAJA A MATERIA" << std::endl;
        std::cout << "3 - LISTA DE MATERIAS INSCRIPTAS" << std::endl;
        std::cout << "4 - NOTAS DE EXAMEN" << std::endl;
        std::cout << "5 - GENERAR CERTIFICADO EXAMEN" << std::endl;
        std::cout << "6 - EDICION" << std::endl;
        std::cout << "7 - MI PERFIL" << std::endl;
        std::cout << "0 - CERRAR SESION" << std::endl;
        std::cout << std::endl;
        std::cout << "=========================================================================" << std::endl;
        processValidationForTheFirstCase("SELECCIONAR UNA OPCION", selectedOption, 0, 7);
        system("cls");
        sendRequest(student, selectedOption);
    } while(selectedOption != 0);
};
void Student::sendRequest(Student student, int selectedOption) {
    switch(selectedOption) {
        case 1: registerToSubject(student);
            break;
        case 2: removeSubject(student);
            break;
        case 3: showRegisteredSubjects(student);
            break;
        case 4: showExamsByStudent(student);
            break;
        case 5: requestCertificate(student);
            break;
        case 6: editInformationRegisterByOption(_studentFile, student);
            break;
        case 7: showInformationRegisterByOption(student);
            break;
        case 0: logout();
            break;
    }
};
void Student::registerToSubject(Student student) {
    int subjectId;
    int careerId = verifyStudentCareerId(student);
    showSubjectsOfTheCareer(careerId);
    std::cout << "SELECCIONAR ID DE MATERIA A LA QUE QUIERE REGISTRARSE: ";
    std::cin >> subjectId;
    if(_studentXSubjectFile.save(StudentXSubject(student.getId(), subjectId))) {
        Subject subject = _subjectFile.read(_subjectFile.searchRecord(subjectId));
        std::cout << "USTED FUE REGISTRADO A LA SIGUIENTE MATERIA CORRECTAMENTE" << std::endl;
        subject.show();
    }
};
int Student::verifyStudentCareerId(Student student) {
    int careerId;
    int numberOfRecordsRelationship = _subjectXCareerFile.numberOfRecords();
    int positionRelationship = 0;
    bool relationshipFound = false;
    std::cout << "MATERIAS DE LA CARRERA" << std::endl;
    while(!relationshipFound && positionRelationship < numberOfRecordsRelationship) {
        StudentXCareer studentXCareer = _studentXCareerFile.read(positionRelationship);
        if(studentXCareer.getFirstResourceId() == student.getId()) {
            int numberOfRecordsCareer = _careerFile.numberOfRecords();
            int positionCareer = 0;
            bool careerFound = false;
            while(!careerFound && positionCareer < numberOfRecordsCareer) {
                Career career = _careerFile.read(positionCareer);
                if(career.getState() && career.getId() == studentXCareer.getSecondResourceId()) {
                    careerFound = true;
                    careerId = career.getId();
                }
            }
            relationshipFound = true;
        }
        positionRelationship++;
    }
    return careerId;
};
void Student::showSubjectsOfTheCareer(int careerId) {
    int numberOfRecordsRelationship = _subjectXCareerFile.numberOfRecords();
    int numberOfRecordsSubject = _subjectFile.numberOfRecords();
    Career career = _careerFile.read(_careerFile.searchRecord(careerId));
    
    for(int i = 0; i < numberOfRecordsRelationship; i++) {
        SubjectXCareer subjectXCareer = _subjectXCareerFile.read(i);
        for(int j = 0; j < numberOfRecordsSubject; j++) {
            Subject subject = _subjectFile.read(j);
            if(career.getId() == subjectXCareer.getSecondResourceId() && subject.getState() && subject.getId() == subjectXCareer.getFirstResourceId()) {
                subject.show();
            }
        }
    }
}
void Student::removeSubject(Student student) {
    std::cout << "MATERIA A DARSE DE BAJA" << std::endl;
    showRegisteredSubjects(student);
    std::cout << std::endl;
    int subjectId;
    std::cout << "INGRESAR ID DE MATERIA A DAR DE BAJA: ";
    std::cin >> subjectId;
    withdrawRelationship(_studentXSubjectFile, StudentXSubject(), student, subjectId, "ALUMNO/A", "MATERIA");
};
void Student::showRegisteredSubjects(Student student) {
    std::cout << "=========================================================================" << std::endl;
    std::cout << "                     LISTA DE MATERIAS INSCRIPTAS                        " << std::endl;
    std::cout << "=========================================================================" << std::endl;
    int numberOfRecordsRelationship = _studentXSubjectFile.numberOfRecords();
    int numberOfRecordsSubject = _subjectFile.numberOfRecords();
    for(int i = 0; i < numberOfRecordsRelationship; i++) {
        StudentXSubject studentXSubject = _studentXSubjectFile.read(i);
        if(studentXSubject.getState() && studentXSubject.getFirstResourceId() == student.getId()) {
            for(int j = 0; j < numberOfRecordsSubject; j++) {
                Subject subject = _subjectFile.read(j);
                if(subject.getState() && subject.getId() == studentXSubject.getSecondResourceId()) {
                    subject.show();
                }
            }
        }
    }
    system("pause");
};
void Student::showExamNotes(Student student) {
    showExamsByStudent(student);
};
void Student::showExamsByStudent(Student student) {
    int numberOfRecordsRelationship = _examXStudentXSubjectFile.numberOfRecords();
    int numberOfRecordsSubject = _subjectFile.numberOfRecords();

    std::cout << "=========================================================================" << std::endl;
    std::cout << "               LISTA DE EXAMENES REALIZADOS POR EL ALUMNO                " << std::endl;
    std::cout << "=========================================================================" << std::endl;
    for(int i = 0; i < numberOfRecordsRelationship; i++) {
        ExamXStudentXSubject examXStudentXSubject = _examXStudentXSubjectFile.read(i);
        if(examXStudentXSubject.getSecondResourceId() == student.getId()) {
            int positionSubject = 0;
            bool subjectFound = false;
            while(!subjectFound && positionSubject < numberOfRecordsSubject) {
                Subject subject = _subjectFile.read(positionSubject);
                if(subject.getId() == examXStudentXSubject.getThirdResourceId()) {
                    subjectFound = true;
                    showExam(examXStudentXSubject, subject);
                }
                positionSubject++;
            }
        }
    }
    system("pause");
};
void Student::requestCertificate(Student student) {
    std::cout << "* SOLICITUD CERTIFICADO EXAMEN *" << std::endl;
    std::cout << std::endl;
    
    int numberOfRecordsRelationship = _examXStudentXSubjectFile.numberOfRecords();
    if(numberOfRecordsRelationship > 0) {
        int examId;

        showExamsByStudent(student);
        std::cout << "INGRESAR ID DE EXAMEN PARA GENERAR EL CERTIFICADO: ";
        std::cin >> examId;

        int positionExam = 0;
        bool examFound = false;
        while(!examFound && positionExam < numberOfRecordsRelationship) {
            ExamXStudentXSubject examXStudentXSubject = _examXStudentXSubjectFile.read(positionExam);
            if(examXStudentXSubject.getId() == examId) {
                examFound = true;
                system("cls");
                if(examXStudentXSubject.getAttendance()) {
                    generateCertificate(examXStudentXSubject, student);
                } else {
                    showMessageErrorGenerateCertificate(examId);
                }
                system("pause");
            }
            positionExam++;
        }
    } else {
        std::cout << "NO REALIZASTE EXAMENES POR EL MOMENTO" << std::endl;
    }
    system("pause");
};
void Student::generateCertificate(ExamXStudentXSubject examXStudentXSubject, Student student) {
    int numberOfRecordsSubject = _subjectFile.numberOfRecords();
    int positionSubject = 0;
    bool subjectFound = false;
    while(!subjectFound && positionSubject < numberOfRecordsSubject) {
        Subject subject = _subjectFile.read(positionSubject);
        if(subject.getId() == examXStudentXSubject.getThirdResourceId()) {
            subjectFound = true;
            showGeneratedCertificate(examXStudentXSubject, student, subject);
        }
        positionSubject++;
    }
};
void Student::showGeneratedCertificate(ExamXStudentXSubject examXStudentXSubject, Student student, Subject subject) {
    System system = System("UNIVERSIDAD TECNOLOGICA NACIONAL", "Argentina", "Buenos Aires");
    Fecha date;
    std::cout << std::endl;
    std::cout << "============================================================================================================================================" << std::endl;
    std::cout << "SE CERTIFICA QUE '" << student.getFullName() << "' CON DOCUMENTO '" << student.getDocument() << "'" << std::endl;
    std::cout << "RINDIO EL EXAMEN CORRESPONDIENTE A LA MATERIA " << subject.getName() << " EL DIA DE LA FECHA " << examXStudentXSubject.getDate().toString() << std::endl;
    std::cout << "SE EXTIENDE EL PRESENTE A PEDIDO DEL/LA INTERESADO/A PARA SER PRESENTADO ANTE QUIEN CORRESPONDA" << std::endl;
    std::cout << "A LA FECHA DEL " << date.toString() << ", EN " << system.getLocation() << "."  << std::endl;
    std::cout << std::endl;
    std::cout << "FIRMA INSTITUCION: " << system.getName() << std::endl;
    std::cout << "============================================================================================================================================" << std::endl;
    std::cout << std::endl;
};
void Student::showMessageErrorGenerateCertificate(int examId) {
    std::cout << std::endl;
    std::cout << "============================================================================================================================================" << std::endl;
    std::cout << "NO PODES SOLICITAR EL CERTIFICADO DEL EXAMEN CON ID '" << examId << "' PORQUE ESTUVISTE AUSENTE" << std::endl;
    std::cout << "============================================================================================================================================" << std::endl;
    std::cout << std::endl;
};
void Student::showExam(ExamXStudentXSubject examXStudentXSubject, Subject subject) {
    std::cout << std::endl;
    std::cout << "ID EXAMEN: " << examXStudentXSubject.getId() << std::endl;
    std::cout << "NOTA: " << examXStudentXSubject.getGrade() << std::endl;
    std::cout << "MATERIA: " << subject.getName() << std::endl;
    std::cout << "ASISTENCIA: " << examXStudentXSubject.getAttendanceMessage() << std::endl;
    std::cout << "FECHA: " << examXStudentXSubject.getDate().toString() << std::endl;
    std::cout << std::endl;
    std::cout << "=========================================================================" << std::endl;
};
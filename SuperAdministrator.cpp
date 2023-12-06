#include "SuperAdministrator.h"

SuperAdministrator::SuperAdministrator() {

};
SuperAdministrator::SuperAdministrator(std::string name, std::string surname, std::string document, std::string email, std::string password, std::string phone, int id, int userType)
:FacultyStaff(name, surname, document, email, password, phone, id, userType) {
};
void SuperAdministrator::showMenu(SuperAdministrator superAdministrator) {
    int selectedOption;
    do {
        system("cls");
        std::cout << "========================== SUPER ADMINISTRADOR ==========================" << std::endl;
        std::cout << " " << getFullName() << std::endl;
        std::cout << "=========================================================================" << std::endl;
        std::cout << std::endl;
        std::cout << "1 - ADMINISTRADOR" << std::endl;
        std::cout << "2 - CARRERA" << std::endl;
        std::cout << "3 - MATERIA" << std::endl;
        std::cout << "4 - EDICION" << std::endl;
        std::cout << "5 - MI PERFIL" << std::endl;
        std::cout << "0 - CERRAR SESION" << std::endl;
        std::cout << std::endl;
        std::cout << "=========================================================================" << std::endl;
        processValidationForTheFirstCase("SELECCIONAR UNA OPCION", selectedOption, 0, 5);
        system("cls");
        sendRequest(superAdministrator, selectedOption);
    } while(selectedOption != 0);
};
void SuperAdministrator::sendRequest(SuperAdministrator superAdministrator, int selectedOption) {
    if(selectedOption != 0) {
        if(selectedOption == 4) {
            editInformationRegisterByOption(_superAdministratorFile, superAdministrator);
        } else if(selectedOption == 5) {
            showInformationRegisterByOption(superAdministrator);
        } else {
            showGenericMenu(selectedOption);
        }
    } else {
        logout();
    }
};
void SuperAdministrator::showGenericMenu(int optionReceived) {
    std::string sectionResource;
    int selectedOption;
    if(optionReceived == 1) {
        sectionResource = "ADMINISTRADOR";
    } else if(optionReceived == 2) {
        sectionResource = "CARRERA";
    } else {
        sectionResource = "MATERIA";
    }
    do {
        system("cls");
        std::cout << "=========================================================================" << std::endl;
        std::cout << "                              MENU " << sectionResource << "             " << std::endl;
        std::cout << "=========================================================================" << std::endl;
        std::cout << std::endl;
        std::cout << "1 - REGISTRAR" << std::endl;
        std::cout << "2 - ELIMINAR" << std::endl;
        std::cout << "3 - VOLVER A DAR DE ALTA" << std::endl;
        std::cout << "4 - BUSCAR" << std::endl;
        std::cout << "5 - MOSTRAR LISTA" << std::endl;
        if(optionReceived == 2) {
            std::cout << "6 - ASIGNAR MATERIA A CARRERA" << std::endl;
            std::cout << "7 - MOSTRAR MATERIAS SEGUN CARRERA" << std::endl;
        }
        std::cout << "0 - VOLVER" << std::endl;
        std::cout << std::endl;
        std::cout << "=========================================================================" << std::endl;
        processValidationForTheSecondCase("SELECCIONAR UNA OPCION", selectedOption, optionReceived, 1, 2, 3, 0, 5, 7);
        system("cls");
        sendGenericRequest(optionReceived, selectedOption);
    } while(selectedOption != 0);
};
void SuperAdministrator::sendGenericRequest(int optionReceived, int selectedOption) {
    switch(selectedOption) {
        case 1: registerByOption(optionReceived);
            break;
        case 2: withdrawByOption(optionReceived);
            break;
        case 3: reEnrollByOption(optionReceived);
            break;
        case 4: searchByOption(optionReceived);
            break;
        case 5: listByOption(optionReceived);
            break;
        case 6: setResourceRelationship(_subjectFile, _careerFile, _subjectXCareerFile, SubjectXCareer(), "MATERIA", "CARRERA");
            break;
        case 7: showFirstResourcesBySecondResources(_subjectFile, _careerFile, _subjectXCareerFile, SubjectXCareer(), Subject(), Career(), "MATERIAS", "CARRERA");
        break;
    }
};
void SuperAdministrator::registerByOption(int optionReceived)  {
    switch(optionReceived) {
        case 1: registerAdministrator();
            break;
        case 2: registerCareer();
            break;
        case 3: registerSubject();
            break;
    }
};
void SuperAdministrator::withdrawByOption(int optionReceived) {
    switch(optionReceived) {
        case 1: withdrawRegisterByOption(_administratorFile, "user");
            break;
        case 2: withdrawResource(_careerFile, _subjectXCareerFile, SubjectXCareer(), Career(), withdrawRegisterByOption(_careerFile, "resource"));
            break;
        case 3: withdrawResource(_subjectFile, _subjectXCareerFile, SubjectXCareer(), Subject(), withdrawRegisterByOption(_subjectFile, "resource"));
            break;
    }
};
void SuperAdministrator::reEnrollByOption(int optionReceived) {
    switch(optionReceived) {
        case 1: reEnrollRegisterByOption(_administratorFile, "user");
            break;
        case 2: reEnrollRegisterByOption(_careerFile, "resource");
            break;
        case 3: reEnrollRegisterByOption(_subjectFile, "resource");
            break;
    }
};
void SuperAdministrator::searchByOption(int optionReceived) {
    switch(optionReceived) {
        case 1: searchRegisterByOption(_administratorFile);
            break;
        case 2: searchRegisterByOption(_careerFile);
            break;
        case 3: searchRegisterByOption(_subjectFile);
            break;
    }
};
void SuperAdministrator::listByOption(int optionReceived) {
    switch(optionReceived) {
        case 1: listRegisterByOption(_administratorFile, "ADMINISTRADOR");
            break;
        case 2: listRegisterByOption(_careerFile, "CARRERA");
            break;
        case 3: listRegisterByOption(_subjectFile, "MATERIA");
            break;
    }
};
void SuperAdministrator::registerAdministrator() {
    std::string name, surname, document, email, password, phone;
    int id;

    inputAdministratorInformation(name, surname, document, email, password, phone, id);
    _administratorFile.save(Administrator(name, surname, document, email, password, phone, id, 2));
    _userLoginFile.save(UserLogin(password, id, 2));
    system("pause");
};
void SuperAdministrator::registerCareer() {
    std::string name;
    int studyType, id, duration;

    inputCareerInformation(name, id, studyType, duration);
    _careerFile.save(Career(name, studyType, id, duration));
    system("pause");
};
void SuperAdministrator::registerSubject() {
    std::string name;
    int id, duration, yearCareer;

    inputSubjectInformation(name, id, duration, yearCareer);
    _subjectFile.save(Subject(name, duration, id, yearCareer));
    system("pause");
};
void SuperAdministrator::inputAdministratorInformation(std::string &name, std::string &surname, std::string &document, std::string &email, std::string &password, std::string &phone, int &id) {
    std::cout << "=========================================================================" << std::endl;
    std::cout << "                           INFORMACION ADMINISTRADOR                     " << std::endl;
    std::cout << "=========================================================================" << std::endl;
    std::cout << "NOMBRE: ";
    std::cin.ignore();
    getline(std::cin, name);
    std::cout << "APELLIDO: ";
    getline(std::cin, surname);
    std::cout << "DNI: ";
    std::cin >>  document; 
    std::cout << "CORREO: ";
    std::cin >>  email;
    std::cout << "TELEFONO: ";
    std::cin >>  phone;
    std::cout << "CLAVE: ";
    std::cin >> password;
    id = verifyIdRegisterByOption(_administratorFile);
};
void SuperAdministrator::inputCareerInformation(std::string &name, int &id, int &studyType, int &duration) {
    std::cout << "=========================================================================" << std::endl;
    std::cout << "                           INFORMACION CARRERA                           " << std::endl;
    std::cout << "=========================================================================" << std::endl;
    processValidationForTheFirstCase("TIPO DE ESTUDIO [1 - TECNICATURA | 2 - CARRERA DE GRADO | 3 - POSGRADO]", studyType, 1, 3);
    std::cout << "NOMBRE: ";
    std::cin.ignore();
    getline(std::cin, name);
    std::cout << "DURACION: ";
    std::cin >> duration;
    std::cout << std::endl;
    id = verifyIdRegisterByOption(_careerFile);
};
void SuperAdministrator::inputSubjectInformation(std::string &name, int &id, int &duration, int &yearCareer) {
    std::cout << "=========================================================================" << std::endl;
    std::cout << "                           INFORMACION MATERIA                           " << std::endl;
    std::cout << "=========================================================================" << std::endl;
    std::cout << "NOMBRE: ";
    std::cin.ignore();
    getline(std::cin, name);
    processValidationForTheFirstCase("DURACION [1 - CUATRIMESTRAL | 2 - ANUAL]", duration, 1, 2);
    std::cout << std::endl;
    std::cout << "ANIO DE LA CARRERA EN EL QUE SE DICTA LA MATERIA: ";
    std::cin >> yearCareer;
    id = verifyIdRegisterByOption(_subjectFile);
};
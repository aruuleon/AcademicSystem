#pragma once
#include "FacultyStaff.h"
#include "GenericFile.h"
#include "SuperAdministrator.h"
#include "Administrator.h"
#include "Subject.h"
#include "Career.h"
#include "SubjectXCareer.h"
#include "Functions.h"

class SuperAdministrator : public FacultyStaff {
    private:
        GenericFile <SuperAdministrator> _superAdministratorFile = GenericFile <SuperAdministrator> ("superAdministrators.dat");
        GenericFile <Administrator> _administratorFile = GenericFile <Administrator> ("administrators.dat");
        GenericFile <UserLogin> _userLoginFile = GenericFile <UserLogin> ("usersLogin.dat");
        GenericFile <Career> _careerFile = GenericFile <Career> ("careers.dat");
        GenericFile <Subject> _subjectFile = GenericFile <Subject> ("subjects.dat");
        GenericFile <SubjectXCareer> _subjectXCareerFile = GenericFile <SubjectXCareer> ("subjectsXCareers.dat");
    public:
        SuperAdministrator();
        SuperAdministrator(std::string, std::string, std::string, std::string, std::string, std::string, int, int);
        void showMenu(SuperAdministrator);
        void sendRequest(SuperAdministrator, int);
        void sendGenericRequest(int, int);
        void showGenericMenu(int);
        void registerByOption(int);
        void withdrawByOption(int);
        void reEnrollByOption(int);
        void searchByOption(int);
        void listByOption(int);
        void registerAdministrator();
        void registerCareer();
        void registerSubject();
        void inputAdministratorInformation(std::string&, std::string&, std::string&, std::string&, std::string&, std::string&, int&);
        void inputCareerInformation(std::string&, int&, int&, int&);
        void inputSubjectInformation(std::string&, int&, int&, int&);
};
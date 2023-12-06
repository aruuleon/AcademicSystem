#pragma once
#include "FacultyStaff.h"
#include "Teacher.h"
#include "Student.h"
#include "UserLogin.h"
#include "Notice.h"
#include "Subject.h"
#include "Comission.h"
#include "GenericFile.h"
#include "SubjectXComission.h"
#include "StudentXSubject.h"
#include "Career.h"
#include "StudentXCareer.h"
#include "TeacherXSubject.h"
#include "SubjectXCareer.h"
#include "ExamXStudentXSubject.h"
#include "ExamXSubject.h"
#include "Administrator.h"
#include "Functions.h"

class Administrator : public FacultyStaff {
    private:
        GenericFile <Administrator> _administratorFile = GenericFile <Administrator> ("administrators.dat");
        GenericFile <Teacher> _teacherFile = GenericFile <Teacher> ("teachers.dat");
        GenericFile <Student> _studentFile = GenericFile <Student> ("students.dat");
        GenericFile <UserLogin> _userLoginFile = GenericFile <UserLogin> ("usersLogin.dat");
        GenericFile <Notice> _noticeFile = GenericFile <Notice> ("notices.dat");
        GenericFile <Comission> _comissionFile = GenericFile <Comission> ("comissions.dat");
        GenericFile <Subject> _subjectFile = GenericFile <Subject> ("subjects.dat");
        GenericFile <SubjectXCareer> _subjectXCareerFile = GenericFile <SubjectXCareer> ("subjectsXCareers.dat");
        GenericFile <Career> _careerFile = GenericFile <Career> ("careers.dat");
        GenericFile <TeacherXSubject> _teacherXSubjectFile = GenericFile <TeacherXSubject> ("teachersXSubjects.dat");
        GenericFile <SubjectXComission> _subjectXComissionFile = GenericFile <SubjectXComission> ("subjectsXComissions.dat");
        GenericFile <StudentXSubject> _studentXSubjectFile = GenericFile <StudentXSubject> ("studentsXSubjects.dat");
        GenericFile <StudentXCareer> _studentXCareerFile = GenericFile <StudentXCareer> ("studentsXCareers.dat");
        GenericFile <ExamXStudentXSubject> _examXStudentXSubject = GenericFile <ExamXStudentXSubject> ("examsXStudentsXSubjects.dat");
    public:
        Administrator();
        Administrator(std::string, std::string, std::string, std::string, std::string, std::string, int, int);
        void showMenu(Administrator);
        void sendRequest(Administrator, int);
        void registerStaff(int);
        void withdrawStaff(int);
        void reEnrollStaff(int);
        void verifyInformation(int);
        void listStaff(int);
        void postNotice();
        void editNotice();
        void showGenericMenu(int);
        void showMenuNotice();
        void showMenuComission();
        void sendUserTypeRequest(int, int);
        void sendGenericRequest(int, int);
        void sendTeacherRequest(int);
        void sendStudentRequest(int);
        void sendNoticeRequest(int);
        void sendComissionRequest(int);
        void registerComission();
        void editComission();
        void assignGradeStudent();
        void showSubjectsByStudent(int);
        void finishGradingProcess(int);
        void modifyGradeStudent();
        void assignTeacherToSubject();
        void showSubjects(int, int, int);
        void finishAssignmentProcess(int, int, int, int);
        void inputStaffInformation(std::string&, std::string&, std::string&, std::string&, std::string&, std::string&);
        void inputNoticeInformation(std::string&, std::string&, int&, int&, int&, int&);
        void inputComissionInformation(int&, int&, int&, int&, int&);
        void inputExamGradeInformation(int&, int&, int&, int&, int&, int&, int&, bool&);
};
#pragma once

#include "FacultyStaff.h"
#include "Career.h"
#include "Subject.h"
#include "StudentXCareer.h"
#include "ExamXStudentXSubject.h"
#include "GenericFile.h"
#include "Student.h"
#include "SubjectXCareer.h"
#include "StudentXSubject.h"
#include "ExamXSubject.h"
#include "Functions.h"

class Student : public FacultyStaff {
    private:
        GenericFile <Student> _studentFile = GenericFile <Student> ("students.dat");
        GenericFile <SubjectXCareer> _subjectXCareerFile = GenericFile <SubjectXCareer> ("subjectsXCareers.dat");
        GenericFile <StudentXCareer> _studentXCareerFile = GenericFile <StudentXCareer> ("studentsXCareers.dat");
        GenericFile <StudentXSubject> _studentXSubjectFile = GenericFile <StudentXSubject> ("studentsXSubjects.dat");
        GenericFile <Career> _careerFile = GenericFile <Career> ("careers.dat");
        GenericFile <Subject> _subjectFile = GenericFile <Subject> ("subjects.dat");
        GenericFile <ExamXSubject> _examXSubjectFile = GenericFile <ExamXSubject> ("examsXSubjects.dat");
        GenericFile <ExamXStudentXSubject> _examXStudentXSubjectFile = GenericFile <ExamXStudentXSubject> ("examsXStudentsXSubjects.dat");
    public:
        Student();
        Student(std::string, std::string, std::string, std::string, std::string, std::string, int, int);
        void showMenu(Student);
        void sendRequest(Student, int);
        void registerToSubject(Student);
        void removeSubject(Student);
        void showRegisteredSubjects(Student);
        void showExamNotes(Student);
        void showExamsByStudent(Student);
        void requestCertificate(Student);
        void generateCertificate(ExamXStudentXSubject, Student);
        void showGeneratedCertificate(ExamXStudentXSubject, Student, Subject);
        void showMessageErrorGenerateCertificate(int);
        void showExam(ExamXStudentXSubject, Subject);
        int verifyStudentCareerId(Student);
        void showSubjectsOfTheCareer(int);
};
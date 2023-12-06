#pragma once
#include "FacultyStaff.h"
#include "GenericFile.h"
#include "Teacher.h"
#include "Subject.h"
#include "TeacherXSubject.h"
#include "Functions.h"

class Teacher : public FacultyStaff {
    private:
        GenericFile <Teacher> _teacherFile = GenericFile <Teacher> ("teachers.dat");
        GenericFile <Subject> _subjectFile = GenericFile <Subject> ("subjects.dat");
        GenericFile <TeacherXSubject> _teacherXSubjectFile = GenericFile <TeacherXSubject> ("teachersXSubjects.dat");
    public:
        Teacher();
        Teacher(std::string, std::string, std::string, std::string, std::string, std::string, int, int);
        void showMenu(Teacher);
        void sendRequest(Teacher, int);
        void showAssignedSubjects(Teacher);
        void showPersonalInformation(Teacher);
};
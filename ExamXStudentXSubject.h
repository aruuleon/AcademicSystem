#pragma once
#include <string>
#include "Fecha.h"

class ExamXStudentXSubject {
    private:
        int _id;
        int _secondResourceId;
        int _thirdResourceId;
        int _grade;
        bool _attendance;
        bool _state;
        Fecha _date;
    public:
        ExamXStudentXSubject();
        ExamXStudentXSubject(int, int, int, int, bool, Fecha);
        std::string getAttendanceMessage() const;
        int getId() const;
        int getSecondResourceId() const;
        int getThirdResourceId() const;
        int getGrade() const;
        bool getAttendance() const;
        bool getState() const;
        Fecha getDate() const;
        void setId(int);
        void setSecondResourceId(int);
        void setThirdResourceId(int);
        void setGrade(int);
        void setAttendance(bool);
        void setState(bool);
        void setDate(Fecha);
};
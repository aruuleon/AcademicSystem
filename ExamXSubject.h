#pragma once
#include <string>

class ExamXSubject {
    private:
        int _firstResourceId;
        int _secondResourceId;
        bool _state;
    public:
        ExamXSubject();
        ExamXSubject(int, int);
        int getFirstResourceId() const;
        int getSecondResourceId() const;
        bool getState() const;
        void setFirstResourceId(int);
        void setSecondResourceId(int);
        void setState(bool);
};
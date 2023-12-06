#pragma once
#include <string>

class SubjectXCareer {
    private:
        int _firstResourceId;
        int _secondResourceId;
        bool _state;
    public:
        SubjectXCareer();
        SubjectXCareer(int, int);
        int getFirstResourceId() const;
        int getSecondResourceId() const;
        bool getState() const;
        void setFirstResourceId(int);
        void setSecondResourceId(int);
        void setState(bool);
};
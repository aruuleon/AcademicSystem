#pragma once
#include <string>

class Career {
    private:
        char _name[60];
        int _studyType;
        int _id;
        int _duration;
        bool _state;
    public:
        Career();
        Career(std::string, int, int, int);
        std::string getName() const;
        std::string getStudyType() const;
        int getId() const;
        int getDuration() const;
        bool getState() const;
        void setName(std::string);
        void setStudyType(int);
        void setId(int);
        void setDuration(int);
        void setState(bool);
        void show();
};
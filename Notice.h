#pragma once
#include <string>
#include <cstring>
#include "Fecha.h"

class Notice{
    private:
        char _title[80];
        char _content[500];
        int _id;
        bool _state;
        Fecha _fecha;
    public:
        Notice();
        Notice(std::string, std::string, int, Fecha);
        Fecha getFecha() const;
        std::string getTitle() const;
        std::string getContent() const;
        int getId() const;
        bool getState() const;
        void setFecha(Fecha);
        void setTitle(std::string);
        void setContent(std::string);
        void setId(int);
        void setState(bool);
        void show();
};
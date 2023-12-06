#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

template <class T>
class GenericFile {
private:
    char _fileName[30];
public:
    GenericFile(){

    };
    GenericFile(std::string fileName) {
        strcpy(_fileName, fileName.c_str());
    };
    T read(int position) {
        T facultyStaff;
        FILE * file = fopen(_fileName, "rb");
        if(file == nullptr){
            return facultyStaff;
        }
        fseek(file, sizeof(T) * position, SEEK_SET);
        fread(&facultyStaff, sizeof(T), 1, file);
        fclose(file);
        return facultyStaff;
    };
    int searchRecord(int id) {
        FILE * file = fopen(_fileName, "rb");
        if(file == nullptr){
            return -1;
        }
        T facultyStaff;
        int position = 0;
        while(fread(&facultyStaff, sizeof(T), 1, file)) {
            if(facultyStaff.getId() == id){
                fclose(file);
                return position;
            }
            position++;
        }
        fclose(file);
        return -1;
    };
    int searchRecord(std::string document) {
        FILE * file = fopen(_fileName, "rb");
        if(file == nullptr){
            return -1;
        }
        T facultyStaff;
        int position = 0;
        while(fread(&facultyStaff, sizeof(T), 1, file)) {
            if(facultyStaff.getDocument() == document){
                fclose(file);
                return position;
            }
            position++;
        }
        fclose(file);
        return -1;
    };
    int numberOfRecords() {
        FILE * file = fopen(_fileName, "rb");
        if(file == nullptr){
            return -1;
        }
        fseek(file, 0, SEEK_END);
        int bytes = ftell(file);
        fclose(file);
        return bytes / sizeof(T);
    };
    bool numberOfActiveRecords() {
        FILE * file = fopen(_fileName, "rb");
        if(file == nullptr){
            return false;
        }
        int numberOfRecords = this->numberOfRecords();
        int position = 0;
        bool activeRecord = false;
        while(!activeRecord && position < numberOfRecords) {
            T resource = this->read(position);
            if(resource.getState()) {
                activeRecord = true;
            }
            position++;
        }
        return activeRecord;
    };
    bool save(const T& facultyStaff) {
        FILE * file = fopen(_fileName, "ab");
        if(file == nullptr) {
            return false;
        }
        bool successfulSave = fwrite(&facultyStaff, sizeof(T), 1, file);
        fclose(file);
        return successfulSave;
    };
    bool save(const T& facultyStaff, int position) {
        FILE * file = fopen(_fileName, "rb+");
        if(file == nullptr) {
            return false;
        }
        fseek(file, position * sizeof(T), SEEK_SET);
        bool successfulSave = fwrite(&facultyStaff, sizeof(T), 1, file);
        fclose(file);
        return successfulSave;
    };
    bool deleteRecord(int registryNumber){
        bool couldEliminate = false;
        int position = searchRecord(registryNumber);
        T facultyStaff = read(position);
        facultyStaff.setState(false);
        return save(facultyStaff, position);
    };
    bool addOrDelete(int file, int action){
        int position = searchRecord(file);
        if(position != -1) {
            T facultyStaff = read(position);
            if(action == 1){
                facultyStaff.setState(true);
            } else {
                facultyStaff.setState(false);
            }
            return save(facultyStaff, position);
        } else {
            return false;
        }
    };
};
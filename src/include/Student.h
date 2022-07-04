#ifndef STUDENT_HEADER
#define STUDENT_HEADER

#include "People.h"

class Student : public People
{
public:
    string roll_no;
    int _class;
    char section;

    Student();
    void setRollNo();
    string getRollNo();
    void setClass();
    int getClass();
    void setSection();
    char getSection();

    void addSection();
    string getSections(int);


    void display_record();
    void create();
    void read_record();
    void update_record();
    void delete_record();

};
#endif
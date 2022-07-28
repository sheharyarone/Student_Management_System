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
    void setClass();
    void setSection();

    void display_record();
    void create();
    static void read_record();
    void update_record();
    void delete_record();

};
#endif
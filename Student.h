#ifndef STUDENT_HEADER
#define STUDENT_HEADER

#include <D:\PROJECT\People.h>

class Student : public People
{
public:
    string roll_no;
    string _class;
    string section;

    Student();
    void setRollNo();
    string getRollNo();
    void setClass();
    string getClass();
    void setSection();
    string getSection();
    void create();
    void read_record();
    void update_record();

};
#endif
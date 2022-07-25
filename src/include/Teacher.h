#ifndef TEACHER_HEADER
#define TEACHER_HEADER

#include "People.h"


class Teacher : public People
{
    public:
    string id;
    string teaching_classes;
    string section;

    Teacher();
    void setID();
    string getID();
    void addClass(); // depend upon whether  we use  file 
    string getTeachingClasses(); //handling or csv file 
    void create();
    void readrec(string tofind);
    void updrec();
    void delrec(int n);
};
#endif

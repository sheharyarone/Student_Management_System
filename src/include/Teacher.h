#ifndef TEACHER_HEADER
#define TEACHER_HEADER

#include "People.h"

class Teacher : public People
{
    public:
    string id;
    string teaching_classes;

    Teacher(){}
    void setID();
    string getID();
    void addClass(); // depend upon whether  we use  file 
    string getTeachingClasses(); //handling or csv file 

};
#endif

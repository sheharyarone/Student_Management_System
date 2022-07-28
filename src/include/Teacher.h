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
    void addClass();
    void create();
    static void read_record();
    void update_record();
    void delete_record(int n);
};
#endif

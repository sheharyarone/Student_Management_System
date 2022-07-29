#ifndef TEACHER_HEADER
#define TEACHER_HEADER

#include "People.h"

class Teacher : public People
{
public:
    string id;
    int teaching_classes;
    char section;

    Teacher();
    void addClass();
    void create();
    static void read_record();
    void update_record();
    void delete_record(int n);
    void add_Class();
    bool avoid_duplicate_entry();
    void setID();


    private:
    void getNameAgaintsID(string);



};
#endif

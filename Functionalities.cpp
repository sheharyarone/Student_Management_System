#include "src\Student_Imp.cpp"
#include "src\Teacher_Imp.cpp"
#include "src\People_Imp.cpp"
#include "src\RoomManag_Imp.cpp"


void add_student()
{
    Student s1;
    People *ptr = &s1;
    ptr->create();
}
void add_teacher()
{
    Teacher t1;
    People *ptr = &t1;
    ptr->create();
}
void read_student()
{
    Student::read_record();
}
void read_teacher()
{
    Teacher::read_record();
}
void update_student()
{
    Student s1;
    People *ptr = &s1;
    ptr->update_record();

}
void update_teacher()
{
    Teacher t1;
    People *ptr = &t1;
    ptr->update_record();
}
void delete_student()
{
    Student s1;
    s1.delete_record();
}
void delete_teacher()
{
    int idd;
    cout<<"Enter the id of the teacher to be deleted : ";
    cin>>idd;
    Teacher t1;
    t1.delete_record(idd);
}
void add_class_to_room()
{
    Room_Class r1;
    r1.create();
}
void update_class_to_room()
{
    Room_Class r1;
    r1.update_record();
}   
void class_room_num_against_section()

{
    Room_Class r1;
    r1.Room_Num_Againts_SectionClass();
}
void add_another_class()
{
    Teacher t1;
    t1.add_Class();

}
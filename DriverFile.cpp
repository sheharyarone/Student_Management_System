#include "src\Student_Imp.cpp"
#include "src\Teacher_Imp.cpp"
#include "src\People_Imp.cpp"
#include "src\RoomManag_Imp.cpp"



int main()
{
    Student s;
    s.read_record();
    s.update_record();
    s.delete_record();
    return 0;
}
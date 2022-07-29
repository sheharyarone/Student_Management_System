#ifndef ROOM_HEADER
#define ROOM_HEADER

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include <typeinfo>
#include <sstream>
using namespace std;

class Room_Class
{
public:
    int room_no;
    int _class;
    char section;

public:
    void Room_Num_Againts_SectionClass();
    void setroom_no();
    Room_Class();
    void create();
    void update_record();
    void read_record();
    bool check_classAndSection();

    private:
    bool check_room(int);
    bool check_room();  
    void set_class();
    void set_section();
};

#endif
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
    string section;

public:
    void setroom_no();
    void set_class();
    


    void set_section();
    Room_Class();
    void create();
    void update_record();
    void read_record();
    void availabe_rooms();

    private:
    bool check_class();
    bool check_room(int);
    bool check_room();
    
};

#endif
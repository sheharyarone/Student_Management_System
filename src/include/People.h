#ifndef PEOPLE_HEADER
#define PEOPLE_HEADER

#include <iostream>
#include<stdio.h>
#include <string>
#include <vector>
#include<fstream>
#include<sstream>


using namespace std;

class People
{

public:
    string name;

    People() {}
    virtual void setName();
    virtual void create()=0; // NEED TO BE SORT OUT 
    static void read_record();
    virtual void update_record()=0;

};
#endif
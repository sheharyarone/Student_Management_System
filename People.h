#ifndef PEOPLE_HEADER
#define PEOPLE_HEADER

#include <iostream>
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
    virtual string getName();
    
    virtual void create()=0; // NEED TO BE SORT OUT 

};
#endif
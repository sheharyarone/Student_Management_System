#ifndef PEOPLE_HEADER
#define PEOPLE_HEADER

#include<iostream>
#include<string>
using namespace std;

class People {

    public:
    string name;
    string username;
    string password;

    People(){}
    virtual void setName();
    virtual string getName();
    virtual void setUsername();
    virtual string getUsername();
    virtual void setPassword();
    virtual string getPassword();



};
#endif
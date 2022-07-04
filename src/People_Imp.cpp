#include "include\People.h"


void People :: setName(){
    cout<<"NAME : ";
    getline(cin,name);
}
string People :: getName(){
    return name;
}

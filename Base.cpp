#include<iostream>
#include<string>
using namespace std;

class People {

    public:
    string name;
    string username;
    string password;

    People();
    virtual void setName();
    virtual string getName();
    virtual void setUsername();
    virtual string getUsername();
    virtual void setPassword();
    virtual string getPassword();



};
void People :: setName(){
    cout<<"NAME : ";
    getline(cin,name);
}
string People :: getName(){
    return name;
}
void People :: setUsername() {
    cout<<"USERNAME : ";
    getline(cin,username);
}
string People::getUsername()
{
    return username;
}
void People :: setPassword() {
    string _password;
    cout<<"PASSWORD : ";
    getline(cin,_password);
    cout<<"ENTER AGAIN TO CONFIRM PASSWORD : ";
    getline(cin,password);
    if (!( _password == password)){
        setPassword();
    }else{
        cout<<"YOUR PASSWORD HAS BEEN CREATED ! "<<endl;
    }
}
string People:: getPassword() {
    return password;
}

class Student: public People {
    public:

    string roll_no;
    string _class;
    string section;


    Student();
    void setRollNo();
    string getRollNo();
    void setClass();
    string getClass();
    void setSection();
    string getSection();
    

};

Student::Student() {
    setName();
    setUsername();
    setPassword();
    setRollNo();
    setClass();
    setSection();
    cout<<getName()<<endl;
    cout<<getUsername()<<endl;
    cout<<getPassword()<<endl;

}
void Student::setClass(){
    cout<<"ENTER THE CLASS : ";
    getline(cin,_class);
}
string Student::getClass(){
    return _class;
}
void Student::setSection(){
    cout<<"ENTER THE SECTION : ";
    getline(cin,section);

}
string Student::getSection() {
    return section;
}
void Student::setRollNo(){
    cout<<"ENTER THE ROLL NO. : ";
    getline(cin,roll_no);
}
string Student::getRollNo(){
    return roll_no;
}
int main(int argc, char const *argv[])
{
    Student S1;
    
    return 0;
}

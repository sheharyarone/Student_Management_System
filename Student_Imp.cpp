
#include<D:\PROJECT\Student.h>
#include<D:\PROJECT\People.h>



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


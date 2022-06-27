
#include <D:\PROJECT\Student.h>
#include <D:\PROJECT\People.h>

Student::Student()
{
    setName();
    setPassword();
    setRollNo();
    setClass();
    setSection();
    cout<<"Printing details: \n";
    cout << getName() << endl;
    cout << getPassword() << endl;
    cout<<getRollNo()<<endl;
    cout<<getClass()<<endl;
    cout<<getSection()<<endl;
    create();

}
void Student::setClass()
{
    cout << "ENTER THE CLASS : ";
    getline(cin, _class);
}
string Student::getClass()
{
    return _class;
}
void Student::setSection()
{
    cout << "ENTER THE SECTION : ";
    getline(cin, section);
}
string Student::getSection()
{
    return section;
}
void Student::setRollNo()
{
    cout << "ENTER THE ROLL NO. : ";
    getline(cin, roll_no);
}
string Student::getRollNo()
{
    return roll_no;
}
void Student::create(){
    // file pointer
    fstream fout;
  
    // opens an existing csv file or creates a new file.
    fout.open("StudentRecord.csv", ios::out | ios::app);
        // Insert the data to file
        fout << name << ", "
             << password << ", "
             << roll_no << ", "
             << _class << ", "
             << section 
             << "\n";
    
}
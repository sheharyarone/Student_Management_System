#include<iostream>
#include<string>
using namespace std;

class Person {

    public :

    int user_id;
    string password_check;
    string name;
    string password ;
    string title;
    bool isActive;
    int userLevel;

    public:

    void Login();
    void Logout();
    void initPassword();
    void changePassword();
    void ListAllUsers();
    void AddNewTutor();
    void ModifyTutor();
    void AddNewSubject();
    void ModifySubject();
    void ShowStudents();
    void ShowTutors();
    void ShowSubjects();
    void CheckUserLevel();
    void resetUserPassword();
    void lockOrUnlockUser();

};
class Student : public Person 
{
    public :
    void requestJoinSubject();


};
class Tutor : public Person 
{
    public:
    void addCommentOfUserRequest();

};
class Teacher : public Person 
{
    public:
    void acceptOrDenyUserRequest();

};

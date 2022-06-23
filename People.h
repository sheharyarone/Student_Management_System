#include<iostream>
#include<string>
using namespace std;

class Person {

   protected:
        /*  level : 1  -->  student
         *  level : 2  -->  tutor
         *  level : 3  -->  teacher    */

    int userLevel;
    int user_id;
    string name;
    string password = "-1";
    string title;
    bool isActive;

    public:
     /*
     * constructor and destructor
     */
    People();

    People(int userId,const string &name,const string &password,bool isActive);

    People(const string &name,const string &title);

    virtual ~People();

     /*
     * object getter and setter
     */

    virtual int getUserId() const;
    virtual void setUserId(int);
    virtual const string getName() const;
    virtual setName(const string &name);
    virtual string getPasdword() const;
    virtual void setPassword(const string &password);
    virtual const string getTitle() const;
    virtual void setTitle(const string &title);
    virtual bool _isActive() const;
    virtual void setIsActive(bool isActive);
    virtual int getUserLevel() const;
    virtual void setUserLevel(int userLevel) ;

    // void Login();
    // void Logout();
    // void initPassword();
    // void changePassword();
    // void ListAllUsers();
    // void AddNewTutor();
    // void ModifyTutor();
    // void AddNewSubject();
    // void ModifySubject();
    // void ShowStudents();
    // void ShowTutors();
    // void ShowSubjects();
    // void CheckUserLevel();
    // void resetUserPassword();
    // void lockOrUnlockUser();

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

#include<D:\PROJECT\People.h>
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
        cout<<"PASWORDS DOESN'T MATCHES."<<endl;
        setPassword();
    }else{
        cout<<"YOUR PASSWORD HAS BEEN CREATED ! "<<endl;
    }
}
string People:: getPassword() {
    return password;
}

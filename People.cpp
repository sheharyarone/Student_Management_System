#include <D:\PROJECT\HeaderFile.h>
#include <typeinfo>
#define quote(x) #x

void Person ::Login()
{
    int _user_id;

    string _password;
    while (1)
    {
        cout << "ENTER USER ID : ";
        cin >> _user_id;
        cout << "ENTER THE PASSWORD : ";
        cin >> _password;
        if ((_user_id == user_id) && (_password == password))
        {
            cout << "LOGIN SUCCESSFUL" << endl;
            break;
        }
        else
        {
            cout << "LOGIN FAILED" << endl;
        }
    }
}
void Person ::initPassword()
{
    while (1)
    {
        string _password;
        cout << "CREATE YOUR OWN PASSWORD :  ";
        cin >> password;
        cout << "ENTER THE PASSWORD AGAIN : ";
        cin >> _password;
        if (!(password == _password))
        {
            cout << "PASSWORDS DOESN'T MATCHES.TRY AGAIN !" << endl;
        }
        else
        {
            cout << "PASSWORD CREATED!" << endl;
            break;
        }
    }
    // PASSWORD RESET CHECK
    cout << "ENTER YOUR FAVOURITE ANIMAL FOR PASSWORD IN CASE YOU NEED TO RESET LATER! : ";
    cin >> password_check;
}
void Person ::changePassword()
{
    string _password;
    while (1)
    {
        cout << "ENTER YOUR OLD PASSWORD : ";
        cin >> _password;
        if (!(_password == password))
        {
            cout << "OLD PASSWORD DOESN'T MATCHES ! TRY AGAIN !" << endl;
            changePassword();
        }
        cout << "ENTER NEW PASSWORD : " << endl;
        cin >> _password;
        cout << "ENTER THE PASSWORD AGAIN : " << endl;
        cin >> password;
        if (!(password == _password))
        {
            cout << "PASSWORDS DOESN'T MATCHES.TRY AGAIN !" << endl;
        }
        else
        {
            cout << "PASSWORD UPDATED!" << endl;
            break;
        }
    }
}
void Person ::CheckUserLevel()
{
    cout << "PERSON" << endl;
}
void Person ::resetUserPassword()
{
    string check;
    cout << "ENTER YOUR FAVOURITE ANIMAL : ";
    cin >> check;
    if (check == password_check)
    {
        string _password;
        while (true)
        {
            cout << "ENTER NEW PASSWORD : " << endl;
            cin >> _password;
            cout << "ENTER THE PASSWORD AGAIN : " << endl;
            cin >> password;
            if (!(password == _password))
            {
                cout << "PASSWORDS DOESN'T MATCHES.TRY AGAIN !" << endl;
            }
            else
            {
                cout << "PASSWORD UPDATED!" << endl;
                break;
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    
    return 0;
}

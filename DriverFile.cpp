#include "Functionalities.cpp"

int main()
{

    while (true)
    {

        cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<WELCOME TO OUR SCHOOL MANAGEMENT SYSTEM>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
        cout << endl
             << "PLEASE SELECT FROM THE OPTIONS AVAILABLE" << endl
             << "1.PRESS 1 FOR STUDENT INFO" << endl
             << "2.PRESS 2 FOR TEACHER INFO" << endl
             << "3.PRESS 3 TO CHECK ROOMS" << endl
             << "4.PRESS 'Q' TO QUIT " << endl
             << "PLEASE ENTER YOUR CHOICE : ";
        char choice;
        cin >> choice;
        cin.ignore();
        if (choice == '1')
        {
            while (true)
            {

                cout << "\n\n\n\n"
                     << "PLEASE SELECT FROM THE OPTIONS AVAILABLE" << endl
                     << "1.PRESS 1 TO CREATE RECORD" << endl
                     << "2.PRESS 2 TO READ RECORD" << endl
                     << "3.PRESS 3 TO UPDATE RECORD" << endl
                     << "4.PRESS  4 TO DELETE RECORD " << endl
                     << "5.PRESS  5 TO GO BACK " << endl
                     << "CHOOSE FROM THE OPTIONS : ";
                char option;
                cin >> option;
                cin.ignore();
                if (option == '1')
                {
                    add_student();
                }
                else if (option == '2')
                {
                    read_student();
                }
                else if (option == '3')
                {
                    update_student();
                }
                else if (option == '4')
                {
                    delete_student();
                }
                else if (option == '5')
                {
                    break;
                }
            }
            continue;
        }
        else if (choice == '2')
        {
            while (true)
            {

                cout << "\n\n\n\n"
                     << "PLEASE SELECT FROM THE OPTIONS AVAILABLE" << endl
                     << "1.PRESS 1 TO CREATE RECORD" << endl
                     << "2.PRESS 2 TO READ RECORD" << endl
                     << "3.PRESS 3 TO UPDATE RECORD" << endl
                     << "4.PRESS  4 TO DELETE RECORD " << endl
                     << "5.PRESS  5 TO GO BACK " << endl
                     << "CHOOSE FROM THE OPTIONS : ";
                char option;
                cin >> option;
                cin.ignore();
                if (option == '1')
                {
                    add_teacher();
                }
                else if (option == '2')
                {
                    read_teacher();
                }
                else if (option == '3')
                {
                    update_teacher();
                }
                else if (option == '4')
                {
                    delete_teacher();
                }
                else if (option == '5')
                {
                    break;
                }
            }
            continue;
        }
        else if (choice == '3')
        {
            while (true)
            {

                cout << "\n\n\n\n"
                     << "PLEASE SELECT FROM THE OPTIONS AVAILABLE" << endl
                     << "1.PRESS 1 TO CREATE ROOM" << endl
                     << "2.PRESS 2 TO UPDATE RECORD" << endl
                     << "3.PRESS 3 TO CHECK YOUR CLASSROOM NUMBER" << endl
                     << "4.PRESS  4 TO GO BACK " << endl
                     << "CHOOSE FROM THE OPTIONS : ";
                char option;
                cin >> option;
                if (option == '1')
                {
                    add_class_to_room();
                }
                else if (option == '2')
                {
                    update_class_to_room();
                }
                else if (option == '3')
                {
                    class_room_num_against_section();
                }
                else if (option == '4')
                {
                    break;
                }
            }
            continue;
        }
        else if (choice == 'Q' || 'q')
        {
            break;
        }
        else
        {
            cout << "INVALID CHOICE";
            continue;
        }
    }
    cout << "THANKYOU FOR USING, SIGNING OFF!!!";
    return 0;
}
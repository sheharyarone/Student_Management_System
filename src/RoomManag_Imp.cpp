#include "include\RoomManagement.h"

void Room_Class::Room_Num_Againts_SectionClass()
{

    string __class, __section;
    cout << "ENTER THE CLASS : ";
    cin >> __class;
    cout << "ENTER THE SECTION : ";
    cin >> __section;

    __class = " " + __class;
    __section = " " + __section;

    fstream fin;
    fin.open("src/csv/RoomAllocation.csv", ios::in);
    vector<string> row;
    string line, word, temp;
    int count = 0;
    while (getline(fin, line))
    {
        stringstream s(line);
        cout << line << endl;
        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        if (row[2] == __class && row[3] == __section)
        {
            count = 1;
            // break;
        }
        row.clear();
    }
    if (count == 0)
    {
        cout << "No room for this class and section" << endl;
    }
    else
    {
        cout << "ROOM FOR THIS CLASS AND SECTION: " << endl;
        cout << "Room No: " << row[1] << endl;
    }
}
bool Room_Class::check_room(int x)
{
    if (x >= 1 && room_no <= 20)
    {

        // File pointer
        fstream fin;

        // string file_dir = "/csv/datafiles/";
        // string csvFile = file_dir + "/RoomAllocation.csv";

        // Open an existing file
        fin.open("src/csv/RoomAllocation.csv", ios::in);

        // Read the Data from the file
        // as String Vector
        vector<string> row;
        string line, word, temp;
        int count = 0;
        while (fin >> temp)
        {

            row.clear();

            // read an entire row and
            // store it in a string variable 'line'
            getline(fin, line);

            // cout<<line<<endl;

            // used for breaking words
            stringstream s(line);

            // read every column data of a row and
            // store it in a string variable, 'word'
            while (getline(s, word, ','))
            {

                // add all the column data
                // of a row to a vector
                row.push_back(word);
            }

            if (stoi(row[0]) == x)
            {
                count = 1;
            }
        }
        if (count == 0)
        {

            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        cout << "INVALID ROOM NUMBER" << endl;

        return true;
    }
}
bool Room_Class::check_room()
{
    if (room_no >= 1 && room_no <= 20)
    {

        // File pointer
        fstream fin;

        // string file_dir = "/csv/datafiles/";
        // string csvFile = file_dir + "/RoomAllocation.csv";

        // Open an existing file
        fin.open("src/csv/RoomAllocation.csv", ios::in);

        // Read the Data from the file
        // as String Vector
        vector<string> row;
        string line, word, temp;
        int count = 0;
        while (fin >> temp)
        {

            row.clear();

            // read an entire row and
            // store it in a string variable 'line'
            getline(fin, line);

            // cout<<line<<endl;

            // used for breaking words
            stringstream s(line);

            // read every column data of a row and
            // store it in a string variable, 'word'
            while (getline(s, word, ','))
            {

                // add all the column data
                // of a row to a vector
                row.push_back(word);
            }

            if (stoi(row[0]) == room_no)
            {
                count = 1;
            }
        }
        if (count == 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        cout << "INVALID ROOM NUMBER" << endl;

        return true;
    }
}
bool Room_Class::check_class()
{
    // File pointer
    fstream fin;

    // Open an existing file
    fin.open("src/csv/RoomAllocation.csv", ios::in);

    // Read the Data from the file
    // as String Vector

    string _section;
    _section = ' ' + section;
    vector<string> row;
    string line, word, temp;
    int count = 0;
    while (fin >> temp)
    {
        row.clear();

        // read an entire row and
        // store it in a string variable 'line'
        getline(fin, line);

        // used for breaking words
        stringstream s(line);

        // read every column data of a row and
        // store it in a string variable, 'word'
        while (getline(s, word, ','))
        {

            // add all the column data
            // of a row to a vector
            row.push_back(word);
        }

        if (((row[2]) == _section) && (stoi(row[1]) == _class))
        {
            count = 1;
        }
    }
    if (count == 0)
    {

        return false;
    }
    else
    {
        return true;
    }
}
Room_Class::Room_Class()
{
    // setroom_no();
    // set_class();
    // set_section();
    // create();
    // read_record();
    // update_record();
}
void Room_Class::setroom_no()
{
    cout << "ENTER THE NEW ROOM NO. BTW 1 and 20 : ";
    cin >> room_no;

    if (check_room())
    {
        cout << "ROOM ALREADY OCCUPIED" << endl;
        setroom_no();
    }
}
void Room_Class ::set_class()
{
    cout << "ENTER THE CLASS FOR WHICH YOU WANT TO ALLOCATE ROOM: ";
    cin >> _class;
    if (_class < 1 || _class > 8)
    {
        cout << "INVALID CLASS" << endl;
        cout << "ONLY 1 TO 8 CLASSES ARE ALLOWED" << endl;
        set_class();
    }
}
void Room_Class ::set_section()
{
    cout << "ENTER THE SECTION : ";
    cin >> section;
    for (int i = 0; i < section.length(); i++)
        section[i] = toupper(section[i]);
    if ((check_class()))
    {
        cout << "SECTION ALREADY EXISTS" << endl;
        cout << "TRY AGAIN" << endl;
        set_class();
    }
}
void Room_Class ::create()
{
    // file pointer
    fstream fout;

    // opens an existing csv file or creates a new file.
    fout.open("src/csv/RoomAllocation.csv", ios::out | ios::app);

    // Insert the data to file
    fout << ", " << room_no << ", "
         << _class << ", "
         << section
         << endl;
}
void Room_Class::read_record()
{

    // File pointer
    fstream fin;

    // Open an existing file
    fin.open("src/csv/RoomAllocation.csv", ios::in);

    // Get the roll number
    // of which the data is required
    int room;
    cout << "ENTER THE ROOM NO. YOU WANT DETAILS ABOUT : ";
    cin >> room;

    // Read the Data from the file
    // as String Vector
    vector<string> row;
    string line, word, temp;
    int count = 0;

    while (fin >> temp)
    {
        row.clear();

        // read an entire row and
        // store it in a string variable 'line'
        getline(fin, line);
        // cout << line << endl;
        // used for breaking words
        stringstream s(line);
        // cout<<line<<endl; FOR TESTING PRUPOSE

        // read every column data of a row and
        // store it in a string variable, 'word'
        while (getline(s, word, ','))
        {

            // add all the column data
            // of a row to a vector
            row.push_back(word);
        }

        // convert string to integer for comparision

        // Compare the roll number
        if (stoi(row[0]) == room)
        {
            count = 1;
            cout << "ROOM NO. : " << row[0] << endl;
            cout << "CLASS : " << row[1] << endl;
            cout << "SECTION : " << row[2] << endl;
        }
    }
    if (count == 0)
        cout << "Record not found\n";
}
void Room_Class::update_record()
{
    // File pointer
    fstream fin, fout;

    // Open an existing record
    fin.open("src/csv/RoomAllocation.csv", ios::in);

    // Create a new file to store updated data
    fout.open("src/csv/RoomAllocationnew.csv", ios::out);

    int _room_no, roll1, count = 0, i;
    int sub;
    string new_entry;
    int index;
    string line, word;
    vector<string> row;

    // Get the roll number from the user

    // Get the data to be updated
    cout << "ENTER THE ROOM NO. YOU WANT TO UPDATE : ";
    cin >> _room_no;

    if (!(check_room(_room_no)))
    {
        cout << "ROOM ALREADY FREE !" << endl;
        update_record();
    }
    cout << "UPDATED DATA : " << endl;
    setroom_no();

    // Traverse the file
    while (!fin.eof())
    {

        row.clear();

        getline(fin, line);
        // cout<<line<<endl;
        stringstream s(line);

        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        int row_size = row.size();

        if (_room_no == stoi(row[1]))
        {
            count = 1;
            stringstream convert;

            // sending a number as a stream into output string
            convert << room_no;

            // the str() converts number into string
            row[1] = room_no;

            row[1] = convert.str();
            row[1] = ' ' + row[1];

            if (!fin.eof())
            {
                for (i = 0; i < row_size - 1; i++)
                {

                    // write the updated data
                    // into a new file 'reportcardnew.csv'
                    // using fout
                    fout << row[i] << ",";
                }

                fout << row[row_size - 1] << "\n";
            }
        }
        else
        {
            if (!fin.eof())
            {
                for (i = 0; i < row_size - 1; i++)
                {

                    // writing other existing records
                    // into the new file using fout.
                    fout << row[i] << ",";
                }

                // the last column data ends with a '\n'
                fout << row[row_size - 1] << "\n";
            }
        }
        if (fin.eof())
            break;
    }

    fin.close();
    fout.close();

    // removing the existing file
    remove("src/csv/RoomAllocation.csv");

    // renaming the updated file with the existing file name
    rename("src/csv/RoomAllocationnew.csv", "src/csv/RoomAllocation.csv");
}

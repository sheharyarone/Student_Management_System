#include "include/Teacher.h"

// vector<string> CLASS;
// vector<string> Section;
Teacher::Teacher()
{
    //
    // addClass();
}
void Teacher::setID()
{
    int id1 = 1000;
    ifstream myfile;
    myfile.open("src/csv/TeacherRecord.csv");
    vector<string> row;
    int count = 0;
    string line, word;
    while (!(myfile.eof()))
    {
        row.clear();

        getline(myfile, line);
        if (line == "")
        {
            break;
        }
        stringstream s(line);

        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        if (id1 < stoi(row[0]))
        {
            cout << "f" << endl;
            id1 = stoi(row[0]);
        }
    }
    id1 += 1;
    id = to_string(id1);
    cout << "TEACHER WITH THE NAME " << name << " HAS BEEN ASSIGNED THE ID " << id << endl;
}

void Teacher::create()
{
    // file pointer
    setName();
    setID();
    fstream fout;

    // opens an existing csv file or creates a new file.
    fout.open("src/csv/TeacherRecord.csv", ios::out | ios::app);
    // Insert the data to file
    while (true)
    {
        cout << "ENTER THE CLASS YOU WANT TO TEACH : ";
        cin >> teaching_classes;
        cout << endl;
        cout << "ENTER THE SECTION(A/B) : ";
        cin >> section;

        section = toupper(section);
        fout << id << ", "
             << name << ", "
             << teaching_classes << ", " << section << ", " << endl;
        cout << endl
             << "Do you want to teach anyother class? "
             << "(Y/N) :: ";
        char sub;
        cin >> sub;
        if (sub == 'Y' || sub == 'y')
        {
            continue;
        }
        else if (sub == 'N' || 'n')
        {
            cout << "    ENTRY CREATED SUCCESSFULLY    " << endl;
            break;
        }
    }
}
void Teacher::read_record()
{
    string tofind;
    cout << "ENTER THE ID TO FIND : ";
    cin >> tofind;
    ifstream myfile;
    myfile.open("src/csv/TeacherRecord.csv");
    vector<string> row;
    int id1;
    int count = 0;
    string line, word;
    while (!(myfile.eof()))
    {
        row.clear();

        getline(myfile, line);
        if (line == "")
        {
            continue;
        }
        // cout<<line<<endl;
        // if (line.size() == 0) continue;

        stringstream s(line);

        while (getline(s, word, ','))
        {
            row.push_back(word);
        }
        // cout<<row[0];

        int row_size = (int)row.size();
        // id1 = std::stoi(row[0]);
        if (tofind == row[0])
        {

            // Print the found data
            count = 1;
            cout << "Details of ID " << row[0] << " : \n";
            cout << "NAME: " << row[1] << "\n";
            cout << "CLASS BEING TAUGHT: " << row[2] << "\n";
            cout << "SECTION: " << row[3] << "\n";
        }
    }
    if (count == 0)
    {
        cout << "Record not found\n";
    }
}

void Teacher::update_record()
{

    // File pointer
    fstream fin, fout;

    // Open an existing record
    fin.open("src/csv/TeacherRecord.csv", ios::in);

    // Create a new file to store updated data
    fout.open("src/csv/TeacherRecordnew.csv", ios::out);

    int count = 0;
    int sub;
    string new_entry;
    int index;
    string line, word;
    vector<string> row;

    // Get the roll number from the user
    cout << "Enter the ID "
         << "of the record to be updated: ";
    cin >> id;

    cout << "Enter the Data Field "
         << "to be updated: " << endl;
    cout << "1.NAME   2.Class&Section" << endl;
    cin >> sub;

    // IF THE SELECTION IS FOR CLASS&SECTION
    if (sub == 2)
    {
        string oldLine, newLine;
        getNameAgaintsID(id);
        cout << "ENTER THE OLD DATA YOU WANT TO UPDATE : " << endl;
        cout << "CLASS : ";
        cin >> teaching_classes;
        cout << "SECTION : ";
        cin >> section;
        section = toupper(section);

        oldLine = id + "," + name + ", " + to_string(teaching_classes) + ", " + section;
        // Read the data from the file
        char _new_section;
        int _new_teaching_classes;
        cout << "ENTER THE NEW DATA YOU WANT TO UPDATE : " << endl;
        cout << "CLASS : ";
        cin >> _new_teaching_classes;
        cout << "SECTION : ";
        cin >> _new_section;
        _new_section = toupper(_new_section);

        newLine = id + "," + name + ", " + to_string(_new_teaching_classes) + ", " + _new_section;
        cout << oldLine << endl;
        cout << newLine << endl;

        while (!(fin.eof()))
        {
            row.clear();
            getline(fin, line);

            stringstream s(line);
            cout << line << endl;
            if (line == oldLine)
            {
                fout << newLine << endl;
            }
            else
            {
                fout << line << endl;
            }
        }
    }
    else if (sub == 1)
    {
        // IF THE SELECTION IS FOR NAME
        string new_name;
        cout << "ENTER THE NEW NAME YOU WANT TO UPDATE : " << endl;
        getline(cin,new_name);
        while (!(fin.eof()))
        {
            row.clear();
            getline(fin, line);
            stringstream s(line);
            while (getline(s, word, ','))
            {
                row.push_back(word);
            }
            int row_size = (int)row.size();
            if (id == row[0])
            {
                fout << id << ", "
                     << new_name << ","
                     << row[2] << "," << row[3] << endl;
                count = 1;
            }
            else
            {
                fout << line << endl;
            }
        }
    }
    else
    {
        cout << "Wrong choice.Enter again\n";
        update_record();
    }
    // Close the file
    fin.close();
    fout.close();
    // Delete the old file
    remove("src/csv/TeacherRecord.csv");
    // Rename the new file with old file name
    rename("src/csv/TeacherRecordnew.csv", "src/csv/TeacherRecord.csv");
    cout << "Record updated successfully\n";
}

void Teacher::delete_record(int n)
{
    fstream fin, fout;

    // Open the existing file
    fin.open("src/csv/TeacherRecord.csv", ios::in);

    // Create a new file to store the non-deleted data
    fout.open("src/csv/TeacherRecordnew.csv", ios::out);

    int rollnum, roll1, marks, count = 0, i;
    char sub;
    int index, new_marks;
    string line, word;
    vector<string> row;

    // Get the roll number
    // to decide the data to be deleted
    // cout << "Enter the roll number "
    //      << "of the record to be deleted: ";
    // cin >> rollnum;

    // Check if this record exists
    // If exists, leave it and
    // add all other data to the new file
    while (!fin.eof())
    {

        row.clear();
        getline(fin, line);
        stringstream s(line);

        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        int row_size = row.size();
        roll1 = stoi(row[0]);

        // S = row[3];

        // writing all records,
        // except the record to be deleted,
        // into the new file 'reportcardnew.csv'
        // using fout pointer
        if (roll1 != n)
        {
            if (!fin.eof())
            {
                for (i = 0; i < row_size - 1; i++)
                {
                    fout << row[i] << ", ";
                }
                fout << row[row_size - 1] << "\n";
            }
        }
        else
        {
            count = 1;
        }
        if (fin.eof())
            break;
    }
    if (count == 1)
        cout << "Record deleted\n";
    else
        cout << "Record not found\n";

    // Close the pointers
    fin.close();
    fout.close();

    // removing the existing file
    remove("src/csv/TeacherRecord.csv");

    // renaming the new file with the existing file name
    rename("src/csv/TeacherRecordnew.csv", "src/csv/TeacherRecord.csv");
}

void Teacher::add_Class()
{
    cout << "ENTER THE ID OF THE TEACHER : ";
    cin >> id;

    getNameAgaintsID(id);
    cout << "ENTER THE CLASS : ";
    cin >> teaching_classes;

    cout << "ENTER THE SECTION : ";
    cin >> section;
    section = toupper(section);

    if (avoid_duplicate_entry())
    {

        fstream fout;
        fout.open("src/csv/TeacherRecord.csv", ios::app);
        fout << id << "," << name << ", " << teaching_classes << ", " << section << "\n";
        fout.close();
    }
    else
    {
        cout << "ALREADY EXISTS" << endl;
    }
}
void Teacher ::getNameAgaintsID(string id)
{
    fstream fin;
    fin.open("src/csv/TeacherRecord.csv", ios::in);
    while (!fin.eof())
    {
        string line;

        getline(fin, line);
        stringstream s(line);
        string word;
        vector<string> row;
        while (getline(s, word, ','))
        {
            row.push_back(word);
        }
        if ((row[0]) == (id))
        {
            // cout<<row[1]<<endl;
            this->name = row[1];
            break;
        }
    }
    fin.close();
}
bool Teacher::avoid_duplicate_entry()
{
    // File pointer
    fstream fin;

    // Open an existing file
    fin.open("src/csv/TeacherRecord.csv", ios::in);

    // Read the Data from the file
    // as String Vector
    string checkLine = id + "," + name + ", " + to_string(teaching_classes) + ", " + section;
    vector<string> row;
    string line, word, temp;
    int count = 0;
    while (!fin.eof())
    {
        row.clear();

        // read an entire row and
        // store it in a string variable 'line'
        getline(fin, line);

        // used for breaking words
        stringstream s(line);
        if (line == checkLine)
        {
            count = 1;
            break;
        }
        if (count == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
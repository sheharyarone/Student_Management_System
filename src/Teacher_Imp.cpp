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
    cout << "ENTER THE ID : ";
    cin >> id;
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
    cout<<"ENTER THE ID TO FIND : ";
    cin>>tofind;
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

    int rollnum, roll1, count = 0, i;
    int sub;
    string new_entry;
    int index;
    string line, word;
    vector<string> row;

    // Get the roll number from the user
    cout << "Enter the ID "
         << "of the record to be updated: ";
    cin >> rollnum;
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // Get the data to be updated
    cout << "Enter the Data Field "
         << "to be updated: " << endl;
    cout << "1.NAME   2.Class     3.Section" << endl;
    cin >> sub;
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // Determine the index of the subject
    // where Maths has index 2,
    // Physics has index 3, and so on
    if (sub == 1)
        index = 1 + 1;
    else if (sub == 2)
        index = 2 + 1;
    else if (sub == 3)
        index = 3 + 1;
    else
    {
        cout << "Wrong choice.Enter again\n";
        update_record();
    }

    // Get the new marks
    cout << "Enter the updated record value : ";
    cin >> new_entry;
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Traverse the file
    while (!fin.eof())
    {

        row.clear();
        // cout<<"LMAO"<<endl;

        getline(fin, line);
        // cout<<line<<endl;
        stringstream s(line);

        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        int row_size = row.size();

        if (rollnum == stoi(row[0]))
        {
            count = 1;
            stringstream convert;

            // sending a number as a stream into output string
            // convert << new_entry;

            // the str() converts number into string
            // row[index] = convert.str();
            row[index - 1] = new_entry;

            if (!fin.eof())
            {
                for (i = 0; i < row_size - 1; i++)
                {

                    // write the updated data
                    // into a new file 'reportcardnew.csv'
                    // using fout
                    fout << row[i] << ", ";
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
                    fout << row[i] << ", ";
                }

                // the last column data ends with a '\n'
                fout << row[row_size - 1] << "\n";
            }
        }
        if (fin.eof())
            break;
    }
    if (count == 0)
        cout << "Record not found\n";
    else
        cout << "Record Updated Successfully\n";

    fin.close();
    fout.close();

    // removing the existing file
    remove("src/csv/TeacherRecord.csv");

    // renaming the updated file with the existing file name
    rename("src/csv/TeacherRecordnew.csv", "src/csv/TeacherRecord.csv");
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

#include<D:\PROJECT\RoomManagement.h>

bool Room_Class::check_room()
{
    // File pointer
    fstream fin;

    // Open an existing file
    fin.open("RoomAllocation.csv", ios::in);

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

        if (stoi(row[0])==room_no)
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
bool Room_Class::check_room(int x)
{
    // File pointer
    fstream fin;

    // Open an existing file
    fin.open("RoomAllocation.csv", ios::in);

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

        if (stoi(row[0])==x)
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
bool Room_Class::check_class()
{
    // File pointer
    fstream fin;

    // Open an existing file
    fin.open("RoomAllocation.csv", ios::in);

    // Read the Data from the file
    // as String Vector
    
    string _section;
    _section=' '+section;
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
}
void Room_Class::setroom_no()
{
    cout << "ENTER THE NEW ROOM NO. : ";
    cin >> room_no;
    if (check_room()){
        cout << "ROOM ALREADY OCCUPIED !" << endl;
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
        cout << "ONLY ONE TO EIGHT CLASSES ARE ALLOWED" << endl;
        set_class();
    }
}

void Room_Class ::set_section()
{
    cout << "ENTER THE SECTION : ";
    cin >> section;
    for(int i=0;i<section.length();i++)
		section[i]=toupper(section[i]);
    if ((check_class()))
    {
        cout << "SECTION ALREADY EXISTS" << endl;
        cout << "ENTER AGAIN" << endl;
        set_section();
    }
}

void Room_Class ::create()
{
    // file pointer
    fstream fout;

    // opens an existing csv file or creates a new file.
    fout.open("RoomAllocation.csv", ios::out | ios::app);
    // Insert the data to file
    fout <<", " << room_no << ", "
         << _class << ", "
         << section
         << endl;
}
void Room_Class::read_record()

{

    // File pointer
    fstream fin;

    // Open an existing file
    fin.open("RoomAllocation.csv", ios::in);

    // Get the roll number
    // of which the data is required
    int room;
    cout << "ENTER THE ROOM NO. YOU WANT DETAILS ABOUT : ";
    cin >> room;

    // Read the Data from the file
    // as String Vector
    vector<string> row;
    string line, word, temp;
        int count=0;

    while (fin >> temp)
    {

        row.clear();

        // read an entire row and
        // store it in a string variable 'line'
        getline(fin, line);
        // cout << line << endl;
        // used for breaking words
        stringstream s(line);
        cout<<line<<endl;
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

        cout<<row[0]<<endl;
        // Compare the roll number
        if (stoi(row[0])==room)
        {
            count=1;
            cout << "ROOM NO. : " << row[0] << endl;
            cout << "CLASS : " << row[1] << endl;
            cout << "SECTION : " << row[2] << endl;
        }
        
    }
    if (count == 0)
        cout << "Record not found\n";
}
void Room_Class :: update_record(){
    // File pointer
	fstream fin, fout;

	// Open an existing record
	fin.open("RoomAllocation.csv", ios::in);

	// Create a new file to store updated data
	fout.open("RoomAllocationnew.csv", ios::out);

	int _room_no, roll1, count = 0, i;
	int sub;
    string new_entry;
	int index;
	string line, word;
	vector<string> row;

	// Get the data to be updated
	cout <<"ENTER THE ROOM YOU WANT TO CHANGE : ";
    cin>>_room_no;
    if((!check_room(_room_no))){
        cout<<"NO CLASS IS IN THIS ROOM !"<<endl;
        cout<<"ENTER AGAIN!"<<endl;
        update_record();
    }
    else{
        cout<<"UPDATED ROOM:";
        setroom_no();
    }
	while (!fin.eof()) {

		row.clear();
		

		getline(fin, line);
		// cout<<line<<endl;
		stringstream s(line);
        

		while (getline(s, word, ',')) {
			row.push_back(word);

		}
        cout<<stoi(row[1])<<endl;
		int row_size = row.size();

		if (_room_no == stoi(row[1])) {
			count = 1;
			stringstream convert;

			// sending a number as a stream into output string
			convert << room_no;

			// the str() converts number into string
			// row[index] = convert.str();
            row[1]=convert.str();

			if (!fin.eof()) {
				for (i = 0; i < row_size - 1; i++) {

					// write the updated data
					// into a new file 'reportcardnew.csv'
					// using fout
					fout << row[i] << ", ";
				}

				fout << row[row_size - 1] << "\n";
			}
		}
		else {
			if (!fin.eof()) {
				for (i = 0; i < row_size - 1; i++) {

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

	fin.close();
	fout.close();

	// removing the existing file
	remove("RoomAllocation.csv");

	// renaming the updated file with the existing file name
	rename("RoomAllocationnew.csv", "RoomAllocation.csv");
}
// void Student::delete_record(){
// 	 fstream fin, fout;
  
//     // Open the existing file
//     fin.open("StudentRecord.csv", ios::in);
  
//     // Create a new file to store the non-deleted data
//     fout.open("StudentRecordnew.csv", ios::out);
  
//     int rollnum, roll1, marks, count = 0, i;
//     char sub;
//     int index, new_marks;
//     string line, word;
//     vector<string> row;
  
//     // Get the roll number
//     // to decide the data to be deleted
//     cout << "Enter the roll number "
//          << "of the record to be deleted: ";
//     cin >> rollnum;
  
//     // Check if this record exists
//     // If exists, leave it and
//     // add all other data to the new file
//     while (!fin.eof()) {
  
//         row.clear();
//         getline(fin, line);
//         stringstream s(line);
  
//         while (getline(s, word, ',')) {
//             row.push_back(word);
//         }
  
//         int row_size = row.size();
//         roll1 = stoi(row[1]);
  
//         // writing all records,
//         // except the record to be deleted,
//         // into the new file 'reportcardnew.csv'
//         // using fout pointer
//         if (roll1 != rollnum) {
//             if (!fin.eof()) {
//                 for (i = 0; i < row_size - 1; i++) {
//                     fout << row[i] << ", ";
//                 }
//                 fout << row[row_size - 1] << "\n";
//             }
//         }
//         else {
//             count = 1;
//         }
//         if (fin.eof())
//             break;
//     }
//     if (count == 1)
//         cout << "Record deleted\n";
//     else
//         cout << "Record not found\n";
  
//     // Close the pointers
//     fin.close();
//     fout.close();
  
//     // removing the existing file
//     remove("StudentRecord.csv");
  
//     // renaming the new file with the existing file name
//     rename("StudentRecordnew.csv", "StudentRecord.csv");
// }
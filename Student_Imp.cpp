
#include <D:\PROJECT\Student.h>
#include <D:\PROJECT\People.h>

Student::Student()
{
    setName();
    setRollNo();
    setClass();
    setSection();
    create();

}
void Student::setClass()
{
    cout << "ENTER THE CLASS : ";
    cin>>_class;
}
string Student::getClass()
{
    return _class;
}
void Student::setSection()
{
    cout << "ENTER THE SECTION : ";
    cin>>section;
}
string Student::getSection()
{
    return section;
}
void Student::setRollNo()
{
    cout << "ENTER THE ROLL NO. : ";
    cin>>roll_no;
}
int Student::getRollNo()
{
    return roll_no;
}
void Student::create(){
    // file pointer
    fstream fout;
  
    // opens an existing csv file or creates a new file.
    fout.open("StudentRecord.csv", ios::out | ios::app);
        // Insert the data to file
        fout<<", "<<roll_no << " , "
             <<  name << " , "
             << _class << " , "
             << section 
             <<endl;
    
}
void Student::read_record()
{
  
    // File pointer
    fstream fin;
  
    // Open an existing file
    fin.open("StudentRecord.csv", ios::in);
  
    // Get the roll number
    // of which the data is required
    int rollnum, roll2;
    int count = 0;
    cout << "Enter the roll number "
         << "of the student to display details: ";
    cin >> rollnum;
  
    // Read the Data from the file
    // as String Vector
    vector<string> row;
    string line, word, temp;
  
    while (fin >> temp) {
  
        row.clear();
  
        // read an entire row and
        // store it in a string variable 'line'
        getline(fin, line);
        // cout<<line<<endl;
        // used for breaking words
        stringstream s(line);
        // cout<<line<<endl; FOR TESTING PRUPOSE

  
        // read every column data of a row and
        // store it in a string variable, 'word'
        while (getline(s, word, ',')) {
  
            // add all the column data
            // of a row to a vector
            row.push_back(word);
        }
//         for(int i=0; i < row.size(); i++){
//             cout << row.at(i) << ' ';
// }
   
  
        // convert string to integer for comparision
        
        roll2 = stoi(row[0]);
        // Compare the roll number
        if (roll2 == rollnum) {
            
            // Print the found data
            count = 1;
            cout << "Details of Roll " << row[0] << " : \n";
            cout << "NAME: " << row[1] << "\n";
            cout << "CLASS: " << row[2] << "\n";
            cout << "SECTION: " << row[3] << "\n";
            break;
        }
    }
    if (count == 0)
        cout << "Record not found\n";
}
void Student::update_record()
{

	// File pointer
	fstream fin, fout;

	// Open an existing record
	fin.open("StudentRecord.csv", ios::in);

	// Create a new file to store updated data
	fout.open("StudentRecordnew.csv", ios::out);

	int rollnum, roll1, count = 0, i;
	int sub;
    string new_entry;
	int index;
	string line, word;
	vector<string> row;

	// Get the roll number from the user
	cout << "Enter the roll number "
		<< "of the record to be updated: ";
	cin >> rollnum;

	// Get the data to be updated
	cout << "Enter the Data Field "
		<< "to be updated: "<<endl;
        cout<<"1.NAME   2.Class     3.Section"<<endl;
	cin>>sub;

	// Determine the index of the subject
	// where Maths has index 2,
	// Physics has index 3, and so on
	if (sub == 1)
		index = 1+1;
	else if (sub == 2)
		index = 2+1;
	else if (sub == 3 )
		index = 3+1;
	else {
		cout << "Wrong choice.Enter again\n";
		update_record();
	}

	// Get the new marks
	cout << "Enter the updated record value : ";
	cin>>new_entry;

	// Traverse the file
	while (!fin.eof()) {

		row.clear();
		cout<<"LMAO"<<endl;

		getline(fin, line);
		cout<<line<<endl;
		stringstream s(line);

		while (getline(s, word, ',')) {
			row.push_back(word);

		}
		
		roll1 = stoi(row[1]);
		int row_size = row.size();

		if (roll1 == rollnum) {
			count = 1;
			stringstream convert;

			// sending a number as a stream into output string
			// convert << new_entry;

			// the str() converts number into string
			// row[index] = convert.str();
            row[index]=new_entry;

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
	if (count == 0)
		cout << "Record not found\n";

	fin.close();
	fout.close();

	// removing the existing file
	remove("StudentRecord.csv");

	// renaming the updated file with the existing file name
	rename("StudentRecordnew.csv", "StudentRecord.csv");
}
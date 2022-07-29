
#include "include/Student.h"
#include "include/People.h"

Student::Student()
{
	
}
void Student::setClass()
{
    cout << "ENTER THE CLASS : ";
	cin>>_class;
	if (!(_class>=1 && _class<=8)){
		cout<<"INVALID CLASS"<<endl;
		setClass();
	}
}
void Student::setSection()
{
    cout << "ENTER THE SECTION : ";
    cin>>section;
	section=toupper(section);
}
void Student::setRollNo()
{
	 int _roll_no=1000;
	ifstream myfile;
    myfile.open("src/csv/StudentRecord.csv");
	vector<string> row;
	string temp;
 		int count = 0;
		string line,word;	
    while (!(myfile.eof()))
    {
	row.clear();
        	
        getline(myfile, line);
		// cout<<line<<endl;
		// if (line.size() == 0) continue;

		stringstream s(line);
		if (line == "")
		{
			break;
		}

		while (getline(s, word, ',')) {
			row.push_back(word);
			
		}
		if ((stoi(row[1])) > (_roll_no)) {
            
			_roll_no = stoi(row[1]);
        }
  
    }
	_roll_no+=1;
	roll_no=to_string( _roll_no);
	cout<<"PERSON WITH THE NAME "<<name<<" HAS BEEN ASSIGNED THE ROLL NO. "<<roll_no<<endl;
    myfile.close();
}	
void Student::create(){
	setName();
	setRollNo();
	setClass();
	setSection();
    // file pointer
    fstream fout;
  
    // opens an existing csv file or creates a new file.
    fout.open("src/csv/StudentRecord.csv", ios::out | ios::app);
        // Insert the data to file
        fout<<", "<<roll_no << ", "
             <<  name << ", "
             << _class << ", "
             << section 
             <<endl;
    
}
void Student::read_record()
{
    ifstream myfile;
    myfile.open("src/csv/StudentRecord.csv");
	vector<string> row;
	int id1;
	cout<<"ENTER THE ID TO FIND : ";
	cin>>id1;
		int count = 0;
		string line,word;	
    while (!(myfile.eof()))
    {
	row.clear();
        	
        getline(myfile, line);
		// cout<<line<<endl;
		// if (line.size() == 0) continue;

		stringstream s(line);

		while (getline(s, word, ',')) {
			row.push_back(word);
			
		}
		if (id1 == stoi(row[0+1])) {
            
            // Print the found data
            count = 1;
            cout << "Details of ID " << row[0+1] << " : \n";
            cout << "NAME: " << row[1+1] << "\n";
            cout << "CLASS: " << row[2+1] << "\n";
            cout << "SECTION: " << row[3+1] << "\n";
			break;
        }
  
    }
    if (count == 0){
        cout << "Record not found\n";}
    }
void Student::update_record()
{

	// File pointer
	fstream fin, fout;

	// Open an existing record
	fin.open("src/csv/StudentRecord.csv", ios::in);

	// Create a new file to store updated data
	fout.open("src/csv/StudentRecordnew.csv", ios::out);

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
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');
	// Get the data to be updated
	cout << "Enter the Data Field "
		<< "to be updated: "<<endl;
        cout<<"1.NAME   2.Class     3.Section"<<endl;
	cin>>sub;
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');

	// Traverse the file
	while (!fin.eof()) {

		row.clear();
		// cout<<"LMAO"<<endl;

		getline(fin, line);
		// cout<<line<<endl;
		stringstream s(line);

		while (getline(s, word, ',')) {
			row.push_back(word);

		}
		
		
		int row_size = row.size();

		if (rollnum == stoi(row[0+1])) {
			count = 1;
			stringstream convert;

			// sending a number as a stream into output string
			// convert << new_entry;

			// the str() converts number into string
			// row[index] = convert.str();
            row[index]=' '+new_entry;
			

			if (!fin.eof()) {
				for (i = 0; i < row_size - 1; i++) {

					// write the updated data
					// into a new file 'reportcardnew.csv'
					// using fout
					fout << row[i] << ",";
				}

				fout << row[row_size - 1] << "\n";
			}
		}
		else {
			if (!fin.eof()) {
				for (i = 0; i < row_size - 1; i++) {

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
	if (count == 0)
		cout << "Record not found\n";

	fin.close();
	fout.close();

	// removing the existing file
	remove("src/csv/StudentRecord.csv");

	// renaming the updated file with the existing file name
	rename("src/csv/StudentRecordnew.csv", "src/csv/StudentRecord.csv");
}
void Student::delete_record(){
	 

	// Open FIle pointers
	fstream fin, fout;

	// Open the existing file
	fin.open("src/csv/StudentRecord.csv", ios::in);

	// Create a new file to store the non-deleted data
	fout.open("src/csv/StudentRecordnew.csv", ios::out);

	int id1, count = 0, i;
	string line, word ,temp,line1;
	vector<string> row;
	cout<<"ENTER THE ID TO DELETE : ";
	cin>>id1;


	// Check if this record exists
	// If exists, leave it and
	// add all other data to the new file
	while (!fin.eof()) {

		row.clear();
		getline(fin, line);
		if (line.size() == 0) break;

		stringstream s(line);
		cout<<line<<endl;

		while (getline(s, word, ',')) {
			row.push_back(word);
		}
		if (id1==stoi(row[1])){
			count=1;
			break;
		}
	}
		while (fin >> temp){
			row.clear();
			getline(fin,line1);
			
			stringstream s(line1);
			line1=","+line1;

			if (line !=line1){
				
				fout<<line1<<endl;
			}
		}
    fin.close();
    fout.close();
    remove("src/csv/StudentRecord.csv");
    rename("src/csv/StudentRecordnew.csv", "src/csv/StudentRecord.csv");
	if (count == 1){
		cout << "Record deleted\n";       
    }
	else{
		cout << "Record not found\n";
    }

}
void Student::display_record(){
	fstream fin;
	fin.open("src/csv/StudentRecord.csv", ios::in);
	string line, word;
	vector<string> row;
	cout<<"ROLL NO.\t NAME\t\tCLASS\t\tSECTION\n";
	while (!fin.eof()) {
		row.clear();
		getline(fin, line);
		stringstream s(line);
		while (getline(s, word, ',')) {
			row.push_back(word);
		}
		int row_size = (int)row.size();
		for (int i = 0; i < row_size; i++) {
			cout << row[i] << "\t\t";
		}
		cout << endl;
	}
	fin.close();
}


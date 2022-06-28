
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
        cout<<line<<endl;
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
/*Student Record Management System using C++*/

#include <iostream>
#include <string>
#include <limits>
using namespace std;

string roll_no[30], name[30], Class[30], course[30], mobile_no[30], admission_year[30]; // Arrays for storing student data
int total = 0; // To store all data

bool isValidRollNo(const string& rollNo) 
{
    if (rollNo.length() > 3) return false;
    for (size_t i = 0; i < rollNo.length(); ++i) 
	{
        if (!isdigit(rollNo[i])) return false;
    }
    return true;
}

bool isValidName(const string& name) 
{
    if (name.length() > 30) return false;
    for (size_t i = 0; i < name.length(); ++i) 
	{
        if (!isalpha(name[i]) && !isspace(name[i])) return false;
    }
    return true;
}

bool isValidMobileNo(const string& mobileNo) 
{
    if (mobileNo.length() != 10) return false;
    for (size_t i = 0; i < mobileNo.length(); ++i) 
	{
        if (!isdigit(mobileNo[i])) return false;
    }
    return true;
}

bool isValidAdmissionYear(const string& admissionYear) 
{
    if (admissionYear.length() != 4) return false;
    for (size_t i = 0; i < admissionYear.length(); ++i) 
	{
        if (!isdigit(admissionYear[i])) return false;
    }
    return true;
}

void enter() 
{
    int ch = 0;
    cout << "How many students do you want to enter?" << endl;
    cin >> ch;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

    if (total == 0) 
	{
        total = ch;
        for (int i = 0; i < ch; i++) 
		{
            string rollNo, studentName, mobileNo, admissionYear, studentClass, courseName;
            cout << "\nEnter the Data of student " << i + 1 << endl << endl;

            while (true) 
			{
                cout << "Enter Roll NO: ";
                getline(cin, rollNo);
                if (isValidRollNo(rollNo)) break;
                cout << "Invalid Roll No. It should be up to 3 digits." << endl;
            }
            roll_no[i] = rollNo;

            while (true) 
			{
                cout << "Enter Name: ";
                getline(cin, studentName);
                if (isValidName(studentName)) break;
                cout << "Invalid Name. It should be up to 30 characters and contain only letters and spaces." << endl;
            }
            name[i] = studentName;

            while (true) 
			{
                cout << "Enter Class: ";
                getline(cin, studentClass);
                Class[i] = studentClass;
                break;
            }

            while (true) 
			{
                cout << "Enter Course: ";
                getline(cin, courseName);
                course[i] = courseName;
                break;
            }

            while (true) 
			{
                cout << "Enter Mobile NO: ";
                getline(cin, mobileNo);
                if (isValidMobileNo(mobileNo)) break;
                cout << "Invalid Mobile No. It should be exactly 10 digits." << endl;
            }
            mobile_no[i] = mobileNo;

            while (true) 
			{
                cout << "Enter Admission Year: ";
                getline(cin, admissionYear);
                if (isValidAdmissionYear(admissionYear)) break;
                cout << "Invalid Admission Year. It should be exactly 4 digits." << endl;
            }
            admission_year[i] = admissionYear;
        }
    } 
	else 
	{
        for (int i = total; i < ch + total; i++) 
		{
            string rollNo, studentName, mobileNo, admissionYear, studentClass, courseName;
            cout << "\nEnter the Data of student " << i + 1 << endl << endl;

            while (true) 
			{
                cout << "Enter Roll NO: ";
                getline(cin, rollNo);
                if (isValidRollNo(rollNo)) break;
                cout << "Invalid Roll No. It should be up to 3 digits." << endl;
            }
            roll_no[i] = rollNo;

            while (true) 
			{
                cout << "Enter Name: ";
                getline(cin, studentName);
                if (isValidName(studentName)) break;
                cout << "Invalid Name. It should be up to 30 characters and contain only letters and spaces." << endl;
            }
            name[i] = studentName;

            while (true) 
			{
                cout << "Enter Class: ";
                getline(cin, studentClass);
                Class[i] = studentClass;
                break;
            }

            while (true) 
			{
                cout << "Enter Course: ";
                getline(cin, courseName);
                course[i] = courseName;
                break;
            }

            while (true) 
			{
                cout << "Enter Mobile NO: ";
                getline(cin, mobileNo);
                if (isValidMobileNo(mobileNo)) break;
                cout << "Invalid Mobile No. It should be exactly 10 digits." << endl;
            }
            mobile_no[i] = mobileNo;

            while (true) 
			{
                cout << "Enter Admission Year: ";
                getline(cin, admissionYear);
                if (isValidAdmissionYear(admissionYear)) break;
                cout << "Invalid Admission Year. It should be exactly 4 digits." << endl;
            }
            admission_year[i] = admissionYear;
        }
        total = ch + total; // Update total count
    }
}

void show() 
{
    if (total == 0) 
	{
        cout << "No Data is Entered!!!" << endl;
    } 
	else 
	{
        for (int i = 0; i < total; i++) 
		{
            cout << "\nData of Student " << i + 1 << endl << endl;
            cout << "Roll NO: " << roll_no[i] << endl;
            cout << "Name: " << name[i] << endl;
            cout << "Class: " << Class[i] << endl;
            cout << "Course: " << course[i] << endl;
            cout << "Mobile NO: " << mobile_no[i] << endl;
            cout << "Admission Year: " << admission_year[i] << endl;
        }
    }
}

void search() 
{
    if (total == 0) 
	{
        cout << "No data is entered!!!" << endl;
    } 
	else 
	{
        string rollno;
        cout << "Enter the roll no of student " << endl;
        getline(cin, rollno);
        for (int i = 0; i < total; i++) 
		{
            if (rollno == roll_no[i]) 
			{
                cout << "Roll NO: " << roll_no[i] << endl;
                cout << "Name: " << name[i] << endl;
                cout << "Class: " << Class[i] << endl;
                cout << "Course: " << course[i] << endl;
                cout << "Mobile NO: " << mobile_no[i] << endl;
                cout << "Admission Year: " << admission_year[i] << endl;
                return; // Exit after finding the student
            }
        }
        cout << "Student with Roll NO " << rollno << " not found." << endl;
    }
}

void update() 
{
    if (total == 0) 
	{
        cout << "No data is entered!!!" << endl;
    } 
	else 
	{
        string rollno;
        cout << "Enter the roll no of student which you want to update: " << endl;
        getline(cin, rollno);
        for (int i = 0; i < total; i++) 
		{
            if (rollno == roll_no[i]) 
			{
                cout << "\nPrevious data" << endl << endl;
                cout << "Data of Student " << i + 1 << endl;
                cout << "Roll NO: " << roll_no[i] << endl;
                cout << "Name: " << name[i] << endl;
                cout << "Class: " << Class[i] << endl;
                cout << "Course: " << course[i] << endl;
                cout << "Mobile NO: " << mobile_no[i] << endl;
                cout << "Admission Year: " << admission_year[i] << endl;
                cout << "\nEnter new data" << endl << endl;

                while (true) 
				{
                    cout << "Enter Roll NO: ";
                    getline(cin, roll_no[i]);
                    if (isValidRollNo(roll_no[i])) break;
                    cout << "Invalid Roll No. It should be up to 3 digits." << endl;
                }

                while (true) 
				{
                    cout << "Enter Name: ";
                    getline(cin, name[i]);
                    if (isValidName(name[i])) break;
                    cout << "Invalid Name. It should be up to 30 characters and contain only letters and spaces." << endl;
                }

                while (true) 
				{
                    cout << "Enter Class: ";
                    getline(cin, Class[i]);
                    break;
                }

                while (true) 
				{
                    cout << "Enter Course: ";
                    getline(cin, course[i]);
                    break;
                }

                while (true) 
				{
                    cout << "Enter Mobile NO: ";
                    getline(cin, mobile_no[i]);
                    if (isValidMobileNo(mobile_no[i])) break;
                    cout << "Invalid Mobile No. It should be exactly 10 digits." << endl;
                }

                while (true) 
				{
                    cout << "Enter Admission Year: ";
                    getline(cin, admission_year[i]);
                    if (isValidAdmissionYear(admission_year[i])) break;
                    cout << "Invalid Admission Year. It should be exactly 4 digits." << endl;
                }
                return; // Exit after updating the student
            }
        }
        cout << "Student with Roll NO " << rollno << " not found." << endl;
    }
}

void Delete() 
{
    if (total == 0) 
	{
        cout << "No data is entered yet!!!" << endl;
    } 
	else 
	{
        int a;
        cout << "Are you sure you want to delete data?" << endl;
        cout << "Press 1 to delete all records" << endl;
        cin >> a;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
        if (a == 1) 
		{
            total = 0;
            cout << "All records are deleted!!!" << endl;
        } 
		else 
		{
            cout << "Please press 1 to delete all records " << endl;
        }
    }
}

int main() // Main function, execution of the program starts from here
{
    int value;
    while (true) // Always in loop
    {
        cout << "Student Record Management System using C++" << endl << endl;
        cout << "\nPress 1 to Enter data" << endl;
        cout << "Press 2 to Show data" << endl;
        cout << "Press 3 to Search data" << endl;
        cout << "Press 4 to Update data" << endl;
        cout << "Press 5 to Delete data" << endl;
        cout << "Press 6 to Quit" << endl;
        cin >> value;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
        switch (value) 
		{
            case 1: enter(); break;
            case 2: show(); break;
            case 3: search(); break;
            case 4: update(); break;
            case 5: Delete(); break;
            case 6:
                cout << "\nThank you" << endl;
                cout << "Designed & Developed by Hemant Katta :)" << endl;
                return 0; // Exit the program
            default: cout << "Invalid input" << endl; break;
        }
    }
}

/*
OUTPUT:

		Student Record Management System using C++


		Press 1 to Enter data
		Press 2 to Show data
		Press 3 to Search data
		Press 4 to Update data
		Press 5 to Delete data
		Press 6 to Quit
		1
		How many students do you want to enter?
		2

		Enter the Data of student 1

		Enter Roll NO: 19R11A0467
		Invalid Roll No. It should be up to 3 digits.
		Enter Roll NO: 467
		Enter Name: Katta
		Enter Class: XI
		Enter Course: MPC
		Enter Mobile NO: 79685432156
		Invalid Mobile No. It should be exactly 10 digits.
		Enter Mobile NO: 1234567890
		Enter Admission Year: 2345

		Enter the Data of student 2

		Enter Roll NO: 19R11A0468
		Invalid Roll No. It should be up to 3 digits.
		Enter Roll NO: 468
		Enter Name: Hemant
		Enter Class: XII
		Enter Course: MPC
		Enter Mobile NO: 1234560987
		Enter Admission Year: 167543
		Invalid Admission Year. It should be exactly 4 digits.
		Enter Admission Year: 4071
		
		
		Student Record Management System using C++


		Press 1 to Enter data
		Press 2 to Show data
		Press 3 to Search data
		Press 4 to Update data
		Press 5 to Delete data
		Press 6 to Quit
		3

		Enter the roll no of student
		19R11A0467
		Student with Roll NO 19R11A0467 not found.
		Student Record Management System using C++


		Press 1 to Enter data
		Press 2 to Show data
		Press 3 to Search data
		Press 4 to Update data
		Press 5 to Delete data
		Press 6 to Quit
		3

		Enter the roll no of student
		468
		Roll NO: 468
		Name: Hemant
		Class: XII
		Course: MPC
		Mobile NO: 1234560987
		Admission Year: 4071
		
		
		Student Record Management System using C++


		Press 1 to Enter data
		Press 2 to Show data
		Press 3 to Search data
		Press 4 to Update data
		Press 5 to Delete data
		Press 6 to Quit
		6

		Thank you
		Designed & Developed by Hemant Katta :)

--------------------------------
Process exited after 192.8 seconds with return value 0
Press any key to continue . . .
*/

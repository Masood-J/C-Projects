/*You need to create a program to track student attendance records using file handling.
The program should allow teachers to mark attendance and store the data in a file for
each day.
• Design a Student class with attributes like Roll Number, name, and is Present.
• Save attendance records in a file named with the current date (e.g., attendance_2024-12-
21.txt).
• Provide functionality to display all attendance records from a file, sorted by Roll
Number.
• Ensure the program creates a new file for each day and doess not overwrite existing data.
• Handle file-related errors, such as when trying to read a file that does not exist.*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Student{
private:
int rollNumber;
string name;
bool isPresent;
string date;
public:

Student(){};
Student(int roll_Number, string studentName, bool present,string attendanceDate){
    rollNumber=roll_Number;
    name=studentName;
    isPresent=present;
    date=attendanceDate;
}
 string getAttendanceFilename() const {
    return "attendance-" + date + ".txt"; 
  }
void record_attendance(){
    ofstream file;
    string attendenceDate=getAttendanceFilename();
    file.open(attendenceDate,ios::app);
        if(file.is_open()){
            file<<rollNumber<<" "<<name<<" "<<isPresent<<endl;
            file.close();
        }
    
}
};
class Record:public Student{
public:
string Date;
Record(string attendace_date){
    Date=attendace_date;
}
string getAttendanceFilename(){ 
    return "attendance-" + Date + ".txt";
  }
string AttendenceData=getAttendanceFilename();
void display_attendance(){
    ifstream file1;
    file1.open(AttendenceData,ios::in);
    if(file1.is_open()){
        string line;
        while(getline(file1,line)){
            cout<<line<<endl;
        }
        file1.close();
    }
}};
int main(){
    int choice=0;
    
    while(choice!=3){
         cout<<"----------Student Attendance Record System----------"<<endl;
         cout<<"Please Enter Your Choice!"<<endl;
         cout<<"1. Record Attendance"<<endl;
         cout<<"2. Display Attendance"<<endl;
         cout<<"3.Exit Program"<<endl; 
         cin>>choice;
         cin.ignore();
    switch(choice){
        case 1:
        {
            int rollNumber;
            string name;
            bool isPresent;
            string date;
            cout<<"Enter Studnent Roll NO:";
            cin>>rollNumber;
            cin.ignore();
            cout<<endl;
            cout<<"Enter Studnent Name:";
            cin>>name;
            cin.ignore();
            cout<<endl;
            cout<<"Enter Student Attendance (Either 1 For True or 0 For False):";
            cin>>isPresent;
            cin.ignore();
            cout<<endl;
            cout<<"Enter Date:";
            getline(cin,date);
            cin.ignore();
            cout<<endl;
            Student student1(rollNumber,name,isPresent,date);
            student1.record_attendance();
            break;
        }
        case 2:
        {
            string RecordDate;
            cout<<"Write Respective Date To Get Attendence Info:";
            getline(cin,RecordDate);
            cin.ignore();
            cout<<endl;
            string DataFile="attendance-"+RecordDate+".txt";
            ifstream file1(DataFile);
            if(file1.is_open()){
                string line;
                while(getline(file1,line)){
                    cout<<line<<endl;
                }
                file1.close();

            }
            else{
                cout<<"File Not Found"<<endl;
            }
            break;

        }
        case 3:
    {
        cout<<"Exiting Program"<<endl;
        break;
    }
    }}
    return 0;
}

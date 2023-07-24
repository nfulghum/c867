//
//  roster.cpp
//  c867
//
//  Created by Nicholas Fulghum on 7/20/23.
//
#include <iostream>
#include <string>
#include "roster.hpp"



void Roster::parse(string studentData)
{
    int rhs = studentData.find(",");
    string sID = studentData.substr(0, rhs);

    int lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string fn = studentData.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string ln = studentData.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string em = studentData.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int age = stoi(studentData.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int dic1 = stoi(studentData.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int dic2 = stoi(studentData.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int dic3 = stoi(studentData.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);

    DegreeProgram dp = NETWORK;
    if (studentData.at(lhs) == 'S' && studentData.at(lhs + 1) == 'E'){
        dp = SECURITY;}
    else if (studentData.at(lhs) == 'S' && studentData.at(lhs + 1) == 'O'){
        dp = SOFTWARE;}
    else if (studentData.at(lhs) == 'N'){
        dp = NETWORK;}

    add(sID, fn, ln, em, age, dic1, dic2, dic3, dp);
};

void Roster::add(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram dp)
{
    int darr[3] = {daysInCourse1, daysInCourse2, daysInCourse3};

    classRosterArray[++lastIdx] = new Student(studentID, firstName, lastName, email, age, darr, dp);
}

void Roster::remove(string studentID)
{
    bool found = false;
    for (int i = 0; i <= Roster::lastIdx; i++)
    {
        if (classRosterArray[i]->getStudentID() == studentID)
        {
            found = true;
            if (i < numStudents - 1)
            {
                Student *temp = classRosterArray[i];
                classRosterArray[i] = classRosterArray[numStudents - 1];
                classRosterArray[numStudents - 1] = temp;
            }
            Roster::lastIdx--;
            cout << "Student " << studentID << " removed." << std::endl;
        }
    }
    if (!found)
    {
        cout << "Error: " << studentID << " not found." << std::endl;
    }
}

void Roster::printAll()
{
    for (int i = 0; i <= Roster::lastIdx; i++)
    {
        classRosterArray[i]->print();
    }
}

void Roster::printAverageDaysInCourse(string studentID)
{
    bool found = false;
    for (int i = 0; i <= lastIdx; i++)
    {
        if (classRosterArray[i]->getStudentID() == studentID)
        {
            found = true;
            int *days = classRosterArray[i]->getDaysInCourse();
            double averageDays = (days[0] + days[1] + days[2]) / 3.0;
            cout << studentID << ": " << averageDays << std::endl;
        }
    }
    if (!found)
    {
        cout << "Error: " << studentID << " not found." << std::endl;
    }
}

void Roster::printInvalidEmails()
{
    bool any = false;
    for (int i = 0; i <= Roster::lastIdx; i++)
    {
        string em = (classRosterArray[i]->getEmail());
        if (em.find('@') == string::npos || em.find('.') == string::npos || em.find(' ') != string::npos)
        {
            any = true;
            cout << "Invalid email address: " << em << std::endl;
        }
    }
    if (!any)
        cout << "No invalid emails" << std::endl;
}

void Roster::printByDegreeProgram(DegreeProgram dp)
{
//    Student::printHeader();
    for (int i = 0; i <= Roster::lastIdx; i++)
    {
        if (Roster::classRosterArray[i]->getDegreeProgram() == dp)
            classRosterArray[i]->print();
    }
    cout << std::endl;
}

Roster::~Roster()
{
    cout << "Destructor called" << std::endl
         << std::endl;
    for (int i = 0; i < numStudents; i++)
    {
        cout << "Removing student " << i + 1 << std::endl;
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}

/*
 E.  Create a Roster class (roster.cpp) by doing the following:

 1.  Create an array of pointers, classRosterArray, to hold the data provided in the “studentData Table.”

 2.  Create a student object for each student in the data table and populate classRosterArray.

 a.  Parse each set of data identified in the “studentData Table.”

 b.  Add each student object to classRosterArray.

 3.  Define the following functions:

 a.  public void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)  that sets the instance variables from part D1 and updates the roster.

 b.  public void remove(string studentID)  that removes students from the roster by student ID. If the student ID does not exist, the function prints an error message indicating that the student was not found.

 c. public void printAll() that prints a complete tab-separated list of student data in the provided format: A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security. The printAll() function should loop through all the students in classRosterArray and call the print() function for each student.

 d.  public void printAverageDaysInCourse(string studentID)  that correctly prints a student’s average number of days in the three courses. The student is identified by the studentID parameter.

 e.  public void printInvalidEmails() that verifies student email addresses and displays all invalid email addresses to the user.
  

 Note: A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
  

 f.  public void printByDegreeProgram(DegreeProgram degreeProgram) that prints out student information for a degree program specified by an enumerated type.
 */

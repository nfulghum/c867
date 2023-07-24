//
//  student.cpp
//  c867
//
//  Created by Nicholas Fulghum on 7/20/23.
//

#include <iostream>
#include <string>
#include "student.hpp"

// constructors
Student::Student() {}

Student::Student(string studentID, string firstName, string lastName, string email, int age, int daysInCourse[], DegreeProgram degreeProgram)
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->age = age;
    for (int i = 0; i < numDaysInCourseArray; i++)
        this->daysInCourse[i] = daysInCourse[i];
    this->degreeProgram = degreeProgram;
}

// destructor
Student::~Student() {}

// accessors

string Student::getStudentID()
{
    return this->studentID;
}

string Student::getFirstName()
{
    return this->firstName;
}

string Student::getLastName()
{
    return this->lastName;
}

string Student::getEmail()
{
    return this->email;
}

int Student::getAge()
{
    return this->age;
}

int *Student::getDaysInCourse()
{
    return this->daysInCourse;
}

DegreeProgram Student::getDegreeProgram()
{
    return this->degreeProgram;
}

// mutators
void Student::setStudentID(string studentID)
{
    this->studentID = studentID;
}

void Student::setFirstName(string firstName)
{
    this->firstName = firstName;
}

void Student::setLastName(string lastName)
{
    this->lastName = lastName;
}

void Student::setEmail(string email)
{
    this->email = email;
}

void Student::setAge(int age)
{
    this->age = age;
}

void Student::setDaysInCourse(int daysInCourse[])
{
    for (int i = 0; i < numDaysInCourseArray; i++)
        this->daysInCourse[i] = daysInCourse[i];
}

void Student::setDegreeProgram(DegreeProgram dp)
{
    this->degreeProgram = dp;
}

void Student::printHeader()
{
    cout << "ID | First Name | Last Name | Email | Age | Days In Course | Degree Program\n";
}

void Student::print()
{
    cout << this->getStudentID() << '\t';
    cout << "First Name: " << this->getFirstName() << '\t';
    cout << "Last Name: " << this->getLastName() << '\t';
    cout << "Age: " << this->getAge() << '\t';
    cout << "daysInCourse: {" << this->getDaysInCourse()[0] << ',';
    cout << this->getDaysInCourse()[1] << ',';
    cout << this->getDaysInCourse()[2]  << "} ";
    cout << "Degree Program: " << degreeProgramStrings[this->getDegreeProgram()] << '\n';
}

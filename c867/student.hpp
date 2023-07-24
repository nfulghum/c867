//
//  student.hpp
//  c867
//
//  Created by Nicholas Fulghum on 7/20/23.
//

#ifndef student_hpp
#define student_hpp
#pragma once
#include <iostream>
#include <stdio.h>
#include "degree.hpp"

using std::cout;
using std::string;

class Student
{
public:
    const static int numDaysInCourseArray = 3;

private:
    string studentID;
    string firstName;
    string lastName;
    string email;
    int age;
    int daysInCourse[numDaysInCourseArray];
    DegreeProgram degreeProgram;

public:
    // constructors
    Student();
    Student(string studentID, string firstName, string lastName, string email, int age, int daysInCourse[], DegreeProgram degreeProgram);
    // destructor
    ~Student();

    // Getters (accessors)
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmail();
    int getAge();
    int *getDaysInCourse();
    DegreeProgram getDegreeProgram();

    // Setters (mutators)
    void setStudentID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmail(string email);
    void setAge(int age);
    void setDaysInCourse(int daysInCourse[]);
    void setDegreeProgram(DegreeProgram dp);

    static void printHeader();

    void print();
};

#endif /* student_hpp */

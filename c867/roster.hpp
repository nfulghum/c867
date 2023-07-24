//
//  roster.hpp
//  c867
//
//  Created by Nicholas Fulghum on 7/20/23.
//

#ifndef roster_hpp
#define roster_hpp
#pragma once
#include "student.hpp"

#include <stdio.h>

class Roster
{
public:
    int lastIdx = -1;
    const static int numStudents = 5;
    Student *classRosterArray[numStudents];

public:
    void parse(string studentData);
    void add(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram dp);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram dp);
    ~Roster();
};

#endif /* roster_hpp */

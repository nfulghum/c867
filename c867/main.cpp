//
//  main.cpp
//  c867
//
//  Created by Nicholas Fulghum on 7/20/23.
//
#include <iostream>
#include <string>
#include "roster.hpp"

int main()
{
    cout << "Course Title: C867 - Scripting and Programming Applications" << std::endl;
    cout << "Programming Language: C++" << std::endl;
    cout << "WGU Student ID: 011196739 " << std::endl;
    cout << "Student Name: Nick Fulghum " << std::endl;
    cout << std::endl;

    static const std::string studentData[] = {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
                                              "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
                                              "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
                                              "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
                                              "A5,Nick,Fulghum,nfulghu@wgu.edu,31,10,20,32,SOFTWARE"};

    const int numStudents = 5;
    Roster roster;

    for (int i = 0; i < numStudents; i++)
        roster.parse(studentData[i]);
    cout << "Displaying all students: " << std::endl;
    roster.printAll();
    cout << std::endl;
    
    cout << "Displaying emails with invalid IDs " << std::endl;
    roster.printInvalidEmails();
    cout << std::endl;
    
    cout << "Average days per class " << std::endl;
    for (int i = 0; i < numStudents; i++)
    {
        roster.printAverageDaysInCourse(roster.classRosterArray[i]->getStudentID());
    }
    cout << std::endl;
  
    cout << "Displaying by degree program " << std::endl;
    roster.printByDegreeProgram(SOFTWARE);
    cout << std::endl;

    cout << "Remove student A3." << std::endl;
    roster.remove("A3");
    cout << std::endl;
    
    cout << "Displaying all students: " << std::endl;
    roster.printAll();
    cout << std::endl;
    
    cout << "Remove student A3." << std::endl;
    roster.remove("A3");
    cout << std::endl;
}

//F.  Demonstrate the program’s required functionality by adding a main() function in main.cpp, which will contain the required function calls to achieve the following results:
//
//1.  Print out to the screen, via your application, the course title, the programming language used, your WGU student ID, and your name.
//
//2.  Create an instance of the Roster class called classRoster.
//
//3.  Add each student to classRoster.
//
//4.  Convert the following pseudo code to complete the rest of the  main() function:
//
//classRoster.printAll();
//
//classRoster.printInvalidEmails();
//
//
//
////loop through classRosterArray and for each element:
//
//classRoster.printAverageDaysInCourse(/*current_object's student id*/);
//
//
//
//Note: For the current_object's student id, use an accessor (i.e., getter) for the classRosterArray to access the student id.
//
//
//
//classRoster.printByDegreeProgram(SOFTWARE);
//
//classRoster.remove("A3");
//
//classRoster.printAll();
//
//classRoster.remove("A3");
//
////expected: the above line should print a message saying such a student with this ID was not found.
//
//5.  Implement the destructor to release the memory that was allocated dynamically in Roster.

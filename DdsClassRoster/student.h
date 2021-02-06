#pragma once							// Header Guard

#include "degree.h"

#include <string>
#include <iostream>

using namespace std;

class Student {
    public:
        const static int tableSize = 3;

    private:
        string studentID;                   // Student ID
        string firstName;                   // First Name
        string lastName;                    // Last Name
        string emailAddress;                // Email Address
        int age;                            // Age
        int* arrayNumberOfDaysToComplete;   // Number of Days To  Complete Course (array)
        DegreeProgram degreeProgram;        // Enumerated Degree Program

    public:
        Student();

        Student(
            string studentID,                   // Student ID
            string firstName,                   // First Name
            string lastName,                    // Last Name
            string emailAddress,                // Email Address
            int age,                            // Age
            int arrayNumberOfDaysToComplete[],  // Number of Days To Complete Course (array)
            DegreeProgram degreeProgram        // Enumerated Degree Program
        );

        // Accessors (getters)

        string getStudentID();
        string getFirstName();
        string getLastName();
        string getEmailAddress();
        int getAge();
        int* getNumberOfDaysToComplete();
        DegreeProgram getDegreeProgram();

        // Mutators (setters)

        void setStudentID(string studentID);
        void setFirstName(string firstName);
        void setLastName(string lastName);
        void setEmailAddress(string emailAddress);
        void setAge(int age);
        void setNumberOfDaysToComplete(int arrayNumberOfDaysToComplete[]);
        void setDegreeProgram(DegreeProgram degreeProgram);
        void print();

        // Destructor

        ~Student();

};

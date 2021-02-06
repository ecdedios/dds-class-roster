#pragma once							// Header Guard

#include "student.h"

#include <iostream>
#include <string>

class Roster {
    public:
        int lastIndex;
        int maxSize = 5;
        Student** classRosterArray;

        Roster();
        Roster(int maxSize);

        void parseAndAdd(string row);
        void add(
            string studentID,
            string firstName,
            string lastName,
            string emailAddress,
            int age,
            int daysInCourse1,
            int daysInCourse2,
            int daysInCourse3,
            DegreeProgram degreeProgram
        );

        Student* getStudent(int index);
        void printAll();
        bool remove(string studentID);
        void printAverageDaysInCourse(string studentID);
        void printInvalidEmails();
        void printByDegreeProgram(DegreeProgram degreeProgram);
        ~Roster();
};
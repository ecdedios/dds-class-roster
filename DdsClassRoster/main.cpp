#include "student.h"
#include "roster.h"

#include <iostream>

using namespace std;

int main()
{
    cout << endl;
    cout << "=============================" << endl;
    cout << "Dd's Class Roster Thinghy v.7" << endl;
    cout << "=============================" << endl;
    cout << endl;
    cout << "Scripting and Programming - Applications - C867" << endl;
    cout << "C++" << endl;
    cout << "Student# #001459994" << endl;
    cout << "Ednalyn C. De Dios" << endl;
    cout << endl;

    int numberOfStudents = 5;

    const string studentData[5] =
    {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Ednalyn,De Dios,ededios@wgu.edu,39,30,60,90,SOFTWARE"
    };

    Roster* classRoster = new Roster(numberOfStudents);
    for (int i = 0; i < numberOfStudents; i++)
    {
        classRoster->parseAndAdd(studentData[i]);
    }

    cout << "-------" << endl;
    cout << "ROSTER:" << endl;
    cout << "-------" << endl;
    classRoster->printAll();
    cout << endl;
    cout << endl;

    classRoster->printInvalidEmails();
    cout << endl;
    cout << endl;

    cout << "----------------------------" << endl;
    cout << "AVERAGE DAYS LEFT IN COURSE:" << endl;
    cout << "----------------------------" << endl;
    for (int i = 0; i < numberOfStudents; i++) {
        classRoster->printAverageDaysInCourse(classRoster->getStudent(i)->getStudentID());
    }
    cout << endl;
    cout << endl;

    classRoster->printByDegreeProgram(DegreeProgram::SOFTWARE);
    cout << endl;
    cout << endl;

    cout << "Remove student A3: " << endl;
    classRoster->remove("A3");
    cout << endl;
    cout << endl;

    cout << "-------" << endl;
    cout << "ROSTER:" << endl;
    cout << "-------" << endl;
    classRoster->printAll();
    cout << endl;
    cout << endl;

    cout << "Remove student A3: " << endl;
    classRoster->remove("A3");
    cout << endl;
    cout << endl;

    system("pause");

    return 0;

}
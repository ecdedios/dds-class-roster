#include "roster.h"

#include <iostream>

using namespace std;

Roster::Roster()
{
    this->maxSize = 0;
    this->lastIndex = -1;
    this->classRosterArray = nullptr;
}

Roster::Roster(int maxSize)
{
    this->maxSize = maxSize;
    this->lastIndex = -1;
    this->classRosterArray = new Student * [maxSize];
}

void Roster::parseAndAdd(string row)
{
    int parseArr[Student::tableSize];
    DegreeProgram degreeProgram;

    if (lastIndex < maxSize)
    {
        lastIndex++;
    }

    this->classRosterArray[lastIndex] = new Student();

    int long righty = row.find(",");
    classRosterArray[lastIndex]->setStudentID(row.substr(0, righty));

    int long lefty = righty + 1;
    righty = row.find(",", lefty);
    classRosterArray[lastIndex]->setFirstName(row.substr(lefty, righty - lefty));

    lefty = righty + 1;
    righty = row.find(",", lefty);
    classRosterArray[lastIndex]->setLastName(row.substr(lefty, righty - lefty));

    lefty = righty + 1;
    righty = row.find(",", lefty);
    classRosterArray[lastIndex]->setEmailAddress(row.substr(lefty, righty - lefty));

    lefty = righty + 1;
    righty = row.find(",", lefty);
    int x = stoi(row.substr(lefty, righty - lefty));
    classRosterArray[lastIndex]->setAge(x);

    lefty = righty + 1;
    righty = row.find(",", lefty);
    parseArr[0] = stoi(row.substr(lefty, righty - lefty));

    lefty = righty + 1;
    righty = row.find(",", lefty);
    parseArr[1] = stoi(row.substr(lefty, righty - lefty));

    lefty = righty + 1;
    righty = row.find(",", lefty);
    parseArr[2] = stoi(row.substr(lefty, righty - lefty));

    classRosterArray[lastIndex]->setNumberOfDaysToComplete(parseArr);

    lefty = righty + 1;
    if (row[lefty] == 'S')
    {
        if (row[lefty + 1] == 'E') classRosterArray[lastIndex]->setDegreeProgram(SECURITY);
        else if (row[lefty + 1] == 'O') classRosterArray[lastIndex]->setDegreeProgram(SOFTWARE);
        else
        {
            cerr << "Invalid degree program; exiting." << endl;
            exit(-1);
        }
    }
    else if (row[lefty] == 'N') classRosterArray[lastIndex]->setDegreeProgram(NETWORK);
    else
    {
        cerr << "Invalid degree program; exiting." << endl;
        exit(-1);
    }
}

void Roster::add(string studentID,
                 string firstName,
                 string lastName,
                 string emailAddress,
                 int age,
                 int daysInCourse1,
                 int daysInCourse2,
                 int daysInCourse3,
                 DegreeProgram degreeProgram)
{
    int arrayNumberOfDaysToComplete[Student::tableSize];

    arrayNumberOfDaysToComplete[0] = daysInCourse1;
    arrayNumberOfDaysToComplete[1] = daysInCourse2;
    arrayNumberOfDaysToComplete[2] = daysInCourse3;

    classRosterArray[lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, arrayNumberOfDaysToComplete, degreeProgram);
}

Student* Roster::getStudent(int index)
{
    return classRosterArray[index];
}

void Roster::printAll()
{
    for (int i = 0; i <= this->lastIndex; i++) (this->classRosterArray)[i]->print();
}

bool Roster::remove(string ID)
{
    bool found = false;
    for (int i = 0; i <= lastIndex; i++)
    {
        if (this->classRosterArray[i]->getStudentID() == ID)
        {
            found = true;
            delete this->classRosterArray[i];
            this->classRosterArray[i] = this->classRosterArray[lastIndex];
            lastIndex--;
        }
    }
    if (!found)
    {
        cout << "Student with ID " << ID << " not found." << endl;
    }
    return found;
}

void Roster::printAverageDaysInCourse(string sID)
{
    bool found = false;
    for (int i = 0; i <= lastIndex; i++)
    {
        if (this->classRosterArray[i]->getStudentID() == sID)
        {
            found = true;
            int* ptr = classRosterArray[i]->getNumberOfDaysToComplete();
            cout << "Average number of days left in class for " << sID << " is " << (ptr[0] + ptr[1] + ptr[2]) / 3 << "\n";
        }
    }
    if (!found) cout << "Student not found!" << endl;;
}

void Roster::printInvalidEmails()
{
    cout << "----------------------" << endl;
    cout << "INVALID EMAIL ENTRIES:" << endl;
    cout << "----------------------" << endl;
    for (int i = 0; i < 5; i++)
    {
        string email = classRosterArray[i]->getEmailAddress();
        if ((email.find("@") == string::npos || email.find(".") == string::npos) || (email.find(" ") != string::npos))
            cout << email << endl;
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
    cout << "--------------------------------" << endl;
    cout << "BY DEGREE:  " << DegreeProgramStrings[degreeProgram] << endl;
    cout << "--------------------------------" << endl;
    for (int i = 0; i <= lastIndex; i++) {
        if (this->classRosterArray[i]->getDegreeProgram() == degreeProgram) this->classRosterArray[i]->print();
    }
}

Roster::~Roster()
{
    for (int i = 0; i < 5; i++)
    {
        delete this->classRosterArray[i];
    }
    delete this;
}
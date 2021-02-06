#include "student.h"

#include <string>
#include <iostream>

using namespace std;

Student::Student()                          // Default Constructor
{
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    this->arrayNumberOfDaysToComplete = new int[tableSize];
    for (int i = 0; i < tableSize; i++) this->arrayNumberOfDaysToComplete[i] = 0;
    this->degreeProgram = SOFTWARE;

}

Student::Student(string studentID,
                 string firstName,
                 string lastName,
                 string emailAddress,
                 int age,
                 int arrayNumberOfDaysToComplete[],
                 DegreeProgram degreeProgram)
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    this->arrayNumberOfDaysToComplete = new int[tableSize];
    for (int i = 0; i < tableSize; i++) this->arrayNumberOfDaysToComplete[i] = arrayNumberOfDaysToComplete[i];
    this->degreeProgram = degreeProgram;
}

// Accessor Functions

string Student::getStudentID() { return studentID; }
string Student::getFirstName() { return firstName; }
string Student::getLastName() { return lastName; }
string Student::getEmailAddress() { return emailAddress; }
int Student::getAge() { return age; }
int* Student::getNumberOfDaysToComplete() { return arrayNumberOfDaysToComplete; }
DegreeProgram Student::getDegreeProgram() { return degreeProgram; }

//Mutator Functions

void Student::setStudentID(string studentID) { this->studentID = studentID; }
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmailAddress(string emailAddress) { this->emailAddress = emailAddress; }
void Student::setAge(int age) { this->age = age; }
void Student::setNumberOfDaysToComplete(int arrayNumberOfDaysToComplete[]) {
    for (int i = 0; i < tableSize; i++) {
        this->arrayNumberOfDaysToComplete[i] = arrayNumberOfDaysToComplete[i];
    }
}
void Student::setDegreeProgram(DegreeProgram degreeProgram){ this->degreeProgram = degreeProgram; }
void Student::print() {
    cout << getStudentID() << '\t' << getFirstName() << '\t' << getLastName() << '\t' << getAge() << '\t';
    int* arrayNumnberOfDaysToComplete = getNumberOfDaysToComplete();
    cout << '\t' << "daysInCourse: " << "{" << arrayNumberOfDaysToComplete[0] << ", " << arrayNumberOfDaysToComplete[1] << ", " << arrayNumberOfDaysToComplete[2] << "}" << '\t';
    cout << "Degree Program: " << DegreeProgramStrings[getDegreeProgram()] << endl;
}

// Destructor
Student::~Student()
{
    if (arrayNumberOfDaysToComplete != nullptr)
    {
        delete[] arrayNumberOfDaysToComplete;
        arrayNumberOfDaysToComplete = nullptr;
    }
}
#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#pragma pack(1)

struct Student {
    string id, full_name;
    float gpa;
};

void inputStudent(ifstream &in, Student &student);
void inputStudentArray(ifstream &in, Student students[], int &n);
void outputStudent(ofstream &out, const Student &student);

// Returns the information of the student with the highest gpa.
// If there are more than 1 answer, choose id less than student.
Student findMaxGpa(Student students[], const int &n);

#endif
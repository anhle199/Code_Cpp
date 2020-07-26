#include "Student.h"

void inputStudent(ifstream &in, Student &student) {
    getline(in, student.id);
    getline(in, student.full_name);
    in >> student.gpa;

    in.ignore(); // clear cache.
}

void inputStudentArray(ifstream &in, Student students[], int &n) {
    in >> n;
    in.ignore();

    for (int i = 0; i < n; i++)
        inputStudent(in, students[i]);
}

void outputStudent(ofstream &out, const Student &student) {
    out << student.id << endl;
    out << student.full_name << endl;
    out << student.gpa << endl;
}

Student findMaxGpa(Student students[], const int &n) {
    Student result = students[0];

    for (int i = 1; i < n; i++) {
        if (result.gpa < students[i].gpa)
            result = students[i];
        else if (result.gpa == students[i].gpa) {
            if (stol(result.id) > stol(students[i].id))
                result = students[i];
        }
    }

    return result;
}
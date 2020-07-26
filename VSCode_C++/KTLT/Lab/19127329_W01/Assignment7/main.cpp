#include "Student.h"

int main() {
    Student students[199];
    int n = 0;

    ifstream in("input.txt");

    if (!in.is_open()) {
        cout << "File does not exist." << endl;
    } else {
        inputStudentArray(in, students, n);
        Student result = findMaxGpa(students, n);

        in.close();

        ofstream out("output.txt");

        if (!out.is_open()) {
            cout << "Can not create file." << endl;
        } else {    
            outputStudent(out, result);
            out.close();
        }
    }

    return 0;
}
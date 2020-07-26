#include "Circle.h"

int main() {
    Circle circles[199];
    int n = 0;

    ifstream in("input.txt");

    if (!in.is_open()) {
        cout << "File does not exist." << endl;
    } else {
        inputCircleArray(in, circles, n);
        float result = sumAreaOfCircles(circles, n);

        in.close();

        ofstream out("output.txt");

        if (!out.is_open()) {
            cout << "Can not create file." << endl;
        } else {
            writeResult(out, result);
            out.close();
        }
    }

    return 0;
}
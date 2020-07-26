#include "Point.h"

int main() {
    Point points[199];
    int n = 0;

    ifstream in("input.txt");
    
    if (!in.is_open()) {
        cout << "File does not exist." << endl;
    } else {
        inputPointArray(in, points, n);
        sortPointArrayWithDistance(points, n);
        
        in.close();
    
        ofstream out("output.txt");

        if (!out.is_open()) {
            cout << "Can not create file." << endl;
        } else {
            outputPointArray(out, points, n);
            out.close();
        }
    }

    return 0;
}
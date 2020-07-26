#include "Circle.h"

void inputCircle(ifstream &in, Circle &circle) {
    in >> circle.center.x >> circle.center.y;
    in >> circle.radius;
}

void inputCircleArray(ifstream &in, Circle circles[], int &n) {
    in >> n;

    for (int i = 0; i < n; i++)
        inputCircle(in, circles[i]);
}

void writeResult(ofstream &out, const float &area) {
    out << area << endl;
}

float sumAreaOfCircles(Circle circles[], const int &n) {
    float sum_area = 0;

    for (int i = 0; i < n; i++)
        sum_area += circles[i].radius;

    sum_area *= 2 * PI; // 2 * PI * (sum of all radius).
    return sum_area;
}
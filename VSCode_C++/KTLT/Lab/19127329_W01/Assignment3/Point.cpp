#include "Point.h"
#include <cmath>

void inputPoint(ifstream &in, Point &point) {
    in >> point.x >> point.y;
}

void inputPointArray(ifstream &in, Point points[], int &n) {
    in >> n;

    for (int i = 0; i < n; i++)
        inputPoint(in, points[i]);
}

void outputPoint(ofstream &out, const Point &point) {
    out << point.x << " " << point.y << endl;
}

void outputPointArray(ofstream &out, Point points[], const int &n) {
    for (int i = 0; i < n; i++)
        outputPoint(out, points[i]);
}

float distance(const Point &point1, const Point &point2) {
    return sqrt(pow(point1.x - point2.x, 2) + pow(point1.y - point2.y, 2));
}

void sortPointArrayWithDistance(Point points[], const int &n) {
    Point origin = {0, 0};
    int pos;
    
    for (int i = 0; i < n - 1; i++) {
        pos = i;

        for (int j = i + 1; j < n; j++)
            if (distance(origin, points[pos]) > distance(origin, points[j]))
                pos = j;

        swap(points[i], points[pos]);
    }
}
#ifndef CIRCLE_H_
#define CICCLE_H_

#include <iostream>
#include <fstream>

#define PI 3.14

using namespace std;

#pragma pack(1)

struct Point {
    float x, y;
};

struct Circle {
    Point center;
    float radius;
};

void inputCircle(ifstream &in, Circle &circle);
void inputCircleArray(ifstream &in, Circle circles[], int &n);
void writeResult(ofstream &out, const float &area);

// Calculate the total area of the circles.
float sumAreaOfCircles(Circle circles[], const int &n);

#endif
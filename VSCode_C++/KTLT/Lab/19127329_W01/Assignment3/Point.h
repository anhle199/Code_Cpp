#ifndef POINT_H_
#define POINT_H_

#include <iostream>
#include <fstream>

using namespace std;

struct Point {
    float x, y; 
};

void inputPoint(ifstream &in, Point &point);
void inputPointArray(ifstream &in, Point points[], int &n);
void outputPoint(ofstream &out, const Point &point);
void outputPointArray(ofstream &out, Point points[], const int &n);

// Returns the distance between two points.
float distance(const Point &point1, const Point &point2);

// Sort array ascending by distance from that point to the origin.
void sortPointArrayWithDistance(Point points[], const int &n);

#endif
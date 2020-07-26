// MSSV: 19127329
#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <iostream>
#include <cmath>
#include <vector>
#include <string>

#define COFFEE 0
#define TEA 1

using namespace std;

struct Point {
    float x, y;
};

struct Tree {
    Point position;
    int type;
};

struct Plantation {
    vector<Tree> trees;
};

bool readData(const string &file_name, Plantation &p);
void writeResult(const string &file_name, const Plantation &p);
int countTrees(const Plantation &p, const int &type);
int countCoffeeTrees(const Plantation &p);
int countTeaTrees(const Plantation &p);
Point findUpperLeft(const Plantation &p);
Point findLowerRight(const Plantation &p);
float calcFenceLength(const Plantation &p);
Point findPump(const Plantation &p);
float distance(const Point &p, const Point &q);
float sumDistance(const Plantation &p, const Point &point);
float calculateTotalLength(const Plantation &p);

#endif
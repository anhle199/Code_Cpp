// MSSV: 19127329
#include "functions.h"
#include <fstream>

bool readData(const string &file_name, Plantation &p) {
    ifstream in(file_name);

    if (!in.is_open())
        return false;
    
    int n;
    in >> n;

    p.trees.resize(n);
    for (int i = 0; i < n; i++) {
        in >> p.trees[i].position.x >> p.trees[i].position.y;
        in >> p.trees[i].type;
    }

    in.close();
    return true;
}

void writeResult(const string &file_name, const Plantation &p) {
    ofstream out(file_name);

    if (!out.is_open()) {
        cout << "File does not exist." << endl;
        return;
    }

    int count_coffee, count_tea;
    float shortest_fence_length, min_distance;

    count_coffee = countCoffeeTrees(p);
    count_tea = countTeaTrees(p);
    shortest_fence_length = calcFenceLength(p);
    min_distance = calculateTotalLength(p);

    out << count_coffee << " " << count_tea << endl;
    out << shortest_fence_length << "\n" << min_distance;

    out.close();
}

int countTrees(const Plantation &p, const int &type) {
    int count = 0, number_of_trees = p.trees.size();

    for (int i = 0; i < number_of_trees; i++)
        if (p.trees[i].type == type)
            count++;

    return count;
}

int countCoffeeTrees(const Plantation &p) {
    return countTrees(p, COFFEE);
}

int countTeaTrees(const Plantation &p) {
    return countTrees(p, TEA);
}

Point findUpperLeft(const Plantation &p) {
    Point result = p.trees[0].position;
    int number_of_trees = p.trees.size();

    for (int i = 1; i < number_of_trees; i++) {
        if (p.trees[i].position.x < result.x)
            result.x = p.trees[i].position.x;
        if (p.trees[i].position.y > result.y)
            result.y = p.trees[i].position.y;
    }
        
    return result;
}

Point findLowerRight(const Plantation &p) {
    Point result = p.trees[0].position;
    int number_of_trees = p.trees.size();

    for (int i = 1; i < number_of_trees; i++) {
        if (p.trees[i].position.x > result.x)
            result.x = p.trees[i].position.x;
        if (p.trees[i].position.y < result.y)
            result.y = p.trees[i].position.y;
    }

    return result;
}

float calcFenceLength(const Plantation &p) {
    float dx, dy;
    Point upper_left, lower_right;

    upper_left = findUpperLeft(p);
    lower_right = findLowerRight(p);

    dx = abs(upper_left.y - lower_right.y);
    dy = abs(lower_right.x - upper_left.x);
    return (2 * (dx + dy));
}

Point findPump(const Plantation &p) {
    vector<Point> test_point;
    Point current_point = {0, 0};
    int number_of_points = p.trees.size();
    float min_distance = 0, temp_distance, low_limit = 0.00001, test_distance = 1000.0;

    //-----------------------------------------------

    for (int i = 0; i < number_of_points; i++) {
        current_point.x += p.trees[i].position.x;
        current_point.y += p.trees[i].position.y;
    }

    // điểm current_point đầu tiên là trung bình cộng của tọa độ tất cả các cây.
    current_point.x /= (float)number_of_points;
    current_point.y /= (float)number_of_points;
    // tổng khoảng cách từ current_point đến tất cả các cây.
    min_distance = sumDistance(p, current_point); 

    //-----------------------------------------------

    for (int i = 0; i < number_of_points; i++) {
        temp_distance = sumDistance(p, p.trees[i].position); // tổng khoảng cách từ 1 cấy đến tất cả các cây.

        if (min_distance > temp_distance) {
            current_point = p.trees[i].position;
            min_distance = temp_distance;
        }
    }

    //-----------------------------------------------

    while (low_limit <= test_distance) {
        test_point = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
        
        for (Point &point : test_point) { 

            // tạo ra 4 điểm mới bằng cách di chuyển current_point lần lượt theo các hướng left, up, right, down .
            point.x = (point.x * test_distance) + current_point.x;
            point.y = (point.y * test_distance) + current_point.y;
            // tổng khoảng cách từ điểm mới đến tất cả các cây.
            temp_distance = sumDistance(p, point);

            if (min_distance > temp_distance) {
                current_point = point;
                min_distance = temp_distance;
                break;
            }
        }

        test_distance /= 2.0;
    }

    return current_point;
}

float distance(const Point &p, const Point &q) {
    return sqrt(pow(p.x - q.x, 2) + pow(p.y - q.y, 2));
}

float sumDistance(const Plantation &p, const Point &point) {
    int number_of_points = p.trees.size();
    float sum_distance = 0;

    for (int i = 0; i < number_of_points; i++)
        sum_distance += distance(point, p.trees[i].position);

    return sum_distance;
}

float calculateTotalLength(const Plantation &p) {
    Point pump = findPump(p);
    return sumDistance(p, pump);
}

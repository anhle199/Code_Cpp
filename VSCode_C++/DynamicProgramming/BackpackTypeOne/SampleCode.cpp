#include <iostream>
#include <vector>

using namespace std;

void backpackTypeOne(const vector<int> &values, const vector<int> &weights, int n, int limit_weight, vector<int> &position_backpack, int &total_value) {
    vector<vector<int>> F(n + 1, vector<int> (limit_weight + 1));

    for (int i = 0; i <= limit_weight; i++) 
        F[0][i] = 0;
    
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= limit_weight; j++) {
            F[i][j] = F[i - 1][j]; // Giả sử không chọn gói thứ i.

            // Nếu chọn gói thứ i lợi hơn thì gán lại F[i][j].
            if (j >= weights[i - 1] && F[i][j] < F[i - 1][j - weights[i - 1]] + values[i - 1])
                F[i][j] = F[i - 1][j - weights[i - 1]] + values[i - 1];
        }

    total_value = F[n][limit_weight];
    while (n != 0) {
        if (F[n][limit_weight] != F[n - 1][limit_weight]) {
            position_backpack.push_back(n);
            limit_weight = limit_weight - weights[n - 1];
        }
        n--;
    }
}

int main() {
    vector<int> weights = {12, 2, 1, 1, 4}, values = {4, 2, 1, 2, 10}, position_backpack;
    int n = 5, limit_weight = 15, total_value = 0;
    
    backpackTypeOne(values, weights, n, limit_weight, position_backpack, total_value);
    
    cout << "The total value of the items: " << total_value << endl;
    for (const int &pos : position_backpack) 
        cout << pos << " ";

    return 0;
}
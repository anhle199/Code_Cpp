#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

vector<vector<int>> shareCandy(const vector<int> &candy) {
    
}

int main() {
    vector<int> candy;
    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        candy.push_back(rand() % 10 + 1);
        cout << candy[i] << " ";
    }
    cout << endl;

    vector<vector<int>> result = shareCandy(candy);

    for (const vector<int> &arr : result) {
        for (const int &item : arr)
            cout << item << " ";
        cout << endl;
    }

    return 0;
}
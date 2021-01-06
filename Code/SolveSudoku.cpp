#include <iostream>
#include <vector>

using namespace std;

bool checkNumberAlreadyInRowOrColumn(const vector<vector<int>> &matrix, int i, int j, int number) {
    for (int k = 0; k < 9; k++)
        if (matrix[i][k] == number || matrix[k][j] == number)
            return true;

    return false;
}

bool checkNumberAlreadyInSubBox(const vector<vector<int>> &matrix, int no, int number) {
    int row = ((no - 1) / 3) * 3;
    int column = ((no + 2) % 3) * 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (matrix[i + row][j + column] == number)
                return true;

    return false;
}

bool isCompleted(const vector<vector<int>> &matrix) {
    for (int i = 0; i < matrix.size(); i++) 
        for (int j = 0; j < matrix[i].size(); j++)
            if (matrix[i][j] == 0)
                return false;

    return true;
}

void printMatrix(const vector<vector<int>> &matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++)
            cout << matrix[i][j] << " ";

        cout << endl;
    }
}

void solve(vector<vector<int>> &matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            int no = ((i / 3) * 3) + (j / 3) + 1;
            if (matrix[i][j] != 0) {
                for (int k = 1; k <= 9; k++)
                    if (!checkNumberAlreadyInRowOrColumn(matrix, i, j, k) &&
                         !checkNumberAlreadyInSubBox(matrix, no, k)) 
                    {
                        matrix[i][j] = k;

                        if (isCompleted(matrix))
                            printMatrix(matrix);

                        solve(matrix);
                        matrix[i][j] = 0;
                    }
            }
        }
    }
}

int main() {
    vector<vector<int>> matrix = {
        {0, 0, 0, 6, 0, 5, 0, 0, 0},
        {0, 0, 1, 0, 7, 0, 6, 0, 0},
        {9, 0, 0, 8, 0, 2, 0, 1, 0},
        {6, 7, 0, 0, 0, 0, 0, 8, 9},
        {4, 0, 0, 0, 0, 0, 0, 0, 7},
        {1, 5, 0, 0, 0, 0, 0, 4, 2},
        {0, 8, 0, 1, 0, 7, 0, 2, 0},
        {0, 0, 2, 0, 5, 0, 9, 0, 0},
        {0, 0, 0, 3, 0, 6, 0, 0, 0}
    };

    solve(matrix);

    return 0;
}
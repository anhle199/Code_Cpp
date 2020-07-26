#include <iostream>
#include <vector>

using namespace std;

bool check(std::vector<std::vector<int>> matrix, int row, int column, const int &number) {
    for (int i = 0; i < 9; i++) {
        if (matrix[row][i] == number)
            return false;
        if (matrix[i][column] == number)
            return false;
    }

    row /= 3;
    column /=3;

    for (int i = 3 * row; i < 3 * row + 3; i++)
        for (int j = 3 * column; j < 3 * column + 3; j++)
            if (matrix[i][j] == number)
                return false;

    return true;
}

void sudoku(std::vector<std::vector<int>> matrix, int &count_solve, const int &x, const int &y) {
    if (y == 9) {
        if (x == 8) count_solve++;
        else sudoku(matrix, count_solve, x + 1, 0);
    } else if (matrix[x][y] == 0) {
        for (int k = 1; k <= 9; k++)
            if (check(matrix, x, y, k)) {
                matrix[x][y] = k;
                sudoku(matrix, count_solve, x, y + 1);
                matrix[x][y] = 0;
            }
    } else {
        sudoku(matrix, count_solve, x, y + 1);
    }
}

int countSodokuSolve(std::vector<std::vector<int>> matrix) {
    int count_solve = 0, fill = 0;

    sudoku(matrix, count_solve, 0, 0);
    return count_solve;
}

int main() {
    vector<vector<int>> matrix = {{0,0,4,2,0,1,0,6,0},{0,0,0,0,0,0,0,0,0},{9,0,5,0,0,0,3,0,7},
    {0,0,0,0,0,0,0,0,0},{5,0,7,0,8,0,1,0,4},{0,1,0,0,0,0,0,9,0},{0,0,1,0,0,0,6,0,0},{0,0,0,7,0,5,0,0,0},{6,0,8,9,0,4,5,0,3}};
    cout << countSodokuSolve(matrix) << endl;    
    return 0;
}
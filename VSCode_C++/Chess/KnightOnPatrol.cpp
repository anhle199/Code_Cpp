// Có rất nhiều lời giải cho bài toán này, chính xác là 26.534.728.821.064 lời giải trong đó quân mã có thể kết thúc tại chính ô mà nó khởi đầu.
// Vì vậy chương trình này sẽ dừng khi tìm được 1 lời giải.

#include <iostream>
#include <vector>

#define CHESSBOARD_SIZE 8

using namespace std;

void printChessboard(const vector<vector<int>> &chessboard);
void knightOnPatrol(vector<vector<int>> &chessboard, const int &n, const int &row, const int &column);

int main() {
    vector<vector<int>> chessboard(CHESSBOARD_SIZE, vector<int>(CHESSBOARD_SIZE, 0));
    int n = 1, row = 2, column = -1;

    knightOnPatrol(chessboard, n, row, column);

    return 0;
}

void printChessboard(const vector<vector<int>> &chessboard) {
    for (const vector<int> &arr : chessboard) {
        for (const int &item : arr) {
            cout << item << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void knightOnPatrol(vector<vector<int>> &chessboard, const int &n, const int &row, const int &column) {
    vector<int> row_coordinates = {-2, -1, 1, 2, 2, 1, -1, -2};
    vector<int> column_coordinates = {1, 2, 2, 1, -1, -2, -2, -1};
    int row_new, column_new;

    for (int i = 0; i < CHESSBOARD_SIZE; i++) {

        // Toạ độ tiếp theo mà quân mã có thể đi.
        row_new = row + row_coordinates[i];
        column_new = column + column_coordinates[i];

        // Kiểm tra tính hợp lệ của tọa độ.
        if ((0 <= row_new && row_new < CHESSBOARD_SIZE) && (0 <= column_new && column_new < CHESSBOARD_SIZE)) {
            if (chessboard[row_new][column_new] == 0) { // Nếu tại vị trí này quân mã chưa đi.
                chessboard[row_new][column_new] = n; // Đánh dấu quân mã đã đi tại vị trí này.

                if (n == CHESSBOARD_SIZE * CHESSBOARD_SIZE) { // Nếu đã đi hết bàn cờ.
                    printChessboard(chessboard); // In bàn cờ.
                    exit(0); // Dừng chương trình khi đã tìm được 1 lời giải.
                } else {
                    knightOnPatrol(chessboard, n + 1, row_new, column_new);
                }

                chessboard[row_new][column_new] = 0; // Bỏ đánh dấu.
            }
        }

        
    }
}
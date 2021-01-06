/*
 * 2 quân hậu không thể ăn nhau nếu chúng không cùng hàng, cùng cột, cùng đường chéo xuôi, cùng đường chéo ngược.
 * Vì biến row để hợp lệ với chỉ số của mảng nên phải đặt mặc định là 0. Cho nên quân hậu sẽ là thứ (row + 1).
 * Thuật toán này tìm được tất cả 92 lời giải.
 * Thực ra là chỉ có 12 lời giải khác nhau thật sự, đó là vì thuật toán không ghi nhận tính đối xứng.
 * Vì vậy chương trình sẽ dùng khi tìm được 1 lời giải.
*/

#include <iostream>
#include <vector>

#define CHESSBOARD_SIZE 8
#define NUMBER_OF_DIAGONALS (2 * CHESSBOARD_SIZE - 1)

using namespace std;

void printChessboard(const vector<vector<int>> &chessboard);
// Đặt quân hậu thứ row lên hàng row.
void eightQueens(vector<vector<int>> &chessboard, vector<bool> &empty_column, vector<bool> &main_diagonal,
 vector<bool> &opposite_diagonal, const int &row = 0);

int main() {
    vector<vector<int>> chessboard(CHESSBOARD_SIZE, vector<int> (CHESSBOARD_SIZE, 0));
    vector<bool> empty_column(CHESSBOARD_SIZE, true);
    vector<bool> main_diagonal(NUMBER_OF_DIAGONALS, true), opposite_diagonal(NUMBER_OF_DIAGONALS, true); 
    
    eightQueens(chessboard, empty_column, main_diagonal, opposite_diagonal);
    
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

void eightQueens(vector<vector<int>> &chessboard, vector<bool> &empty_column, vector<bool> &main_diagonal,
 vector<bool> &opposite_diagonal, const int &row) {
    for (int column = 0; column < CHESSBOARD_SIZE; column++) {
        
        // Nếu cột, đường chéo xuôi, đường chéo ngược đều trống.
        if (empty_column[column] == true && main_diagonal[row - column + CHESSBOARD_SIZE - 1] == true &&
         opposite_diagonal[row + column] == true) {

            chessboard[row][column] = row + 1; // Đặt quân hậu thứ (row + 1) tại vị trí (row, column).
            
            // Đánh dấu cột, đường chéo xuôi, đường chéo ngược này không còn trống.
            empty_column[column] = false;
            main_diagonal[row - column + CHESSBOARD_SIZE - 1] = false;
            opposite_diagonal[row + column] = false;

            if (row == CHESSBOARD_SIZE - 1) { // Nếu đủ 8 quân hậu thì in bàn cờ.
                printChessboard(chessboard);
                exit(0); // Dừng chương trình khi tìm được 1 lời giải.
            } else {
                eightQueens(chessboard, empty_column, main_diagonal, opposite_diagonal, row + 1);
            }
        
            // Bỏ đánh dấu cột, đường chéo xuôi, đường chéo ngược này.
            empty_column[column] = true;
            main_diagonal[row - column + CHESSBOARD_SIZE - 1] = true;
            opposite_diagonal[row + column] = true;
            
            chessboard[row][column] = 0; // Bỏ đặt quân hậu tại vị trí này.
        }
    }
}
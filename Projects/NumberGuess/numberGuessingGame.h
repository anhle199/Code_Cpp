// Tập tin functions.h
#ifndef NUMBER_GUESSING_GAME_
#define NUMBER_GUESSING_GAME_

#include <iostream> // Sử dụng hàm srand().
#include <ctime> // Sử dụng hàm time().

#define NUMBER_OF_TIMES 3 // Số lượt chơi đoán số.
#define MAX_SECRET_NUMBER 20 // Số bí mật lớn nhất.
#define MIN_SECRET_NUMBER 0 // Số bí mật nhỏ nhất.
#define NUMBER_OF_DIVISORS 4 // Số lượng ước số của số X (tính cả 1 và X).
#define NUMBER_OF_PRIMES 2 // Số lượng ước nguyên tố của số X (khác 1 và X).

using namespace std;

// - Nhập vào số người chơi đoán.
void getNumberToGuess(int &number);
// - Trả về 1 số ngẫu nhiên trong đoạn 0-20.
int chooseRandomNumber();
// - Kiểm tra xem số người chơi đoán đúng số bí mật không.
bool simulateGuessingGame(const int &secret_number, const int &number);
// - Nhập 1 số tự nhiên bất kì.
void getUserInput(int &user_input);
// - Kiểm tra số nguyên tố.
bool isPrime(int n);
// - Tìm số X lớn nhất.
int findMaxX();
// - Kiểm tra xem có phải số X hay không.
bool checkXNumber(const int &number);
// - Tìm số X nhỏ nhất lớn hơn số bí mật.
int findSmallestXWithSecretNumber(const int &secret_number, const int &max_x);
// - Trả về kết quả người chơi thắng hay thua.
bool checkWhoWin(const int &user_input, const int &smallest_x_with_secret_number);
// - Dừng màn hình console trước khi chuyển qua vòng 2.
void pauseScreen();
// - Vòng chơi đầu tiên (đoán số bí mật).
void theFirstRound(const int &secret_number, int &number_to_guess, bool &win_the_first_round);
// - Vòng chơi thứ hai (đoán số X).
void theSecondRound(int &smallest_x_with_secret_number, int &max_x, const int &secret_number, int &number_to_guess);

#endif // Kết thúc tập tin functions.h
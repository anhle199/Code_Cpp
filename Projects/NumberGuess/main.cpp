#include "numberGuessingGame.h"

int main()
{
    bool win_the_first_round = false;
    int secret_number, number_to_guess, smallest_x_with_secret_number, max_x;

    // Tạo 1 số ngẫu nhiên trong [MIN_SECRET_NUMBER, MAX_SECRET_NUMBER] để làm số bí mật.
    secret_number = chooseRandomNumber();
    
    theFirstRound(secret_number, number_to_guess, win_the_first_round);
    if (win_the_first_round)
    {
        pauseScreen(); // Dừng màn hình console trước khi chơi vòng 2.    
        theSecondRound(smallest_x_with_secret_number, max_x, secret_number, number_to_guess);
    }

    return 0;
}
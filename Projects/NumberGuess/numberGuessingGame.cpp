// Tập tin functions.cpp
#include "numberGuessingGame.h"
#include <cmath> // Sử dụng hàm sqrt().

void getNumberToGuess(int &number)
{
    cout << "\n==> Moi ban nhap vao so can doan (" << MIN_SECRET_NUMBER << "-" << MAX_SECRET_NUMBER << "): ";
    cin >> number;

    while (number < MIN_SECRET_NUMBER || number > MAX_SECRET_NUMBER)
    {
        cout << "==> So ban vua nhap khong hop le." << endl;
        cout << "==> Moi ban nhap vao so can doan (" << MIN_SECRET_NUMBER << "-" << MAX_SECRET_NUMBER << "): ";
        cin >> number;
    }
}

int chooseRandomNumber()
{
    srand((int)time(NULL));

    return ((rand() % MAX_SECRET_NUMBER) + MIN_SECRET_NUMBER);
}

bool simulateGuessingGame(const int &secret_number, const int &number)
{
    return (secret_number == number);
}

void getUserInput(int &user_input)
{
    cout << "\n==> Moi ban nhap vao 1 so tu nhien bat ki: ";
    cin >> user_input;
}

bool isPrime(int x)
{
    if (x < 2)
        return false;
    
    for (int i = 2; i <= sqrt(x); i++)
        if (x % i == 0)
            return false;

    return true;
}

int findMaxX()
{
    int max_x = MAX_SECRET_NUMBER + 1;

    while (checkXNumber(max_x)) max_x++;

    return max_x;
}

bool checkXNumber(const int &number)
{
    int count_divisor(2), count_prime(0), j;

    for (int i = 2; i <= sqrt(number); i++)
        if (number % i == 0)
        {
            j = number / i;

            if (i == j)
            {
                count_divisor++;
                if (isPrime(i)) count_prime++;
            }
            else
            {
                count_divisor += 2;

                if (isPrime(i)) count_prime++;
                if (isPrime(j)) count_prime++;    
            }
        }

    if (count_divisor != NUMBER_OF_DIVISORS || count_prime != NUMBER_OF_PRIMES)
        return false;
    return true;
}

int findSmallestXWithSecretNumber(const int &secret_number, const int &max_x)
{
    int x = secret_number + 1;

    while (x <= max_x)
    {
        if (checkXNumber(x))
            return x;       
        
        x++;
    }
}

bool checkWhoWin(const int &user_input, const int &smallest_x_with_secret_number)
{
    return (user_input == smallest_x_with_secret_number);
}

void pauseScreen()
{
    int x;

    cout << "Vui long nhap phim 1 de tiep tuc: ";
    cin >> x;

    while (x != 1)
    {
        cout << "==> So ban vua nhap khong hop le." << endl;
        cout << "Vui long nhap phim 1 de tiep tuc: ";
        cin >> x;
    }
}

void theFirstRound(const int &secret_number, int &number_to_guess, bool &win_the_first_round)
{
    system("cls"); 
    cout << "---------- TRO CHOI DOAN SO ----------" << endl;
    cout << "\n----- Tro choi gom co 2 vong:" << endl;
    cout << "---- Vong 1:" << endl;
    cout << "--- Nguoi to chuc da chon ra 1 con so bi mat trong doan [" << MIN_SECRET_NUMBER << ", " << MAX_SECRET_NUMBER << "]." << endl;
    cout << "--- Ban co 3 luot de doan so bi mat nay." << endl;
    cout << "--- Neu ban doan dung thi ban se duoc choi vong 2." << endl;
    cout << "--- Neu ban doan sai thi ban se thua va tro choi ket thuc.\n" << endl;
    
    // Vòng chơi đầu tiên (đoán số bí mật).
    for (int i = NUMBER_OF_TIMES; i > 0; i--)
    {
        // Nhập vào số người chơi đoán.
        getNumberToGuess(number_to_guess);
        // Kiểm tra sô người chơi nhập và số bí mật.
        if (simulateGuessingGame(secret_number, number_to_guess))
        {
            win_the_first_round = true;

            cout << "==> Ban da doan dung so bi mat." << endl;
            cout << "==> Ban da vuot qua vong 1.\n" << endl;

            return;
        }
        else if (i == 1)
        {
            cout << "==> Ban da het luot choi." << endl;
            cout << "==> Ban da thua trong tro choi nay." << endl;
        }
        else
        {
            if (number_to_guess < secret_number)
                cout << "==> So ban vua nhap nho hon so bi mat." << endl;
            else
                cout << "==> So ban vua nhap lon hon so bi mat." << endl;

            cout << "==> Ban con " << i - 1 << " luot choi." << endl;
        }
    }
}

void theSecondRound(int &smallest_x_with_secret_number, int &max_x, const int &secret_number, int &number_to_guess)
{
    system("cls");
    cout << "---------- TRO CHOI DOAN SO ----------" << endl;
    cout << "\n---- Vong 2:" << endl;
    cout << "--- Ban phai nhap vao 1 so tu nhien thoa cac yeu sau:" << endl;
    cout << "-- Co 4 uoc so nguyen duong." << endl;
    cout << "-- Co 2 uoc la so nguyen to (ngoai tru 1 va chinh no).\n" << endl;

    // Tìm số X lớn nhất có thể.
    max_x = findMaxX();
    // TÌm số X nhở nhất lớn hơn số bí mật.
    smallest_x_with_secret_number = findSmallestXWithSecretNumber(secret_number, max_x);

    // Nhập số người chơi đoán.
    getUserInput(number_to_guess);

    if (checkWhoWin(number_to_guess, smallest_x_with_secret_number))
    {
        cout << "==> Ban da doan dung so X." << endl;
        cout << "==> Ban da chien thang vong 2." << endl;
        cout << "==> Ban da chien tro choi nay." << endl;
    }
    else
    {
        cout << "==> Ban da doan sai so X." << endl;
        cout << "==> Ban da thua vong 2." << endl;
        cout << "==> Ban da thua trong tro choi nay." << endl;
    }
}
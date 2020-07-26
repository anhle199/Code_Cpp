#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    clock_t start = clock();
    cout << (double) (clock() - start) / CLOCKS_PER_SEC << endl;

    return 0;
}
#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

bool isPrime(int n) {
    if (n < 2)
        return false;

    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;

    return true;
}

int main() {
    int n, prime;
    queue<int> result;
    
    cin >> n;
    
    for (int i = 2; i <= min(n, 7); i++) {
        if (i == 2) {
            result.push(i);
        } else {
            result.push(i);
            i++;
        }
    }
    
    while (result.empty() == false && result.front() <= n) {
        for (int i = 1; i < 10; i++) {
            prime = (result.front() * 10) + i;
            
            if (prime > n)
                break;

            if (isPrime(prime))
                result.push(prime);
        }

        cout << result.front() << " ";
        result.pop();
    }

    while (!result.empty()) {
        cout << result.front() << " ";
        result.pop();
    }

    return 0;
}
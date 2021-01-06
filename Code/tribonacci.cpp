int arr[100] = { 0 };
int tribonacci(int n) {
    if (n <= 0)
        return 0;
    else if (n == 2 || n == 1) {
        arr[n] = 1;
        return 1;
    }

    if (arr[n] == 0)
        arr[n] = tribonacci(n - 3) + tribonacci(n - 2) + tribonacci(n - 1);

    return arr[n];
}

int arr[100] = { 0, 1, 1 };
int tribonacci(int n) {
    if (n <= 0)
        return 0;
    else if (n == 2 || n == 1)
        return 1;

    if (arr[n] == 0)
        arr[n] = tribonacci(n - 3) + tribonacci(n - 2) + tribonacci(n - 1);

    return arr[n];
}

int arr[100] = { 0, 1, 1 };
int tribonacci(int n) {
    if (n < 0)
        return 0;

    if (n <= 2)
        return arr[n];

    if (arr[n] == 0)
        arr[n] = tribonacci(n - 3) + tribonacci(n - 2) + tribonacci(n - 1);

    return arr[n];
}
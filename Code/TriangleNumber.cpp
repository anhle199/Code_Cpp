#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void printTriangle(int n)
{
	int k, m, p(n);
	k = (int)log10(n) + 1;
	m = (k + 1) * n;

	for (int i = n; i > 0; i--)
	{
		cout << setw(m)  << right;
		m -= (k + 1);
		
		for (int j = p; j <= n; j++)
			cout << j << setw(k  + 1) << right;
		for (int j = n - 1; j >= p; j--)
			cout << j << setw(k + 1) << right;
		cout << endl;
		
		p--;
	}
}

int main()
{
	int n;
	
	cout << "Nhap 1 so bat ky thuoc [1, 19]: ";
	cin >> n;
	
	while (1 <= n && n <= 19)
	{
		printTriangle(n);
		cout << endl;
		
		cout << "Nhap 1 so bat ky thuoc [1, 19]: ";
		cin >> n;
	}
	
	return 0;
}
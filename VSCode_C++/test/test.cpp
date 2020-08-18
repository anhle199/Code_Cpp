#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> a = {3,0,-2,-1,1,2};
    for (int i = 0; i < a.size(); i++) {
	cout << a[i] << " ";
    }

    return 0;
}
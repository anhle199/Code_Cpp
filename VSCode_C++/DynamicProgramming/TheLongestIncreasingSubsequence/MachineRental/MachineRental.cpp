#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void quickSort(vector<int> &s, vector<int> &e, vector<int> &c);
void quickSortImp(vector<int> &s, vector<int> &e, vector<int> &c, const int &left, const int &right);
int machineRentalV1(vector<int> s, vector<int> e, vector<int> c);
int machineRentalV2(vector<int> s, vector<int> e, vector<int> c);

int main() {
    vector<int> s = {1, 2, 3, 5};
    vector<int> e = {2, 3, 6, 8};
    vector<int> c = {2, 4, 5, 10};
    cout << machineRentalV1(s, e, c) << endl;
    cout << machineRentalV2(s, e, c) << endl;

    return 0;
}

void quickSort(vector<int> &s, vector<int> &e, vector<int> &c) {
    int n = e.size();
    quickSortImp(s, e, c, 0, n - 1);
}

void quickSortImp(vector<int> &s, vector<int> &e, vector<int> &c, const int &left, const int &right) {
    int i, j, x;

    i = left;
    j = right;
    x = e[left + ((right - left) / 2)]; // Lấy phần tử ở giữa làm mốc.

    do
    {
        while (x > e[i]) i++; // intìm vị trí phần tử bên trái bị sai vị trí.
        while (e[j] > x) j--; // intìm vị trí phần tử bên phải bị sai vị trí.
        
        if (i <= j)
        {
            swap(e[i], e[j]); // Đổi chỗ 2 phần tử sai vị trí.
            swap(s[i], s[j]);
            swap(c[i], c[j]);
            i++;
            j--;
        }
    } while (i <= j); // intiếp tục thực hiện neéu chỉ số còn hợp lệ.
    
    // Sắp xếp các dãy nếu còn nhiều phần tử.
    // Không sắp xếp nữa nếu các dãy chỉ còn 1 phần tử.
    if (left < j) quickSortImp(s, e, c, left, j);
    if (i < right) quickSortImp(s, e, c, i, right);
}

int machineRentalV1(vector<int> s, vector<int> e, vector<int> c) {
    int n = e.size(), pos_max;
    vector<int> total_money(n + 2, 0);

    quickSort(s, e, c);
    e.insert(e.begin(), INT_MIN);
    s.insert(s.begin(), INT_MIN);
    c.insert(c.begin(), 0);

    for (int i = n; i >= 0; i--) {
        pos_max = n + 1;
        for (int j = i + 1; j <= n; j++)
            if (s[j] >= e[i] && total_money[j] > total_money[pos_max])
                pos_max = j;

        total_money[i] = total_money[pos_max] + c[i];
    }

    return total_money[0];
}

int machineRentalV2(vector<int> s, vector<int> e, vector<int> c) {
    int n = e.size(), pos_max;
    vector<int> total_money(n);

    quickSort(s, e, c);
    
    total_money[0] = c[0];

    for (int i = 1; i < n; i++) {
        total_money[i] = c[i];

        for (int j = 0; j < i; j++) 
            if (s[i] >= e[j] && total_money[i] < total_money[j] + c[i])
                total_money[i] = total_money[j] + c[i];
    }

    return *max_element(total_money.begin(), total_money.end());
}
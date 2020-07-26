#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void quickSort(vector<int> &s, vector<int> &e);
void quickSortImp(vector<int> &s, vector<int> &e, const int &left, const int &right);
int mettingRoomV1(vector<int> s, vector<int> e);
int mettingRoomV2(vector<int> s, vector<int> e);

int main() {
    vector<int> s = {1, 2, 3, 5};
    vector<int> e = {2, 4, 6, 8};
    cout << mettingRoomV1(s, e) << endl;
    cout << mettingRoomV2(s, e) << endl;
    return 0;
}

void quickSort(vector<int> &s, vector<int> &e) {
    int n = s.size();
    quickSortImp(s, e, 0, n - 1);
}

void quickSortImp(vector<int> &s, vector<int> &e, const int &left, const int &right) {
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
            i++;
            j--;
        }
    } while (i <= j); // intiếp tục thực hiện neéu chỉ số còn hợp lệ.
    
    // Sắp xếp các dãy nếu còn nhiều phần tử.
    // Không sắp xếp nữa nếu các dãy chỉ còn 1 phần tử.
    if (left < j) quickSortImp(s, e, left, j);
    if (i < right) quickSortImp(s, e, i, right);
}

int mettingRoomV1(vector<int> s, vector<int> e) {
    int n = e.size(), pos_max;
    vector<int> length(n + 2, 0);

    quickSort(s, e);
    e.insert(e.begin(), INT_MIN);
    s.insert(s.begin(), INT_MIN);

    for (int i = n; i >= 0; i--) {
        pos_max = n + 1;
        for (int j = i + 1; j <= n; j++)
            if (s[j] >= e[i] && length[j] > length[pos_max])
                pos_max = j;
    
        length[i] = length[pos_max] + 1;
    }

    return length[0] - 1;
}

int mettingRoomV2(vector<int> s, vector<int> e) {
    int n = e.size();
    vector<int> length(n);

    quickSort(s, e);
    length[0] = 1;

    for (int i = 1; i < n; i++) {
        length[i] = 1;

        for (int j = 0; j < i; j++) 
            if (s[i] >= e[j] && length[i] < length[j] + 1)
                length[i] = length[j] + 1;
    }

    return *max_element(length.begin(), length.end());
}
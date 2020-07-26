// Mặc định là sắp xếp tăng dần.
// Nếu sắp xếp giảm dần thì thêm tham số descending. 

#ifndef MY_SORT_VECTOR_T
#define MY_SORT_VECTOR_T

#include <vector>   // Dùng vector<>
#include <algorithm>

using namespace std;

// ------------------------------------------------------------------------------
// Phần khai báo

template <class T>
bool ascending(const T &a, const T &b); // Sắp xếp tăng dần.
template <class T>
bool descending(const T &a, const T &b); // Sắp xếp giảm dần.
template <class T>
void selectionSort(vector<T> &arr, bool (*compare)(const T&, const T&) = ascending);
template <class T>
void dummySelectionSort(vector<T> &arr, bool (*compare)(const T&, const T&) = ascending);
template <class T>
void insertionSort(vector<T> &arr, bool (*compare)(const T&, const T&) = ascending);
template <class T>
void insertionSortWithSentinel(vector<T> &arr, bool (*compare)(const T&, const T&) = ascending); // Giảm được 1 điều kiện trong vòng lặp while so với hàm InsertionSort
template <class T>
void binaryInsertionSort(vector<T> &arr, bool (*compare)(const T&, const T&) = ascending);
template <class T>
void bubbleSort(vector<T> &arr, bool (*compare)(const T&, const T&) = ascending); // ExchangeSort
template <class T>
void shakeSort(vector<T> &arr, bool (*compare)(const T&, const T&) = ascending);
template <class T>
void quickSort(vector<T> &arr, bool (*compare)(const T&, const T&) = ascending);
template <class T>
void quickSortImp(vector<T> &arr, const int &left, const int &right, bool (*compare)(const T&, const T&) = ascending);

//------------------------------------------------------------------------------------------------
// Phần cài đặt

// a là phần tử phía trước phần tử b
template <class T>
bool ascending(const T &a, const T &b)
{
    return (a > b);
}

template <class T>
bool descending(const T &a, const T &b)
{
    return (a < b);
}

template <class T>
void selectionSort(vector<T> &arr, bool (*compare)(const T&, const T&))
{
    int n = arr.size();

    for (int i = 0; i < n - 1; i++)
    {
        int j, pos(i);

        for (j = i + 1; j < n; j++)
            if (compare(arr[pos], arr[j]))
                pos = j;
        
        swap(arr[i], arr[pos]);
    }
}

template <class T>
void dummySelectionSort(vector<T> &arr, bool (*compare)(const T&, const T&))
{
    int n = arr.size();

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (compare(arr[i], arr[j]))
                swap(arr[i], arr[j]);
}

template <class T>
void insertionSort(vector<T> &arr, bool (*compare)(const T&, const T&))
{
    int n = arr.size();

    for (int i = 1; i < n; i++)
    {
        int x, j;

        x = arr[i];
        j = i - 1;

        while ((j >= 0) && compare(arr[j], x))
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = x;
    }
}

template <class T>
void insertionSortWithSentinel(vector<T> &arr, bool (*compare)(const T&, const T&))
{
    arr.push_back(arr[0]);
    int n = arr.size();
    
    for (int i = 2; i < n; i++)
    {
        int x, j;

        x = arr[i];
        j = i - 1;
        arr[0] = x;

        while (compare(arr[j], x))
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = x;
    }

    arr.erase(arr.begin());
}

template <class T>
void binaryInsertionSort(vector<T> &arr, bool (*compare)(const T&, const T&))
{
    int n = arr.size();

    for (int i = 1; i < n; i++)
    {
        int x, left, right, mid;

        x = arr[i];
        left = 0;
        right = i - 1;

        while (left <= right)
        {
            mid = (left + right) / 2;
            
            if (compare(x, arr[mid]))
                left = mid + 1;
            else
                right = mid - 1;
        }

        for (int j = i; j > left; j--)
            arr[j] = arr[j - 1];
        arr[left] = x;
    }
}

template <class T>
void bubbleSort(vector<T> &arr, bool (*compare)(const T&, const T&))
{
    int n = arr.size();

    for (int i = 1; i < n; i++)
        for (int j = n - 1; j >= i; j--)
            if (compare(arr[j - 1], arr[j]))
                swap(arr[j - 1], arr[j]);
}

template <class T>
void shakeSort(vector<T> &arr, bool (*compare)(const T&, const T&))
{
    int left, right, k, n;
    
    n = arr.size();
    left = 1;
    right = n - 1;

    do
    {
        for (int i = right; i >= left; i--)
            if (compare(arr[i - 1], arr[i]))
            {
                swap(arr[i - 1], arr[i]);
                k = i;
            }

        left = k + 1;

        for (int i = left; i <= right; i++)
            if (compare(arr[i - 1], arr[i]))
            {
                swap(arr[i - 1], arr[i]);
                k = i;
            }

        right = k - 1;
    } while (left <= right);
}

template <class T>
void quickSort(vector<T> &arr, bool (*compare)(const T&, const T&))
{
    int n = arr.size();
    quickSortImp(arr, 0, n - 1, compare);
}

template <class T>
void quickSortImp(vector<T> &arr, const int &left, const int &right, bool (*compare)(const T&, const T&))
{
    int i, j;
    T x;

    i = left;
    j = right;
    x = arr[left + ((right - left) / 2)]; // Lấy phần tử ở giữa làm mốc.

    do
    {
        while (compare(x, arr[i])) i++; // Tìm vị trí phần tử bên trái bị sai vị trí.
        while (compare(arr[j], x)) j--; // Tìm vị trí phần tử bên phải bị sai vị trí.
        
        if (i <= j)
        {
            swap(arr[i], arr[j]); // Đổi chỗ 2 phần tử sai vị trí.
            i++;
            j--;
        }
    } while (i <= j); // Tiếp tục thực hiện neéu chỉ số còn hợp lệ.
    
    // Sắp xếp các dãy nếu còn nhiều phần tử.
    // Không sắp xếp nữa nếu các dãy chỉ còn 1 phần tử.
    if (left < j) quickSortImp(arr, left, j, compare);
    if (i < right) quickSortImp(arr, i, right, compare);
}

#endif
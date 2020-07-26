#ifndef ARRAY_1D_T_IMP_H_
#define ARRAY_1D_T_IMP_H_

#include "Array1D_T.h"
#include <iostream> // Use std::cout, std::endl.
#include <algorithm> // Use function swap().

template <class T>
bool operator==(Array1D<T> &arr_src, Array1D<T> &arr_dest)
{
    int size_arr_src = sizeArray(arr_src), size_arr_dest = sizeArray(arr_dest);

    if (size_arr_src != size_arr_dest)
        return false;
    
    for (int i = 0; i < size_arr_src; i++)
        if (arr_src[i] != arr_dest[i])
            return false;
    
    return true;
}

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
T* const beginArray(Array1D<T> &arr)
{ 
    if (sizeArray(arr) <= 0)
        return nullptr; 
    return arr.data;
}

template <class T>
T* const endArray(Array1D<T> &arr)
{
    if (sizeArray(arr) <= 0)
        return nullptr;
    return arr.data + ((sizeArray(arr) - 1) * sizeof(T));
}

template <class T>
T& front(Array1D<T> &arr)
{ 
    return *beginArray(arr); 
}

template <class T>
T& back(Array1D<T> &arr)
{ 
    return *endArray(arr);
}

template <class T>
T& maxElement(Array1D<T> &arr)
{
    int max_value = arr[0], n = sizeArray(arr);
    static T dummy;

    if (n == 0)
        return dummy;

    for (int i = 1; i < n; i++)
        if (max_value < arr[i])
            max_value = arr[i];
    
    return max_value;
}

template <class T>
T& minElement(Array1D<T> &arr)
{
    int min_value = arr[0], n = sizeArray(arr);
    static T dummy;

    if (n == 0)
        return dummy;
    
    for (int i = 1; i < n; i++)
        if (min_value > arr[i])
            min_value = arr[i];
        
    return min_value;
}

template <class T>
bool isEmpty(Array1D<T> &arr)
{
    if (sizeArray(arr) == 0)
        return true;
    return false;
}

template <class T>
void resizeArray(Array1D<T> &arr, const int &newSize)
{
    int n = sizeArray(arr); // Lấy ra số phần tử của mảng cũ.

    if (newSize <= 0)
        return;

    T *arrNew = new T[newSize]; // Cấp phát mảng mới.

    if (arr.data != nullptr)
    {
        for (int i = 0; i < n; i++)
            arrNew[i] = arr[i]; // Sao chép từng phần tử của mảng cũ sang mảng mới.
    
        delete[] arr.data; // Thu mảng cũ.
    }

    arr.data = arrNew; // Trỏ sang mảng mới.
    arr.number_of_elements = newSize; // Cập nhật lại số phần tử.
}

template <class T>
int sizeArray(Array1D<T> &arr)
{ 
    return arr.number_of_elements; 
}

template <class T>
T* const findElement(Array1D<T> &arr, const T &value)
{
    int index = 0, n = sizeArray(arr);
    
    for ( ;index < n; index++)
        if (arr[index] == value)
            break;

    return (beginArray(arr) + index);
}

template <class T>
T* const binarySearch(Array1D<T> &arr, const T &x, const bool &is_sorted, bool (*cmp)(const T &, const T &))
{
    int from(0), to(sizeArray(arr) - 1), mid;

    if (sizeArray(arr) == 0)
        return nullptr;
    if (is_sorted == false)
        sortArray(arr);

    while (from <= to)
    {
        mid = (from + to) / 2;

        if (arr[mid] == x)
            return (beginArray(arr) + mid);
        else if (cmp(x, arr[mid]))
            from = mid + 1; // Tìm kiếm bên nửa phải của mảng
        else
            to = mid - 1; // Tìm kiếm bên nửa trái của mảng
    }

    return nullptr; // Nếu không tìm thấy giá trị của x thì trả về NULL;
}

template <class T>
void binaryInsertWithAscending(Array1D<T> &arr, const T &x, const bool &is_sorted, bool (*cmp)(const T &, const T &))
{
    int from(0), to(sizeArray(arr) - 1), mid;

    if (is_sorted == false)
        sortArray(arr, cmp);
    
    while (from <= to)
    {
        mid = (from + to) / 2;

        if (cmp(x, arr[mid]))
            from = mid + 1;
        else
            to = mid - 1;
    }

    insertAt(arr, from, x);
}

template <class T>
void pushBack(Array1D<T> &arr, const T &value)
{
    int newSize = ++arr.number_of_elements;
    
    resizeArray(arr, newSize); // Cập nhật mảng thêm 1 phần tử.
    arr[newSize - 1] = value; // Gán giá trị vào cuối mảng.
}

template <class T>
void popBack(Array1D<T> &arr)
{
    int newSize = --arr.number_of_elements;
    resizeArray(arr, newSize);
}

template <class T>
void insertAt(Array1D<T> &arr, const int &position, const T &value)
{   
    if (position > sizeArray(arr) || position < 0)
        return;
    
    int newSize = ++arr.number_of_elements;
    resizeArray(arr, newSize);

    for (int i = newSize - 1; i > position; i--)
        arr[i] = arr[i - 1];
    
    arr[position] = value;
}

template <class T>
void removeAtPosition(Array1D<T> &arr, const int &position)
{
    int n = sizeArray(arr);

    for (int i = position + 1; i < n; i++)
        arr[i - 1] = arr[i];
    
    popBack(arr);
}

template <class T>
void quickSortImp(Array1D<T> &arr, const int &left, const int &right, bool (*compare)(const T&, const T&))
{
    int i, j, x;

    i = left;
    j = right;
    x = arr[left + ((right - left) / 2)]; // Lấy phần tử ở giữa làm mốc.

    do
    {
        while (compare(x, arr[i])) i++; // Tìm vị trí phần tử bên trái bị sai vị trí.
        while (compare(arr[j], x)) j--; // Tìm vị trí phần tử bên phải bị sai vị trí.
        
        if (i <= j)
        {
            std::swap(arr[i], arr[j]); // Đổi chỗ 2 phần tử sai vị trí.
            i++;
            j--;
        }
    } while (i <= j); // Tiếp tục thực hiện neéu chỉ số còn hợp lệ.
    
    // Sắp xếp các dãy nếu còn nhiều phần tử.
    // Không sắp xếp nữa nếu các dãy chỉ còn 1 phần tử.
    if (left < j) quickSortImp(arr, left, j, compare);
    if (i < right) quickSortImp(arr, i, right, compare);
}

template <class T>
void sortArray(Array1D<T> &arr, bool (*compare)(const T&, const T&))
{
    if (sizeArray(arr) == 0)
        return;

    quickSortImp(arr, 0, sizeArray(arr) - 1, compare);
}

template <class T>
void printArray(Array1D<T> &arr)
{
    int n = sizeArray(arr);

    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

template <class T>
void deleteArray(Array1D<T> &arr)
{
    if (arr.data != nullptr)
    {
        delete[] arr.data;

        arr.data = nullptr;
        arr.number_of_elements = 0;
    }
}

#endif
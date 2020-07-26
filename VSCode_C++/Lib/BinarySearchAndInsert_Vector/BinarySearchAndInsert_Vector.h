// File: BinarySearchAndInsert_Vector.h
// Use STL vector.

#ifndef BINARY_SEARCH_AND_INSERT_VECTOR_H_
#define BINARY_SEARCH_AND_INSERT_VECTOR_H_

#include <vector>

// - Hàm này dùng để tìm kiếm cho mảng tăng dần.
template <class T>
bool ascending(const T &a, const T &b);

// - Hàm này dùng để tìm kiếm cho mảng giảm dần.
template <class T>
bool descending(const T &a, const T &b);

// - Thuật toán tìm kiếm nhị phân, mặc định là tìm với mảng tăng dần.
// - Nếu tìm thấy thì rả về chỉ số mà phần tử x xuất hiện cuối cùng.
// - Ngược lại thì trả về -1.
template <class T>
int binarySearch(const std::vector<T> &arr, const T &x, bool (*cmp)(const T &, const T &) = ascending);

template <class T>
void binaryInsert(std::vector<T> &arr, const T &x, bool (*cmp)(const T &, const T &) = ascending);

/*
 * -----------------------------------------------------
 * Phần cài đặt.
 * -----------------------------------------------------
 */

template <class T>
bool ascending(const T &a, const T &b) {
    return a > b;
}

template <class T>
bool descending(const T &a, const T &b) {
    return a < b;
}

template <class T>
int binarySearch(const std::vector<T> &arr, const T &x, bool (*cmp)(const T &, const T &)) {
    int n = arr.size(), from(0), to(n - 1), mid;

    while (from <= to) {
        mid = (from + to) / 2;

        if (arr[mid] == x)
            return mid;
        else if (cmp(x, arr[mid]))
            from = mid + 1; // Tìm kiếm bên nửa phải của mảng
        else
            to = mid - 1; // Tìm kiếm bên nửa trái của mảng
    }

    return -1; // Nếu không tìm thấy giá trị của x thì trả về 1;
}

template <class T>
void binaryInsert(std::vector<T> &arr, const T &x, bool (*cmp)(const T &, const T &) = ascending) {
    int n = arr.size(), from(0), to(n - 1), mid;

    while (from <= to) {
        mid = (from + to) / 2; // Chọn phần tử làm mốc để so sánh.

        if (cmp(x, arr[mid])) // Vị trí cần chèn không xuất hiện từ from đến mid.
            from = mid + 1; // Chỉ xét tiếp từ mid + 1 đến to.
        else // Vị trí cần chèn không xuất hiện từ mid đến to.
            to = mid - 1; // Chỉ xét tiếp từ from đến mid - 1.
    }

    arr.insert(arr.begin() + from, x); // Chèn giá trị x vào vị trí from.
}

#endif // End of file BinarySearchAndInsert_Vector.h
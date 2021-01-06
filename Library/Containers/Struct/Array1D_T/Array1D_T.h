// Tập tin Array1D_T.h.
#ifndef ARRAY_1D_T_H_
#define ARRAY_1D_T_H_

#pragma pack(1) // Tính đúng kích thước của kiểu.



/*
 * -----------------------------------------------------
 * Phần khai báo.
 * -----------------------------------------------------
 */

template <class T>
struct Array1D
{
    int number_of_elements;
    T *data;

    // - Tự động chạy khi khai báo biến cấu trúc.
    // - Dùng để đặc giá trị mặc định khi không khởi tạo số phần tử.
    Array1D(); 

    // - Khởi tạo mảng có giá trị khởi tạo.
    // - Giá trị khởi tạo mặc định là 0.
    Array1D(const int &n, const T &value = 0);

    // - Có thể truy cập với chỉ số âm. Ví dụ: data[-2] = data[1].
    T& operator[](int i);
};

// - So sánh hai mảng.
// - Trả về true nếu: số phần tử bằng nhau, giá trị của từng phần tử bằng nhau.
// - Ngược lại trả về false.
template <class T>
bool operator==(Array1D<T> &arr_src, Array1D<T> &arr_dest);

// - a là phần tử phía trước phần tử b.
// - Dùng cho sắp xếp tăng dần.
template <class T>
bool ascending(const T &a, const T &b);

// - a là phần tử phía trước phần tử b.
// - Dùng cho sắp xếp giảm dần.
template <class T>
bool descending(const T &a, const T &b); 

// - Trả về 1 con trỏ đến phần tử đầu tiên.
template <class T>
T* const begin(Array1D<T> &arr);

// - Trả về 1 con trỏ đến phần tử cuối.
template <class T>
T* const end(Array1D<T> &arr);

// - Trả về 1 giá trị tham chiếu đến phần tử đầu tiên.
template <class T>
T& front(Array1D<T> &arr);

// - Trả về 1 giá trị tham chiếu đến phần tử cuối.
template <class T>
T& back(Array1D<T> &arr);

// - Trả về giá trị tham chiếu đến phần tử lớn nhất xuất hiện đầu tiên.
template <class T>
T& maxElement(Array1D<T> &arr);
    
// - Trả về giá trị tham chiếu đến phần tử nhỏ nhất xuất hiện đầu tiên.
template <class T>
T& minElement(Array1D<T> &arr);

// Kiểm tra mảng có rỗng hay không.
template <class T>
bool isEmpty(Array1D<T> &arr);

// - Thay đổi kích thước của mảng.
template <class T>
void resizeArray(Array1D<T> &arr, const int &newSize);

// - Kích thước hiện tại của mảng.
template <class T>
int sizeArray(Array1D<T> &arr);

// - Nếu tìm thấy thì trả về 1 con trỏ đến vị trí phần tử đó xuất hiện dầu tiên.
// - Ngược lại thì trả về null;
template <class T>
T* const findElement(Array1D<T> &arr, const T &value);

// - Tìm kiếm nhị phân trên mảng.
// - Giá trị trả về giống hàm findElement.
template <class T>
T* const binarySearch(Array1D<T> &arr, const T &x, const bool &is_sorted, bool (*cmp)(const T &, const T &) = ascending);

template <class T>
void binaryInsertWithAscending(Array1D<T> &arr, const T &x, const bool &is_sorted, bool (*cmp)(const T &, const T &) = ascending);

// - Thêm 1 phần tử vào cuối mảng.
template <class T>
void pushBack(Array1D<T> &arr, const T &value);

// - Xóa 1 phần tử cuối mảng.
template <class T>
void popBack(Array1D<T> &arr);

// - Thêm 1 phần tử vào vị trí position.
template <class T>
void insertAt(Array1D<T> &arr, const int &position, const T &value);

// - Xoá phần tử đầu tiên có giá trị value.
template <class T>
void removeValue(Array1D<T> &arr, const T &value);

// - Xóa 1 phần tử tại vị trí position.
template <class T>
void removeAtPosition(Array1D<T> &arr, const int &position);

// - Sắp xếp lại mảng.
// - Mặc định là tăng dần.
// - Nếu sắp xếp giảm dần thì truyền vào con trỏ hàm bool descending(const T &a, const T &b) đã định nghĩa sẵn.
template <class T>
void sortArray(Array1D<T> &arr, bool (*compare)(const T&, const T&) = ascending);

// - Hàm in mảng.
template <class T>
void printArray(Array1D<T> &arr);

// - Giải phóng vùng nhớ data được cấp phát.
template <class T>
void deleteArray(Array1D<T> &arr);

/*
 * -----------------------------------------------------
 * Phần cài đặt hàm của struct.
 * -----------------------------------------------------
 */

template <class T>
Array1D<T>::Array1D()
{
    number_of_elements = 0;
    data = nullptr;
}

template <class T>
Array1D<T>::Array1D(const int &n, const T &value)
{
    if (n <= 0) return;

    data = new T[n]; // Khởi tạo các phần tử của mảng có giá trị value, mặc định là 0.
    number_of_elements = n; // Cập nhật só phần tử của mảng.

    for (int i = 0; i < number_of_elements; i++)
        data[i] = value;
}

template <class T>
T& Array1D<T>::operator[](int i)
{
    static T dummy;
    
    if (i >= number_of_elements || i < -number_of_elements || data == nullptr)
        return dummy; // Trả về giá trị rác khi truy cập chỉ số mảng không hợp lệ.
    else if (i < 0) // Truy cập với chỉ âm trong đoạn từ [-n, -1].
        i = (-i) - 1;

    return data[i];
}

#endif // Kết thúc tập tin Array1D.h.
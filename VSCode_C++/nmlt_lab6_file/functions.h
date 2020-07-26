#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

// Tính tổng các chữ số của 1 số.
int sumDigits(int n);

// Kiểm tra số nguyên tố.
bool isPrime(const int &n);

// Sao chép dữ liệu từ file_input.txt sang file_output.txt
bool copyFile(string file_input, string file_output);

// Convert nội dung file sao cho mỗi dòng có 60 kí tự
bool convertFile60CharsperLine(string file_input, string file_output);

// Tính giá trị trung bình số lượng các kí tự trên 1 dòng
float countAverageChar(string file_input);

// In code của chính nó ra màn hình
void printSource(string file_input);

// Xóa đi dòng cuối cùng
bool deleteLastLine(string file_input);

// Xóa đi các dòng trống (dòng chỉ có kí tự \n)
bool deleteEmptyLines(string file_input);

// Chèn một dòng trống sau dòng thứ 7
bool insert7thLine(string file_input);

// Chèn giữa các dòng một dòng trống (double-spaced)
bool insertDoubleSpaced(string file_input);

// Chèn dòng thứ 2 vào các dòng có số thứ tự chia hết cho 2
bool insert2thLine(string file_input);

// Xóa 2 kí tự đầu tiên của mỗi dòng
bool delete2FirstChars(string file_input);

// Ghi các số lẻ < n có tổng các chữ số chia hết cho 2 vào file
bool writeListOddNumbers(string file_output, const int &n);

// Đọc file output ở câu trên, và trả về số lượng số nguyên tố từ danh sách các số lẻ nói trên
int countPrimes(string file_input);

// - Đọc ma trận (mảng 2 chiều) từ file và tính tổng các phần tử trong ma trận đó.
// - Dòng đầu chứa số dòng và số cột.
// - Các dòng tiếp theo là nội dung của ma trận.
int sumMatrix(string file_input);


// - Đọc danh sách tên các thí sinh trong file, 
// - Xuất ra màn hình danh sách thí sinh được sắp xếp theo thứ tự aphabet
// - Với file đầu vào có dòng đầu tiên chứa số lượng tên thí sinh
// - Những dòng tiếp theo chứa tên của thí sinh.
void sortListNameV1(string file_input);

// - Đọc danh sách tên các thí sinh trong file, 
// - Xuất ra màn hình danh sách thí sinh được sắp xếp theo thứ tự aphabet
// - Với file đầu vào là các dòng chứa tên của thí sinh.
void sortListNameV2(string file_input);

#endif
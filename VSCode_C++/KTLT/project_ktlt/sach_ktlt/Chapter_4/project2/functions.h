#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

bool checkExpression(const string &expression);

// - Nhập 1 biểu thức từ người dùng.
void getExpression(string &expression);

// - Lấy ra 1 toán hạng đầu tiên kể từ chỉ số index để kiểm tra.
string getOperandInExpression(const string &str, int &index);

// - Kiểm tra có phải 1 kí số hay không.
bool isDigit(const char &ch);

// - Kiểm tra xem có phải 1 toán hạng hay không.
bool isOperand(const string &str);

/*
 - Kiểm tra có phải 1 toán hạng hay không.
 - Trả về giá trị theo thứ tự ưu tiên của toán hạng.
*/
int isOperator(const char &ch);

/*
 - Kiểm tra xem có phải dấu đóng, mở ngoặc hay không.
 - Trả về 1 nếu là mở ngoặc, 2 nếu là đóng ngoặc.
*/
int isBracket(const char &ch);

// - Tính giá trị 1 biểu thức có 2 toán hạng và 1 toán tử.
int calculate(const int &a, const int &b, const char &__operator);

// - Biểu diễn một biểu thức theo dạng Ba Lan ngược.
queue<string> representsExpression(const string &expression);

// - Tính giá trị biểu thức Ba Lan ngược.
int calculateExpressionValue(queue<string> &expression);

#endif
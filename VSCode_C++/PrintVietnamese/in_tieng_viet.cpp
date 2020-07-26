#include <iostream>
#include <io.h> // Để dùng hàm _setmode()
#include <fcntl.h> // Để dùng hàm _setmode()

using namespace std;

int main()
{
    int oldMode = _setmode(_fileno(stdout), _O_WTEXT);

    wcout << L"Xin chào các bạn! " << endl;
    wcout << L"Tôi là Lê Hoàng Anh." << endl;
    wcout << L"Hôm nay là chủ nhật, 12/1/2020." << endl;
    wcout << L"Bây giờ là 3:45 PM." << endl;

    return 0;
}
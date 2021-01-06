#include <iostream>
#include <io.h>
#include <fcntl.h>

using namespace std;

#define MAX_SIZE 10000

int main() {
    _setmode(_fileno(stdout), _O_U8TEXT);
    FILE* fin;
    fopen_s(&fin, "data.txt", "r");
    _setmode(_fileno(fin), _O_U8TEXT);
    // _O_TEXT : file mode is text.
    // _O_BINARY : file mode is binary.
    // _O_WTEXT: file mode is UTF16.
    // _O_U16TEXT : file mode is UTF16 no BOM.
    // _O_U8TEXT: file mode is UTF8 no BOM.

    wchar_t* buffer = new wchar_t[MAX_SIZE] {0};
    size_t count = 0;

    do {
        count = fread(buffer, sizeof(wchar_t), MAX_SIZE, fin);
        wcout << buffer << endl;
    } while (count == MAX_SIZE);

    fclose(fin);

    return 0;
}
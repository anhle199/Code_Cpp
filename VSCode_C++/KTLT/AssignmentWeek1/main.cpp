// MSSV: 19127329
#include "functions.h"

int main() {
    Plantation p;

    if (readData("NongTrai.in", p)) {
        writeResult("NongTrai.out", p);
        cout << "Done." << endl;
    } else {
        cout << "File does not exist." << endl;
    }

    return 0;
}

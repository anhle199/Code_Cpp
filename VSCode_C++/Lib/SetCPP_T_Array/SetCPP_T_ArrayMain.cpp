#include "SetCPP_T_Array.h"
#include "SetCPP_T_ArrayImp.h"
#include <ctime>

int main() {
    Set<int> set;
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    initSet(set);
    srand((int)time(NULL));

    for (int i = 0; i < n; i++)
        insertElement(set, rand() % 20);

    cout << "Ban dau: ";
    printSet(set);

    cout << "Sau khi xoa phan tu dau va cuoi: ";
    removeElementWithPosition(set, beginSet(set));
    removeElementWithPosition(set, endSet(set));
    printSet(set);

    closeSet(set);

    return 0;
}
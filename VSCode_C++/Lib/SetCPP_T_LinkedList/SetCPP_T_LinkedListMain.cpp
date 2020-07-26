#include "SetCPP_T_LinkedList.h"
#include "SetCPP_T_LinkedListImp.h"
#include <ctime>

using namespace std;

int main() {
    Set<int> set;
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    initSet(set);
    srand((int)time(NULL));

    for (int i = 0; i < n; i++)
        insertElement(set, rand() % 20);

    cout << "Kich thuoc: " << sizeSet(set) << endl;
    cout << "Co " << n - sizeSet(set) << " phan tu bi trung" << endl;

    cout << "Ban dau: ";
    printSet(set);

    cout << "Sau khi xoa phan tu dau va cuoi: ";
    removeElement(set, front(set));
    removeElement(set, back(set));
    printSet(set);

    closeSet(set);
    return 0;
}
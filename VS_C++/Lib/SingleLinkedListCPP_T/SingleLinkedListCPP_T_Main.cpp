#include "SingleLinkedListCPP_T.h"
#include <ctime>

int main() {
    List<int> list;
    Node<int> *Max, *Min;
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    srand((int)time(NULL));

    for (int i = 0; i < n; i++)
        insertAtLast(list, rand() % 20);

    cout << "Size of single linked list: " << length(list) << endl;

    cout << "Danh sach ban dau: ";
    printList(list);

    Max = maxElement(list);
    Min = minElement(list);
    cout << "Gia tri lon nhat danh sach: " << Max->data << endl;
    cout << "Gia tri nho nhat danh sach: " << Min->data << endl;

    cout << "Danh sach sau khi da sap xep giam dan: ";
    sortList(list, descending);
    printList(list);

    deleteList(list);

    return 0;
}
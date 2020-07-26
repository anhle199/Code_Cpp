#include "DoubleLinkedListCPP_T.h"
#include <ctime>

int main() {
    DoubleList<int> double_list;
    Node<int> *Max, *Min;
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    srand((int)time(NULL));

    for (int i = 0; i < n; i++)
        insertAtLast(double_list, rand() % 20);

    cout << "Size of double linked list: " << length(double_list) << endl;

    cout << "Danh sach ban dau: ";
    printDoubleList(double_list);

    Max = maxElement(double_list);
    Min = minElement(double_list);
    cout << "Gia tri lon nhat danh sach: " << Max->data << endl;
    cout << "Gia tri nho nhat danh sach: " << Min->data << endl;

    cout << "Danh sach sau khi da sap xep giam dan: ";
    sortDoubleList(double_list, descending);
    printDoubleList(double_list);

    deleteDoubleList(double_list);

    return 0;
}
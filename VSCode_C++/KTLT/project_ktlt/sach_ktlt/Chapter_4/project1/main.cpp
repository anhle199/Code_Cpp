#include "Functions_T.h"
#include "SingleLinkedListCPP_T.h"

int main() {
    List<int> list, list_even_positon, list_odd_position;

    inputList(list);
    
    cout << "Danh sach ban dau: ";
    printList(list);

    splitIntoTwoLists(list, list_even_positon, list_odd_position);
    cout << "Danh sach chua cac phan tu o vi tri chan: ";
    printList(list_even_positon);
    cout << "Danh sach chua cac phan tu o vi tri le: ";
    printList(list_odd_position);

    reverseList(list);
    cout << "Danh sach sau khi dao nguoc: ";
    printList(list);

    removeElementsDuplicateInList(list);
    cout << "Danh sach sau khi da xoa cac phan tu trung: ";
    printList(list);

    deleteList(list);

    return 0;
}
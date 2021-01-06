#include "StackCPP_T.h"
#include "StackCPP_T_Imp.h"
#include <ctime> // Use function time()

using namespace std;

int main() {
    Stack<int> stack;
    int n, top_element;

    srand((int)time(NULL));

    cout << "Enter number of elements: ";
    cin >> n;

    initStack(stack);

    for (int i = 0; i < n; i++)
        pushStack(stack, rand() % 20);

    cout << "Size of stack: " << sizeStack(stack) << endl;
    printStack(stack);

    top_element = topStack(stack);
    cout << "Top element of the stack: " << top_element << endl;

    closeStack(stack);

    return 0;
}
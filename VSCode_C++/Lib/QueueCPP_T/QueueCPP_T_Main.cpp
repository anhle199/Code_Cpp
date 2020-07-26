#include "QueueCPP_T.h"
#include "QueueCPP_T_Imp.h"
#include <ctime> // Use function time()

using namespace std;

int main() {
    Queue<int> queue;
    int n;
    
    srand((int) time(NULL));
    initQueue(queue);
    
    cout << "Enter number of element: ";
    cin >> n;

    for (int i = 0; i < n; i++)
        pushQueue(queue, rand() % 100);
        
    cout << "Size of queue: " << sizeQueue(queue) << endl;
    printQueue(queue);
    closeQueue(queue);

    return 0;
}
#include <iostream>
#include "Sort.h"

using namespace std;

template <class T>
bool ascending(const T &lhs, const T &rhs) {
    return lhs <= rhs;
}

template <class T>
int ascendingInt(const T &lhs, const T &rhs) {
    if (lhs == rhs)
        return 0;
    if (lhs < rhs)
        return 1;
    return -1;
}

class test {
public:
    int value;
    char c;

    //test() : value(0), c('a') {}

    bool operator==(const test &t) const {
        return value == t.value;
    }

    bool operator<(const test &t) const {
        return value < t.value;
    }

    bool operator>(const test &t) const {
        return value > t.value;
    }

    bool operator<=(const test &t) const {
        return value <= t.value;
    }

    friend ostream& operator<<(ostream &os, const test &t) {
        cout << t.value << t.c;

        return os;
    }
};

void RadixSort(vector<test> &a) {
    test maxElement = *max_element(a.begin(), a.end());
    int maxCountDigit = (int)log10(maxElement.value) + 1;
    int temp = 1;
    int size = a.size();

    vector<int> numberOfElements(10, 0);
    vector<vector<test>> bins(10, vector<test>(size));

    while (maxCountDigit > 0) {
        for (int i = 0; i < size; i++) {
            int digit = (a[i].value / temp) % 10;
            bins[digit][numberOfElements[digit]++] = a[i];
        }

        int j = 0;
        vector<int> index(10, 0);
        for (int i = 0; i < size; i++) {
            while (numberOfElements[j] == 0 || index[j] == numberOfElements[j]) 
                ++j;

            a[i] = bins[j][index[j]++];
        }

        temp *= 10;
        --maxCountDigit;
    }
}

void InsertionSortTemp(test a[], int n) {
    test x;
    int j;

    for (int i = 1; i < n; i++) {
        x = a[i];

        j = i - 1;
        while (j >= 0 && a[j].value > x.value) {
            a[j + 1] = a[j];
            --j;
        }

        a[j + 1] = x;
    }
}

void FlashSort(vector<test> &a) {
    // find max and min.
    auto temp = minmax_element(a.begin(), a.end());
    int maxElement = temp.second->value;
    int minElement = temp.first->value;
    int n = a.size();

    // count the number of classes.
    int countClasses = int(0.42 * n);

    vector<int> classes(maxElement - minElement + 1);
    vector<int> firstPositions(countClasses + 1, 0);

    for (int i = 0; i < n; i++) {
        int k = ((countClasses - 1) * (a[i].value - minElement)) / (maxElement - minElement);
        classes[a[i].value - minElement] = k;
        ++firstPositions[k + 1];
    }

    for (int i = 2; i < countClasses; i++)
        firstPositions[i] += firstPositions[i - 1];

    vector<int> sizeCurrent(countClasses, 0);
    test dummy[n];
    for (int i = 0; i < n; i++) {
        int index = firstPositions[classes[a[i].value - minElement]] + sizeCurrent[classes[a[i].value - minElement]];
        ++sizeCurrent[classes[a[i].value - minElement]];
        dummy[index] = a[i];
    }

    for (int i = 0; i < countClasses; i++) {
        int length = firstPositions[i + 1] - firstPositions[i];
        InsertionSortTemp(dummy + firstPositions[i], length);
    }

    for (int i = 0; i < n; i++)
        a[i] = dummy[i];
}

void CountingSort(vector<test> &a) {
    auto temp = minmax_element(a.begin(), a.end());
    int maxElement = temp.second->value;
    int minElement = temp.first->value;
    int n = a.size();

    int m = maxElement - minElement + 1;
    vector<int> count(m, 0);

    for (int i = 0; i < n; i++)
        ++count[a[i].value - minElement];
    
    for (int i = 1; i < m; i++)
        count[i] += count[i - 1];

    vector<test> dummy(n);
    for (int i = n - 1; i >= 0; i--) {
        --count[a[i].value - minElement];
        dummy[count[a[i].value - minElement]] = a[i]; 
    }

    for (int i = 0; i < n; i++)
        a[i] = dummy[i];
}

int main() {
    // vector<int> a = {4, 38, 6, 8, 72, 3, 5, 6, 8, 2, 3, 49, 23};
    // vector<test> a = { {3, 'a'}, {8, 'a'}, {3, 'b'}, {8, 'b'}, {6, 'a'}, {6, 'b'}, {5, 'a'}, {7, 'a'}, {4, 'a'}, {5, 'b'}, {3, 'c'} , {4, 'b'}};
    // vector<test> b = a;
    // vector<test> c = a;
    // vector<test> d = a;
    // vector<test> e = a;
    // vector<test> f = a;
    // vector<test> g = a;
    // vector<test> h = a;
    // vector<test> i = a;
    
    // ////// STABLE.

    // cout << "Before                 : ";
    // for (const test &t : a)    
    //     cout << t << " ";
    // cout << endl;

    // Sort<test>::InsertionSort(b, ascending);
    // Sort<test>::BinaryInsertionSort(c, ascending);
    // Sort<test>::BubbleSort(d, ascending);
    // Sort<test>::ShakerSort(e, ascending);
    // Sort<test>::MergeSort(f, ascending);
    // CountingSort(g);
    // RadixSort(h);
    // FlashSort(i);
    
    // cout << "\nAfter                  :" << endl;

    // cout << "- Insertion Sort       : ";
    // for (const test &t : b)    
    //     cout << t << " ";
    // cout << endl;

    // cout << "- Binary Insertion Sort: ";
    // for (const test &t : c)    
    //     cout << t << " ";
    // cout << endl;

    // cout << "- Bubble               : ";    
    // for (const test &t : d)    
    //     cout << t << " ";
    // cout << endl;

    // cout << "- Shaker Sort          : ";
    // for (const test &t : e)    
    //     cout << t << " ";
    // cout << endl;

    // cout << "- Merge Sort           : ";
    // for (const test &t : f)    
    //     cout << t << " ";
    // cout << endl;

    // cout << "- Counting Sort        : ";
    // for (const test &t : g)    
    //     cout << t << " ";
    // cout << endl;

    // cout << "- Radix Sort           : ";
    // for (const test &t : h)    
    //     cout << t << " ";
    // cout << endl;

    // cout << "- Flash Sort           : ";
    // for (const test &t : i)    
    //     cout << t << " ";
    // cout << endl;


    ////// UNSTABLE.

    // Sort<test>::SelectionSort(b, ascending);
    // Sort<test>::ShellSort(c, ascending);
    // Sort<test>::HeapSort(d, ascendingInt);
    // Sort<test>::QuickSort(e, ascendingInt);

    // cout << "Before        : ";
    // for (const test &t : a)    
    //     cout << t << " ";
    // cout << endl;

    // cout << "\nAfter         : " << endl;

    // cout << "Selection Sort: ";
    // for (const test &t : b)    
    //     cout << t << " ";
    // cout << endl;

    // cout << "Shell Sort    : ";
    // for (const test &t : c)    
    //     cout << t << " ";
    // cout << endl;

    // cout << "Heap Sort     : ";
    // for (const test &t : d)    
    //     cout << t << " ";
    // cout << endl;

    // cout << "Quick Sort    : ";
    // for (const test &t : e)    
    //     cout << t << " ";
    // cout << endl;



    return 0;
}

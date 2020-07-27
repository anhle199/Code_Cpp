#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main() {
	BinaryTree<int> b;

	int x;

	for (int i = 0; i < 5; i++) {
		cout << "Enter: ";
		cin >> x;
		
		b.add(x);
	}

	cout << BinaryTree<int>::size << endl;

	return 0;
}
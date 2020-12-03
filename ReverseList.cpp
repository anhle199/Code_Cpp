#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
};

typedef Node* Ref;

void ReverseList(Ref &head) {
	if (head == nullptr || head->next == nullptr)
		return;

	Ref q1 = nullptr;
	Ref q2 = head;
	Ref q3 = head->next;

	while (q3) {
		q2->next = q1;
		q1 = q2;
		q2 = q3;
		q3 = q3->next;
	}

	head = q2;
}

int main() {
	return 0;
}
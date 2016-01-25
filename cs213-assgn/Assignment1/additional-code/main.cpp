#include <iostream>
#include "list.hpp"
#include "node.hpp"

using namespace std;

int main() {
	int chain_size, loop_size;
	cin >> chain_size >> loop_size;
	Node* head = new Node(0);
	Node* cur = head;
	for (int i = 0; i < chain_size; ++i) {
		Node* next = new Node(0);
		cur->setNext(next);
		cur = cur->getNext();
	}
	
	Node* chain_end = cur;

	cur = head;
	head = head->getNext();
	delete cur;

	Node* head2 = new Node(0);
	cur = head2;

	for (int j = 0; j < loop_size; ++j) {
		Node* next = new Node(0);
		cur->setNext(next);
		cur = cur->getNext();
	}
	if (chain_size != 0) {
		chain_end->setNext(head2->getNext());
	} else {
		head = head2->getNext();
	}
	cur->setNext(head2->getNext());
	delete head2;

	cout << cycle_size(head) << endl;
}
	
	

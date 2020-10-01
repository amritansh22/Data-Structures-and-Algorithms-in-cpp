#include <iostream>
using namespace std; 

struct Node {
	int data; 
	Node* next;
	Node(int data): data(data), next(nullptr) {}
};

class LinkedList {
private: 
	Node* head;
	Node* tail;

public:
	LinkedList();
	void append(int );
	bool search(int );
};


LinkedList::LinkedList() {
	head = nullptr;
	tail = nullptr;
}

void LinkedList::append(int val) {
	Node* newNode = new Node(val);

	if (head == nullptr) {
		head = newNode;
		tail = newNode;
	}
	else if (tail == head) {
		head->next = newNode;
		tail = newNode;
	}
	else { 
		tail->next = newNode;
		tail = newNode;
	}
}

bool LinkedList::search(int val) {
	
	for (Node* curr = head; curr != nullptr; curr = curr->next) {
		if (curr->data == val) {
			cout << "True" << endl;
			return true;
		}
	}
	cout << "False" << endl;
	return false;
}

int main() {
	LinkedList list1;
	
	list1.append(1);
	list1.append(2);
	list1.append(3);
	list1.append(4);
	list1.append(5);
	list1.append(6);

	list1.search(4); //True
	list1.search(10); //False


}
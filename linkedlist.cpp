#include <iostream>
using namespace std;

// Declare Node
struct Node {
	int data;
	Node* next;
};

// Head Node
struct Node* head = NULL;

// Insert Node at start
void insertNode(int n) {
    Node* newNode = new Node;
	newNode->data = n;
	newNode->next = head;
	head = newNode;
}

void display() {
	if (head == NULL) {
		cout << "List is empty" << endl;
		return;
	}
	Node* temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

// Delete node
void deleteItem() {
	if (head == NULL) {
		cout << "List is empty" << endl;
		return;
	}
	Node* temp = head;
	cout << head->data << " is removed" << endl;
	head = head->next;
	delete temp;   // ¾ø¾îµµ µÊ
}

void main() {
	display();
	insertNode(10);
	insertNode(20);
	insertNode(22);
	insertNode(44);
	insertNode(52);
	
	display();
	
	deleteItem();
	deleteItem();
	deleteItem();

	display();

	system("pause");
}




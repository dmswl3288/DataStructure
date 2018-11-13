#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

class Queue {
public:
	Node* front;
    Node* rear;
	// ������ �ʱ�ȭ
	Queue() {
		front = rear = NULL;
	}

	void insert(int n);
	void deleteItem();
	void display();
	// �Ҹ���
	~Queue();
};

void Queue::insert(int n) {
	// �ӽ� ��� ����
	Node* temp = new Node;
	if (temp == NULL) {
		cout << "Overflow" << endl;
		return;
	}
	// ���ο� ����Ÿ �߰�
	temp->data = n;
	temp->next = NULL;

	// ù��° ����� ���
	if (front == NULL) {
		front = rear = temp;
	}
	else {
		rear->next = temp;
		rear = temp;
	}
	cout << n << " has been inserted successfully." << endl;
}

void Queue::display() {
	if (front == NULL) {
		cout << "Underflow and Nothing" << endl;
		return;
	}
	Node* temp = front;
	// front �������� �����ϴ� data�� ��� ���
	while (temp) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

void Queue::deleteItem() {
	if (front == NULL) {
		cout << "Underflow" << endl;
		return;
	}

	cout << front->data << " is being deleted " << endl;
	// ������ ����� ���
	if (front == rear) {
		front = rear = NULL;
	}
	else {
		front = front->next;
	}
}

Queue::~Queue() {
	// front���� NULL�� �ɶ����� ����
	while (front != NULL) {
		Node* temp = front;
		front = front->next;
		delete temp;
	}
	rear = NULL;
}

void main() {
	Queue q;
	q.display();

	q.insert(10);
	q.insert(24);
	q.insert(32);
	q.insert(68);

	q.display();

	q.deleteItem();
	q.deleteItem();

	q.display();

	q.~Queue();

	q.display();

	system("pause");
}
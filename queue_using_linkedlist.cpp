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
	// 생성자 초기화
	Queue() {
		front = rear = NULL;
	}

	void insert(int n);
	void deleteItem();
	void display();
	// 소멸자
	~Queue();
};

void Queue::insert(int n) {
	// 임시 노드 생성
	Node* temp = new Node;
	if (temp == NULL) {
		cout << "Overflow" << endl;
		return;
	}
	// 새로운 데이타 추가
	temp->data = n;
	temp->next = NULL;

	// 첫번째 노드인 경우
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
	// front 에서부터 존재하는 data를 모두 출력
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
	// 마지막 노드인 경우
	if (front == rear) {
		front = rear = NULL;
	}
	else {
		front = front->next;
	}
}

Queue::~Queue() {
	// front값이 NULL이 될때까지 제거
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
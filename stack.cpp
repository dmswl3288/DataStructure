#include <iostream>
#include <string.h>
#include <string>
using namespace std;

class stack
{
   private:
	   int arr[10];
	   int top;

   public:
	   stack();
	   void push(int data);
	   int pop();
	   void print();
};

stack::stack() {
	top = -1;
}

void stack::push(int data) {

	if (top == 9)
	{
		cout << "Overflow!" << endl;
	}
	arr[++top] = data;
}

int stack::pop()
{
	if (top == -1) {
		cout << "Underflow!" << endl;
		return 0;
	}
	return arr[top--];
}

void stack::print() {

	for (int i = 0; i <= top; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

/*
    If you enter "end", this program ends. 
    push 10
	push 2
	push 3
	pop
	pop
	print
	>> 10
*/
void main() {

	stack st;
	int k;
	string type;
	
	while (1) {

		cin >> type;
		if (type.compare("end") == 0) {
			cout << "Exit!" << endl;
			break;
		}

		if (type.compare("push") == 0) {
			cin >> k;
			st.push(k);
		}
		else if (type.compare("pop") == 0) {
			st.pop();
		}
		else if (type.compare("print") == 0) {
			st.print();
		}
	}

	system("pause");
}
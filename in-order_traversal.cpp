#include <iostream>
#include <stack>
using namespace std;

/*
a. Traverse the left subtree (inorder(root->left))
b. visit the root
c. Traverse the right subtree (inorder(root->right))
*/

struct Node {
	int info;
	Node* left;
	Node* right;
};

// Method to create a newNode if a tree does not exist
Node* newNode(int n) {
	Node* ptr = new Node;
	ptr->info = n;
	ptr->left = ptr->right = NULL;
	return ptr;
}

Node* insert(Node* node, int info) {
	// node가 빈경우 새로운 노드 추가
	if (node == NULL) {
		return newNode(info);
	}
	// 새로 추가할 info가 현재 노드의 info보다 작은 경우
	if (info < node->info) {
		// recursion
		node->left = insert(node->left, info);
	}
	// 새로 추가할 info가 현재 노드의 info보다 큰 경우
	else {
		node->right = insert(node->right, info);
	}
	return node;
}

// 중위순회
void inorder(Node* root) {
	stack<Node*> stack;
	Node* curr = root;

	while (!stack.empty() || curr != NULL) {
		// 현재 노드가 NULL이 아닌 경우 stack에 노드를 추가
		if (curr != NULL) {
			stack.push(curr);
			curr = curr->left;
		}
		// 현재 노드가 NULL이거나 빈 경우 stack에서 제거
		else {
			curr = stack.top();
			stack.pop();
			cout << curr->info << " ";
			curr = curr->right;
		}
	}
}
void main() {

	Node* root = newNode(60);

	insert(root, 50);
	insert(root, 70);
	insert(root, 40);
	insert(root, 30);
	insert(root, 80);
	insert(root, 75);
	insert(root, 65);
	insert(root, 45);
	insert(root, 55);
	insert(root, 90);
	insert(root, 67);

	cout << "Inorder traversal : ";

	inorder(root);

	cout << endl;

	system("pause");
}




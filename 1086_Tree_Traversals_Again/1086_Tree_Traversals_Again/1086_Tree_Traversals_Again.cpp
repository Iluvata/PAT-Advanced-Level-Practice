// 1086_Tree_Traversals_Again.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Node {
	int n;
	Node* left;
	Node* right;
};

void getTree(Node** root, vector<int> preorder, vector<int> inorder) {
	*root = new Node;
	int n = preorder[0];
	(*root)->n = n;
	(*root)->left = (*root)->right = nullptr;
	int pos = find(inorder.begin(), inorder.end(), n) - inorder.begin();
	if (pos > 0) {
		vector<int> lpre(preorder.begin() + 1, preorder.begin() + pos + 1);
		vector<int> lin(inorder.begin(), inorder.begin() + pos);
		getTree(&(*root)->left, lpre, lin);
	}
	if (pos + 1 < inorder.size()) {
		vector<int> rpre(preorder.begin() + pos + 1, preorder.end());
		vector<int> rin(inorder.begin() + pos + 1, inorder.end());
		getTree(&(*root)->right, rpre, rin);
	}
}

void postorderTrav(Node* root, vector<int> &postorder) {
	if (root == nullptr) {
		return;
	}
	postorderTrav(root->left, postorder);
	postorderTrav(root->right, postorder);
	postorder.push_back(root->n);
}

int main()
{
	int n;
	cin >> n;
	vector<int> preorder;
	vector<int> inorder;
	string command;
	stack<int> order;
	for (int i = 0; i < n * 2; ++i) {
		cin >> command;
		if (command == "Pop") {
			inorder.push_back(order.top());
			order.pop();
		}
		else {
			int num;
			cin >> num;
			preorder.push_back(num);
			order.push(num);
		}
	}
	Node *root = nullptr;
	getTree(&root, preorder, inorder);
	vector<int> postorder;
	postorderTrav(root, postorder);
	cout << postorder[0];
	for (int i = 1; i < n; ++i) {
		cout << " " << postorder[i];
	}
}

// 1119_Pre-_and_Post-order_Traversals.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
	int key;
	Node* left;
	Node* right;
};

vector<int> inorder;

bool createTree(Node** root, vector<int> preorder, vector<int> postorder) {
	*root = new Node;
	(*root)->key = preorder[0];
	(*root)->left = (*root)->right = nullptr;
	preorder.erase(preorder.begin());
	if (preorder.empty()) {
		return true;
	}
	postorder.pop_back();
	auto left = find(postorder.begin(), postorder.end(), preorder[0]);
	if (left + 1 == postorder.end()) {
		createTree(&((*root)->left), preorder, postorder);
		return false;
	}
	else {
		int dist = distance(postorder.begin(), left);
		vector<int> lpre(preorder.begin(), preorder.begin() + dist + 1);
		vector<int> lpost(postorder.begin(), postorder.begin() + dist + 1);
		vector<int> rpre(preorder.begin() + dist + 1, preorder.end());
		vector<int> rpost(postorder.begin() + dist + 1, postorder.end());
		bool isunique = createTree(&((*root)->left), lpre, lpost);
		isunique = isunique && createTree(&((*root)->right), rpre, rpost);
		return isunique;
	}
}

void inorder_trav(Node* root) {
	if (root->left) {
		inorder_trav(root->left);
	}
	inorder.push_back(root->key);
	if (root->right) {
		inorder_trav(root->right);
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> preorder(n);
	vector<int> postorder(n);
	for (int i = 0; i < n; ++i) {
		cin >> preorder[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> postorder[i];
	}
	Node* root = nullptr;
	bool isunique = createTree(&root, preorder, postorder);
	inorder_trav(root);
	if (isunique) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	cout << inorder[0];
	for (int i = 1; i < n; ++i) {
		cout << " " << inorder[i];
	}
	cout << endl;
}

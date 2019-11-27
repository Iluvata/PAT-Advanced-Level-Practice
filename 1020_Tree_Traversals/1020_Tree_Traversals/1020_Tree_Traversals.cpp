// 1020_Tree_Traversals.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
	int x;
	Node* left;
	Node* right;
};

void get_tree(vector<int> postorder, vector<int> inorder, Node* t) {
	int len = postorder.size();
	if (len == 1) {
		t->left = t->right = nullptr;
		t->x = inorder[0];
		return;
	}

	int root = postorder[len - 1];
	t->x = root;
	t->left = nullptr;
	t->right = nullptr;

	int i;
	for (i = 0; i < len; ++i) {
		if (inorder[i] == root) {
			break;
		}
	}
	if (i != 0) {
		vector<int> leftpost(postorder.begin(), postorder.begin() + i);
		vector<int> leftin(inorder.begin(), inorder.begin() + i);
		t->left = new Node;
		get_tree(leftpost, leftin, t->left);
	}
	if (i != len - 1) {
		vector<int> rightpost(postorder.begin() + i, postorder.begin() + len - 1);
		vector<int> rightin(inorder.begin() + i + 1, inorder.end());
		t->right = new Node;
		get_tree(rightpost, rightin, t->right);
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> postorder(n);
	vector<int> inorder(n);
	for (int i = 0; i < n; ++i) {
		cin >> postorder[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> inorder[i];
	}
	Node *tree = new Node;
	get_tree(postorder, inorder, tree);

	queue<Node*> layer;
	vector<int> layer_order;
	layer_order.push_back(tree->x);
	if (tree->left || tree->right) {
		layer.push(tree);
	}
	Node *temp;
	while (!layer.empty()) {
		if (layer.front()->left) {
			temp = layer.front()->left;
			layer_order.push_back(temp->x);
			if (temp->left || temp->right)
				layer.push(temp);
		}
		if (layer.front()->right) {
			temp = layer.front()->right;
			layer_order.push_back(temp->x);
			if (temp->left || temp->right)
				layer.push(temp);
		}
		layer.pop();
	}
	for (int i = 0; i < n - 1; ++i) {
		cout << layer_order[i] << " ";
	}
	cout << layer_order[n - 1];
}

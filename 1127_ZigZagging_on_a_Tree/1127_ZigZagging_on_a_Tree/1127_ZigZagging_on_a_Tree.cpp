// 1127_ZigZagging_on_a_Tree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

struct Node {
	int key;
	Node* left;
	Node* right;
};

void createTree(Node** root, vector<int> inorder, vector<int> postorder) {
	*root = new Node;
	int key = postorder[postorder.size() - 1];
	(*root)->key = key;
	(*root)->left = (*root)->right = nullptr;
	postorder.erase(postorder.end() - 1);
	int dist = distance(inorder.begin(), find(inorder.begin(), inorder.end(), key));
	if (dist > 0) {
		vector<int> lin(inorder.begin(), inorder.begin() + dist);
		vector<int> lpost(postorder.begin(), postorder.begin() + dist);
		createTree(&((*root)->left), lin, lpost);
	}
	if (dist + 1 < inorder.size()) {
		vector<int> rin(inorder.begin() + dist + 1, inorder.end());
		vector<int> rpost(postorder.begin() + dist, postorder.end());
		createTree(&((*root)->right), rin, rpost);
	}
}

void zigzag(Node* root, vector<int> &trav) {
	queue<Node*> oddlevel;
	queue<Node*> levelorder;
	stack<Node*> evenlevel;
	evenlevel.push(root);
	levelorder.push(root);
	bool isodd = false;
	while (!oddlevel.empty() || !evenlevel.empty()) {
		Node* now;
		if (isodd) {
			now = oddlevel.front();
			oddlevel.pop();
			trav.push_back(now->key);
			if (now->left) {
				evenlevel.push(now->left);
				levelorder.push(now->left);
			}
			if (now->right) {
				evenlevel.push(now->right);
				levelorder.push(now->right);
			}
		}
		else {
			now = evenlevel.top();
			Node* rev = levelorder.front();
			levelorder.pop();
			evenlevel.pop();
			trav.push_back(now->key);
			if (rev->left) {
				oddlevel.push(rev->left);
			}
			if (rev->right) {
				oddlevel.push(rev->right);
			}
		}
		if (oddlevel.empty()) {
			isodd = false;
		}
		if (evenlevel.empty()) {
			isodd = true;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> inorder(n);
	vector<int> postorder(n);
	for (int i = 0; i < n; ++i) {
		cin >> inorder[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> postorder[i];
	}
	Node* root = nullptr;
	createTree(&root, inorder, postorder);
	vector<int> zigzag_trav;
	zigzag(root, zigzag_trav);
	cout << zigzag_trav[0];
	for (int i = 1; i < n; ++i) {
		cout << " " << zigzag_trav[i];
	}
}

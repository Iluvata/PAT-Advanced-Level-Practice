// 1123_Is_It_a_Complete_AVL_Tree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct Node {
	int key;
	int height;
	Node* left;
	Node* right;
};

int getheight(Node* tree) {
	if (tree == nullptr) {
		return 0;
	}
	return tree->height;
}

Node* LL_Rotate(Node* root) {
	Node* newroot = root->left;
	root->left = newroot->right;
	newroot->right = root;

	root->height = max(getheight(root->left), getheight(root->right)) + 1;
	newroot->height = max(getheight(root->left), getheight(root->right)) + 1;
	return newroot;
}

Node* RR_Rotate(Node* root) {
	Node* newroot = root->right;
	root->right = newroot->left;
	newroot->left = root;

	root->height = max(getheight(root->left), getheight(root->right)) + 1;
	newroot->height = max(getheight(root->left), getheight(root->right)) + 1;
	return newroot;
}

Node* LR_Rotate(Node* root) {
	root->left = RR_Rotate(root->left);
	return LL_Rotate(root);
}

Node* RL_Rotate(Node* root) {
	root->right = LL_Rotate(root->right);
	return RR_Rotate(root);
}

void insert_AVL(Node** root, int key) {
	if (*root == nullptr) {
		Node* newnode = new Node;
		newnode->key = key;
		newnode->height = 0;
		newnode->left = newnode->right = nullptr;
		*root = newnode;
	}
	else if (key < (*root)->key) {
		insert_AVL(&((*root)->left), key);
		if (getheight((*root)->left) - getheight((*root)->right) == 2) {
			if (key < (*root)->left->key) {
				*root = LL_Rotate(*root);
			}
			else {
				*root = LR_Rotate(*root);
			}
		}
	}
	else {
		insert_AVL(&((*root)->right), key);
		if (getheight((*root)->right) - getheight((*root)->left) == 2) {
			if (key > (*root)->right->key) {
				*root = RR_Rotate(*root);
			}
			else {
				*root = RL_Rotate(*root);
			}
		}
	}
	if (abs(getheight((*root)->left) - getheight((*root)->right)) > 1) {
		cout << "ERROR! inserting " << key << " to " << (*root)->key << endl;
	}
	(*root)->height = max(getheight((*root)->left), getheight((*root)->right)) + 1;
}

void level_trav(Node* tree, vector<int> &level_order) {
	queue<Node*> tmp;
	tmp.push(tree);
	while (!tmp.empty()) {
		Node* now = tmp.front();
		tmp.pop();
		level_order.push_back(now->key);
		if (now->left) {
			tmp.push(now->left);
		}
		if (now->right) {
			tmp.push(now->right);
		}
	}
}

int main()
{
	int n;
	cin >> n;
	Node* tree = nullptr;
	int key;
	for (int i = 0; i < n; ++i) {
		cin >> key;
		insert_AVL(&tree, key);
	}
	vector<int> level_order;
	level_trav(tree, level_order);
	cout << level_order[0];
	for (int i = 1; i < n; ++i) {
		cout << " " << level_order[i];
	}
	bool iscomplete = true;
	for (int i = 0; i < n; ++i) {
		if (i * 2 + 1 < n) {
			if (level_order[i * 2 + 1] > level_order[i]) {
				iscomplete = false;
				break;
			}
		}
		if (i * 2 + 2 < n) {
			if (level_order[i * 2 + 2] < level_order[i]) {
				iscomplete = false;
				break;
			}
		}
	}
	cout << endl;
	if (iscomplete) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}

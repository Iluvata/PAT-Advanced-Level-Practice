// 1115_Counting_Nodes_in_a_BST.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

struct Node {
	int key;
	Node* left;
	Node* right;
	int level;
};

vector<Node> nodes;

void insert_BST(Node** root, int k) {
	Node** tmp = root;
	int level = 0;
	while (*tmp != nullptr) {
		if (k <= (*tmp)->key) {
			tmp = &((*tmp)->left);
		}
		else {
			tmp = &((*tmp)->right);
		}
		level++;
	}
	*tmp = new Node;
	(*tmp)->key = k;
	(*tmp)->left = (*tmp)->right = nullptr;
	(*tmp)->level = level;
	nodes.push_back(**tmp);
}

int main()
{
	int n;
	cin >> n;
	Node* root = nullptr;
	int k;
	for (int i = 0; i < n; ++i) {
		cin >> k;
		insert_BST(&root, k);
	}
	int deepest = 0;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (nodes[i].level > deepest) {
			deepest = nodes[i].level;
			cnt = 1;
		}
		else if (nodes[i].level == deepest) {
			cnt++;
		}
	}
	deepest--;
	int cnt2 = 0;
	for (int i = 0; i < n; ++i) {
		if (nodes[i].level == deepest) {
			cnt2++;
		}
	}
	cout << cnt << " + " << cnt2 << " = " << cnt + cnt2;
}

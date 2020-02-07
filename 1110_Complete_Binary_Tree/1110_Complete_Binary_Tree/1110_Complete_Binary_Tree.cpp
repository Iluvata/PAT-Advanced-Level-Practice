// 1110_Complete_Binary_Tree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct Node {
	int left;
	int right;
};

int main()
{
	int n;
	cin >> n;
	vector<int> father(n, -1);
	Node leaf;
	leaf.left = leaf.right = -1;
	vector<Node> tree(n, leaf);
	string s;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		if (s[0] != '-') {
			father[stoi(s)] = i;
			tree[i].left = stoi(s);
		}
		cin >> s;
		if (s[0] != '-') {
			father[stoi(s)] = i;
			tree[i].right = stoi(s);
		}
	}
	int root;
	for (int i = 0; i < n; ++i) {
		if (father[i] == -1) {
			root = i;
			break;
		}
	}
	queue<int> levelorder;
	levelorder.push(root);
	vector<int> heap(n);
	for (int i = 0; i < n; ++i) {
		int id = levelorder.front();
		levelorder.pop();
		heap[i] = id;
		if (tree[id].left != -1) {
			levelorder.push(tree[id].left);
		}
		if (tree[id].right != -1) {
			levelorder.push(tree[id].right);
		}
	}
	bool iscomplete = true;
	for (int i = 0; i < n; ++i) {
		if (i * 2 + 1 < n) {
			if (heap[i * 2 + 1] != tree[heap[i]].left) {
				iscomplete = false;
				break;
			}
		}
		if (i * 2 + 2 < n) {
			if (heap[i * 2 + 2] != tree[heap[i]].right) {
				iscomplete = false;
				break;
			}
		}
	}
	if (iscomplete) {
		cout << "YES " << heap[n - 1];
	}
	else {
		cout << "NO " << root;
	}
}

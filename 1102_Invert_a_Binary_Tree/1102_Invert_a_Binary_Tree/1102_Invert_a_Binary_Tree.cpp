// 1102_Invert_a_Binary_Tree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct Node{
	int left;
	int right;
};

vector<int> layer(10, 0);

vector<int> levelorder(vector<Node> &tree, int root) {
	vector<int> level;
	queue<int> tmp;
	tmp.push(root);
	while (!tmp.empty()) {
		int p = tmp.front();
		tmp.pop();
		level.push_back(p);
		if (tree[p].left != -1) {
			tmp.push(tree[p].left);
		}
		if (tree[p].right != -1) {
			tmp.push(tree[p].right);
		}
	}
	return level;
}

void inorder(vector<Node> &tree, vector<int> &inseq, int now) {
	if (tree[now].left != -1) {
		inorder(tree, inseq, tree[now].left);
	}
	inseq.push_back(now);
	if (tree[now].right != -1) {
		inorder(tree, inseq, tree[now].right);
	}
}

int getlayer(vector<Node> &tree, int x) {
	if (layer[x] > 0) {
		return layer[x];
	}
	if (tree[x].left != -1) {
		if (layer[tree[x].left] > 0) {
			layer[x] = layer[tree[x].left] + 1;
		}
		else {
			getlayer(tree, tree[x].left);
		}
	}
	if (tree[x].right != -1) {
		if (layer[tree[x].right] > 0) {
			if (layer[x] < layer[tree[x].right] + 1) {
				layer[x] = layer[tree[x].right] + 1;
			}
		}
		else {
			getlayer(tree, tree[x].right);
		}
	}

	return layer[x];
}

int main()
{
	int n;
	cin >> n;
	vector<Node> tree(n);
	string keyr, keyl;
	for (int i = 0; i < n; ++i) {
		cin >> keyr >> keyl;
		if (isdigit(keyr[0])) {
			tree[i].right = stoi(keyr);
			if (layer[stoi(keyr)] > 0) {
				layer[i] = layer[stoi(keyr)] + 1;
			}
		}
		else {
			tree[i].right = -1;
		}
		if (isdigit(keyl[0])) {
			tree[i].left = stoi(keyl);
			if (layer[stoi(keyl)] > 0) {
				if (layer[i] < layer[stoi(keyl)] + 1) {
					layer[i] = layer[stoi(keyl)] + 1;
				}
			}
		}
		else {
			tree[i].left = -1;
		}
		if (keyr == "-" && keyl == "-") {
			layer[i] = 1;
		}
	}
	int root = 0;
	int maxlayer = 0;
	for (int i = 0; i < n; ++i) {
		int l = getlayer(tree, i);
		if (l > maxlayer) {
			maxlayer = l;
			root = i;
		}
	}
	vector<int> level_order = levelorder(tree, root);
	vector<int> in_order;
	inorder(tree, in_order, root);
	cout << level_order[0];
	for (int i = 1; i < n; ++i) {
		cout << " " << level_order[i];
	}
	cout << endl;
	cout << in_order[0];
	for (int i = 1; i < n; ++i) {
		cout << " " << in_order[i];
	}
}

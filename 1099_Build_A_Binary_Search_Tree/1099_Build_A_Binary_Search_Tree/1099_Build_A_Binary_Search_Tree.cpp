// 1099_Build_A_Binary_Search_Tree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Node {
	int addr;
	int key;
	int left;
	int right;
};

vector<int> seq(100, -1);
int pot = 0;

void inorder(vector<Node> &tree, int &n, int startfrom) {
	if (tree[startfrom].left != -1) {
		inorder(tree, n, tree[startfrom].left);
	}
	tree[startfrom].key = seq[pot];
	pot++;
	if (tree[startfrom].right != -1) {
		inorder(tree, n, tree[startfrom].right);
	}
}

int main()
{
	int n;
	cin >> n;
	vector<Node> tree(n);
	for (int i = 0; i < n; ++i) {
		tree[i].addr = i;
		cin >> tree[i].left >> tree[i].right;
	}
	for (int i = 0; i < n; ++i) {
		cin >> seq[i];
	}
	sort(seq.begin(), seq.begin() + n);
	inorder(tree, n, 0);

	vector<int> layerorder;
	queue<Node> tmp;
	tmp.push(tree[0]);
	Node no;
	while (!tmp.empty()) {
		no = tmp.front();
		tmp.pop();
		layerorder.push_back(no.key);
		if (no.left != -1) {
			tmp.push(tree[no.left]);
		}
		if (no.right != -1) {
			tmp.push(tree[no.right]);
		}
	}
	cout << layerorder[0];
	for (int i = 1; i < n; ++i) {
		cout << " " << layerorder[i];
	}
}

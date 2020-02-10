// 1130_Infix_Expression.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
	string data;
	int left;
	int right;
};

bool isfirst = true;

void inorder(vector<Node> &tree, int now) {
	if (tree[now].left != -1 || tree[now].right != -1) {
		if (isfirst) {
			isfirst = false;
			if (tree[now].left != -1) {
				inorder(tree, tree[now].left);
			}
			cout << tree[now].data;
			if (tree[now].right != -1) {
				inorder(tree, tree[now].right);
			}
		}
		else {
			cout << "(";
			if (tree[now].left != -1) {
				inorder(tree, tree[now].left);
			}
			cout << tree[now].data;
			if (tree[now].right != -1) {
				inorder(tree, tree[now].right);
			}
			cout << ")";
		}
	}
	else {
		cout << tree[now].data;
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> father(n + 1, 0);
	vector<Node> tree(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> tree[i].data >> tree[i].left >> tree[i].right;
		if (tree[i].left != -1) {
			father[tree[i].left] = i;
		}
		if (tree[i].right != -1) {
			father[tree[i].right] = i;
		}
	}
	int root = 1;
	while (father[root] != 0) {
		root = father[root];
	}
	inorder(tree, root);
}

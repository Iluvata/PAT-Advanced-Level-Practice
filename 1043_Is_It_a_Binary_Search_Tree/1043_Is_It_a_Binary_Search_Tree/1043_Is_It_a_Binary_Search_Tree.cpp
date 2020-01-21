// 1043_Is_It_a_Binary_Search_Tree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Node {
	int x;
	Node* left;
	Node* right;
};

bool constructTree(vector<int> &pre, vector<int> &mid, Node **head, bool &is_mirror) {
	if (pre.empty()) {
		*head = nullptr;
		return true;
	}
	*head = new Node;
	(*head)->x = pre[0];
	int head_ind = -1;
	for (int i = 0; i < mid.size(); ++i) {
		if (mid[i] == (*head)->x) {
			head_ind = i;
			if(!is_mirror)
				break;
		}
	}
	if (head_ind == -1) {
		return false;
	}
	vector<int> p1;
	vector<int> p2;
	vector<int> m1;
	vector<int> m2;
	for (int i = 0; i < head_ind; ++i) {
		m1.push_back(mid[i]);
		p1.push_back(pre[i + 1]);
	}
	for (int i = head_ind + 1; i < mid.size(); ++i) {
		m2.push_back(mid[i]);
		p2.push_back(pre[i]);
	}
	if (!constructTree(p1, m1, &((*head)->left), is_mirror)) {
		return false;
	}
	if (!constructTree(p2, m2, &((*head)->right), is_mirror)) {
		return false;
	}
	return true;
}

void post_trav(Node* head, vector<int> &order) {
	if (head == nullptr) {
		return;
	}
	post_trav(head->left, order);
	post_trav(head->right, order);
	order.push_back(head->x);
}

int main()
{
	int n;
	cin >> n;
	vector<int> pre(n);
	vector<int> mid(n);
	int min = INT_MAX;
	int max = INT_MIN;
	for (int i = 0; i < n; ++i) {
		cin >> pre[i];
		if (pre[i] > max) {
			max = pre[i];
		}
		if (pre[i] < min) {
			min = pre[i];
		}
	}
	mid = pre;
	sort(mid.begin(), mid.end());
	Node* tree = nullptr;
	bool is_mirror = (pre[n - 1] < pre[0]);
	if (is_mirror) {
		reverse(mid.begin(), mid.end());
	}
	if (constructTree(pre, mid, &tree, is_mirror)) {
		cout << "YES" << endl;
		vector<int> order;
		post_trav(tree, order);
		for (int i = 0; i < n - 1; ++i) {
			cout << order[i] << " ";
		}
		cout << order[n - 1];
	}
	else {
		cout << "NO";
	}
}

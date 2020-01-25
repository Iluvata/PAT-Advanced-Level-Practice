// 1053_Path_of_Equal_Weight.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
	int weight;
	vector<int> children;
};

vector<vector<int>> paths;
int s;

bool backtrace(int head, vector<Node> &nodes, vector<int> path, int sum) {
	sum += nodes[head].weight;
	if (sum > s) {
		return false;
	}
	path.push_back(nodes[head].weight);
	if (nodes[head].children.empty()) {         // leaf node
		if (sum == s) {
			paths.push_back(path);
		}
		return true;
	}
	for (int i = 0; i < nodes[head].children.size(); ++i) {
		backtrace(nodes[head].children[i], nodes, path, sum);
	}
	return true;
}

bool cmp(vector<int> &p1, vector<int> &p2) {
	for (int i = 0; i < p1.size() && i < p2.size(); ++i) {
		if (p1[i] != p2[i]) {
			return p1[i] > p2[i];
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m >> s;
	vector<Node> nodes(n);
	for (int i = 0; i < n; ++i) {
		cin >> nodes[i].weight;
	}
	for (int i = 0; i < m; ++i) {
		int id, k, child;
		cin >> id >> k;
		for (int j = 0; j < k; ++j) {
			cin >> child;
			nodes[id].children.push_back(child);
		}
	}
	vector<int> path;
	backtrace(0, nodes, path, 0);
	sort(paths.begin(), paths.end(), cmp);
	for (int i = 0; i < paths.size(); ++i) {
		cout << paths[i][0];
		for (int j = 1; j < paths[i].size(); ++j) {
			cout << " " << paths[i][j];
		}
		cout << endl;
	}
}

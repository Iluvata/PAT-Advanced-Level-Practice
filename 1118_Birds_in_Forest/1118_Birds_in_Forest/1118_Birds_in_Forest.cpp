// 1118_Birds_in_Forest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> father(10001);

int findfather(int x) {
	int tmp = x;
	while (father[tmp] != tmp) {
		tmp = father[tmp];
	}
	int root = tmp;
	while (father[x] != root) {
		tmp = father[x];
		father[x] = root;
		x = tmp;
	}
	return root;
}

int main()
{
	for (int i = 1; i <= 10000; ++i) {
		father[i] = i;
	}
	int n;
	cin >> n;
	int k, num = 0;
	vector<int> roots;
	for (int i = 0; i < n; ++i) {
		cin >> k;
		if (k > 0) {
			int id;
			cin >> id;
			if (id > num) {
				num = id;
			}
			int root = findfather(id);
			roots.push_back(root);
			int f;
			for (int j = 1; j < k; ++j) {
				cin >> id;
				if (id > num) {
					num = id;
				}
				f = findfather(id);
				father[f] = root;
			}
		}
	}
	set<int> trees;
	for (int i = 0; i < roots.size(); ++i) {
		trees.insert(findfather(roots[i]));
	}
	cout << trees.size() << " " << num << endl;
	int q;
	cin >> q;
	int n1, n2;
	for (int i = 0; i < q; ++i) {
		cin >> n1 >> n2;
		if (findfather(n1) == findfather(n2)) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
}

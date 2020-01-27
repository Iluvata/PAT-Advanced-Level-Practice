// 1056_Mice_and_Rice.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int np, ng;
	cin >> np >> ng;
	vector<int> w(np);
	vector<int> order(np);
	for (int i = 0; i < np; ++i) {
		cin >> w[i];
	}
	for (int i = 0; i < np; ++i) {
		cin >> order[i];
	}
	vector<int> rank(np);
	vector<int> upgrade;
	int r = np;
	while (r > 1) {
		int left = r % ng;
		r = r / ng;
		if (left) {
			r++;
		}
		int i = 0;
		while (i < order.size()) {
			int count = 0;
			int maxw = -1;
			int maxid;
			while (i < order.size() && count < ng) {
				rank[order[i]] = r + 1;
				if (w[order[i]] > maxw) {
					maxw = w[order[i]];
					maxid = order[i];
				}
				count++;
				i++;
			}
			upgrade.push_back(maxid);
		}
		order = upgrade;
		upgrade.clear();
	}
	rank[order[0]] = 1;
	cout << rank[0];
	for (int i = 1; i < np; ++i) {
		cout << " " << rank[i];
	}
}

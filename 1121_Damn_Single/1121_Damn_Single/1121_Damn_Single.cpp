// 1121_Damn_Single.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	map<int, int> couples;
	for (int i = 0; i < n; ++i) {
		int c1, c2;
		cin >> c1 >> c2;
		couples[c1] = c2;
		couples[c2] = c1;
	}
	int m;
	cin >> m;
	
	map<int, bool> hascome;
	vector<int> single;
	vector<int> ids;
	int id;
	for (int i = 0; i < m; ++i) {
		cin >> id;
		ids.push_back(id);
		hascome[id] = true;
	}
	for (int i = 0; i < m; ++i) {
		if (couples.count(ids[i]) == 0 || !hascome[couples[ids[i]]]) {
			single.push_back(ids[i]);
		}
	}
	sort(single.begin(), single.end());
	cout << single.size() << endl;
	if (single.size() > 0) {
		printf("%05d", single[0]);
		for (int i = 1; i < single.size(); ++i) {
			printf(" %05d", single[i]);
		}
	}
}

// 1125_Chain_the_Ropes.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(double &d1, double &d2) {
	return d1 > d2;
}

int main()
{
	int n;
	cin >> n;
	vector<double> ropes(n);
	for (int i = 0; i < n; ++i) {
		cin >> ropes[i];
	}
	sort(ropes.begin(), ropes.end());
	int len;
	while (ropes.size() > 1) {
		len = (ropes[0] + ropes[1]) / 2;
		ropes.erase(ropes.begin());
		ropes.erase(ropes.begin());
		bool flag = false;
		for (auto i = ropes.begin(); i < ropes.end(); ++i) {
			if (*i >= len) {
				ropes.insert(i, len);
				flag = true;
				break;
			}
		}
		if (!flag) {
			ropes.insert(ropes.end(), len);
		}
	}
	cout << int(ropes[0]);
}

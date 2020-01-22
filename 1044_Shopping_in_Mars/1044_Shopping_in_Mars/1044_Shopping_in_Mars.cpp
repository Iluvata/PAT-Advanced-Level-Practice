// 1044_Shopping_in_Mars.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <climits>
#include <string>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> d(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> d[i];
	}
	vector<string> pay;
	int l = 1, r = 1;
	int count = 0;
	int maxcount = INT_MAX;
	while (r <= n || count >= m) {
		while (r <= n && count < m) {
			count += d[r];
			r++;
		}
		if (count < maxcount) {
			maxcount = count;
			pay.clear();
			pay.push_back(to_string(l) + "-" + to_string(r - 1));
		}
		else if (count == maxcount) {
			pay.push_back(to_string(l) + "-" + to_string(r - 1));
		}
		count -= d[l];
		l++;
	}
	for (int i = 0; i < pay.size(); ++i) {
		cout << pay[i] << endl;
	}
}

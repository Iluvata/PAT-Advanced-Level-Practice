// 1101_Quick_Sort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> origin(n);
	for (int i = 0; i < n; ++i) {
		cin >> origin[i];
	}
	vector<int> sorted = origin;
	sort(sorted.begin(), sorted.end());
	int max_till_now = 0;
	vector<int> pivots;
	for (int i = 0; i < n; ++i) {
		if (origin[i] > max_till_now) {
			if (origin[i] == sorted[i]) {
				pivots.push_back(origin[i]);
			}
			max_till_now = origin[i];
		}
	}
	
	cout << pivots.size() << endl;
	if (!pivots.empty()) {
		cout << pivots[0];
		for (int i = 1; i < pivots.size(); ++i) {
			cout << " " << pivots[i];
		}
	}
	cout << endl;
}

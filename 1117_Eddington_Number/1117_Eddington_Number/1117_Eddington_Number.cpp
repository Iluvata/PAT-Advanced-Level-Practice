// 1117_Eddington_Number.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> miles(n);
	for (int i = 0; i < n; ++i) {
		cin >> miles[i];
	}
	sort(miles.begin(), miles.end());
	reverse(miles.begin(), miles.end());
	int e = 0;
	for (int i = 0; i < n; ++i) {
		if (miles[i] > i + 1) {
			e = i + 1;
		}
		else {
			break;
		}
	}
	cout << e;
}

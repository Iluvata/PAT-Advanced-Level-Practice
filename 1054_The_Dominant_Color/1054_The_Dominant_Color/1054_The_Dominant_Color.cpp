// 1054_The_Dominant_Color.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <map>

using namespace std;

int main()
{
	int m, n;
	cin >> m >> n;
	map<int, int> colors;
	int c;
	for (int i = 0; i < m * n; ++i) {
		cin >> c;
		colors[c]++;
	}
	int maxnum = 0;
	int maxc = 0;
	for (auto i = colors.begin(); i != colors.end(); ++i) {
		if (i->second > maxnum) {
			maxc = i->first;
			maxnum = i->second;
		}
	}
	cout << maxc;
}

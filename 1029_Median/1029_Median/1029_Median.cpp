// 1029_Median.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"

#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);//解除cin与stdin同步占用的时间

	int n1, n2;

	cin >> n1;
	vector<long long> s1(n1 + 1, LLONG_MAX);
	for (int i = 0; i < n1; ++i) {
		cin >> s1[i];
	}
	cin >> n2;
	vector<long long> s2(n2 + 1, LLONG_MAX);
	for (int i = 0; i < n2; ++i) {
		cin >> s2[i];
	}
	int c1 = 0, c2 = 0;
	int m = (n1 + n2 + 1) / 2;
	for (int i = 1; i < m; ++i) {
		if (s1[c1] < s2[c2]) {
			c1++;
		}
		else {
			c2++;
		}
	}
	if (s1[c1] < s2[c2]) {
		cout << s1[c1];
	}
	else {
		cout << s2[c2];
	}
}

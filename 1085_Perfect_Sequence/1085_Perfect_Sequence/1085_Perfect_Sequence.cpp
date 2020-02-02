// 1085_Perfect_Sequence.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	long long p;
	cin >> n >> p;
	vector<long long> seq(n);
	for (int i = 0; i < n; ++i) {
		cin >> seq[i];
	}
	sort(seq.begin(), seq.end());
	int maxcnt = 1;
	for (int i = 0; i < n - 1; ++i) {
		int temp = upper_bound(seq.begin(), seq.end(), seq[i] * p) - seq.begin();
		if (temp - i > maxcnt) {
			maxcnt = temp - i;
		}
	}
	cout << maxcnt;
}

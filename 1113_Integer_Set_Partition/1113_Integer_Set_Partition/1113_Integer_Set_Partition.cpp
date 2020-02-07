// 1113_Integer_Set_Partition.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
	vector<long long> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int n1 = n / 2;
	long long s1 = 0, s2 = 0;
	for (int i = 0; i < n1; ++i) {
		s1 += v[i];
	}
	for (int i = n1; i < n; ++i) {
		s2 += v[i];
	}
	cout << n % n1 << " " << s2 - s1 << endl;
}

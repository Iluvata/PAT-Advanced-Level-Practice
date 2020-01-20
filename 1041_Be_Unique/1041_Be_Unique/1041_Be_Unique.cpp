// 1041_Be_Unique.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	map<int, int> m;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		m[v[i]] += 1;
	}
	bool flag = false;
	for (int i = 0; i < n; ++i) {
		if (m[v[i]] == 1) {
			flag = true;
			cout << v[i];
			break;
		}
	}
	if (!flag) {
		cout << "None";
	}
	return 0;
}

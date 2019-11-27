// 1019_General_Palindromic_Number.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, b;
	cin >> n >> b;
	vector<int> a;
	while (n > 0) {
		a.push_back(n%b);
		n /= b;
	}
	reverse(a.begin(), a.end());
	bool is_palindromic = true;
	int len = a.size();
	for (int i = 0; i < len / 2; ++i) {
		if (a[i] != a[len - i - 1]) {
			is_palindromic = false;
			break;
		}
	}
	if (is_palindromic)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	for (int i = 0; i < len - 1; ++i) {
		cout << a[i]<< " ";
	}
	cout << a[len - 1];
}

// 1024_Palindromic_Number.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string string_add(string a, string b) {
	string s;
	int c = 0;
	int r;
	for (int i = a.size() - 1; i >= 0; --i) {
		r = a[i] + b[i] - 96 + c;
		c = r / 10;
		r %= 10;
		s.push_back(r + 48);
	}
	if (c > 0) {
		s.push_back(c + 48);
	}
	reverse(s.begin(), s.end());
	return s;
}

int main()
{
	string n;
	int k;
	cin >> n >> k;
	int steps = 0;
	bool p = false;
	for (int i = 0; i < k; ++i) {
		string d = n;
		reverse(d.begin(), d.end());
		if (d == n) {
			cout << d << endl;
			cout << steps;
			p = true;
			break;
		}
		steps += 1;
		n = string_add(n, d);
	}
	if (!p) {
		cout << n << endl;
		cout << steps;
	}
	return 0;
}

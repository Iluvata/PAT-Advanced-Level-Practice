// 1023_Have_Fun_with_Numbers.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string s;
	cin >> s;
	string d;
	int c = 0;
	int r;
	for (int i = s.size() - 1; i >= 0; --i) {
		r = 2 * (s[i] - 48) + c;
		c = r / 10;
		r %= 10;
		d.push_back(r + 48);
	}
	if (c > 0) {
		d.push_back(c + 48);
	}
	reverse(d.begin(), d.end());
	string k = d;
	sort(s.begin(), s.end());
	sort(k.begin(), k.end());
	if (s == k) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	cout << d;
}

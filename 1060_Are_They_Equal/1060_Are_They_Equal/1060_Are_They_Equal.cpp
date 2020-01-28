// 1060_Are_They_Equal.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

int n;

void f(string &s, int &u) {
	u = 0;
	int len = s.length();
	while (u < len&&s[u] != '.') u++;
	if (u == len) {
		int t = u;
		if (s == "0") u = 0;
		for (int i = 0; i < n - t; i++) {
			s.push_back('0');
		}
	}
	else {
		int w = 0;
		while (w < len && (s[w] == '0' || s[w] == '.')) w++;
		if (w == len) w = u;
		s.erase(u, 1);
		while (s[0] == '0') s.erase(0, 1);
		len = s.length();
		for (int i = 0; i < n - len; i++) {
			s.push_back('0');
		}
		if (u < w) u = u - w + 1;
		else u = u - w;
	}
	s = "0." + s.substr(0, n);

}

int main()
{
	string s1, s2;
	cin >> n >> s1 >> s2;
	int u1 = 0, u2 = 0;
	f(s1, u1);
	f(s2, u2);
	if (u1 == u2 && s1 == s2) {
		cout << "YES " << s1 << "*10^" << u1;
	}
	else {
		cout << "NO " << s1 << "*10^" << u1 << " " << s2 << "*10^" << u2;
	}
}

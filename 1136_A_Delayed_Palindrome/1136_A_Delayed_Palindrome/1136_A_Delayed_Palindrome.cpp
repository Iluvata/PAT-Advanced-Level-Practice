// 1136_A_Delayed_Palindrome.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool ispalindrome(string a) {
	int alen = a.size();
	for (int i = 0; i <= alen / 2; ++i) {
		if (a[i] != a[alen - 1 - i]) {
			return false;
		}
	}
	return true;
}

string getsum(string a, string b) {
	int carry = 0;
	string c;
	for (int i = 0; i < a.size(); ++i) {
		int dig = int(a[i]) + int(b[i]) - 96 + carry;
		carry = dig / 10;
		dig %= 10;
		c += char(dig + 48);
	}
	c += char(carry + 48);
	reverse(c.begin(), c.end());
	int start = 0;
	while (c[start] == '0') {
		start++;
	}
	return c.substr(start);
}

int main()
{
	string c;
	cin >> c;
	string a, b;
	int cnt = 0;
	while (cnt < 10 && !ispalindrome(c)) {
		a = b = c;
		reverse(b.begin(), b.end());
		c = getsum(a, b);
		cout << a << " + " << b << " = " << c << endl;
		cnt++;
	}
	if (cnt < 10) {
		cout << c << " is a palindromic number." << endl;
	}
	else {
		cout << "Not found in 10 iterations." << endl;
	}
}

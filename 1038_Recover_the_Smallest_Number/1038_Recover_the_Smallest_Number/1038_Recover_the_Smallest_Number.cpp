// 1038_Recover_the_Smallest_Number.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct Dig {
	int num;
	string s;
};

bool cmp(Dig& d1, Dig& d2) {
	return d1.s < d2.s;
}

int main()
{
	vector<Dig> digits;
	int n;
	cin >> n;
	string s;
	Dig d;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		d.num = s.size();
		while (s.size() < 8) {
			s += s;
		}
		d.s = s.substr(0, 8);
		digits.push_back(d);
	}
	sort(digits.begin(), digits.end(), cmp);
	int i = 0;
	while (i < n && stoi(digits[i].s) == 0) {
		i++;
	}
	if (i == n) {
		cout << 0;
	}
	else {
		cout << stoi(digits[i].s.substr(0, digits[i].num));
		i++;
		while (i < n) {
			cout << digits[i].s.substr(0, digits[i].num);
			i++;
		}
	}

}

// 1084_Broken_Keyboard.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
	transform(s2.begin(), s2.end(), s2.begin(), ::toupper);
	while (s2.size() < s1.size()) {
		s2.push_back('.');
	}
	map<char, int> m;
	for (int i = 0, j = 0; i < s1.size(); ++i, ++j) {
		if (s1[i] != s2[j]) {
			j--;
			if (!m[s1[i]])
			{
				m[s1[i]]++;
				cout << s1[i];
			}
		}
	}
}

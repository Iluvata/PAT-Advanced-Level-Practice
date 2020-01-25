// 1050_String_Subtraction.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	string s1, s2;
	map<char, int> m;
	getline(cin, s1);
	getline(cin, s2);
	for (int i = 0; i < s2.size(); ++i) {
		m[s2[i]]++;
	}
	for (int i = 0; i < s1.size(); ++i) {
		if (m[s1[i]] == 0) {
			cout << s1[i];
		}
	}
}

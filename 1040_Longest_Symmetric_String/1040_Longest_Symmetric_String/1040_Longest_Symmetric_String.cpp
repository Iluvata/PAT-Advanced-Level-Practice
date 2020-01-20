// 1040_Longest_Symmetric_String.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	getline(cin, s);
	int maxcount = 0;
	int count;
	for (int i = 0; i < s.size(); ++i) {
		count = 0;
		while (i - count >= 0 && i + count < s.size() && s[i - count] == s[i + count]) {
			count++;
		}
		count = count * 2 - 1;
		if (maxcount < count) {
			maxcount = count;
		}
		count = 0;
		while (i - count - 1 >= 0 && i + count < s.size() && s[i - count - 1] == s[i + count]) {
			count++;
		}
		count *= 2;
		if (maxcount < count) {
			maxcount = count;
		}
	}
	cout << maxcount;
}

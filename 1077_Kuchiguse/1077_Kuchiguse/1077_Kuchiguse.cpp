// 1077_Kuchiguse.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	string suffix;
	getchar();
	getline(cin, suffix);
	reverse(suffix.begin(), suffix.end());
	string line;
	for (int i = 1; i < n; ++i) {
		getline(cin, line);
		reverse(line.begin(), line.end());
		int count = 0;
		while (count < suffix.size() && count < line.size() && suffix[count] == line[count]) {
			count++;
		}
		suffix = suffix.substr(0, count);
	}
	if (suffix.size() == 0) {
		cout << "nai";
	}
	else {
		reverse(suffix.begin(), suffix.end());
		cout << suffix;
	}
}

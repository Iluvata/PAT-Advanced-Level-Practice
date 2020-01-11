// 1027_Colors_in_Mars.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

int base13(int n) {
	if (n < 10)
		return n + 48;
	return n + 55;
}
int main()
{
	int rgb[3];
	cin >> rgb[0] >> rgb[1] >> rgb[2];
	string mars = "#";
	for (int i = 0; i < 3; ++i) {
		mars += base13(rgb[i] / 13);
		mars += base13(rgb[i] % 13);
	}
	cout << mars;
}

// 1069_The_Black_Hole_of_Numbers.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int n;
	scanf_s("%d", &n);
	char digit[5];
	do {
		sprintf_s(digit, "%04d", n);
		string s = digit;
		sort(s.begin(), s.end());
		int n1 = stoi(s);
		reverse(s.begin(), s.end());
		int n2 = stoi(s);
		n = n2 - n1;
		printf("%04d - %04d = %04d\n", n2, n1, n);
	} while (n != 0 && n != 6174);
}

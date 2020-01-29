// 1065_A+B_and_C.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	long long a, b, c;
	long long res;
	bool flag;
	for (int i = 1; i <= n; ++i) {
		cin >> a >> b >> c;
		res = a + b;
		if (a > 0 && b > 0 && res <= 0) {
			flag = true;
		}
		else if (a < 0 && b < 0 && res >= 0) {
			flag = false;
		}
		else {
			flag = res > c;
		}
		if (flag) {
			printf("Case #%d: true\n", i);
		}
		else {
			printf("Case #%d: false\n", i);
		}
	}
}

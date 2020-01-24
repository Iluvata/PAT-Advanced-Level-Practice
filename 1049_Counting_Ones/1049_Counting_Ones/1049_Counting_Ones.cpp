// 1049_Counting_Ones.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	int n, left = 0, right = 0, a = 1, now = 1, ans = 0;
	scanf("%d", &n);
	while (n / a) {
		left = n / (a * 10), now = n / a % 10, right = n % a;
		if (now == 0) ans += left * a;
		else if (now == 1) ans += left * a + right + 1;
		else ans += (left + 1) * a;
		a = a * 10;
	}
	printf("%d", ans);
}

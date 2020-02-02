// 1081_Rational_Sum.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <cmath>

using namespace std;

long long gcd(long long a, long long b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int main()
{
	int n;
	cin >> n;
	long long suma, sumb;
	suma = 0;
	sumb = 1;
	long long ai, bi;
	for (int i = 0; i < n; ++i) {
		scanf_s("%lld/%lld", &ai, &bi);
		long long g = gcd(sumb, bi);
		suma = suma * bi / g + ai * sumb / g;
		sumb = sumb * bi / g;
		g = gcd(suma, sumb);
		suma /= g;
		sumb /= g;
	}
	long long int_part = 0;
	int_part = suma / sumb;
	suma = suma % sumb;
	if (int_part != 0 && suma != 0) {
		cout << int_part << " " << suma << "/" << sumb;
	}
	else if (int_part != 0) {
		cout << int_part;
	}
	else if (suma != 0) {
		cout << suma << "/" << sumb;
	}
	else {
		cout << 0;
	}
}

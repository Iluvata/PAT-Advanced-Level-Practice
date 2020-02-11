// 1132_Cut_Integer.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <cmath>

using namespace std;

bool cut(int z) {
	int dig = 0;
	int tmp = z;
	while (tmp > 0) {
		tmp /= 10;
		dig++;
	}
	dig /= 2;
	dig = pow(10, dig);
	int l, r;
	l = z % dig;
	r = z / dig;
	if (l == 0) {
		return false;
	}
	if (z % (l * r)) {
		return false;
	}
	return true;
}

int main()
{
	int n;
	cin >> n;
	int z;
	for (int i = 0; i < n; ++i) {
		cin >> z;
		if (cut(z)) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
}

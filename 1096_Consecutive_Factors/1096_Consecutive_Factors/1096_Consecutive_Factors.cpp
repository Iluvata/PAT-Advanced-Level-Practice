// 1096_Consecutive_Factors.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int k = sqrt(n);
	int startfrom = 1;
	int maxcount = 0;
	for (int i = 2; i <= k; ++i) {
		int j = i;
		int factor = i;
		int count = 0;
		while (n % factor == 0 && factor <= n) {
			count++;
			j++;
			factor *= j;
		}
		if (count > maxcount) {
			maxcount = count;
			startfrom = i;
		}
	}
	if (maxcount == 0) {
		maxcount = 1;
		startfrom = n;
	}
	cout << maxcount << endl;
	cout << startfrom;
	for (int i = startfrom + 1; i < startfrom + maxcount; ++i) {
		cout << "*" << i;
	}
}

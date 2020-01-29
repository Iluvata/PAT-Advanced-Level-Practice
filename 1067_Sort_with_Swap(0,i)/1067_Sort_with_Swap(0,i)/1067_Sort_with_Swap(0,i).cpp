// 1067_Sort_with_Swap(0,i).cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	int n, t, cnt = 0, a[100010];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t;
		a[t] = i;
	}
	for (int i = 1; i < n; i++) {
		if (i != a[i]) {
			while (a[0] != 0) {
				swap(a[0], a[a[0]]);
				cnt++;
			}
			if (i != a[i]) {
				swap(a[0], a[i]);
				cnt++;
			}
		}
	}
	cout << cnt;
}

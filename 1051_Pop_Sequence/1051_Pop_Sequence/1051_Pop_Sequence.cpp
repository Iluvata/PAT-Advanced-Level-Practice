// 1051_Pop_Sequence.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int m, n, k;
	cin >> m >> n >> k;
	vector<int> popsec(n);
	int c;
	for (int i = 0; i < k; ++i) {
		int maxc = 0;
		int minc = 0;
		int count = 0;
		bool ispop = true;
		for (int j = 0; j < n; ++j) {
			cin >> popsec[j];
		}
		for (int j = 0; j < n; ++j) {
			c = popsec[j];
			if (c > maxc) {
				count = 1;
				maxc = minc = c;
			}
			else {
				if (c > minc) {
					ispop = false;
					break;
				}
				count++;
				if (count > m) {
					ispop = false;
					break;
				}
				minc = c;
			}
		}
		if (ispop) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}

// 1128_N_Queens_Puzzle.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

int main()
{
	int k, n;
	cin >> k;
	for (int i = 0; i < k; ++i) {
		cin >> n;
		vector<bool> row(n + 1, false);
		map<int, bool> diagsum;
		map<int, bool> diagdel;
		int p;
		bool flag = true;
		for (int j = 1; j <= n; ++j) {
			cin >> p;
			if (row[p] || diagsum[j + p] || diagdel[j - p])
				flag = false;
			row[p] = diagsum[j + p] = diagdel[j - p] = true;
		}
		if (flag) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}

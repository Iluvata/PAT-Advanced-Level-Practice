// 1105_Spiral_Matrix.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main()
{
	int n;
	cin >> n;
	vector<int> seq(n);
	for (int i = 0; i < n; ++i) {
		cin >> seq[i];
	}
	int n1 = sqrt(n);
	while (n % n1 != 0) {
		n1--;
	}
	int m = n / n1;
	sort(seq.begin(), seq.end(), cmp);
	vector<vector<int>> spiral(m, vector<int>(n1));
	vector<vector<bool>> visited(m, vector<bool>(n1));
	int x = 0, y = 0;
	int tmpx = 0, tmpy = 0;
	int dir = 0;
	for (int i = 0; i < n; ++i) {
		spiral[y][x] = seq[i];
		visited[y][x] = true;
		switch (dir) {
		case 0:
			tmpx = x + 1;
			break;
		case 1:
			tmpy = y + 1;
			break;
		case 2:
			tmpx = x - 1;
			break;
		case 3:
			tmpy = y - 1;
			break;
		}
		if (tmpx < 0 || tmpy < 0 || tmpx >= n1 || tmpy >= m || visited[tmpy][tmpx]) {
			tmpx = x;
			tmpy = y;
			switch (dir) {
			case 0:
				dir = 1;
				tmpy = y + 1;
				break;
			case 1:
				dir = 2;
				tmpx = x - 1;
				break;
			case 2:
				dir = 3;
				tmpy = y - 1;
				break;
			case 3:
				dir = 0;
				tmpx = x + 1;
				break;
			}
		}
		x = tmpx;
		y = tmpy;
	}
	for (int i = 0; i < m; ++i) {
		cout << spiral[i][0];
		for (int j = 1; j < n1; ++j) {
			cout << " " << spiral[i][j];
		}
		cout << endl;
	}
}

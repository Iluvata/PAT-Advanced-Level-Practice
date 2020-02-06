// 1106_Lowest_Price_in_Supply_Chain.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> layer(100000, -1);

int getlayer(int id, vector<int> &chain) {
	if (layer[id] >= 0) {
		return layer[id];
	}
	layer[id] = getlayer(chain[id], chain) + 1;
	return layer[id];
}
int main()
{
	int n;
	double p, r;
	cin >> n >> p >> r;
	vector<int> chain(n);
	vector<int> retailers;
	int k, id;
	layer[0] = 0;
	int nowlayer;
	for (int i = 0; i < n; ++i) {
		cin >> k;
		if (k == 0) {
			retailers.push_back(i);
		}
		nowlayer = -1;
		if (layer[i] >= 0) {
			nowlayer = layer[i] + 1;
		}
		for (int j = 0; j < k; ++j) {
			cin >> id;
			chain[id] = i;
			layer[id] = nowlayer;
		}
	}
	int minlayer = n;
	int mincnt = 0;
	for (int i = 0; i < retailers.size(); ++i) {
		int l = getlayer(retailers[i], chain);
		if (l == minlayer) {
			mincnt++;
		}
		else if (l < minlayer) {
			mincnt = 1;
			minlayer = l;
		}
	}
	double lowestp = pow(r / 100 + 1, minlayer) * p;
	printf("%.4f %d", lowestp, mincnt);
}

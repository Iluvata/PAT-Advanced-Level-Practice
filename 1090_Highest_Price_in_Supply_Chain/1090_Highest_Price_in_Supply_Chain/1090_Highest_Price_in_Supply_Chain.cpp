// 1090_Highest_Price_in_Supply_Chain.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> layer(100000, -1);

int getlayer(vector<int> &supplier, int i) {
	int nowlayer;
	if (layer[i] == -1) {
		nowlayer = getlayer(supplier, supplier[i]) + 1;
		layer[i] = nowlayer;
	}
	return layer[i];
}

int main()
{
	int n;
	double p, r;
	cin >> n >> p >> r;
	vector<int> supplier(n);
	for (int i = 0; i < n; ++i) {
		cin >> supplier[i];
		if (supplier[i] == -1) {
			layer[i] = 0;
		}
		else if (layer[supplier[i]] != -1) {
			layer[i] = layer[supplier[i]] + 1;
		}
	}
	
	int maxlayer = 0;
	int maxretailer = 0;
	for (int i = 0; i < n; ++i) {
		if (layer[i] == -1) {
			getlayer(supplier, i);
		}
		if (layer[i] > maxlayer) {
			maxlayer = layer[i];
			maxretailer = 1;
		}
		else if (layer[i] == maxlayer) {
			maxretailer++;
		}
	}
	r = r / 100 + 1;
	printf("%.2f %d", p * pow(r, maxlayer), maxretailer);
}

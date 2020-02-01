// 1079_Total_Sales_of_Supply_Chain.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

vector<int> layers(100000, -1);

int findlayer(int retailer, vector<int> &chain) {
	if (layers[retailer] != -1) {
		return layers[retailer];
	}
	layers[retailer] = findlayer(chain[retailer], chain) + 1;
	return layers[retailer];
}

int main()
{
	int n;
	double p, r;
	cin >> n >> p >> r;
	r = r / 100 + 1;
	vector<int> chain(n);
	layers[0] = 0;
	map<int, int> retailers;
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		if (k > 0) {
			for (int j = 0; j < k; ++j) {
				int distribute;
				cin >> distribute;
				chain[distribute] = i;
				if (layers[i] != -1) {
					layers[distribute] = layers[i] + 1;
				}
			}
		}
		else {
			cin >> retailers[i];
		}
	}
	double sales = 0;
	for (auto i = retailers.begin(); i != retailers.end(); ++i) {
		double sale = p * i->second;
		int layer = findlayer(i->first, chain);
		sales += sale * pow(r, layer);
	}
	printf("%.1f", sales);
}

// 1070_Mooncake.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Mooncake {
	double inventory;
	double price;
};

bool cmp(Mooncake &m1, Mooncake &m2) {
	return m1.price > m2.price;
}

int main()
{
	int n, d;
	cin >> n >> d;
	vector<Mooncake> cakes(n);
	for (int i = 0; i < n; ++i) {
		cin >> cakes[i].inventory;
	}
	for (int i = 0; i < n; ++i) {
		cin >> cakes[i].price;
		cakes[i].price /= cakes[i].inventory;
	}
	sort(cakes.begin(), cakes.end(), cmp);
	double sum = 0;
	for (int i = 0; i < n; ++i) {
		if (cakes[i].inventory < d) {
			d -= cakes[i].inventory;
			sum += cakes[i].price * cakes[i].inventory;
		}
		else {
			sum += cakes[i].price * d;
			break;
		}
	}
	printf("%.2f", sum);
}

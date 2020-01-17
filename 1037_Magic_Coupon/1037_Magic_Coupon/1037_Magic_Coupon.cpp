// 1037_Magic_Coupon.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(long long &l1, long long &l2) {
	return l1 > l2;
}

int main()
{
	int nc, np;
	vector<long long> cp;
	vector<long long> cn;
	vector<long long> pp;
	vector<long long> pn;
	long long amount;
	cin >> nc;
	for (int i = 0; i < nc; ++i) {
		cin >> amount;
		if (amount > 0) {
			cp.push_back(amount);
		}
		else if (amount < 0) {
			cn.push_back(amount);
		}
	}
	cin >> np;
	for (int i = 0; i < np; ++i) {
		cin >> amount;
		if (amount > 0) {
			pp.push_back(amount);
		}
		else if (amount < 0) {
			pn.push_back(amount);
		}
	}
	amount = 0;
	sort(cn.begin(), cn.end());
	sort(pn.begin(), pn.end());
	sort(cp.begin(), cp.end(), cmp);
	sort(pp.begin(), pp.end(), cmp);

	for (int i = 0; i < cn.size() && i < pn.size(); ++i) {
		amount += cn[i] * pn[i];
	}

	for (int i = 0; i < cp.size() && i < pp.size(); ++i) {
		amount += cp[i] * pp[i];
	}
	cout << amount;
}


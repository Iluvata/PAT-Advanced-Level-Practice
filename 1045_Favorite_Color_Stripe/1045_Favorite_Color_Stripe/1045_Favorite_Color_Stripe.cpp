// 1045_Favorite_Color_Stripe.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n, m, l;
	cin >> n;
	cin >> m;
	vector<bool> in_favor(n + 1, false);
	vector<int> favor_order(m);
	for (int i = 0; i < m; ++i) {
		cin >> favor_order[i];
		in_favor[favor_order[i]] = true;
	}
	reverse(favor_order.begin(), favor_order.end());
	cin >> l;
	vector<int> stripe;
	int color;
	for (int i = 0; i < l; ++i) {
		cin >> color;
		if (in_favor[color]) {
			stripe.push_back(color);
		}
	}
	stripe.push_back(0);
	reverse(stripe.begin(), stripe.end());
	vector<int> final_len(stripe.size(), 0);
	for (int i = 0; i < m; ++i) {
		int c = favor_order[i];
		for (int j = 1; j < stripe.size(); ++j) {
			if (stripe[j] == c) {
				int max_len = final_len[j - 1] + 1;
				if (max_len > final_len[j]) {
					final_len[j] = max_len;
				}
			}
			else {
				if (final_len[j - 1] > final_len[j]) {
					final_len[j] = final_len[j - 1];
				}
			}
		}
	}
	cout << final_len[stripe.size() - 1];
}

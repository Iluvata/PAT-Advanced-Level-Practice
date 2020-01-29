// 1064_Complete_Binary_Search_Tree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int c;

void get_layer_order(vector<int> &mid_trav, vector<int> &layer_order, int p, const int &n) {
	if (c <= n) {
		if(p * 2 <= n)
			get_layer_order(mid_trav, layer_order, p * 2, n);
		layer_order[p] = mid_trav[c];
		c++;
		if(p * 2 + 1 <= n)
			get_layer_order(mid_trav, layer_order, p * 2 + 1, n);
	}
}

int main()
{
	int n;
	cin >> n;
	c = 1;
	vector<int> v(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	vector<int> layer_order(n + 1);
	get_layer_order(v, layer_order, 1, n);
	cout << layer_order[1];
	for (int i = 2; i <= n; ++i) {
		cout << " " << layer_order[i];
	}
}

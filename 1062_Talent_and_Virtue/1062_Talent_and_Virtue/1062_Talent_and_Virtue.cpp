// 1062_Talent_and_Virtue.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n, l, h;

struct Grade {
	string id;
	int r;
	int v;
	int t;
};

bool cmp(Grade &g1, Grade &g2) {
	if (g1.r == g2.r) {
		if (g1.v + g1.t == g2.v + g2.t) {
			if (g1.v == g2.v) {
				return g1.id < g2.id;
			}
			return g1.v > g2.v;
		}
		return g1.v + g1.t > g2.v + g2.t;
	}
	return g1.r < g2.r;
}

int main()
{
	vector<Grade> rank;
	cin >> n >> l >> h;
	Grade g;
	for (int i = 0; i < n; ++i) {
		cin >> g.id >> g.v >> g.t;
		if (g.t >= l && g.v >= l) {
			if (g.t >= h && g.v >= h) {
				g.r = 1;
			}
			else if (g.v >= h) {
				g.r = 2;
			}
			else if (g.v >= g.t) {
				g.r = 3;
			}
			else {
				g.r = 4;
			}
			rank.push_back(g);
		}
	}
	cout << rank.size() << endl;
	sort(rank.begin(), rank.end(), cmp);
	for (int i = 0; i < rank.size(); ++i) {
		cout << rank[i].id << " " << rank[i].v << " " << rank[i].t << endl;
	}
}

// 1063_Set_Similarity.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	int n, m, k;
	scanf_s("%d", &n);
	vector<set<int>> s(n + 1);
	for (int i = 1; i <= n; ++i) {
		scanf_s("%d", &m);
		for (int j = 0; j < m; ++j) {
			int c;
			scanf_s("%d", &c);
			s[i].insert(c);
		}
	}
	scanf_s("%d", &k);
	set<int> inter;
	for (int i = 0; i < k; ++i) {
		int s1, s2;
		scanf_s("%d %d", &s1, &s2);
		inter.clear();
		set_intersection(s[s1].begin(), s[s1].end(), s[s2].begin(), s[s2].end(), inserter(inter, inter.begin()));
		printf("%.1f%%\n", 100 * float(inter.size()) / float(s[s1].size() + s[s2].size() - inter.size()));
	}
}

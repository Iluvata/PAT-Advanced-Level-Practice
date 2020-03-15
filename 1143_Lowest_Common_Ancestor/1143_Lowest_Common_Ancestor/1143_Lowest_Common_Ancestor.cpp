// 1143_Lowest_Common_Ancestor.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include<iostream>
#include<cstdio>
#include<vector>
#include<unordered_map>

using namespace std;

int w, u, v, n, m;

unordered_map<int, bool> have;

int main() {
	scanf_s("%d%d", &m, &n);
	vector<int> pre(n);
	for (int i = 0; i < n; ++i) {
		scanf_s("%d", &pre[i]);
		have[pre[i]] = true;
	}
	for (int i = 0; i < m; ++i) {
		scanf_s("%d%d", &u, &v);
		for (int j = 0; j < n; ++j) {
			w = pre[j];
			if ((w == u) || (w == v) || (w < u && w > v) || (w > u && w < v)) break;
		}
		if (!have[u] && !have[v]) printf("ERROR: %d and %d are not found.\n", u, v);
		else if (!have[u] || !have[v]) printf("ERROR: %d is not found.\n", have[u] ? v : u);
		else if (u == w || v == w) printf("%d is an ancestor of %d.\n", w, w == v ? u : v);
		else printf("LCA of %d and %d is %d.\n", u, v, w);
	}
}
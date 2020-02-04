// 1093_The_Largest_Generation.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

vector<int> level(101, 0);
vector<int> pedigree(101, 0);

int getlevel(int id) {
	if (level[id] > 0) {
		return level[id];
	}
	level[id] = getlevel(pedigree[id]) + 1;
	return level[id];
}

int main()
{
	int n, m;
	cin >> n >> m;
	level[1] = 1;
	int k, pid, cid;
	for (int i = 0; i < m; ++i) {
		cin >> pid >> k;
		int clevel = level[pid] > 0 ? level[pid] + 1 : 0;
		for (int j = 0; j < k; ++j) {
			cin >> cid;
			pedigree[cid] = pid;
			level[cid] = clevel;
		}
	}
	vector<int> level_count(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		level_count[getlevel(i)]++;
	}
	int maxnum = 0;
	int maxlevel = 1;
	for (int i = 1; i <= n; ++i) {
		if (level_count[i] > maxnum) {
			maxnum = level_count[i];
			maxlevel = i;
		}
	}
	cout << maxnum << " " << maxlevel;
}

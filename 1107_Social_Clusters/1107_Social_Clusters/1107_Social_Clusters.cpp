// 1107_Social_Clusters.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> hobby_cluster(1001);
vector<int> cluster_num(1001, 0);

int find_father(int x) {
	int f = x;
	while (hobby_cluster[f] != f) {
		f = hobby_cluster[f];
	}
	int next;
	while (x != f) {
		next = hobby_cluster[x];
		hobby_cluster[x] = f;
		x = next;
	}
	return f;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= 1000; ++i) {
		hobby_cluster[i] = i;
	}
	int k;
	vector<int> roots;
	for (int i = 1; i <= n; ++i) {
		cin >> k;
		getchar();
		int hid;
		cin >> hid;
		int f = find_father(hid);
		cluster_num[f]++;
		roots.push_back(f);
		int tmpf;
		for (int j = 1; j < k; ++j) {
			cin >> hid;
			tmpf = find_father(hid);
			if (tmpf != f) {
				hobby_cluster[tmpf] = f;
				cluster_num[f] += cluster_num[tmpf];
			}
		}
	}
	set<int> real_roots;
	for (int i = 0; i < n; ++i) {
		real_roots.insert(find_father(roots[i]));
	}
	vector<int> popu;
	for (auto i = real_roots.begin(); i != real_roots.end(); ++i) {
		popu.push_back(cluster_num[*i]);
	}
	sort(popu.begin(), popu.end());
	reverse(popu.begin(), popu.end());
	cout << popu.size() << endl;
	cout << popu[0];
	for (int i = 1; i < popu.size(); ++i) {
		cout << " " << popu[i];
	}
}

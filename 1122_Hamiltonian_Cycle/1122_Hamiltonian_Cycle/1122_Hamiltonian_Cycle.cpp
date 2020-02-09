// 1122_Hamiltonian_Cycle.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int v1, v2;
	vector<vector<bool>> adj(n + 1, vector<bool>(n + 1, false));
	for (int i = 0; i < m; ++i) {
		cin >> v1 >> v2;
		adj[v1][v2] = adj[v2][v1] = true;
	}
	int k;
	cin >> k;
	vector<bool> visited(n + 1, false);
	int num;
	for (int i = 0; i < k; ++i) {
		cin >> num;
		if (num != n + 1) {
			int id;
			for (int j = 0; j < num; ++j) {
				cin >> id;
			}
			cout << "NO" << endl;
		}
		else {
			vector<bool> v(visited);
			int fid;
			cin >> fid;
			int prev = fid;
			int id;
			bool flag = false;
			for (int j = 1; j < num; ++j) {
				cin >> id;
				if (v[id]) {
					flag = true;
				}
				v[id] = true;
				if (!adj[id][prev]) {
					flag = true;
				}
				prev = id;
			}
			if (flag) {
				flag = false;
			}
			else if (id == fid) {
				flag = true;
				for (int j = 1; j <= n; ++j) {
					if (!v[id]) {
						flag = false;
						break;
					}
				}
			}
			if (flag) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
	}
}

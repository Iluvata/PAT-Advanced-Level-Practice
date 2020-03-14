// 1142_Maximal_Clique.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

int isclique(vector<vector<bool>> &adj, vector<int> &req) {
	// 0: yes; 1: Not Maximal; 2: Not a Clique;
	vector<bool> tmp = adj[req[0]];
	for (int i = 1; i < req.size(); ++i) {
		if (!tmp[req[i]]) {
			return 2;
		}
		for (int j = 1; j < tmp.size(); ++j) {
			tmp[j] = tmp[j] & adj[req[i]][j];
		}
	}
	int res = 0;
	for (int i = 1; i < tmp.size(); ++i) {
		res |= tmp[i];
	}
	return res;
}

int main()
{
	int nv, ne;
	cin >> nv >> ne;
	vector<vector<bool>> adj(nv + 1, vector<bool>(nv + 1, false));
	int v1, v2;
	for (int i = 0; i < ne; ++i) {
		cin >> v1 >> v2;
		adj[v1][v2] = adj[v2][v1] = true;
	}
	int m, k, v;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> k;
		vector<int> req(k);
		for (int j = 0; j < k; ++j) {
			cin >> req[j];
		}
		switch (isclique(adj, req)) {
		case 0:
			cout << "Yes" << endl;
			break;
		case 1:
			cout << "Not Maximal" << endl;
			break;
		case 2:
			cout << "Not a Clique" << endl;
			break;
		}
	}
}

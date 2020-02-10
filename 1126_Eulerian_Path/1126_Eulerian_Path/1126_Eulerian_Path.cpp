// 1126_Eulerian_Path.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<bool>> &adj, int startfrom, vector<bool> &visited) {
	visited[startfrom] = true;
	for (int i = 1; i < adj.size(); ++i) {
		if (!visited[i] && adj[startfrom][i]) {
			dfs(adj, i, visited);
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> degrees(n + 1, 0);
	vector<vector<bool>> adj(n + 1, vector<bool>(n + 1, false));
	int v1, v2;
	for (int i = 0; i < m; ++i) {
		cin >> v1 >> v2;
		degrees[v1]++;
		degrees[v2]++;
		adj[v1][v2] = adj[v2][v1] = true;
	}
	vector<bool> visited(n + 1, false);
	dfs(adj, 1, visited);
	int oddnum = 0;
	for (int i = 1; i <= n; ++i) {
		if (!visited[i]) {
			oddnum = 3;
		}
	}
	for (int i = 1; i < n; ++i) {
		cout << degrees[i] << " ";
		if (degrees[i] % 2) {
			oddnum++;
		}
	}
	cout << degrees[n] << endl;
	if (degrees[n] % 2) {
		oddnum++;
	}
	if (oddnum == 0) {
		cout << "Eulerian" << endl;
	}
	else if (oddnum == 2) {
		cout << "Semi-Eulerian" << endl;
	}
	else {
		cout << "Non-Eulerian" << endl;
	}
}

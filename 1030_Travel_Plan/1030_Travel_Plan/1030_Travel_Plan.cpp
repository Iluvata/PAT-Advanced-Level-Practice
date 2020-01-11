// 1030_Travel_Plan.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

void dijkstra(vector<vector<int>> g, vector<vector<int>> cost, int s, vector<int> &p, vector<int> &d, vector<int> &c) {
	vector<bool> visited(g.size(), false);   // 是否已经被访问
	// init
	int n = g.size();
	d = vector<int>(n, INT_MAX);   // d 距离
	c = vector<int>(n, INT_MAX);   // cost
	p = vector<int>(n, -1);     // p 前驱

	// initialize single source
	for (int i = 0; i < n; ++i) {
		if (g[s][i] != INT_MAX) {
			d[i] = g[s][i];
			c[i] = cost[s][i];
			p[i] = s;
		}
	}
	visited[s] = true;

	for (int i = 1; i < n; ++i) {
		int nearest_v;
		int nearest_d = INT_MAX;
		int least_cost = INT_MAX;
		// find nearest vertex
		for (int j = 0; j < n; ++j) {
			if (!visited[j]) {
				if (d[j] < nearest_d) {
					nearest_d = d[j];
					least_cost = c[j];
					nearest_v = j;
				}
				else if (d[j] == nearest_d && c[j] < least_cost) {
					nearest_d = d[j];
					least_cost = c[j];
					nearest_v = j;
				}
			}
		}
		// cout << nearest_v;
		for (int j = 0; j < n; ++j) {
			// 对于每个相邻点
			if (!visited[j] && g[nearest_v][j] < INT_MAX) {
				// 若能减少路程则改变路程和前驱
				if (d[j] > d[nearest_v] + g[nearest_v][j]) {
					d[j] = d[nearest_v] + g[nearest_v][j];
					c[j] = c[nearest_v] + cost[nearest_v][j];
					p[j] = nearest_v;
				}
				else if (d[j] == d[nearest_v] + g[nearest_v][j] && c[j] > c[nearest_v] + cost[nearest_v][j]) {
					c[j] = c[nearest_v] + cost[nearest_v][j];
					p[j] = nearest_v;
				}
			}
		}
		visited[nearest_v] = true;
	}
}

int main()
{
	int n, m, s, d;
	cin >> n >> m >> s >> d;
	vector<vector<int>> adj_matrix(n, vector<int>(n, INT_MAX));
	vector<vector<int>> cost_matrix(n, vector<int>(n, INT_MAX));
	int city1, city2, distance, cost;
	for (int i = 0; i < m; ++i) {
		cin >> city1 >> city2 >> distance >> cost;
		adj_matrix[city1][city2] = adj_matrix[city2][city1] = distance;
		cost_matrix[city1][city2] = cost_matrix[city2][city1] = cost;
	}
	vector<int> prev;
	vector<int> dist;
	vector<int> least_cost;
	
	dijkstra(adj_matrix, cost_matrix, s, prev, dist, least_cost);

	vector<int> path;
	int tempd = d;
	while (tempd != s) {
		path.push_back(tempd);
		tempd = prev[tempd];
	}
	path.push_back(s);
	reverse(path.begin(), path.end());
	for (int i = 0; i < path.size(); ++i) {
		cout << path[i] << " ";
	}
	cout << dist[d] << " " << least_cost[d];
	/*
	cout << endl;
	for (int i = 0; i < prev.size(); ++i) {
		cout << prev[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < prev.size(); ++i) {
		cout << dist[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < prev.size(); ++i) {
		cout << least_cost[i] << " ";
	}
	cout << endl;
	*/
}

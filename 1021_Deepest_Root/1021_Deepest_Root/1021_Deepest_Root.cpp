// 1021_Deepest_Root.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int adj[10001][10001] = { 0 };

struct Vertex {
	int degree;
	int layer;
	bool visited;
	Vertex(int d = 0) :degree(d), visited(false), layer(0) {}
};

void dfs(vector<Vertex> &v, int n, int start) {
	v[start].visited = true;
	for (int i = 1; i <= n; ++i) {
		if (adj[start][i] == 1 && !v[i].visited) {
			v[i].layer = v[start].layer + 1;
			dfs(v, n, i);
		}
	}
}

int main()
{
	int n;
	cin >> n;
	vector<Vertex> v(n + 1);
	int i, j;
	for (int k = 0; k < n - 1; ++k) {
		cin >> i >> j;
		adj[i][j] = adj[j][i] = 1;
		v[i].degree += 1;
		v[j].degree += 1;
	}
	// find one vertex with one degree
	for (i = 1; i <= n; ++i) {
		if (v[i].degree == 1) {
			break;
		}
	}
	// dfs
	if(i > n)
		i = 1;
	v[i].layer = 0;
	dfs(v, n, i);
	// find deepest
	for (i = 1; i <= n; ++i) {
		if (!v[i].visited) {
			break;
		}
	}
	// more than one component
	if (i <= n) {
		int components = 1;
		// do dfs multiple times
		while (1) {
			components += 1;
			dfs(v, n, i);
			for (i = 1; i <= n; ++i) {
				if (!v[i].visited) {
					break;
				}
			}
			if (i > n) {
				break;
			}
		}
		printf("Error: %d components", components);
	}
	// only one component
	else {
		int maxlayer = 0;
		vector<int> points;
		// find max for the first time
		for (i = 1; i <= n; ++i) {
			if (v[i].layer > maxlayer) {
				points.clear();
				points.push_back(i);
				maxlayer = v[i].layer;
			}
			else if (v[i].layer == maxlayer) {
				points.push_back(i);
			}
		}
		// dfs for the 2nd time
		v[points[0]].layer = 0;
		for (int k = 1; k <= n; ++k) {
			v[k].visited = false;
		}
		dfs(v, n, points[0]);
		maxlayer = 0;
		for (int i = 1; i <= n; ++i) {
			if (v[i].layer > maxlayer) {
				maxlayer = v[i].layer;
			}
		}
		for (int i = 1; i <= n; ++i) {
			if (v[i].layer == maxlayer) {
				points.push_back(i);
			}
		}

		sort(points.begin(), points.end());
		// avoid repeated point
		i = points[0];
		cout << i;
		for (int j = 1; j < points.size(); ++j) {
			if (points[j] == i)
				continue;
			i = points[j];
			cout << endl << i;
		}
	}
}

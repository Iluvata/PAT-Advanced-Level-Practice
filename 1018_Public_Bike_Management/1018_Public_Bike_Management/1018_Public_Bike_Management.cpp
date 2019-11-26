// 1018_Public_Bike_Management.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

struct Vertex {
	int num;
	int d;
	vector<int> p;
	vector<int> accumulate;
	vector<int> shouldtake;
	vector<int> lastj;
	bool visited;
};

void dijkstra(vector<Vertex> &c, vector<vector<int>> t, int perfect_num) {
	c[0].visited = true;
	c[0].p.push_back(0);
	c[0].lastj.push_back(-1);
	c[0].shouldtake.push_back(0);
	for (int i = 1; i < c.size(); ++i) {
		if (t[0][i] < INT_MAX) {
			c[i].p.push_back(0);
			int acc = perfect_num - c[i].num;
			c[i].accumulate.push_back(acc);
			c[i].shouldtake.push_back(acc > 0 ? acc : 0);
			c[i].lastj.push_back(0);
			c[i].d = t[0][i];
		}
	}

	for (int k = 1; k < c.size(); ++k) {
		// find nearest vertex
		int min_d = INT_MAX;
		int min_ix = 0;
		for (int i = 1; i < c.size(); ++i) {
			if (!c[i].visited && c[i].d < min_d) {
				min_d = c[i].d;
				min_ix = i;
			}
		}
		c[min_ix].visited = true;

		// relax
		for (int i = 1; i < c.size(); ++i) {
			if (!c[i].visited && t[min_ix][i] < INT_MAX) {
				if (t[min_ix][i] + c[min_ix].d == c[i].d) {
					for (int j = 0; j < c[min_ix].accumulate.size(); ++j) {
						c[i].p.push_back(min_ix);
						int acc = perfect_num - c[i].num + c[min_ix].accumulate[j];
						c[i].accumulate.push_back(acc);
						c[i].lastj.push_back(j);
						if (acc > c[min_ix].shouldtake[j]) {
							c[i].shouldtake.push_back(acc);
						}
						else {
							c[i].shouldtake.push_back(c[min_ix].shouldtake[j]);
						}
					}
				}
				else if (t[min_ix][i] + c[min_ix].d < c[i].d) {
					c[i].d = t[min_ix][i] + c[min_ix].d;
					c[i].p.clear();
					c[i].accumulate.clear();
					c[i].shouldtake.clear();
					c[i].lastj.clear();
					for (int j = 0; j < c[min_ix].accumulate.size(); ++j) {
						c[i].p.push_back(min_ix);
						int acc = perfect_num - c[i].num + c[min_ix].accumulate[j];
						c[i].accumulate.push_back(acc);
						c[i].lastj.push_back(j);
						if (acc > c[min_ix].shouldtake[j]) {
							c[i].shouldtake.push_back(acc);
						}
						else {
							c[i].shouldtake.push_back(c[min_ix].shouldtake[j]);
						}
					}
				}
			}
		}

	}
}
int main()
{
	int cmax, n, s, m;
	cin >> cmax >> n >> s >> m;
	
	vector<Vertex> c(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> c[i].num;
		c[i].d = INT_MAX;
		c[i].visited = false;
	}

	vector<vector<int>> t(n + 1, vector<int>(n + 1, INT_MAX));
	int i, j, time;
	for (int k = 0; k < m; ++k) {
		cin >> i >> j >> time;
		t[i][j] = t[j][i] = time;
	}
	dijkstra(c, t, cmax / 2);
	int mintake = INT_MAX;
	vector<int> path;
	int bestpath;
	int minback = INT_MIN;
	for (int i = 0; i < c[s].shouldtake.size(); ++i) {

		c[s].accumulate[i] -= c[s].shouldtake[i];

		if (c[s].shouldtake[i] == mintake) {
			if (c[s].accumulate[i] > minback) {
				bestpath = i;
				mintake = c[s].shouldtake[i];
				minback = c[s].accumulate[i];
			}
		}
		else if (c[s].shouldtake[i] < mintake) {
			bestpath = i;
			mintake = c[s].shouldtake[i];
			minback = c[s].accumulate[i];
		}
	}

	path.push_back(s);
	Vertex temp = c[s];
	int lastj = c[s].lastj[bestpath];
	while (temp.lastj[0] != -1) {
		path.push_back(temp.p[bestpath]);
		temp = c[temp.p[bestpath]];
		bestpath = lastj;
		lastj = temp.lastj[bestpath];
	}
	cout << mintake << " ";
	reverse(path.begin(), path.end());
	for (int i = 0; i < path.size(); ++i) {
		if (i == path.size() - 1) {
			cout << path[i];
		}
		else {
			cout << path[i] << "->";
		}
	}
	cout << " " << -minback;
}

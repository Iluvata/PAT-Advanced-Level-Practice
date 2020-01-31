// 1072_Gas_Station.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

vector<vector<int>> d(11, vector<int>(1020, INT_MAX));
vector<vector<bool>> visited(11, vector<bool>(1020, false));

struct Station {
	int id;
	float shortest;
	float average_dist;
};

bool cmp(Station &s1, Station &s2) {
	if (s1.shortest == s2.shortest) {
		if (s1.average_dist == s2.average_dist) {
			return s1.id < s2.id;
		}
		return s1.average_dist < s2.average_dist;
	}
	return s1.shortest > s2.shortest;
}

void dijkstra(int startfrom, vector<vector<int>> &adj, int n, int &g) {
	// init
	visited[g][startfrom] = true;
	d[g][startfrom] = 0;
	for (int i = 1; i <= n; ++i) {
		if (adj[startfrom][i] < INT_MAX) {
			d[g][i] = adj[startfrom][i];
		}
	}

	for (int i = 1; i < n; ++i) {
		// find nearest
		int nearest_d = INT_MAX;
		int nearest_x = 0;
		for (int j = 1; j <= n; ++j) {
			if (!visited[g][j] && d[g][j] < nearest_d) {
				nearest_d = d[g][j];
				nearest_x = j;
			}
		}
		if (nearest_d == INT_MAX) {
			break;
		}
		visited[g][nearest_x] = true;
		for (int j = 1; j <= n; ++j) {
			if (!visited[g][j] && adj[nearest_x][j] < INT_MAX) {
				if (adj[nearest_x][j] + d[g][nearest_x] < d[g][j]) {
					d[g][j] = adj[nearest_x][j] + d[g][nearest_x];
				}
			}
		}
	}
}

int main()
{
	int n, m, k, ds;
	// scanf_s("%d %d %d %d", &n, &m, &k, &ds);
	cin >> n >> m >> k >> ds;
	vector<vector<int>> adj(n + m + 1, vector<int>(n + m + 1, INT_MAX));
	for (int i = 0; i < k; ++i) {
		int dist;
		string p1, p2;
		int ip1, ip2;
		cin >> p1 >> p2 >> dist;
		if (p1[0] == 'G') {
			p1 = p1.substr(1);
			ip1 = stoi(p1) + n;
		}
		else {
			ip1 = stoi(p1);
		}
		if (p2[0] == 'G') {
			p2 = p2.substr(1);
			ip2 = stoi(p2) + n;
		}
		else {
			ip2 = stoi(p2);
		}
		adj[ip1][ip2] = adj[ip2][ip1] = dist;
	}
	
	for (int i = 1; i <= m; ++i) {
		dijkstra(n + i, adj, n + m, i);
	}
	vector<Station> res;
	for (int i = 1; i <= m; ++i) {
		float shortest = 99999;
		float ave = 0;
		bool satis = true;
		for (int j = 1; j <= n; ++j) {
			if (d[i][j] > ds) {
				satis = false;
				break;
			}
			if (d[i][j] < shortest) {
				shortest = d[i][j];
			}
			ave += d[i][j];
		}
		if (!satis) {
			continue;
		}
		ave /= n;
		Station s;
		s.id = i;
		s.average_dist = ave;
		s.shortest = shortest;
		res.push_back(s);
	}
	if (res.empty()) {
		cout << "No Solution";
	}
	else {
		sort(res.begin(), res.end(), cmp);
		cout << "G" << res[0].id << endl;
		printf("%.1f %.1f", res[0].shortest, res[0].average_dist);
	}
}

// 1111_Online_Map.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int n, m;

struct Street {
	int length;
	int time;
	Street operator+(Street s) {
		Street res;
		res.length = length + s.length;
		res.time = time + s.time;
		return res;
	}
	bool operator<(Street s) {
		if (length == s.length) {
			return time < s.time;
		}
		return length < s.length;
	}
};

struct Time {
	int time;
	int internum;
	Time operator+(Time t) {
		Time res;
		res.time = time + t.time;
		res.internum = internum + 1;
		return res;
	}
	bool operator<(Time t) {
		if (time == t.time) {
			return internum < t.internum;
		}
		return time < t.time;
	}
};

int find_shortest(int source, int dest, vector<vector<Street>> &adj, vector<int> &prev) {
	Street s;
	s.length = s.time = INT_MAX;
	vector<Street> d(n, s);
	vector<int> p(n, -1);
	//init
	vector<bool> visited(n, false);
	s.length = s.time = 0;
	d[source] = s;
	visited[source] = true;
	for (int i = 0; i < n; ++i) {
		if (adj[source][i].length < INT_MAX) {
			d[i] = adj[source][i];
			p[i] = source;
		}
	}
	for (int i = 1; i < n; ++i) {
		// find nearest
		int nearest = -1;
		Street nearestdist;
		nearestdist.length = nearestdist.time = INT_MAX;
		for (int j = 0; j < n; ++j) {
			if (!visited[j] && d[j] < nearestdist) {
				nearest = j;
				nearestdist = d[j];
			}
		}
		if (nearest == -1) {
			break;
		}
		visited[nearest] = true;
		for (int j = 0; j < n; ++j) {
			if (!visited[j] && adj[nearest][j].length < INT_MAX && d[nearest] + adj[nearest][j] < d[j]) {
				d[j] = d[nearest] + adj[nearest][j];
				p[j] = nearest;
			}
		}
	}
	prev = p;
	return d[dest].length;
}

int find_fastest(int source, int dest, vector<vector<Street>> &adj, vector<int> &prev) {
	Time t;
	t.time = t.internum = INT_MAX;
	vector<Time> d(n, t);
	vector<int> p(n, -1);
	// init
	vector<bool> visited(n, false);
	t.time = t.internum = 0;
	d[source] = t;
	visited[source] = true;
	for (int i = 0; i < n; ++i) {
		if (adj[source][i].length < INT_MAX) {
			d[i].internum++;
			d[i].time = adj[source][i].time;
			p[i] = source;
		}
	}
	for (int i = 1; i < n; ++i) {
		// find fastest
		int fastest = -1;
		Time fastesttime;
		fastesttime.time = fastesttime.internum = INT_MAX;
		for (int j = 0; j < n; ++j) {
			if (!visited[j] && d[j] < fastesttime) {
				fastesttime = d[j];
				fastest = j;
			}
		}
		if (fastest == -1) {
			break;
		}
		visited[fastest] = true;
		// loosen
		for (int j = 0; j < n; ++j) {
			if (!visited[j] && adj[fastest][j].length < INT_MAX) {
				Time tmp;
				tmp.time = adj[fastest][j].time;
				tmp = d[fastest] + tmp;
				if (tmp < d[j]) {
					d[j] = tmp;
					p[j] = fastest;
				}
			}
		}
	}
	prev = p;
	return d[dest].time;
}

int main()
{
	cin >> n >> m;
	Street s;
	s.length = s.time = INT_MAX;
	vector<vector<Street>> adj(n, vector<Street>(n, s));
	int v1, v2, one_way;
	for (int i = 0; i < m; ++i) {
		cin >> v1 >> v2 >> one_way >> s.length >> s.time;
		adj[v1][v2] = s;
		if (one_way == 0) {
			adj[v2][v1] = s;
		}
	}
	int source, dest;
	cin >> source >> dest;
	vector<int> dist_prev;
	vector<int> time_prev;
	int d = find_shortest(source, dest, adj, dist_prev);
	int t = find_fastest(source, dest, adj, time_prev);
	vector<int> dist_path;
	vector<int> time_path;
	int tmp = dest;
	while (tmp != source) {
		dist_path.push_back(tmp);
		tmp = dist_prev[tmp];
	}
	dist_path.push_back(source);
	tmp = dest;
	while (tmp != source) {
		time_path.push_back(tmp);
		tmp = time_prev[tmp];
	}
	time_path.push_back(source);
	reverse(dist_path.begin(), dist_path.end());
	reverse(time_path.begin(), time_path.end());
	if (time_path == dist_path) {
		cout << "Distance = " << d << "; Time = " << t << ": " << dist_path[0];
		for (int i = 1; i < dist_path.size(); ++i) {
			cout << " -> " << dist_path[i];
		}
	}
	else {
		cout << "Distance = " << d << ": " << dist_path[0];
		for (int i = 1; i < dist_path.size(); ++i) {
			cout << " -> " << dist_path[i];
		}
		cout << endl;
		cout << "Time = " << t << ": " << time_path[0];
		for (int i = 1; i < time_path.size(); ++i) {
			cout << " -> " << time_path[i];
		}
	}
}

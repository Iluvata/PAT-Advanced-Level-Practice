// 1087_All_Roads_Lead_to_Rome.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <climits>
#include <stack>

using namespace std;

struct Cost {
	int cost;
	int happ;
	int passby;
	string prev;
	int shortestPathNum;
	bool operator<(Cost &c) {
		if (cost == c.cost) {
			if (happ == c.happ) {
				return passby < c.passby;
			}
			return happ > c.happ;
		}
		return cost < c.cost;
	}
	Cost operator+(Cost &c) {
		Cost sumed;
		sumed.cost = cost + c.cost;
		sumed.happ = happ + c.happ;
		sumed.passby = passby + 1;
	}
};

int dijkstra(map<string, map<string, int>> &adj, map<string, int> &happiness, string startfrom, map<string, Cost> &d) {
	//init
	map<string, bool> visited;
	d[startfrom].cost = 0;
	d[startfrom].shortestPathNum = 1;
	visited[startfrom] = true;
	for (auto i = adj[startfrom].begin(); i != adj[startfrom].end(); ++i) {
		d[i->first].cost = i->second;
		d[i->first].prev = startfrom;
		d[i->first].passby = 1;
		d[i->first].happ = happiness[i->first];
		d[i->first].shortestPathNum = 1;
	}

	for (int i = 1; i < adj.size(); ++i) {
		string bestcname;
		Cost bestc;
		bestc.cost = INT_MAX;
		for (auto j = adj.begin(); j != adj.end(); ++j) {
			if (!visited[j->first] && d.count(j->first) != 0 && d[j->first] < bestc) {
				bestcname = j->first;
				bestc = d[bestcname];
			}
		}
		if (bestcname.empty()) {
			break;
		}
		visited[bestcname] = true;
		Cost temp;
		for (auto j = adj[bestcname].begin(); j != adj[bestcname].end(); ++j) {
			temp.cost = adj[bestcname][j->first] + d[bestcname].cost;
			temp.happ = happiness[j->first] + d[bestcname].happ;
			temp.passby = d[bestcname].passby + 1;
			temp.shortestPathNum = d[bestcname].shortestPathNum;
			if (d.count(j->first) > 0 && temp.cost == d[j->first].cost) {
				d[j->first].shortestPathNum += temp.shortestPathNum;
			}
			if (!visited[j->first] && (d.count(j->first) == 0 || temp < d[j->first])) {
				if (d.count(j->first) > 0 && temp.cost == d[j->first].cost) {
					temp.shortestPathNum = d[j->first].shortestPathNum;
				}
				d[j->first] = temp;
				d[j->first].prev = bestcname;
			}
		}
	}
	return 0;
}
int main()
{
	int n, k;
	string startfrom;
	cin >> n >> k >> startfrom;
	map<string, int> happiness;
	string city;
	for (int i = 1; i < n; ++i) {
		cin >> city;
		cin >> happiness[city];
	}
	map<string, map<string, int>> adj;
	string city1, city2;
	int cost;
	for (int i = 0; i < k; ++i) {
		cin >> city1 >> city2;
		cin >> cost;
		adj[city1][city2] = adj[city2][city1] = cost;
	}
	map<string, Cost> d;
	dijkstra(adj, happiness, startfrom, d);
	Cost dest = d["ROM"];
	cout << dest.shortestPathNum << " " << dest.cost << " " << dest.happ << " " << dest.happ / dest.passby << endl;
	string p = "ROM";
	stack<string> path;
	while (p != startfrom) {
		path.push(p);
		p = d[p].prev;
	}
	cout << startfrom;
	while (!path.empty()) {
		cout << "->" << path.top();
		path.pop();
	}
}

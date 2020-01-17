// 1034_Head_of_a_Gang.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

struct Record {
	int time;
	bool visited;
};

struct Gang {
	string head;
	int num;
};

bool cmp(Gang &g1, Gang &g2) {
	return g1.head < g2.head;
}

int dfs(string name, map<string, Record> &names, map<string, map<string, int>> &records, string &head, int& num) {
	num += 1;
	int totaltime = names[name].time;
	if (names[name].time > names[head].time) {
		head = name;
	}
	names[name].visited = true;
	for (auto i = records[name].begin(); i != records[name].end(); ++i) {
		if (!names[i->first].visited) {
			totaltime += dfs(i->first, names, records, head, num);
		}
	}
	return totaltime;
}
int main()
{
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	map<string, Record> names;
	map<string, map<string, int>> records;
	string name1, name2;
	int time;
	for (int i = 0; i < n; ++i) {
		cin >> name1 >> name2 >> time;
		names[name1].time += time;
		names[name2].time += time;
		records[name1][name2] = records[name2][name1] = time;
	}
	
	int totalnum = 0;
	vector<Gang> gangs;
	while (totalnum < names.size()) {
		string name;                   // find first name not visited
		for (auto i = names.begin(); i != names.end(); ++i) {
			if (!i->second.visited) {
				name = i->first;
				break;
			}
		}
		int num = 0;
		string head = name;
		int totaltime = dfs(name, names, records, head, num);
		totalnum += num;
		if (num > 2 && totaltime / 2 > k) {
			Gang g;
			g.head = head;
			g.num = num;
			gangs.push_back(g);
		}
	}
	sort(gangs.begin(), gangs.end(), cmp);
	cout << gangs.size() << endl;
	for (int i = 0; i < gangs.size(); ++i) {
		cout << gangs[i].head << " " << gangs[i].num << endl;
	}
}

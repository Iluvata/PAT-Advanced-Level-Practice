// 1141_PAT_Ranking_of_Institutions.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <climits>
#include <vector>

using namespace std;

int ToLower(int c)
{
	return tolower(c);
}

struct School {
	string name;
	double b, a, t;
	int tws, ns;
};

bool cmp(School &s1, School &s2) {
	if (s1.tws == s2.tws) {
		if (s1.ns == s2.ns) {
			return s1.name < s2.name;
		}
		return s1.ns < s2.ns;
	}
	return s1.tws > s2.tws;
}

int main()
{
	int n, score;
	cin >> n;
	string id, school;
	map<string, School> insts;
	for (int i = 0; i < n; ++i) {
		cin >> id >> score >> school;
		transform(school.begin(), school.end(), school.begin(), ToLower);
		insts[school].ns++;
		switch (id[0]) {
		case 'B':
			insts[school].b += score;
			break;
		case 'A':
			insts[school].a += score;
			break;
		case 'T':
			insts[school].t += score;
			break;
		}
	}
	vector<School> rank;
	School tmp;
	for (auto i = insts.begin(); i != insts.end(); ++i) {
		tmp = i->second;
		tmp.name = i->first;
		tmp.tws = tmp.b / 1.5 + tmp.a + tmp.t * 1.5;
		rank.push_back(tmp);
	}
	sort(rank.begin(), rank.end(), cmp);
	cout << rank.size() << endl;
	int r = 1;
	int hightws = INT_MAX;
	for (int i = 0; i < rank.size(); ++i) {
		if (hightws > rank[i].tws) {
			r = i + 1;
			hightws = rank[i].tws;
		}
		cout << r << " " << rank[i].name << " " << rank[i].tws << " " << rank[i].ns << endl;
	}
}

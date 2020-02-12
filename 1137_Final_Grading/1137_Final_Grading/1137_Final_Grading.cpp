// 1137_Final_Grading.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

struct Grade {
	string id;
	int p;
	int mid;
	int gfinal;
	int g;
};

bool cmp(Grade &g1, Grade &g2) {
	if (g1.g == g2.g) {
		return g1.id < g2.id;
	}
	return g1.g > g2.g;
}

int main()
{
	int p, m, n;
	cin >> p >> m >> n;
	Grade init;
	init.p = init.mid = init.gfinal = init.g = -1;
	map<string, Grade> grades;
	string id;
	int score;
	for (int i = 0; i < p; ++i) {
		cin >> id >> score;
		grades[id] = init;
		grades[id].p = score;;
	}
	for (int i = 0; i < m; ++i) {
		cin >> id >> score;
		if (grades.count(id) == 1) {
			grades[id].mid = score;
		}
	}
	for (int i = 0; i < n; ++i) {
		cin >> id >> score;
		if (grades.count(id) == 1) {
			grades[id].gfinal = score;
		}
	}
	vector<Grade> passed;
	for (auto i = grades.begin(); i != grades.end(); ++i) {
		if (i->second.p >= 200) {
			if (i->second.gfinal >= i->second.mid) {
				i->second.g = i->second.gfinal;
			}
			else {
				i->second.g = floor(0.4 * i->second.mid + 0.6 * i->second.gfinal + 0.5);
			}
			if (i->second.g >= 60) {
				i->second.id = i->first;
				passed.push_back(i->second);
			}
		}
	}
	sort(passed.begin(), passed.end(), cmp);
	for (int i = 0; i < passed.size(); ++i) {
		cout << passed[i].id << " " << passed[i].p << " " << passed[i].mid << " " << passed[i].gfinal << " " << passed[i].g << endl;
	}
}

// 1080_Graduate_Admission.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Appli {
	int aid;
	int ge;
	int gi;
	int finalgrade;
	vector<int> schools;
	bool operator<(Appli &a1) {
		if (finalgrade == a1.finalgrade) {
			return ge > a1.ge;
		}
		return finalgrade > a1.finalgrade;
	}
};

bool cmp(Appli &a1, Appli &a2) {
	if (a1.finalgrade == a2.finalgrade) {
		return a1.ge > a2.ge;
	}
	return a1.finalgrade > a2.finalgrade;
}

int main()
{
	ios::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> quota(m);
	for (int i = 0; i < m; ++i) {
		cin >> quota[i];
	}
	vector<Appli> apps(n);
	for (int i = 0; i < n; ++i) {
		apps[i].aid = i;
		cin >> apps[i].ge >> apps[i].gi;
		apps[i].finalgrade = apps[i].ge + apps[i].gi;
		for (int j = 0; j < k; ++j) {
			int school;
			cin >> school;
			apps[i].schools.push_back(school);
		}
	}
	sort(apps.begin(), apps.end());
	vector<vector<int>> schoolres(m);
	int rank = 1;
	Appli bestapp = apps[0];
	vector<Appli> schoollast(m, bestapp);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < k; ++j) {
			int s = apps[i].schools[j];
			if (quota[s] > 0) {   // admitted
				quota[s]--;
				schoolres[s].push_back(apps[i].aid);
				schoollast[s] = apps[i];
				break;
			}
			else if (!(schoollast[s] < apps[i])) {
				schoolres[s].push_back(apps[i].aid);
				break;
			}
		}
	}

	for (int i = 0; i < m; ++i) {
		if (!schoolres[i].empty()) {
			sort(schoolres[i].begin(), schoolres[i].end());
			cout << schoolres[i][0];
		}
		for (int j = 1; j < schoolres[i].size(); ++j) {
			cout << " " << schoolres[i][j];
		}
		cout << endl;
	}
}

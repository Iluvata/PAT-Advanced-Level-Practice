// 1039_Course_List_for_Student.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	// vector<vector<string>> regisinfo(k + 1);
	map<string, vector<int>> rinfo;
	int cid, snum;
	string sname;
	for (int i = 0; i < k; ++i) {
		cin >> cid >> snum;
		for (int j = 0; j < snum; ++j) {
			cin >> sname;
			// regisinfo[cid].push_back(sname);
			rinfo[sname].push_back(cid);
		}
	}
	vector<string> req;
	for (int i = 0; i < n; ++i) {
		cin >> sname;
		req.push_back(sname);
	}
	for (auto i = rinfo.begin(); i != rinfo.end(); ++i) {
		sort(i->second.begin(), i->second.end());
	}
	for (int i = 0; i < n; ++i) {
		sname = req[i];
		cout << sname << " " << rinfo[sname].size();
		for (int j = 0; j < rinfo[sname].size(); ++j) {
			cout << " " << rinfo[sname][j];
		}
		cout << endl;
	}
}

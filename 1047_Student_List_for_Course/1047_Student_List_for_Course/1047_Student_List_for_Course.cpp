// 1047_Student_List_for_Course.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	// ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector<vector<string>> stu_list(k + 1);
	string sname;
	int cid;
	int c;
	for (int i = 0; i < n; ++i) {
		cin >> sname >> c;
		for (int j = 0; j < c; ++j) {
			cin >> cid;
			stu_list[cid].push_back(sname);
		}
	}
	for (int i = 1; i < stu_list.size(); ++i) {
		cout << i << " " << stu_list[i].size() << endl;
		sort(stu_list[i].begin(), stu_list[i].end());
		for (int j = 0; j < stu_list[i].size(); ++j) {
			printf("%s\n", stu_list[i][j].c_str());
		}
	}
}

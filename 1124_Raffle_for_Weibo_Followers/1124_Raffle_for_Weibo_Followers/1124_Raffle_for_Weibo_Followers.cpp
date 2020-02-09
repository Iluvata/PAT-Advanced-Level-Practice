// 1124_Raffle_for_Weibo_Followers.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main()
{
	int m, n, s;
	cin >> m >> n >> s;
	vector<string> followers;
	followers.push_back("");
	string fol;
	for (int i = 0; i < m; ++i) {
		cin >> fol;
		followers.push_back(fol);
	}
	bool flag = false;
	set<string> haswon;
	for (int i = s; i < followers.size(); i += n) {
		while (i < followers.size() && haswon.count(followers[i]) > 0) {
			i++;
		}
		if (i < followers.size()) {
			haswon.insert(followers[i]);
			flag = true;
			cout << followers[i] << endl;
		}
	}
	if (!flag) {
		cout << "Keep going..." << endl;
	}
}

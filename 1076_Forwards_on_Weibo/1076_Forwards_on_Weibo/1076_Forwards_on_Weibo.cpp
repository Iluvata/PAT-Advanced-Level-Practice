// 1076_Forwards_on_Weibo.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(int startfrom, vector<vector<int>> &user_list, int &totallayer, vector<bool> &visited) {
	int cnt = -1;
	int nowlayer;
	vector<queue<int>> layers(totallayer + 2);
	layers[0].push(startfrom);
	visited[startfrom] = true;
	for (nowlayer = 0; nowlayer <= totallayer; ++nowlayer) {
		while (!layers[nowlayer].empty()) {
			int user = layers[nowlayer].front();
			layers[nowlayer].pop();
			cnt++;
			for (int i = 0; i < user_list[user].size(); ++i) {
				int u = user_list[user][i];
				if (!visited[u]) {
					visited[u] = true;
					layers[nowlayer + 1].push(u);
				}
			}
		}
	}
	return cnt;
}

int main()
{
	int n, l;
	cin >> n >> l;
	vector<int> m(n + 1);
	vector<vector<int>> user_list(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> m[i];
		for (int j = 0; j < m[i]; ++j) {
			int followed;
			cin >> followed;
			user_list[followed].push_back(i);
		}
	}

	vector<bool> visited(n + 1, false);
	vector<bool> v;

	int k;
	cin >> k;
	int uid;
	for (int i = 0; i < k; ++i) {
		cin >> uid;
		v = visited;
		cout << bfs(uid, user_list, l, v) << endl;
	}
}

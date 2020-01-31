// 1075_PAT_Judge.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

struct User {
	int totalscore;
	int uid;
	vector<int> s;
	vector<bool> perfect;
	int perfectnum;
};

bool cmp(User &u1, User &u2) {
	if (u1.totalscore == u2.totalscore) {
		if (u1.perfectnum == u2.perfectnum) {
			return u1.uid < u2.uid;
		}
		return u1.perfectnum > u2.perfectnum;
	}
	return u1.totalscore > u2.totalscore;
}

int main()
{
	ios::sync_with_stdio(false);
	int n, k, m;
	cin >> n >> k >> m;
	vector<int> p(k + 1);
	for (int i = 1; i <= k; ++i) {
		cin >> p[i];
	}
	User u;
	u.perfect = vector<bool>(k + 1, false);
	u.perfectnum = 0;
	u.totalscore = 0;
	u.s = vector<int>(k + 1, -2);
	map<int, User> usermap;
	int uid, pid, score;
	for (int i = 0; i < m; ++i) {
		cin >> uid >> pid >> score;
		if (usermap.count(uid) > 0) {
			if(usermap[uid].s[pid] < score)
				usermap[uid].s[pid] = score;
		}
		else {
			usermap[uid] = u;
			usermap[uid].uid = uid;
			usermap[uid].s[pid] = score;
		}
		if (score == p[pid]) {
			usermap[uid].perfect[pid] = true;
		}
	}
	vector<User> ranklist;
	for (auto i = usermap.begin(); i != usermap.end(); ++i) {
		int totalscore = 0;
		bool canrank = false;
		for (int j = 1; j <= k; ++j) {
			int score = i->second.s[j];
			if (score >= 0) {
				totalscore += score;
				canrank = true;
			}
		}
		if (canrank) {
			i->second.totalscore = totalscore;
			i->second.perfectnum = count(i->second.perfect.begin(), i->second.perfect.end(), true);
			ranklist.push_back(i->second);
		}
	}
	sort(ranklist.begin(), ranklist.end(), cmp);
	int rank = 1;
	int highest = ranklist[0].totalscore;
	for (int i = 0; i < ranklist.size(); ++i) {
		if (ranklist[i].totalscore < highest) {
			highest = ranklist[i].totalscore;
			rank = i + 1;
		}
		printf("%d %05d %d", rank, ranklist[i].uid, ranklist[i].totalscore);
		for (int j = 1; j <= k; ++j) {
			if (ranklist[i].s[j] >= 0) {
				printf(" %d", ranklist[i].s[j]);
			}
			else if (ranklist[i].s[j] == -1) {
				printf(" 0");
			}
			else {
				printf(" -");
			}
		}
		printf("\n");
	}
}

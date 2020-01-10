// 1025_PAT_Ranking.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Testee {
	string registration_number;
	int location;
	int score;
};

struct Local_rank {
	int num;
	int rank;
	int score;
};

bool cmp(Testee& t1, Testee& t2) {
	if (t1.score == t2.score) {
		return t1.registration_number < t2.registration_number;
	}
	return t1.score > t2.score;
}

int main()
{
	int n, k;
	cin >> n;
	vector<Testee> ranklist;
	for (int i = 1; i <= n; ++i) {
		cin >> k;
		for (int j = 0; j < k; ++j) {
			Testee t;
			cin >> t.registration_number;
			cin >> t.score;
			t.location = i;
			ranklist.push_back(t);
		}
	}
	sort(ranklist.begin(), ranklist.end(), cmp);
	
	int highest_rank = 1;
	int highest_score = ranklist[0].score;
	Local_rank local_rank;
	local_rank.num = 0;
	local_rank.rank = 1;
	local_rank.score = 0;
	vector<Local_rank> local_highest_rank(n + 1, local_rank);

	cout << ranklist.size() << endl;
	for (unsigned i = 0; i < ranklist.size(); ++i) {
		cout << ranklist[i].registration_number << " ";
		int final_rank = i + 1;
		if (ranklist[i].score == highest_score) {
			cout << highest_rank << " ";
		}
		else {
			cout << final_rank << " ";
			highest_rank = final_rank;
			highest_score = ranklist[i].score;
		}
		int location = ranklist[i].location;
		cout << location << " ";
		local_highest_rank[location].num += 1;
		if (local_highest_rank[location].score != ranklist[i].score) {
			local_highest_rank[location].score = ranklist[i].score;
			local_highest_rank[location].rank = local_highest_rank[location].num;
		}
		cout << local_highest_rank[location].rank << endl;
	}
}

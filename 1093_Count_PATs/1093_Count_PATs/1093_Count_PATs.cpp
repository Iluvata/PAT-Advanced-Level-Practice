// 1093_Count_PATs.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string pats;
	cin >> pats;
	reverse(pats.begin(), pats.end());
	vector<int> num_t(pats.size());
	int count = 0;
	for (int i = 0; i < num_t.size(); ++i) {
		if (pats[i] == 'T') {
			count++;
		}
		num_t[i] = count;
	}
	count = 0;
	vector<int> num_at(pats.size(), 0);
	for (int i = 0; i < num_at.size(); ++i) {
		if (pats[i] == 'A') {
			count += num_t[i];
			count %= 1000000007;
		}
		num_at[i] = count;
	}
	count = 0;
	for (int i = 0; i < num_t.size(); ++i) {
		if (pats[i] == 'P') {
			count += num_at[i];
			count %= 1000000007;
		}
		num_at[i] = count;
	}
	cout << count;
}

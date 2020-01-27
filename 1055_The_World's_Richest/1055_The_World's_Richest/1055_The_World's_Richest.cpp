// 1055_The_World's_Richest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Worth {
	string name;
	int age;
	int net_worth;
};

bool cmp(Worth &w1, Worth &w2) {
	if (w1.net_worth == w2.net_worth) {
		if (w1.age == w2.age) {
			return w1.name < w2.name;
		}
		return w1.age < w2.age;
	}
	return w1.net_worth > w2.net_worth;
}

int main()
{
	ios::sync_with_stdio(false);
	int n, k;
	string name;
	int age, net_worth;
	cin >> n >> k;
	vector<Worth> forbes(n);
	for (int i = 0; i < n; ++i) {
		cin >> forbes[i].name >> forbes[i].age >> forbes[i].net_worth;
	}
	sort(forbes.begin(), forbes.end(), cmp);
	int m, amin, amax;
	for (int i = 1; i <= k; ++i) {
		cin >> m >> amin >> amax;
		cout << "Case #" << i << ":" << endl;
		int count = 0;
		int j = 0;
		while (j < n && count < m) {
			if (forbes[j].age <= amax && forbes[j].age >= amin) {
				cout << forbes[j].name << " " << forbes[j].age << " " << forbes[j].net_worth << endl;
				count++;
			}
			j++;
		}
		if (count == 0) {
			cout << "None" << endl;
		}
	}
}

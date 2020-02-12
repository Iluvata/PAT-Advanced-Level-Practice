// 1139_First_Contant.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

struct Contact {
	int f1, f2;
};

bool cmp(Contact &c1, Contact &c2) {
	if (c1.f1 == c2.f1) {
		return c1.f2 < c2.f2;
	}
	return c1.f1 < c2.f1;
}

int main()
{
	int n, m;
	cin >> n >> m;
	string id1, id2;
	map<int, map<int, bool>> adj;
	map<int, vector<int>> homo;
	for (int i = 0; i < m; ++i) {
		cin >> id1 >> id2;
		int negcnt = 0;
		if (id1[0] == '-') {
			negcnt++;
			id1 = id1.substr(1);
		}
		if (id2[0] == '-') {
			negcnt++;
			id2 = id2.substr(1);
		}
		int g1 = stoi(id1);
		int g2 = stoi(id2);
		adj[g1][g2] = adj[g2][g1] = true;
		if (negcnt % 2 == 0) {
			homo[g1].push_back(g2);
			homo[g2].push_back(g1);
		}
	}
	int q;
	cin >> q;
	int g1, g2;
	for (int i = 0; i < q; ++i) {
		cin >> g1 >> g2;
		if (g1 < 0) {
			g1 = -g1;
		}
		if (g2 < 0) {
			g2 = -g2;
		}
		vector<Contact> contacts;
		Contact cont;
		for (int j = 0; j < homo[g1].size(); ++j) {
			cont.f1 = homo[g1][j];
			for (int k = 0; k < homo[g2].size(); ++k) {
				if (adj[homo[g1][j]][homo[g2][k]] && homo[g2][k] != g1 && homo[g1][j] != g2) {
					cont.f2 = homo[g2][k];
					contacts.push_back(cont);
				}
			}
		}
		sort(contacts.begin(), contacts.end(), cmp);
		cout << contacts.size() << endl;
		for (int j = 0; j < contacts.size(); ++j) {
			printf("%04d %04d\n", contacts[j].f1, contacts[j].f2);
		}
	}
}

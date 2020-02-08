// 1116_Come_on!_Let's_C.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<bool> isprime(10001, true);

int main()
{
	isprime[1] = false;
	for (int i = 0; i <= 10000; i += 2) {
		isprime[i] = false;
	}
	for (int i = 3; i <= 10000; i += 2) {
		if (isprime[i]) {
			for (int j = i * 2; j <= 10000; j += i) {
				isprime[j] = false;
			}
		}
	}
	int n;
	cin >> n;
	vector<bool> checked(n + 1, false);
	map<int, int> rank;
	int id;
	for (int i = 1; i <= n; ++i) {
		cin >> id;
		rank[id] = i;
	}
	int k;
	cin >> k;
	
	for (int i = 0; i < k; ++i) {
		cin >> id;
		if (rank.count(id) == 0) {
			printf("%04d: Are you kidding?\n", id);
		}
		else if (checked[rank[id]]) {
			printf("%04d: Checked\n", id);
		}
		else {
			checked[rank[id]] = true;
			if (isprime[rank[id]]) {
				printf("%04d: Minion\n", id);
			}
			else if(rank[id] == 1) {
				printf("%04d: Mystery Award\n", id);
			}
			else {
				printf("%04d: Chocolate\n", id);
			}
		}
	}
}

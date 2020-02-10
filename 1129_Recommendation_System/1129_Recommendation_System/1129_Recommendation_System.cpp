// 1129_Recommendation_System.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int book[50001];

struct node {
	int value, cnt;
	node(int a, int b) :value(a), cnt(b) {}
	bool operator < (const node &a) const {
		return (cnt != a.cnt) ? cnt > a.cnt : value < a.value;
	}
};

int main()
{
	int n, k, num;
	cin >> n >> k;
	set<node> s;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (i != 0) {
			printf("%d:", num);
			int tempCnt = 0;
			for (auto it = s.begin(); tempCnt < k && it != s.end(); it++) {
				printf(" %d", it->value);
				tempCnt++;
			}
			printf("\n");
		}
		auto it = s.find(node(num, book[num]));
		if (it != s.end()) s.erase(it);
		book[num]++;
		s.insert(node(num, book[num]));
	}
}

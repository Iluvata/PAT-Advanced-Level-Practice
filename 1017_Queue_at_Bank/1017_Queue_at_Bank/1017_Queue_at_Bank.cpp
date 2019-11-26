// 1017_Queue_at_Bank.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Customer {
	int wait_time;
	int process_time;
};

bool cmp(const Customer &c1, const Customer &c2) {
	return c1.wait_time < c2.wait_time;
}

int from_eight(const string t) {
	int h = stoi(t.substr(0, 2));
	int m = stoi(t.substr(3, 2));
	int s = stoi(t.substr(6, 2));
	return ((h - 8) * 3600 + m * 60 + s);
}

int main()
{
	Customer customers[10000];
	int windows[100] = { 0 };
	int n, k;
	cin >> n >> k;
	string arrive_time;
	int process_time;
	for (int i = 0 ; i < n; ++i) {
		cin >> arrive_time >> process_time;
		if (arrive_time > "17:00:00") {
			i--;
			n--;
			continue;
		}
		customers[i].wait_time = from_eight(arrive_time);
		customers[i].process_time = process_time;
	}
	sort(customers, customers + n, cmp);
	int wait_time = 0;
	int cus_num = 0;
	while (cus_num < n) {
		for (int i = 0; i < k; ++i) {
			if (cus_num < n && customers[cus_num].wait_time <= 0 && windows[i] == 0) {
				windows[i] += customers[cus_num].process_time * 60;
				wait_time -= customers[cus_num].wait_time;
				cus_num += 1;
			}
			if (windows[i] > 0) {
				windows[i] -= 1;
			}
		}
		for (int i = cus_num; i < n; ++i) {
			customers[i].wait_time -= 1;
		}
	}
	double ave_wait_time = wait_time / 60.0 / n;
	printf("%.1f", ave_wait_time);
}

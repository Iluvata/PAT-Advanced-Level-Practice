// 1046_Shortest_Distance.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n;
	vector<int> dist(n + 1);
	int sum = 0;
	int c;
	for (int i = 1; i <= n; ++i) {
		cin >> c;
		dist[i] = sum;
		sum += c;
	}
	int longest = sum / 2;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int e1, e2;
		cin >> e1 >> e2;
		if (e1 > e2) {
			int temp = e1;
			e1 = e2;
			e2 = temp;
		}
		int s = dist[e2] - dist[e1];
		if (s > longest) {
			s = sum - s;
		}
		cout << s << endl;
	}
}

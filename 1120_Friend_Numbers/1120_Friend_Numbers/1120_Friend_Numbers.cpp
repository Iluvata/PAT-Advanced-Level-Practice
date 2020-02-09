// 1120_Friend_Numbers.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <set>

using namespace std;

int getid(int x) {
	int id = 0;
	while (x != 0) {
		id += x % 10;
		x /= 10;
	}
	return id;
}
int main()
{
	int n;
	cin >> n;
	set<int> ids;
	int x;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		ids.insert(getid(x));
	}
	cout << ids.size() << endl;
	for (auto i = ids.begin(); i != ids.end(); ++i) {
		cout << *i;
		if (++i == ids.end()) {
			cout << endl;
		}
		else {
			cout << " ";
		}
		i--;
	}
}

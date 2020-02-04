// 1092_To_Buy_or_Not_to_Buy.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	string eva, shop;
	cin >> shop >> eva;
	map<char, int> e;
	for (int i = 0; i < eva.size(); ++i) {
		e[eva[i]]++;
	}
	for (int i = 0; i < shop.size(); ++i) {
		if (e[shop[i]] > 0) {
			e[shop[i]]--;
		}
	}
	int count = 0;
	for (auto i = e.begin(); i != e.end(); ++i) {
		count += i->second;
	}
	if (count > 0) {
		cout << "No " << count;
	}
	else {
		cout << "Yes " << shop.size() - eva.size();
	}
}

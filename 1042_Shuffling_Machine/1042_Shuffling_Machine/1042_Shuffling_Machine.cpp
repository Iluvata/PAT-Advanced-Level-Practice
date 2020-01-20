// 1042_Shuffling_Machine.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main()
{
	int k;
	cin >> k;
	vector<string> deck;
	deck.push_back("");
	for (int i = 1; i <= 13; ++i) {
		char buf[4];
		sprintf_s(buf, "S%d", i);
		deck.push_back(buf);
	}
	for (int i = 1; i <= 13; ++i) {
		char buf[4];
		sprintf_s(buf, "H%d", i);
		deck.push_back(buf);
	}
	for (int i = 1; i <= 13; ++i) {
		char buf[4];
		sprintf_s(buf, "C%d", i);
		deck.push_back(buf);
	}
	for (int i = 1; i <= 13; ++i) {
		char buf[4];
		sprintf_s(buf, "D%d", i);
		deck.push_back(buf);
	}
	deck.push_back("J1");
	deck.push_back("J2");

	vector<int> s(55);
	for (int i = 1; i < 55; ++i) {
		cin >> s[i];
	}
	vector<string> res(55);
	for (int i = 0; i < k; ++i) {
		for (int j = 1; j < 55; ++j) {
			res[s[j]] = deck[j];
		}
		deck = res;
	}
	for (int i = 1; i < 54; ++i) {
		cout << deck[i] << " ";
	}
	cout << deck[54];
	return 0;
}

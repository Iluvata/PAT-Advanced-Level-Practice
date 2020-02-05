// 1100_Mars_Numbers.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> lowerdig = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
vector<string> higherdig = { "tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };

string to_mars(int n) {
	string mars;
	int high = n / 13;
	int low = n % 13;
	if (high > 0) {
		mars += higherdig[high];
		if (low > 0) {
			mars += " ";
			mars += lowerdig[low];
		}
	}
	else {
		mars = lowerdig[low];
	}
	return mars;
}

int to_earth(string s) {
	int high = 0;
	int low = 0;
	if (s.size() > 3) {
		string marshigh = s.substr(0, 3);
		s = s.substr(4);
		for (int i = 1; i < 13; ++i) {
			if (marshigh == higherdig[i]) {
				high = i;
				break;
			}
		}
	}
	for (int i = 0; i < 13; ++i) {
		if (s == lowerdig[i]) {
			low = i;
			break;
		}
	}
	for (int i = 1; i < 13; ++i) {
		if (s == higherdig[i]) {
			high = i;
			break;
		}
	}
	return high * 13 + low;
}

int main()
{
	int n;
	cin >> n;
	getchar();
	string ori;
	for (int i = 0; i < n; ++i) {
		getline(cin, ori);
		if (isdigit(ori[0])) {
			cout << to_mars(stoi(ori)) << endl;
		}
		else {
			cout << to_earth(ori) << endl;
		}
	}
}

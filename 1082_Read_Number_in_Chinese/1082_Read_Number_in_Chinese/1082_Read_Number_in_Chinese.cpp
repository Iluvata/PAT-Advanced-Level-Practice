// 1082_Read_Number_in_Chinese.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string chinese_read(int n) {
	vector<string> character = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
	vector<string> metric = { "Qian", "Bai", "Shi", "" };
	int numeric[4];
	numeric[0] = n / 1000;
	n %= 1000;
	numeric[1] = n / 100;
	n %= 100;
	numeric[2] = n / 10;
	n %= 10;
	numeric[3] = n;
	string read;
	int state = 0;
	for (int i = 0; i < 4; ++i) {
		if (numeric[i] > 0) {
			if (state == 0) {
				state = 1;
			}
			else if (state == 2) {
				state = 1;
				read += " ling ";
			}
			else {
				read += " ";
			}
			read += character[numeric[i]];
			if (i < 3) {
				read += " ";
				read += metric[i];
			}
		}
		else {
			if (state == 1) {
				state = 2;
			}
		}
	}
	if (state == 0) {
		read = "ling";
	}
	return read;
}

int main()
{
	int n;
	cin >> n;
	if (n < 0) {
		cout << "Fu ";
		n = -n;
	}
	int yi = n / 100000000;
	n %= 100000000;
	int wan = n / 10000;
	n %= 10000;
	int state = 0;
	if (yi > 0) {
		state = 1;
		cout << chinese_read(yi) << " Yi";
	}
	if (wan > 0) {
		if (state == 1) {
			if(wan / 1000 == 0)
				cout << " ling";
			cout << " ";
		}
		cout << chinese_read(wan) << " Wan";
		state = 1;
	}
	if (n > 0) {
		if (state == 1) {
			if (n / 1000 == 0) {
				cout << " ling";
			}
			cout << " ";
		}
		cout << chinese_read(n);
		state = 1;
	}
	if (state == 0) {
		cout << "ling";
	}
}

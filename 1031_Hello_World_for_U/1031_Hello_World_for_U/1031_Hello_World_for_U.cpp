// 1031_Hello_World_for_U.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string helloworld;
	cin >> helloworld;
	int len = helloworld.size();
	//cout << len << endl;
	if (len < 5) {
		cout << helloworld;
	}
	else {
		int n;
		if (len % 2) {
			n = 3;
		}
		else {
			n = 4;
		}
		while ((len - n) / 2 + 1 > n) {
			n += 2;
		}
		for (int i = 0; i < (len - n) / 2; ++i) {
			cout << helloworld[i];
			for (int j = 0; j < n - 2; ++j) {
				cout << " ";
			}
			cout << helloworld[len - 1 - i] << endl;
		}
		cout << helloworld.substr((len - n) / 2, n);
		//cout << n;
	}
}

// 1035_Password.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Account {
	string username;
	string password;
};

bool replace(string &s) {
	bool changed = false;
	for (int i = 0; i < s.size(); ++i) {
		switch (s[i]) {
		case '1':
			s[i] = '@';
			changed = true;
			break;
		case '0':
			s[i] = '%';
			changed = true;
			break;
		case 'l':
			s[i] = 'L';
			changed = true;
			break;
		case 'O':
			s[i] = 'o';
			changed = true;
		}
	}
	return changed;
}

int main()
{
	int n;
	cin >> n;
	int count = 0;
	Account a;
	vector<Account> replaced;
	for (int i = 0; i < n; ++i) {
		cin >> a.username >> a.password;
		if (replace(a.password)) {
			count++;
			replaced.push_back(a);
		}
	}
	if (count == 0 && n == 1) {
		cout << "There is 1 account and no account is modified";
	}
	else if (count == 0) {
		cout << "There are " << n << " accounts and no account is modified";
	}
	else {
		cout << count << endl;
		for (int i = 0; i < replaced.size(); ++i) {
			cout << replaced[i].username << " " << replaced[i].password << endl;
		}
	}
}

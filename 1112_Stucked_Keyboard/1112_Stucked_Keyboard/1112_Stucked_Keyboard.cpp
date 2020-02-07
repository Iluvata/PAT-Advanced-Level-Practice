// 1112_Stucked_Keyboard.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

struct Appear {
	int from;
	char key;
};

bool cmp(Appear &a1, Appear &a2) {
	return a1.from < a2.from;
}

int main()
{
	int k;
	cin >> k;
	string s;
	cin >> s;
	int repeattimes = 0;
	char lastone = ' ';
	set<char> normal;
	map<char, int> stucked;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] != lastone) {
			if (repeattimes > 0 && repeattimes % k == 0) {
				if (normal.count(lastone) == 0 && stucked.count(lastone) == 0) {
					stucked[lastone] = i;
				}
			}
			else {
				normal.insert(lastone);
				if (stucked.count(lastone) > 0) {
					stucked.erase(lastone);
				}
			}
			repeattimes = 1;
			lastone = s[i];
		}
		else {
			repeattimes++;
		}
	}
	if (repeattimes % k == 0 && normal.count(lastone) == 0 && stucked.count(lastone) == 0) {
		stucked[lastone] = s.size();
	}
	else if (stucked.count(lastone) > 0 && repeattimes % k != 0) {
		normal.insert(lastone);
		stucked.erase(lastone);
	}
	Appear a;
	vector<Appear> stucked_keys;
	for (auto i = stucked.begin(); i != stucked.end(); ++i) {
		a.from = i->second;
		a.key = i->first;
		stucked_keys.push_back(a);
	}
	sort(stucked_keys.begin(), stucked_keys.end(), cmp);
	for (int i = 0; i < stucked_keys.size(); ++i) {
		cout << stucked_keys[i].key;
	}
	cout << endl;
	int cnt = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (stucked.count(s[i]) > 0) {
			if (cnt == k) {
				cnt = 0;
			}
			if (cnt == 0) {
				cout << s[i];
			}
			cnt++;
		}
		else
			cout << s[i];
	}
	cout << endl;
}

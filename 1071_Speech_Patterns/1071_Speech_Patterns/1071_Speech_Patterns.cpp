// 1071_Speech_Patterns.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	string s;
	getline(cin, s);
	string word;
	map<string, int> words;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] <= 'Z' && s[i] >= 'A' || s[i] <= 'z' && s[i] >= 'a' || s[i] <= '9' && s[i] >= '0') {
			word.push_back(tolower(s[i]));
		}
		else if (!word.empty()) {
			words[word]++;
			word.clear();
		}
	}
	if (!word.empty()) {
		words[word]++;
		word.clear();
	}
	int max_count = 0;
	string max_s = "";
	for (auto i = words.begin(); i != words.end(); ++i) {
		if (i->second > max_count) {
			max_count = i->second;
			max_s = i->first;
		}
	}
	cout << max_s << " " << max_count;
}

// 1073_Scientific_Notation.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string sci;
	cin >> sci;
	int exp;
	
	exp = stoi(sci.substr(sci.find("E") + 1));
	char sign = sci[0];
	char int_part = sci[1];
	sci = sci.substr(3, sci.find('E') - 3);
	sci = int_part + sci;
	if (exp >= 0) {
		if (exp + 1 >= sci.size()) {
			exp = exp + 1 - sci.size();
			for (int i = 0; i < exp; ++i) {
				sci += '0';
			}
		}
		else {
			sci.insert(sci.begin() + exp + 1, '.');
		}
		int zeros = 0;
		while (zeros < sci.size() && sci[zeros] == '0') {
			zeros++;
		}
		sci = sci.substr(zeros);
		if (sci[0] == '.') {
			sci = '0' + sci;
		}
	}
	else {
		for (int i = 0; i > exp; --i) {
			sci = '0' + sci;
		}
		sci.insert(sci.begin() + 1, '.');
	}
	if (sign == '+') {
		cout << sci;
	}
	else {
		cout << sign << sci;
	}
}

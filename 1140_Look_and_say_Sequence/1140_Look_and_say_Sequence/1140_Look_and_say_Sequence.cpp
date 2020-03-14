// 1140_Look_and_say_Sequence.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	char buffer[10];
	string d, newd, digit;
	int n;
	cin >> d >> n;
	int cnt, tmp, prev;
	for (int i = 1; i < n; ++i) {
		newd = "";
		cnt = 0;
		prev = -1;
		for (int j = 0; j < d.size(); ++j) {
			digit = d[j];
			tmp = stoi(digit);
			if (tmp == prev) {
				cnt++;
			}
			else {
				if (prev != -1) {
					newd += char(prev + 48);
					// _itoa_s(cnt, buffer, 10);
					sprintf_s(buffer, "%d", cnt);
					newd += buffer;
				}
				prev = tmp;
				cnt = 1;
			}
		}
		if (prev != -1) {
			newd += char(prev + 48);
			// _itoa_s(cnt, buffer, 10);
			sprintf_s(buffer, "%d", cnt);
			newd += buffer;
		}
		d = newd;
	}
	cout << d;
}


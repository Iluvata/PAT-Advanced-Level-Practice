// 1078_Hashing.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<bool> isprime(20000, true);

int main()
{
	int msize, n;
	cin >> msize >> n;
	for (int i = 3; i < 150; i += 2) {
		if (isprime[i]) {
			for (int j = i * 2; j < 20000; j += i) {
				isprime[j] = false;
			}
		}
	}
	for (int i = 4; i < 20000; i += 2) {
		isprime[i] = false;
	}
	isprime[1] = false;

	int tsize = msize;
	while (!isprime[tsize]) {
		tsize++;
	}

	vector<bool> hash(tsize, false);
	int h;
	cin >> h;
	cout << h % tsize;
	hash[h % tsize] = true;
	for (int i = 1; i < n; ++i) {
		cin >> h;
		int j;
		for (j = 0; j < tsize; ++j) {
			int hashplace = (h + j * j) % tsize;
			if (!hash[hashplace]) {
				hash[hashplace] = true;
				cout << " " << hashplace;
				break;
			}
		}
		if (j == tsize) {
			cout << " -";
		}
	}
}

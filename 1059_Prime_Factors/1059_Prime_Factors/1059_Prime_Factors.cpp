// 1059_Prime_Factors.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

vector<bool> isprime(100000, true);
vector<int> prime;

int main()
{
	long int n;
	cin >> n;
	if (n == 1) {
		cout << "1=1";
		return 0;
	}
	prime.push_back(2);
	for (int i = 3; i < 100000; i += 2) {
		if (isprime[i]) {
			prime.push_back(i);
			for (int j = i * 2; j < 100000; j += i) {
				isprime[j] = false;
			}
		}
	}
	int i = 0;
	cout << n << "=";
	bool first = true;
	while (n > 1) {
		int count = 0;
		while (n > 1 && n % prime[i] == 0) {
			n /= prime[i];
			count++;
		}
		if (count > 0) {
			if (first) {
				first = false;
				cout << prime[i];
			}
			else
				cout << "*" << prime[i];
			if (count > 1) {
				cout << "^" << count;
			}
		}
		i++;
	}
}

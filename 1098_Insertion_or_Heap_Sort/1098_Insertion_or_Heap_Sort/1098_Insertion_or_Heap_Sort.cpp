// 1098_Insertion_or_Heap_Sort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> origin(n);
	vector<int> partially(n);
	for (int i = 0; i < n; ++i) {
		cin >> origin[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> partially[i];
	}
	int i;
	for (i = 1; i < n; ++i) {
		if (partially[i] < partially[i - 1]) {
			break;
		}
	}
	int j;
	for (j = i; j < n; ++j) {
		if (partially[j] != origin[j]) {
			break;
		}
	}
	if (j == n) {
		cout << "Insertion Sort" << endl;
		sort(partially.begin(), partially.begin() + i + 1);
		cout << partially[0];
		for (int i = 1; i < n; ++i) {
			cout << " " << partially[i];
		}
		return 0;
	}

	int top = partially[0];
	int len = n;
	for (int i = 1; i < n; ++i) {
		if (partially[i] >= top) {
			len = i;
			break;
		}
	}
	partially[0] = partially[len - 1];
	partially[len - 1] = top;
	make_heap(partially.begin(), partially.begin() + len - 1);
	cout << "Heap Sort" << endl;
	cout << partially[0];
	for (int i = 1; i < n; ++i) {
		cout << " " << partially[i];
	}
}

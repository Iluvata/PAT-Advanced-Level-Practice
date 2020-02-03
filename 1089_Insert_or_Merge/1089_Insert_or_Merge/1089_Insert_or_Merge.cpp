// 1089_Insert_or_Merge.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

void merge_once(vector<int> &arr, int t) {
	int s = pow(2, t);
	if (s >= arr.size()) {
		return;
	}
	for (int i = 0; i < arr.size(); i += s * 2) {
		int lr, rl, rr;
		rl = i + s;
		rr = i + 2 * s;
		if (rl > arr.size()) {
			rl = arr.size();
		}
		if(rr > arr.size()) {
			rr = arr.size();
		}
		vector<int> left(arr.begin() + i, arr.begin() + rl);
		vector<int> right(arr.begin() + rl, arr.begin() + rr);
		left.push_back(INT_MAX);
		right.push_back(INT_MAX);
		int l = 0, r = 0;
		for (int j = i; j < rr; ++j) {
			if (left[l] < right[r]) {
				arr[j] = left[l];
				l++;
			}
			else {
				arr[j] = right[r];
				r++;
			}
		}
	}
}

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

	int i = 0;
	while (partially[i + 1] >= partially[i]) {
		i++;
	}
	i++;
	int j;
	for (j = i; j < n; ++j) {
		if (partially[j] != origin[j]) {
			break;
		}
	}
	if (j == n) {
		cout << "Insertion Sort" << endl;
		sort(origin.begin(), origin.begin() + i + 1);
		cout << origin[0];
		for (int i = 1; i < n; ++i) {
			cout << " " << origin[i];
		}
		return 0;
	}

	vector<int> merge = origin;
	for (int i = 0; i < n; ++i) {
		merge_once(merge, i);
		if (merge == partially) {
			cout << "Merge Sort" << endl;
			merge_once(merge, i + 1);
			cout << merge[0];
			for (int j = 1; j < n; ++j) {
				cout << " " << merge[j];
			}
			break;
		}
	}
}

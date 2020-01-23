// 1048_Find_Coins.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	map<int, int> face_map;
	vector<int> faces(n);
	for (int i = 0; i < n; ++i) {
		cin >> faces[i];
		face_map[faces[i]] += 1;
	}
	sort(faces.begin(), faces.end());
	int i = 0;
	while (i < n && faces[i] < m / 2) {
		if (face_map[m - faces[i]] > 0) {
			cout << faces[i] << " " << m - faces[i];
			return 0;
		}
		i++;
	}
	if (m % 2 == 0 && face_map[m / 2] > 1) {
		cout << m / 2 << " " << m / 2;
	}
	else if (m % 2 == 1 && face_map[m / 2] > 0 && face_map[m / 2 + 1] > 0) {
		cout << m / 2 << " " << m / 2 + 1;
	}
	else {
		cout << "No Solution";
	}
}


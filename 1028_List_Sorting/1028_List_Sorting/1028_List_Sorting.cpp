// 1028_List_Sorting.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Record {
	int id;
	string name;
	int grade;
};

bool cmp1(Record& r1, Record& r2) {
	return r1.id < r2.id;
}

bool cmp2(Record& r1, Record& r2) {
	if (r1.name == r2.name) {
		return r1.id < r2.id;
	}
	return r1.name < r2.name;
}

bool cmp3(Record& r1, Record& r2) {
	if (r1.grade == r2.grade) {
		return r1.id < r2.id;
	}
	return r1.grade < r2.grade;
}
int main()
{
	int n, c;
	cin >> n >> c;
	vector<Record> records(n);
	for (int i = 0; i < n; ++i) {
		cin >> records[i].id >> records[i].name >> records[i].grade;
	}

	switch (c) {
	case 1:
		sort(records.begin(), records.end(), cmp1);
		break;
	case 2:
		sort(records.begin(), records.end(), cmp2);
		break;
	case 3:
		sort(records.begin(), records.end(), cmp3);
		break;
	}

	for (int i = 0; i < n; ++i) {
		printf("%06d %s %d\n", records[i].id, records[i].name.c_str(), records[i].grade);
		//cout << records[i].id << " " << records[i].name << " " << records[i].grade << endl;
	}
}

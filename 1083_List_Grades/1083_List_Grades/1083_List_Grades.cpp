// 1083_List_Grades.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Record {
	string name;
	string id;
};

int main()
{
	int n;
	cin >> n;
	vector<Record> grades(101);
	Record r;
	int grade;
	for (int i = 0; i < n; ++i) {
		cin >> r.name >> r.id >> grade;
		grades[grade] = r;
	}
	int grade1, grade2;
	cin >> grade1 >> grade2;
	bool isnone = true;
	for (int i = grade2; i >= grade1; --i) {
		if (!grades[i].id.empty()) {
			isnone = false;
			cout << grades[i].name << " " << grades[i].id << endl;
		}
	}
	if (isnone) {
		cout << "NONE";
	}
}

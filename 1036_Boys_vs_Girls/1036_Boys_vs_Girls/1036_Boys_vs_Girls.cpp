// 1036_Boys_vs_Girls.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int grade_f = -1;
	int grade_m = 101;
	string fname, fid, mname, mid;
	string name, gender, id;
	int grade;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> name >> gender >> id >> grade;
		if (gender == "M") {
			if (grade < grade_m) {
				grade_m = grade;
				mname = name;
				mid = id;
			}
		}
		else {
			if (grade > grade_f) {
				grade_f = grade;
				fname = name;
				fid = id;
			}
		}
	}
	int diff = grade_f - grade_m;
	if (grade_f == -1) {
		cout << "Absent" << endl;
	}
	else {
		cout << fname << " " << fid << endl;
	}
	if (grade_m == 101) {
		cout << "Absent" << endl;
	}
	else {
		cout << mname << " " << mid << endl;
	}
	if (grade_f == -1 || grade_m == 101) {
		cout << "NA";
	}
	else {
		cout << diff;
	}
}

// 1109_Group_Photo.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Person {
	string name;
	int height;
};

bool cmp(Person &p1, Person &p2) {
	if (p1.height == p2.height) {
		return p1.name < p2.name;
	}
	return p1.height > p2.height;
}

int main()
{
	int n, k;
	cin >> n >> k;
	int m = n / k;
	string name;
	int height;
	vector<Person> people(n);
	for (int i = 0; i < n; ++i) {
		cin >> people[i].name >> people[i].height;
	}
	sort(people.begin(), people.end(), cmp);
	int m1 = m + n % k;
	int pos = m1 / 2 + 1;
	vector<string> row1(m1 + 1);
	int leftp = pos - 1;
	bool isright = true;
	for (int i = 0; i < m1; ++i) {
		if (isright) {
			row1[pos] = people[i].name;
			pos++;
			isright = false;
		}
		else {
			row1[leftp] = people[i].name;
			leftp--;
			isright = true;
		}
	}
	cout << row1[1];
	for (int i = 2; i <= m1; ++i) {
		cout << " " << row1[i];
	}
	cout << endl;
	int startfrom = m1;
	vector<string> row(m + 1);
	for (int i = 1; i < n / m; ++i) {
		pos = m / 2 + 1;
		leftp = pos - 1;
		isright = true;
		for (int j = 0; j < m; ++j) {
			if (isright) {
				row[pos] = people[startfrom + j].name;
				pos++;
				isright = false;
			}
			else {
				row[leftp] = people[startfrom + j].name;
				leftp--;
				isright = true;
			}
		}
		startfrom += m;
		cout << row[1];
		for (int j = 2; j <= m; ++j) {
			cout << " " << row[j];
		}
		cout << endl;
	}
}

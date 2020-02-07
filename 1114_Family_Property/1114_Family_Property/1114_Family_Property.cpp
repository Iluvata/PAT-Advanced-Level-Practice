// 1114_Family_Property.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct Member {
	int id;
	int membernum;
	double sets;
	double area;
	Member operator+(Member m) {
		Member res;
		res.membernum = membernum + m.membernum;
		res.sets = sets + m.sets;
		res.area = area + m.area;
		return res;
	}
};

vector<int> memberof(10000);
vector<Member> properties(10000);

bool cmp(Member &m1, Member &m2) {
	if (m1.area / m1.membernum == m2.area / m2.membernum) {
		return m1.id < m2.id;
	}
	return m1.area / m1.membernum > m2.area / m2.membernum;
}

/*
int findfather(int x) {
	int minmember = x;
	int tmp = x;
	while (memberof[tmp] != tmp) {
		tmp = memberof[tmp];
		if (tmp < minmember) {
			minmember = tmp;
		}
	}
	memberof[tmp] = minmember;
	memberof[minmember] = minmember;
	properties[minmember] = properties[tmp];
	int root = minmember;
	while (memberof[x] != root) {
		tmp = memberof[x];
		memberof[x] = root;
		x = tmp;
	}
	return root;
}
*/

int findfather(int x) {
	int tmp = x;
	while (memberof[tmp] != tmp) {
		tmp = memberof[tmp];
	}
	int root = tmp;
	while (memberof[x] != root) {
		tmp = memberof[x];
		memberof[x] = root;
		x = tmp;
	}
	return root;
}

int main()
{
	Member initmember;
	initmember.membernum = 1;
	initmember.area = initmember.sets = 0;
	for (int i = 0; i < 10000; ++i) {
		memberof[i] = i;
		properties[i] = initmember;
	}
	int n;
	cin >> n;
	int id, father, mother, k, child;
	double estate, area;
	vector<int> families;
	for (int i = 0; i < n; ++i) {
		cin >> id >> father >> mother >> k;
		int m1, m2, m3;
		m1 = findfather(id);
		m2 = m3 = m1;
		if (father != -1) {
			m2 = findfather(father);
			m1 = findfather(m1);
			if (m1 != m2) {
				properties[m1] = properties[m1] + properties[m2];
				memberof[m2] = m1;
			}
		}
		if (mother != -1) {
			m3 = findfather(mother);
			m1 = findfather(m1);
			if (m1 != m3) {
				properties[m1] = properties[m1] + properties[m3];
				memberof[m3] = m1;
			}
		}
		for (int j = 0; j < k; ++j) {
			cin >> child;
			int tmpmember = findfather(child);
			m1 = findfather(m1);
			if (m1 != tmpmember) {
				properties[m1] = properties[m1] + properties[tmpmember];
				memberof[tmpmember] = m1;
			}

		}
		cin >> estate >> area;
		m1 = findfather(m1);
		properties[m1].sets += estate;
		properties[m1].area += area;
		families.push_back(m1);
	}
	set<int> familyids;
	for (int i = 0; i < families.size(); ++i) {
		familyids.insert(findfather(families[i]));
	}
	vector<Member> family_property;
	Member fam;
	for (auto i = familyids.begin(); i != familyids.end(); ++i) {
		fam = properties[*i];
		fam.id = *i;
		int minm = fam.id;
		for (int j = 0; j < 10000; ++j) {
			if (findfather(j) == fam.id) {
				if (j < fam.id) {
					fam.id = j;
					break;
				}
			}
		}
		family_property.push_back(fam);
	}
	sort(family_property.begin(), family_property.end(), cmp);
	cout << family_property.size() << endl;
	for (int i = 0; i < family_property.size(); ++i) {
		fam = family_property[i];
		printf("%04d %d %.3lf %.3lf\n", fam.id, fam.membernum, fam.sets / fam.membernum, fam.area / fam.membernum);
	}
}

// 1052_Linked_List_Sorting.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Node {
	int addr;
	int key;
	int next;
};

bool cmp(Node &n1, Node &n2) {
	return n1.key < n2.key;
}

int main()
{
	// ios::sync_with_stdio(false);
	int n, head;
	cin >> n >> head;
	if (head == -1) {
		cout << "0 -1";
		return 0;
	}
	map<int, Node> list;
	Node k;
	for (int i = 0; i < n; ++i) {
		cin >> k.addr >> k.key >> k.next;
		list[k.addr] = k;
	}
	vector<Node> sorted_list;
	while (head != -1) {
		sorted_list.push_back(list[head]);
		head = list[head].next;
	}
	sort(sorted_list.begin(), sorted_list.end(), cmp);
	// cout << sorted_list.size() << " " << sorted_list[0].addr << endl;
	printf("%d %05d\n", sorted_list.size(), sorted_list[0].addr);
	for (int i = 0; i < sorted_list.size(); ++i) {
		if (i + 1 < sorted_list.size()) {
			sorted_list[i].next = sorted_list[i + 1].addr;
			printf("%05d %d %05d\n", sorted_list[i].addr, sorted_list[i].key, sorted_list[i].next);
		}
		else {
			sorted_list[i].next = -1;
			printf("%05d %d %d\n", sorted_list[i].addr, sorted_list[i].key, sorted_list[i].next);
		}
	}
}

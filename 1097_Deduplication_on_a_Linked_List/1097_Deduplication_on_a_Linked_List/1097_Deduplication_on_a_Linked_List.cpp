// 1097_Deduplication_on_a_Linked_List.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <vector>

using namespace std;

struct Node {
	int address;
	int key;
	int next;
};

int main()
{
	int n, head;
	cin >> head >> n;
	map<int, Node> linked;
	Node temp;
	for (int i = 0; i < n; ++i) {
		cin >> temp.address >> temp.key >> temp.next;
		linked[temp.address] = temp;
	}
	set<int> repeated;
	vector<Node> left;
	vector<Node> removed;
	while (head != -1) {
		if (repeated.count(abs(linked[head].key)) == 0) {
			repeated.insert(abs(linked[head].key));
			left.push_back(linked[head]);
		}
		else {
			removed.push_back(linked[head]);
		}
		head = linked[head].next;
	}
	if (left.size() > 0) {
		int i;
		for (i = 1; i < left.size(); ++i) {
			printf("%05d %d %05d\n", left[i - 1].address, left[i - 1].key, left[i].address);
		}
		printf("%05d %d -1\n", left[i - 1].address, left[i - 1].key);
	}
	if (removed.size() > 0) {
		int j;
		for (j = 1; j < removed.size(); ++j) {
			printf("%05d %d %05d\n", removed[j - 1].address, removed[j - 1].key, removed[j].address);
		}
		printf("%05d %d -1\n", removed[j - 1].address, removed[j - 1].key);
	}
}

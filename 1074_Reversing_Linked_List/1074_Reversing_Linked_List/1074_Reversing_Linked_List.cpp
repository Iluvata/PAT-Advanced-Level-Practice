// 1074_Reversing_Linked_List.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <map>
#include <vector>
#include <stack>

using namespace std;

struct Node {
	int addr;
	int data;
	int next;
};

int main()
{
	int n, k, head;
	cin >> head >> n >> k;
	map<int, Node> linked_list;
	Node node;
	for (int i = 0; i < n; ++i) {
		cin >> node.addr >> node.data >> node.next;
		linked_list[node.addr] = node;
	}
	vector<Node> reversed;
	stack<Node> tmp;
	int cnt = 0;
	while (head != -1) {
		tmp.push(linked_list[head]);
		head = linked_list[head].next;
		cnt++;
		if (cnt == k) {
			for (int i = 0; i < k; ++i) {
				reversed.push_back(tmp.top());
				tmp.pop();
			}
			cnt = 0;
		}
	}
	node.addr = -1;
	while (!tmp.empty()) {
		node = tmp.top();
		tmp.pop();
	}
	head = node.addr;
	while (head != -1) {
		reversed.push_back(linked_list[head]);
		head = linked_list[head].next;
	}
	int i;
	for (i = 1; i < reversed.size(); ++i) {
		printf("%05d %d %05d\n", reversed[i - 1].addr, reversed[i - 1].data, reversed[i].addr);
	}
	printf("%05d %d -1", reversed[i - 1].addr, reversed[i - 1].data);
}

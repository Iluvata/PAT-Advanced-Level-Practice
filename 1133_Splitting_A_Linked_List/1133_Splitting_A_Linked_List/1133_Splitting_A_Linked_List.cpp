// 1133_Splitting_A_Linked_List.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Node {
	int addr;
	int data;
	int next;
};

int main()
{
	int head, n, k;
	cin >> head >> n >> k;
	map<int, Node> linked;
	Node init;
	for (int i = 0; i < n; ++i) {
		cin >> init.addr >> init.data >> init.next;
		linked[init.addr] = init;
	}
	vector<Node> negative;
	vector<Node> lesserk;
	vector<Node> greaterk;
	while (head != -1) {
		int key = linked[head].data;
		if (key < 0) {
			negative.push_back(linked[head]);
		}
		else if (key <= k) {
			lesserk.push_back(linked[head]);
		}
		else {
			greaterk.push_back(linked[head]);
		}
		head = linked[head].next;
	}
	for (int i = 0; i < lesserk.size(); ++i) {
		negative.push_back(lesserk[i]);
	}
	for (int i = 0; i < greaterk.size(); ++i) {
		negative.push_back(greaterk[i]);
	}
	for (int i = 1; i < negative.size(); ++i) {
		printf("%05d %d %05d\n", negative[i - 1].addr, negative[i - 1].data, negative[i].addr);
	}
	printf("%05d %d -1\n", negative[negative.size() - 1].addr, negative[negative.size() - 1].data);
}

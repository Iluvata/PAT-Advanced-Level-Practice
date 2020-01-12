// 1032_Sharing.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Node {
	int address;
	char data;
	int next;
	bool visited;
};


int main()
{
	ios::sync_with_stdio(false);
	int c1, c2, n;
	cin >> c1 >> c2 >> n;

	map<int, Node> nodes;
	Node letter;
	letter.visited = false;
	for (int i = 0; i < n; ++i) {
		cin >> letter.address >> letter.data >> letter.next;
		nodes[letter.address] = letter;
	}

	Node l1 = nodes[c1];
	Node l2 = nodes[c2];
	bool found = false;
	while (l1.next != -1 && l1.next != nodes[c1].address) {
		nodes[l1.address].visited = true;
		l1 = nodes[l1.next];
	}
	nodes[l1.address].visited = true;

	while (l2.next != -1 && l2.next != nodes[c2].address) {
		if (nodes[l2.address].visited) {
			found = true;
			break;
		}
		l2 = nodes[l2.next];
	}
	if (nodes[l2.address].visited) {
		found = true;
	}

	if (found) {
		printf("%05d", l2.address);
	}
	else {
		cout << -1;
	}
}

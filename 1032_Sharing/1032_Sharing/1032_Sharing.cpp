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
} nodes[100000];


int main()
{
	ios::sync_with_stdio(false);
	int c1, c2, n;
	cin >> c1 >> c2 >> n;

	// map<int, Node> nodes;
	Node letter;
	letter.visited = false;
	for (int i = 0; i < n; ++i) {
		cin >> letter.address >> letter.data >> letter.next;
		nodes[letter.address] = letter;
	}

	bool found = false;
	while (c1 != -1) {
		nodes[c1].visited = true;
		c1 = nodes[c1].next;
	}
	while (c2 != -1) {
		if (nodes[c2].visited) {
			found = true;
			break;
		}
		c2 = nodes[c2].next;
	}

	if (found) {
		printf("%05d", c2);
	}
	else {
		cout << -1;
	}
}

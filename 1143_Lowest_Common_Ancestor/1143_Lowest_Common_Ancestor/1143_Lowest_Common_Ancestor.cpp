// 1143_Lowest_Common_Ancestor.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <set>
#include <vector>

using namespace std;

struct Node {
	int key;
	Node* left;
	Node* right;
};

int main()
{
	int m, n;
	cin >> m >> n;
	set<int> elems;
	Node* root = nullptr;
	int key;
	for (int i = 0; i < n; ++i) {
		cin >> key;
		elems.insert(key);
		Node** tmp = &root;
		while (*tmp != nullptr) {
			if (key < (*tmp)->key) {
				tmp = &((*tmp)->left);
			}
			else {
				tmp = &((*tmp)->right);
			}
		}
		*tmp = new Node;
		(*tmp)->left = (*tmp)->right = nullptr;
		(*tmp)->key = key;
	}

	int e1, e2;
	bool hase1, hase2;
	for (int i = 0; i < m; ++i) {
		cin >> e1 >> e2;
		hase1 = elems.count(e1);
		hase2 = elems.count(e2);
		if (hase1 && hase2) {
			Node* tmp = root;
			while (tmp->key != e1 && tmp->key != e2) {
				if (tmp->key > e1 && tmp->key > e2) {
					tmp = tmp->left;
				}
				else if (tmp->key < e1 && tmp->key < e2) {
					tmp = tmp->right;
				}
				else {
					break;
				}
			}
			if (tmp->key == e1) {
				cout << e1 << " is an ancestor of " << e2 << "." << endl;
			}
			else if (tmp->key == e2) {
				cout << e2 << " is an ancestor of " << e1 << "." << endl;
			}
			else {
				cout << "LCA of " << e1 << " and " << e2 << " is " << tmp->key << "." << endl;
			}
		}
		else if (hase1) {
			cout << "ERROR: " << e2 << " is not found." << endl;
		}
		else if (hase2) {
			cout << "ERROR: " << e1 << " is not found." << endl;
		}
		else {
			cout << "ERROR: " << e1 << " and " << e2 << " are not found." << endl;
		}
	}
}

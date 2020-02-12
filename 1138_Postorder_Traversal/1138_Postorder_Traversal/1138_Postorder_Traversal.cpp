// 1138_Postorder_Traversal.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getpost(vector<int> &preorder, vector<int> &inorder) {
	while (preorder.size() > 1) {
		int dist = distance(inorder.begin(), find(inorder.begin(), inorder.end(), preorder[0]));
		if (dist > 0) {
			inorder.erase(inorder.begin() + dist, inorder.end());
			preorder.erase(preorder.begin() + dist + 1, preorder.end());
			preorder.erase(preorder.begin());
		}
		else {
			inorder.erase(inorder.begin());
			preorder.erase(preorder.begin());
		}
	}
	return preorder[0];
}

int main()
{
	int n;
	cin >> n;
	vector<int> preorder(n);
	vector<int> inorder(n);
	for (int i = 0; i < n; ++i) {
		cin >> preorder[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> inorder[i];
	}
	cout << getpost(preorder, inorder);
}

# Summary
要死，就是不知道哪里过不去  
放上代码  

```c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Node {
	int key;
	bool isred;
	Node* left;
	Node* right;
};

void createTree(Node** root, int key) {
	bool isred = false;
	if (key < 0) {
		isred = true;
		key = -key;
	}
	Node** tmp = root;
	while (*tmp) {
		if (key < (*tmp)->key) {
			tmp = &((*tmp)->left);
		}
		else {
			tmp = &((*tmp)->right);
		}
	}
	*tmp = new Node;
	(*tmp)->isred = isred;
	(*tmp)->key = key;
	(*tmp)->left = (*tmp)->right = nullptr;
}

bool isRedBlack(Node* root, bool &isred, int &blacknum) {
	isred = root->isred;
	blacknum = 0;

	int lblack = 0, rblack = 0;
	bool lred = false, rred = false;
	bool redblack = true;
	if (root->left) {
		redblack = isRedBlack(root->left, lred, lblack);
	}
	if (root->right) {
		redblack = isRedBlack(root->right, rred, rblack) && redblack;
	}
	blacknum = rblack + lblack;
	if (!isred) {
		blacknum++;
	}
	if (!redblack || lblack != rblack) {
		return false;
	}
	if (isred) {
		if (root->left && root->left->isred) {
			return false;
		}
		if (root->right && root->right->isred) {
			return false;
		}
	}
	return true;
}

int main()
{
	int k;
	cin >> k;
	int n;
	for (int i = 0; i < k; ++i) {
		cin >> n;
		int key;
		Node* tree = nullptr;
		int cnt = 0;
		for (int j = 0; j < n; ++j) {
			cin >> key;
			if (key > 0) {
				cnt++;
			}
			createTree(&tree, key);
		}
		bool isred;
		int blacknum;
		if (!isRedBlack(tree, isred, blacknum) || isred) {
			cout << "No" << endl;
		}
		else {
			cout << "Yes" << endl;
		}
		if (blacknum != cnt) {
			cout << "ERROR! " << blacknum << " should be " << cnt << endl;
		}
	}
}
```

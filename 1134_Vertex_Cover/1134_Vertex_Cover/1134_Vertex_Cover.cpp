// 1134_Vertex_Cover.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> vertexs(n);
	int v1, v2;
	for (int i = 0; i < m; ++i) {
		cin >> v1 >> v2;
		vertexs[v1].push_back(i);
		vertexs[v2].push_back(i);
	}
	int q;
	cin >> q;
	int nv, id;
	for (int i = 0; i < q; ++i) {
		vector<bool> edges(m, false);
		cin >> nv;
		bool covered = true;
		for (int j = 0; j < nv; ++j) {
			cin >> id;
			for (int k = 0; k < vertexs[id].size(); ++k) {
				edges[vertexs[id][k]] = true;
			}
		}
		for (int j = 0; j < m; ++j) {
			if (!edges[j]) {
				covered = false;
				break;
			}
		}
		if (covered) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
}

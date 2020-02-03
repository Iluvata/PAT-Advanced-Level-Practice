// 1091_Acute_Stroke.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int mri[1286][128][60];
bool visited[1286][128][60];
int n, m, l, t;

struct Node {
	int x, y, z;
};

int X[6] = { 1, 0, 0, -1, 0, 0 };
int Y[6] = { 0, 1, 0, 0, -1, 0 };
int Z[6] = { 0, 0, 1, 0, 0, -1 };


bool judge(int x, int y, int z) {
	if (x < 0 || x >= m || y < 0 || y >= n || z < 0 || z >= l) return false;
	if (mri[x][y][z] == 0 || visited[x][y][z] == true) return false;
	return true;
}

int bfs(int x, int y, int z) {
	if (mri[x][y][z] == 0) {
		return 0;
	}
	int cnt = 0;
	visited[x][y][z] = true;
	queue<Node> connected;
	Node p;
	p.x = x;
	p.y = y;
	p.z = z;
	connected.push(p);
	while (!connected.empty()) {
		Node now = connected.front();
		connected.pop();
		cnt++;
		for (int i = 0; i < 6; ++i) {
			int xi, yi, zi;
			xi = now.x + X[i];
			yi = now.y + Y[i];
			zi = now.z + Z[i];
			if (judge(xi, yi, zi)) {
				visited[xi][yi][zi] = true;
				now.x = xi;
				now.y = yi;
				now.z = zi;
				connected.push(now);
			}
		}
	}
	if (cnt < t) {
		return 0;
	}
	return cnt;
}

int main()
{
	scanf_s("%d %d %d %d", &m, &n, &l, &t);
	for (int i = 0; i < l; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < n; k++)
				scanf_s("%d", &mri[j][k][i]);
	int ans = 0;
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				if (mri[j][k][i] == 1 && visited[j][k][i] == false)
					ans += bfs(j, k, i);
			}
		}
	}
	printf("%d", ans);
}

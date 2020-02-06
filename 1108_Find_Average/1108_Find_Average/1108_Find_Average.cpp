// 1108_Find_Average.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
int main() {
	int n, cnt = 0;
	char a[50], b[50];
	double temp, sum = 0.0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf_s("%s", a);
		sscanf_s(a, "%lf", &temp);
		sprintf_s(b, "%.2f", temp);
		int flag = 0;
		for (int j = 0; j < strlen(a); j++)
			if (a[j] != b[j]) flag = 1;
		if (flag || temp < -1000 || temp > 1000) {
			printf("ERROR: %s is not a legal number\n", a);
			continue;
		}
		else {
			sum += temp;
			cnt++;
		}
	}
	if (cnt == 1)
		printf("The average of 1 number is %.2f", sum);
	else if (cnt > 1)
		printf("The average of %d numbers is %.2f", cnt, sum / cnt);
	else
		printf("The average of 0 numbers is Undefined");
	return 0;
}

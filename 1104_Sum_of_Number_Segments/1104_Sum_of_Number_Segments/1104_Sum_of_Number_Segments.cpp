// 1104_Sum_of_Number_Segments.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	double sum = 0;
	double ele;
	for (int i = 1; i <= n; ++i) {
		cin >> ele;
		sum += ele * (n - i + 1) * i;
	}
	printf("%.2f", sum);
}

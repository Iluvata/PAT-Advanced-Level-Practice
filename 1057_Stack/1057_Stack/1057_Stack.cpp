// 1057_Stack.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <stack>
#include <set>
#include <string>


using namespace std;

multiset<int>s1, s2;
int mid;

void adjust()
{
	multiset<int>::iterator it;
	if (s1.size() < s2.size())
	{
		it = s2.begin();
		s1.insert(*it);
		s2.erase(it);
	}
	if (s1.size() > s2.size() + 1)
	{
		it = s1.end();
		it--;
		s2.insert(*it);
		s1.erase(it);
	}
	if (!s1.empty())
	{
		it = s1.end();
		it--;
		mid = *it;
	}
}

int main()
{

	int n;
	cin >> n;
	stack<int>sta;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		if (s == "Push")
		{
			int num;
			cin >> num;
			sta.push(num);
			if (s1.empty()) s1.insert(num);
			else if (num <= mid) s1.insert(num);
			else s2.insert(num);
			adjust();
		}
		else if (s == "Pop")
		{
			if (sta.empty())
			{
				printf("Invalid\n");
			}
			else
			{
				int tmp = sta.top();
				printf("%d\n", tmp);
				sta.pop();
				if (tmp <= mid)
				{
					s1.erase(s1.find(tmp));
				}
				else
				{
					s2.erase(s2.find(tmp));
				}
				adjust();
			}
		}
		else if (s == "PeekMedian")
		{
			if (sta.empty())
			{
				printf("Invalid\n");
			}
			else
			{
				printf("%d\n", mid);
			}
		}
		else
			printf("Invalid\n");
	}
}

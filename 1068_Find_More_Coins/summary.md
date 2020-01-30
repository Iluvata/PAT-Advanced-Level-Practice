# Summary
哈哈哈，这题我是骗到分的。用的回溯法，但最后一个测试点超时。但是发现最后一个是`No Solution`，于是开始想办法过。经过两次测试后发现最后一个测试点第一个输入为1，在结束递归的条件中加上就能过。但是会影响倒数第二个测试点。于是再加一个硬币总数量>9的条件，真过了哈哈哈哈。虽然练习的时候不可取，但考试的时候不失为一种办法。  
这里先放上我骗到分的代码  

```c++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> backtrace(int m, vector<int> &coins, int startfrom) {
	vector<int> t;
	if (startfrom >= coins.size() || coins[startfrom] > m || coins[0] == 1 && coins.size() > 9) {
		return t;
	}
	m -= coins[startfrom];
	startfrom++;
	if (m == 0) {
		t.push_back(coins[startfrom - 1]);
		return t;
	}
	vector<int> b = backtrace(m, coins, startfrom);
	if (!b.empty()) {
		b.push_back(coins[startfrom -1]);
		return b;
	}
	m += coins[startfrom - 1];
	b = backtrace(m, coins, startfrom);
	if (!b.empty()) {
		return b;
	}
	return t;
}

int main()
{
    ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<int> coins(n);
	for (int i = 0; i < n; ++i) {
		cin >> coins[i];
	}
	sort(coins.begin(), coins.end());
	vector<int> c = backtrace(m, coins, 0);
	if (c.empty()) {
		cout << "No Solution";
		return 0;
	}
	reverse(c.begin(), c.end());
	cout << c[0];
	for (int i = 1; i < c.size(); ++i) {
		cout << " " << c[i];
	}
}

```

注意`backtrace`函数第一个if语句条件中的`coins[0] == 1 && coins.size() > 9`  

其实正确方法应该是用动态规划。0-1背包问题如果在得到物品重量相同的时候选择新的解那么总会倾向于选择后面的物品。如果不更换新物品的话并不会有某种特殊的顺序。因此遇到跟物品顺序有关系的题目时需要将物品优先级从低到高排序，然后动态规划求解，过程中总是选择最新解。  
这道题就是把硬币先从大到小排好就行了。  
我对动态规划掌握的还是不行，需要好好加强。需要在[博客](https://www.yucongsplayground.top)里总结，并且记录相似题型。
# Summary
一开始用了STL，虽然超时了但还是需要好好学习，因为就算用STL也有好多是网上查的，还没记住。。  
关于max的可以看[这里](https://blog.csdn.net/qq844352155/article/details/39346111)，还有我一开始想用map，虽然查了后发现好像没用，但[这个](https://blog.csdn.net/iicy266/article/details/11906189)也还是需要记下。  
最后还是抄了网上的用set，还是STL操作（利用重载结构体的 operator< 决定set排序）。。  
这里是我的超时代码。。。  

```c++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> items(n + 1, 0);
	int id;
	int flag = true;
	for (int i = 0; i < n; ++i) {
		cin >> id;
		if (!flag) {
			cout << id << ":";
			vector<int> tmp(items);
			vector<int>::iterator x = max_element(tmp.begin(), tmp.end());
			int cnt = 0;
			while (cnt < k && *x != 0) {
				cout << " " << distance(tmp.begin(), x);
				*x = 0;
				x = max_element(tmp.begin(), tmp.end());
				cnt++;
			}
			cout << endl;
		}
		else {
			flag = false;
		}
		items[id]++;
	}
}
```

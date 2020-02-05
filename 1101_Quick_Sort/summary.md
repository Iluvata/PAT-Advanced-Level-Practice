# Summary
如果当前元素在正确的位置并且他前面没有比他大的数，那么他就是pivot  
一开始我用了另一种判断，如果他前面没有比他大的数，并且他在排好序的队列中在到目前为止最大数的下一个，那么就是pivot。用了map做从排序到数字的索引。但是结果有一个测试点过不去，我想来想去想不到。。。  
这里贴上这份代码  

```c++

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> origin(n);
	for (int i = 0; i < n; ++i) {
		cin >> origin[i];
	}
	vector<int> sorted = origin;
	sorted.push_back(0);
	sort(sorted.begin(), sorted.end());
	map<int, int> pos;
	for (int i = 0; i <= n; ++i) {
		pos[sorted[i]] = i;
	}
	int max_till_now = 0;
	vector<int> pivots;
	for (int i = 0; i < n; ++i) {
		if (origin[i] > max_till_now) {
			if (pos[max_till_now] <= n && sorted[pos[max_till_now] + 1] == origin[i]) {
				pivots.push_back(origin[i]);
			}
			max_till_now = origin[i];
		}
	}
	
	cout << pivots.size() << endl;
	if (!pivots.empty()) {
		cout << pivots[0];
		for (int i = 1; i < pivots.size(); ++i) {
			cout << " " << pivots[i];
		}
	}
	cout << endl;
}
```

还有就是原来PAT默认是最后输出一个换行符？反正这题如果0个点的不多输出一个空行就会格式错误。。  

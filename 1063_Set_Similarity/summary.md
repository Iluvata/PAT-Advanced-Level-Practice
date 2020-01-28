# Summary
这题有点坑的地方是他的输入并不是集合，会有重复。一开始我没发现，还懵了好久  
我感觉用STL会方便很多。这样想就可以看作主要考STL的使用。但我并不会。。。以后还要在我的[博客](https://www.yucongsplayground.top)里总结一下有关STL的知识。  
主要用`algorithm`头文件里的`set_intersection`，参数有四个，分别为输入1的begin和end迭代器、输入2的begin和end迭代器、输出的插入迭代器。插入迭代器可以用`iterator`里的`inserter`。[这里](https://blog.csdn.net/zangker/article/details/22984803)有一份使用总结。  
如果不会用也可以用这个思路：  
先用set对每组序列进行去重和递增排序，再依次枚举序列a中元素，看能否在序列b中找到，以此计算出交集和并集中元素个数。  
代码：  

```c++
#include <cstdio>
#include <set>
using namespace std;

const int maxn = 51;
set<int> sets[maxn];

int main()
{
	int n, m, x, k, a, b;
	int Nc, Nt;
	set<int>::iterator it;
	
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)        //　序列去重排序后存储
	{
		scanf("%d", &m);
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &x);
			sets[i].insert(x);
		}
	}
	
	scanf("%d", &k);
	for (int i = 0; i < k; i++)
	{
		Nc = 0;
		scanf("%d %d", &a, &b);
		for (it = sets[a].begin(); it != sets[a].end(); it++)   // 枚举a中元素，在b中查找
			if (sets[b].find(*it) != sets[b].end())
				Nc++;
		Nt = sets[a].size() + sets[b].size() - Nc;
		printf("%.1f%%\n", 1.0 * Nc / Nt * 100);
	}
	
	return 0;
}
```
# Summary
这题要是直接排序会超时，最后是看了网上的，但其实我自己应该也能想到。有两种方法，虽然一种我不会，但至少另一种应该想到。  
先说我用的这种。  
模拟stack，不过这里的stack加多一个功能，就是输出中位数。用一个stack数据结构来模拟栈的功能，而为了方便得到中位数，要同时维护两个multiset数据结构（因为值可以重复，所以要用multiset）。一个set储存前一半的数（设为s1），一个set储存后一半的数（设为s2），这里s1的大小要和s2的大小一样或比s2的大小大1。同时更新中位数值mid，mid就是s1的最后一个数。在push的时候，把值push到stack中，同时，如果push的值小于等于mid就插入到s1，否则插入到s2，最后为了使他们的大小符合上面的描述，所以要调整一下，更新s1，s2和mid。pop的时候，对stack进行pop操作，同时，如果pop出来的值小于等于mid，就在s1中找出该值然后删除，否则在s2中找出该值然后删除，当前最后也要调整一下，更新s1，s2和mid。最后找中位数就直接找就行了。这里要注意的是multiset删除操作中，不能用实值作为参数，因为这样会把所有的这个值都删去，这里要先用find函数找出其中一个然后再删除。  
然后另一种是使用树形数组，介绍的可以先看[这里](https://www.cnblogs.com/zhangshu/archive/2011/08/16/2141396.html)，对于lowbit的解释可以看[这里](https://blog.csdn.net/weixin_30387423/article/details/97675528)。我自己感觉一种比较好的解释方法就是把负数补码看作正数取反加一。要是光取反然后&最后会是0.加了1后会一直进位到最高的1前面停下。就是说这样之后再&，正数最低位的1会被留下，也就是最低的二的幂形式的因子了。具体的之后写[博客](https://www.yucongsplayground.top)补上。  
这里是使用树形数组的代码。对每个数个数做统计，寻找中位数时用二分法找个数在中间的数字。  

```c++
#include <iostream>
#include <stack>
#define lowbit(i) ((i) & (-i))
const int maxn = 100010;
using namespace std;
int c[maxn];
stack<int> s;
void update(int x, int v) {
    for(int i = x; i < maxn; i += lowbit(i))
        c[i] += v;
}
int getsum(int x) {
    int sum = 0;
    for(int i = x; i >= 1; i -= lowbit(i))
        sum += c[i];
    return sum;
}
void PeekMedian() {
    int left = 1, right = maxn, mid, k = (s.size() + 1) / 2;
    while(left < right) {
        mid = (left + right) / 2;
        if(getsum(mid) >= k)
            right = mid;
        else
            left = mid + 1;
    }
    printf("%d\n", left);
}
int main() {
    int n, temp;
    scanf("%d", &n);
    char str[15];
    for(int i = 0; i < n; i++) {
        scanf("%s", str);
        if(str[1] == 'u') {
            scanf("%d", &temp);
            s.push(temp);
            update(temp, 1);
        } else if(str[1] == 'o') {
            if(!s.empty()) {
                update(s.top(), -1);
                printf("%d\n", s.top());
                s.pop();
            } else {
                printf("Invalid\n");
            }
        } else {
            if(!s.empty())
                PeekMedian();
            else
                printf("Invalid\n");
        }
    }
    return 0;
}
```

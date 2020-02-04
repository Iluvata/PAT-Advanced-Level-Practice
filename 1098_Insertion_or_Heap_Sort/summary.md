# Summary
堆排序。这题用STL会方便很多，但也是要在知道堆排的情况下，并且要熟悉STL。  
堆排序确实该好好整理下，看了好多资料才慢慢想起来。。。而且最后看别人的代码时才发现写的好方便。。。  
这里贴上堆排中调整堆的代码  

```c++
void downAdjust(vector<int> &b, int low, int high) {
    int i = 1, j = i * 2;
    while(j <= high) {
        if(j + 1 <= high && b[j] < b[j + 1]) j = j + 1;
        if (b[i] >= b[j]) break;
        swap(b[i], b[j]);
        i = j; j = i * 2;
    }
}
```

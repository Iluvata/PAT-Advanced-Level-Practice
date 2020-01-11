# Summary
一开始用分治排序合并类似的方法，复杂度为O(N)但有个测试点超时了。。。  
还有就是大数组在栈中放不下，要放到data段中，放在main函数外。  
后来想了想，也不用换成静态数组和二分法，就用vector和原来O(N)的办法，把cin的同步关了就过了。。。  
记住这句关同步的代码：
```c++
std::ios_base::sync_with_stdio(false); // 解除cin与stdin同步占用的时间
```
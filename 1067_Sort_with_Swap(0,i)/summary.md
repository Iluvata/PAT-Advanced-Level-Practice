# Summary
这题就真感觉我啥都不行了。。  
一开始想了好久，想从排列中找到规律，没想到方法，不得已看了网上的。  
用贪心法，每次交换必定将一个数换回正确的位置。有时候0在0位置，又得找一个位置不对的数字交换。结束条件就可以是找不到位置不对的数字。里面有一点可以记一下，就是在迭代器想转换成下标可以用`distance(v.begin(), iter)`.  
但这样子会超时。我一开始以为是寻找位置不对的数字导致的，就用set先保存位置不对的元素。但改了后还是超时。最后看了别人的代码后我发现是因为我在查找0元素当前位置的正确元素当前的位置的时候用了find。。  
网上大神的代码里用数字当下标，该数字当前位子作为内容，这样在查找当前位置正确元素的位置时可以直接下标查找，空间换时间。还有就是关于结束条件。其实可以用for循环，当所有元素都到合适的位置后就自动结束。  
关于这题的总结的话，首先应该是当一道题目找不到规律，也找不到什么最优子结构时，不妨先考虑下贪心。还有就是空间换时间，超时时元素和下标可以调换试试。这题感觉也只有拿数字做下标才过得了。。。  
要多练动态规划和贪心了。。  
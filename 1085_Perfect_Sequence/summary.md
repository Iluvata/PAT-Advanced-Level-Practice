# Summary
干，这题我想了好久才弄清楚是子序列不是子串。说白了就是有几个元素罢了。。  
弄明白了以后先上了暴力搜索超时，改成二分搜索后有错。看了别人答案后发现忘了相同元素的情况。。。二分搜索还要再仔细[整理](https://www.yucongsplayground.top)一下，包括有相同元素查找最左或最右情况。  
弄明白后再写还是错。。  
最后看别人的代码时发现有个直接用了STL的`upper_bound`。淦，又吃了不熟悉STL的亏。还得再[整理](https://www.yucongsplayground.top)下STL中有用的东西。。。  
`int temp = upper_bound(seq.begin(), seq.end(), seq[i] * p) - seq.begin();`  
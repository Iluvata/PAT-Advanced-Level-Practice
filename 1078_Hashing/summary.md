# Summary
这题要考试可真就炸了。看来数据结构整本书一点都不能落啊。。。包括算法导论。。。  
一开始看到二次探测想不起来，查了以后感觉想起来了就写了。但写完过不了。。。于是看了别人的代码说明，发现  

**二次方探查法**：

- 如果hashTable里面key % size的下标对应的hashTable为false,说明这个下标没有被使用过，直接输出。否则step步长从1加到size-1，一次次尝试是否能使`index = (key + step * step) % size;`所对应的位置没有元素，如果都没有找到就输出“-”，否则就输出这个找到的元素的位置。~~~~

- 注意 是`(key + step * step) % size` 而不是`(key % size + step* step)`  

回头好好整理下[哈希](https://www.yucongsplayground.top)。。  

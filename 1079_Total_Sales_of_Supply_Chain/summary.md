# Summary
这题可能也需要一点空间换时间的技巧。由于树的结构并不一定跟序号相关，因此不能在输入的时候就记录层数。而在输出的时候逐层计算层数又会超时。因此我先用一个数组记录层数，在需要用到时候如果有记录则直接用，否则计算并一边记录该点的层数。这样免去了重复的计算，有一点带记忆的递归或者动态规划的思想。
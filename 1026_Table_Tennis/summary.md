# Summary
这题到最后也没AC，留着后面来复盘。。。  
坑点特别多，首先就是vip在普通table和viptable共存会选择viptable不管序号大小。这点好像题目中都没有体现。  
还有会有规定时段外来的客人不能计入  
而且规定的2小时不是说所有输入都在2小时内，是说如果超过2小时，要按照2小时算。。。坑爹啊  
还有就是如果直接比较string会超时，因此将string时间转换为整数再比较好些  

我的算法是遍历所有时间，每秒钟遍历所有桌子，桌子记录当前组剩余时间。如果时间为0则从等待队列中寻找下一组。如果是vip桌则先找等待中的vip。然而vip在普通桌子和vip桌共存会先选择vip桌，因此如果等待队列头的组为vip，但当前桌子不是vip，要先遍历所有剩余桌子寻找vip桌，确认没有后再选择当前桌。
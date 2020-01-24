# Summary
这题一开始我是想到用类似递归方法，从高位到低位计算累加。但后面越来越乱。。。  
最后抄了网上的代码，发现真的是大神，十几行就搞定了。。。  
有些题要是你一开始想到的方法很麻烦，很有可能有更好的方法。  
由于代码也不长，我直接把网上的代码和思路贴在这里  
第一种方法是，扫每一位，然后把每一位按是不是1来考虑，很好很实用  

```c++
#include <iostream>
using namespace std;
int main() {
    int n, left = 0, right = 0, a = 1, now = 1, ans = 0;
    scanf("%d", &n);
    while(n / a) {
        left = n / (a * 10), now = n / a % 10, right = n % a;
        if(now == 0) ans += left * a;
        else if(now == 1) ans += left * a + right + 1;
        else ans += (left + 1) * a;
        a = a * 10;
    }
    printf("%d", ans);
    return 0;
}
```

第二种感觉就是直接遍历，带点dp思想  

```c++
#include<iostream>
#include<vector>
using namespace std;
int main(){
    long long int n,sum=0;
    cin>>n;
    int a[n+1]={0};
   //vector<int> a(n+1,0);
    for(int i=1;i<=n;i++){
        if(i%10==0)
            a[i]=a[i/10];
        else if(i%10==1)
            a[i]=a[i-1]+1;
        else if(i%10==2)
            a[i]=a[i-1]-1;
        else 
            a[i]=a[i-1];
        sum+=a[i];
    }
    cout<<sum<<endl;
    return 0;
}  
```

额，果然第二种过不了。毕竟最大有2^30。。。不过最后用来骗分还是有用的  
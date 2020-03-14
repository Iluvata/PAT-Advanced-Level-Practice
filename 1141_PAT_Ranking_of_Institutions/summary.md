# Summary
还是用map，最后转成vector排序。  
注意整理大小写转换。在<ctype.h>头文件的toupper和tolower在linux中的实现是宏

```c
/* Note: this is decimal, not hex, to avoid accidental promotion to unsigned */
#define _toupper(__c) ((__c) & ~32)
#define _tolower(__c) ((__c) | 32)
__ctype_inline int toupper(int __c)
{
return islower(__c) ? _toupper(__c) : __c;
}
__ctype_inline int tolower(int __c)
{
return isupper(__c) ? _tolower(__c) : __c;
}
```

因此不能直接用transform. 自己再套一层就行了。

```c++
int ToUpper(int c)
{
    return toupper(c);
}
transform(str.begin(), str.end(), str.begin(), ToUpper);
```

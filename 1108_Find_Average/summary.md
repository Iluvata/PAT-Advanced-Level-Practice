# Summary
这题我tm是真的人都做傻了。写半天写了个自动机出来，还考虑了各种可能的非法合法输入，包括认为前导0合法，小数点后面超过2位的0不知道合不合法，就都试试。还有小数点的位置，个数。但就是有一个点过不去。。。  
最后我发现了，类似这种 "23." 小数点放在最后的输入他居然算作合法，我真是服了。。。  
看了别人的代码后发现都是直接用sscanf和sprintf。好吧，我对c语言不够熟悉没想到这个。但是我马上就能举出合法但这样被判成非法和非法被判成合法的几个例子。比如如果有前导0，题目里没明确说明是不是合法，那在实数里面这样写应该是合法的，但用网上的方法就是不合法。还有就是我被卡的原因，最后一位是小数点的情况，至少我觉得应该不能算作合法。而且如果这样合法，第一位是小数点为什么不能也看做合法？最后还有就是题目没有具体说明输入的长度限制。如果输入一个超长序列就会有栈溢出，覆盖cnt。  
最后不知道为什么，把网上的代码放到VS里面，scanf改成scanf_s，sscanf改成sscanf_s，sprintf改成sprintf_s，会在scanf_s那里出异常。。  
草！！  

```c++
// 1108_Find_Average.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

double islegel(string s) {
	bool negative = false;
	if (s[0] == '-') {
		s = s.substr(1);
		negative = true;
	}
	if (s.empty()) {
		return 1001;
	}
	int state = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (isdigit(s[i])) {
			switch (state) {
			case 0:
			case 1:
				state = 2;
				if (s[i] == '0') {
					state = 1;
				}
				break;	
			case 2:
				state = 3;
				break;
			case 3:
				state = 4;
				break;
			case 4:
				if (s.substr(i - 3, 4) == "1000") {
					if (i + 1 < s.size()) {
						if (s.size() == i + 2 || s[i + 1] != '.') {
							return 1001;
						}
						for (int j = i + 2; j < s.size(); j++) {
							if (s[j] != '0') {
								return 1001;
							}
						}
					}
					if (negative) {
						return -1000;
					}
					else {
						return 1000;
					}
				}
				return 1001;
			case 5:
				state = 6;
				break;
			case 6:
				state = 7;
				break;
			case 7:
				if (s[i] == '0') {
					break;
				}
				else
					return 1001;
			}
		}
		else if (s[i] == '.') {
			switch (state) {
			case 0:
				return 1001;
			case 1:
			case 2:
			case 3:
			case 4:
				state = 5;
				break;
			case 5:
			case 6:
			case 7:
				return 1001;
			default:
				return 1001;
			}
		}
		else {
			return 1001;
		}
	}
	if (state == 5)
		return 1001;
	if (negative) {
		s = '-' + s;
	}
	int point = s.find('.');
	if (point == -1) {
		return stoi(s);
	}
	else {
		double ret = stoi(s.substr(0, point));
		if (s.size() == point + 2) {
			s = s + '0';
		}
		if (negative) {
			ret -= double(stoi(s.substr(point + 1))) / 100;
		}
		else
			ret += double(stoi(s.substr(point + 1))) / 100;
		return ret;
	}
}

int main()
{
	string s;
	int n;
	cin >> n;
	int cnt = 0;
	double legelsum = 0;
	double res;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		res = islegel(s);
		if (res == 1001) {
			cout << "ERROR: " << s << " is not a legal number" << endl;
		}
		else {
			cnt++;
			legelsum += res;
		}
	}
	if (cnt == 0) {
		cout << "The average of 0 numbers is Undefined" << endl;
	}
	else if (cnt == 1) {
		printf("The average of 1 number is %.2f\n", legelsum);
	}
	else {
		printf("The average of %d numbers is %.2f\n", cnt, legelsum / cnt);
	}
}
```

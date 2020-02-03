// 1088_Rational_Arithmetic.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

long long gcd(long long a, long long b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

long long simp(long long a, long long b, long long &simpa, long long &simpb) {
	long long g = gcd(a, b);
	simpa = a / g;
	simpb = b / g;
	long long ret = simpa / simpb;
	simpa = simpa % simpb;
	if (simpa < 0 && simpb < 0 || simpa > 0 && simpb < 0) {
		simpa = -simpa;
		simpb = -simpb;
	}
	if (ret < 0 && simpa < 0) {
		simpa = -simpa;
	}
	return ret;
}

void printRational(long long a, long long b, long long i) {
	int state = 0;
	if (i != 0) {
		state = 1;
		if (i < 0) {
			state = 2;
			cout << "(";
		}
		cout << i;
	}
	if (a == 0) {
		if(state == 0)
			cout << 0;
		else if (state == 2) {
			cout << ")";
		}
		return;
	}
	if (state > 0) {
		cout << " ";
	}
	else if (a < 0) {
		cout << "(";
		state = 2;
	}
	cout << a << "/" << b;
	if (state == 2) {
		cout << ")";
	}
}

int main()
{
	long long a1, a2, b1, b2;
	scanf_s("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
	long long simpa1, simpa2, simpb1, simpb2, simpint1, simpint2;
	simpint1 = simp(a1, b1, simpa1, simpb1);
	simpint2 = simp(a2, b2, simpa2, simpb2);

	long long suma, sumb, sumint;
	printRational(simpa1, simpb1, simpint1);
	cout << " + ";
	printRational(simpa2, simpb2, simpint2);
	cout << " = ";
	sumint = simp(a1 * b2 + a2 * b1, b1 * b2, suma, sumb);
	printRational(suma, sumb, sumint);
	cout << endl;

	long long suba, subb, subint;
	printRational(simpa1, simpb1, simpint1);
	cout << " - ";
	printRational(simpa2, simpb2, simpint2);
	cout << " = ";
	subint = simp(a1 * b2 - a2 * b1, b1 * b2, suba, subb);
	printRational(suba, subb, subint);
	cout << endl;

	long long mula, mulb, mulint;
	printRational(simpa1, simpb1, simpint1);
	cout << " * ";
	printRational(simpa2, simpb2, simpint2);
	cout << " = ";
	mulint = simp(a1 * a2, b1 * b2, mula, mulb);
	printRational(mula, mulb, mulint);
	cout << endl;
	
	long long diva, divb, divint;
	printRational(simpa1, simpb1, simpint1);
	cout << " / ";
	printRational(simpa2, simpb2, simpint2);
	cout << " = ";
	if (a2 == 0) {
		cout << "Inf";
		return 0;
	}
	divint = simp(a1 * b2, b1 * a2, diva, divb);
	printRational(diva, divb, divint);
}

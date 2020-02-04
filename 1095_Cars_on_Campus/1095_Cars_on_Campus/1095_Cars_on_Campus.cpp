// 1095_Cars_on_Campus.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct Time {
	int hh, mm, ss;

	Time operator+(Time &t) {
		Time res;
		res.hh = hh + t.hh;
		res.mm = mm + t.mm;
		res.ss = ss + t.ss;
		if (res.ss >= 60) {
			res.ss -= 60;
			res.mm++;
		}
		while (res.mm >= 60) {
			res.mm -= 60;
			res.hh++;
		}
		return res;
	}

	Time operator-(Time &t) {
		Time res;
		res.hh = hh - t.hh;
		res.mm = mm - t.mm;
		res.ss = ss - t.ss;
		if (res.ss < 0) {
			res.mm--;
			res.ss += 60;
		}
		while (res.mm < 0) {
			res.hh--;
			res.mm += 60;
		}
		return res;
	}

	bool operator<(Time &t) {
		if (hh == t.hh) {
			if (mm == t.mm) {
				return ss < t.ss;
			}
			return mm < t.mm;
		}
		return hh < t.hh;
	}

};

struct Car {
	string plate;
	bool hasin;
	Time intime, staytime;
};

struct Record {
	string plate;
	bool isin;
	Time t;
};

bool cmp(Record &r1, Record &r2) {
	return r1.t < r2.t;
}

bool carscmp(Car &c1, Car &c2) {
	if (c1.staytime.hh == c2.staytime.hh) {
		if (c1.staytime.mm == c2.staytime.mm) {
			if (c1.staytime.ss == c2.staytime.ss) {
				return c1.plate < c2.plate;
			}
			return c1.staytime.ss > c2.staytime.ss;
		}
		return c1.staytime.mm > c2.staytime.mm;
	}
	return c1.staytime.hh > c2.staytime.hh;
}

int main()
{
	int n, k;
	cin >> n >> k;
	map<string, Car> cars;
	vector<Record> records(n);
	Car c;
	Time t;
	string plate;
	string status;
	Record r;
	for (int i = 0; i < n; ++i) {
		cin >> records[i].plate;
		scanf_s("%d:%d:%d", &(t.hh), &(t.mm), &(t.ss));
		records[i].t = t;
		cin >> status;
		if (status == "in") {
			records[i].isin = true;
		}
		else {
			records[i].isin = false;
		}
	}
	sort(records.begin(), records.end(), cmp);
	vector<Record> eff_recs;
	for (int i = 0; i < n; ++i) {
		plate = records[i].plate;
		if (records[i].isin) {
			eff_recs.push_back(records[i]);
			cars[plate].hasin = true;
			cars[plate].intime = records[i].t;
		}
		else if(cars[plate].hasin){
			eff_recs.push_back(records[i]);
			cars[plate].hasin = false;
			t = records[i].t - cars[plate].intime;
			cars[plate].staytime = cars[plate].staytime + t;
		}
	}
	reverse(eff_recs.begin(), eff_recs.end());
	for (auto i = cars.begin(); i != cars.end(); ++i) {
		i->second.hasin = false;
	}
	for (int i = 0; i < eff_recs.size(); ++i) {
		plate = eff_recs[i].plate;
		if (eff_recs[i].isin) {
			if (!cars[plate].hasin) {
				eff_recs.erase(eff_recs.begin() + i);
				i--;
				continue;
			}
			cars[plate].hasin = false;
		}
		else {
			cars[plate].hasin = true;
		}
	}
	reverse(eff_recs.begin(), eff_recs.end());
	int cnt = 0;
	int j = 0;
	for (int i = 0; i < k; ++i) {
		scanf_s("%d:%d:%d", &(t.hh), &(t.mm), &(t.ss));
		while (j < eff_recs.size() && !(t < eff_recs[j].t)) {
			if (eff_recs[j].isin) {
				cnt++;
			}
			else {
				cnt--;
			}
			j++;
		}
		cout << cnt << endl;
	}
	vector<Car> cal_most;
	for (auto i = cars.begin(); i != cars.end(); ++i) {
		i->second.plate = i->first;
		cal_most.push_back(i->second);
	}
	sort(cal_most.begin(), cal_most.end(), carscmp);
	t = cal_most[0].staytime;
	cout << cal_most[0].plate;
	int i = 1;
	while (i < cal_most.size() && !(cal_most[i].staytime < t)) {
		cout << " " << cal_most[i].plate;
		i++;
	}
	printf(" %02d:%02d:%02d", t.hh, t.mm, t.ss);
}

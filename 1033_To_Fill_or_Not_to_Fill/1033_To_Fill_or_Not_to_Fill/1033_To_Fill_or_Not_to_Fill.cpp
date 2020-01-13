// 1033_To_Fill_or_Not_to_Fill.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Station {
	float price;
	int distance;
};

bool cmp(Station& s1, Station& s2) {
	if (s1.price == s2.price) {
		return s1.distance > s2.distance;
	}
	return s1.price < s2.price;
}

vector<float> prices(30001, -1);

int main()
{
	int cmax, d, davg, n;
	cin >> cmax >> d >> davg >> n;
	vector<Station> stations(n);

	Station station_now;
	station_now.distance = 0;
	station_now.price = -1;

	stations[0].price = 0;
	stations[0].distance = d;
	prices[d] = 0;

	float price;
	int distance;
	for (int i = 1; i < n; ++i) {
		cin >> price >> distance;
		if (distance == 0) {
			station_now.price = price;
			i--;
			prices[0] = price;
			continue;
		}
		stations[i].price = price;
		stations[i].distance = distance;
		if(prices[distance] < 0 || prices[distance > price])
			prices[distance] = price;
	}
	if (station_now.price < 0) {
		printf("The maximum travel distance = 0.00");
		return 0;
	}
	sort(stations.begin(), stations.end(), cmp);
	//float tank_left = 0;
	float price_total = 0;
	int maxdist = davg * cmax;
	int dmax;
	int tank_left = 0;

	while (station_now.distance < d && !stations.empty()) {
		dmax = maxdist + station_now.distance;
		bool found = false;
		for (int i = station_now.distance + 1; i < 30001 && i <= dmax; ++i) {
			if (prices[i] >= 0 && prices[i] <= station_now.price) {      // lower price station
				price_total += (i - station_now.distance - tank_left) * station_now.price / davg;
				tank_left = 0;
				station_now.distance = i;
				station_now.price = prices[i];
				for (int j = 0; j < stations.size(); ++j) {
					if (stations[j].distance <= station_now.distance) {
						stations.erase(stations.begin() + j);
						j--;
					}
				}
				found = true;
				break;
			}
		}
		if (found) {
			continue;
		}
		for (int i = 0; i < stations.size(); ++i) {
			if (stations[i].distance <= dmax) {     // find next station to stop
				price_total += (maxdist - tank_left) * station_now.price / davg;    // full
				tank_left = maxdist - (stations[i].distance - station_now.distance);
				station_now = stations[i];
				for (int j = 0; j < stations.size(); ++j) {
					if (stations[j].distance <= station_now.distance) {
						stations.erase(stations.begin() + j);
						j--;
					}
				}
				found = true;
				break;
			}
		}
		if (!found) {
			break;
		}
	}
	if (station_now.distance < d) {      // cannot arrive
		printf("The maximum travel distance = %.2f", float(station_now.distance + maxdist));
	}
	else {
		printf("%.2f", price_total);
	}
}

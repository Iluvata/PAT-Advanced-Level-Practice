// 1026_Table_Tennis.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Arrive {
	int arrive_time;
	int serve_time;
	int wait_time;
	bool isvip;
};

struct Table {
	int time_left;
	bool isvip;
	int serve_num;
};

bool cmp(Arrive& a1, Arrive& a2) {
	return a1.arrive_time > a2.arrive_time;
}

int str2time(string strtime) {
	int time = 0;
	time += (stoi(strtime.substr(0, 2)) - 8) * 3600;
	time += stoi(strtime.substr(3, 2)) * 60;
	time += stoi(strtime.substr(6, 2));
	return time;
}

string time2str(int time) {
	char s[9];
	int hh, mm, ss;
	hh = time / 3600 + 8;
	mm = (time % 3600) / 60;
	ss = time % 3600 % 60;
	sprintf_s(s, "%02d:%02d:%02d", hh, mm, ss);
	return s;
}

int main()
{
	int n;
	cin >> n;
	vector<Arrive> arrive_queue;
	for (int i = 0; i < n; ++i) {
		Arrive a;
		string arrive_time;
		cin >> arrive_time >> a.serve_time >> a.isvip;
		if (a.serve_time > 120) {
			a.serve_time = 120;
		}
		a.arrive_time = str2time(arrive_time);
		a.wait_time = 0;
		arrive_queue.push_back(a);
	}
	sort(arrive_queue.begin(), arrive_queue.end(), cmp);

	int k, m;
	cin >> k >> m;
	Table t;
	t.isvip = false;
	t.time_left = 1;
	t.serve_num = 0;
	vector<Table> tables(k + 1, t);
	for (int i = 0; i < m; ++i) {
		int t_vip;
		cin >> t_vip;
		tables[t_vip].isvip = true;
	}

	vector<Arrive> waiting_queue;
	
	int time = 0;
	while (time < 13 * 60 * 60) {

		// enter waiting queue
		Arrive a;
		if (!arrive_queue.empty() && arrive_queue.back().arrive_time == time) {
			a = arrive_queue.back();
			arrive_queue.pop_back();
			waiting_queue.push_back(a);
		}

		// update table time and player, output, update serve num
		for (int i = 1; i <= k; ++i) {
			if (tables[i].time_left > 0) {
				tables[i].time_left -= 1;
			}
		}

		for (int i = 1; i <= k; ++i) {
			if (tables[i].time_left == 0) {        // serve finished, update player
				bool istaken = false;
				if (tables[i].isvip) {             // vip priority
					for (int j = 0; j < waiting_queue.size(); ++j) {
						if (waiting_queue[j].isvip) {
							//////istaken = true;
							tables[i].time_left = waiting_queue[j].serve_time * 60;
							// update serve num
							tables[i].serve_num += 1;
							// output
							int wait_time = waiting_queue[j].wait_time / 60;
							if (waiting_queue[j].wait_time % 60) {
								wait_time += 1;
							}
							cout << time2str(waiting_queue[j].arrive_time) << " " << time2str(time) << " " << wait_time << endl;
							waiting_queue.erase(waiting_queue.begin() + j);
							break;
						}
					}
				}
				if(!istaken && !waiting_queue.empty()) {
					if (!tables[i].isvip) {
						while (!waiting_queue.empty() && waiting_queue.front().isvip) {      // vip will choose vip table first
							bool hasvip_place = false;
							for (int j = i + 1; j <= k; ++j) {
								if (tables[j].time_left == 0 && tables[j].isvip) {
									tables[j].time_left = waiting_queue.front().serve_time * 60;
									// update serve num
									tables[j].serve_num += 1;
									// output
									int wait_time = waiting_queue.front().wait_time / 60;
									if (waiting_queue.front().wait_time % 60) {
										wait_time += 1;
									}
									cout << time2str(waiting_queue.front().arrive_time) << " " << time2str(time) << " " << wait_time << endl;
									waiting_queue.erase(waiting_queue.begin());
									hasvip_place = true;
									break;
								}
							}
							if (!hasvip_place) {
								break;
							}
						}
					}
					if (!waiting_queue.empty()) {
						tables[i].time_left = waiting_queue.front().serve_time * 60;
						// update serve num
						tables[i].serve_num += 1;
						// output
						int wait_time = waiting_queue.front().wait_time / 60;
						if (waiting_queue.front().wait_time % 60) {
							wait_time += 1;
						}
						cout << time2str(waiting_queue.front().arrive_time) << " " << time2str(time) << " " << wait_time << endl;
						waiting_queue.erase(waiting_queue.begin());
					}

				}
			}
		}

		// update waiting time
		for (int i = 0; i < waiting_queue.size(); ++i) {
			waiting_queue[i].wait_time += 1;
		}

		// update time
		time++;

		/*
		int j = 0;
		for (j = 0; j < waiting_queue.size(); ++j) {
			cout << waiting_queue[j].arrive_time << " ";
		}
		if (j > 0) {
			cout << endl;
		}
		*/
	}
	
	// output serve num
	for (int i = 1; i < k; ++i) {
		cout << tables[i].serve_num << " ";
	}
	cout << tables[k].serve_num;
}

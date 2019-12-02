// 1022_Digital_Library.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Book {
	string id;
	string title;
	string author;
	vector<string> key_words;
	string publisher;
	int year;
};

Book books[10000];   // not enough space in stack

vector<string> get_keywords(string s) {
	vector<int> whitespace;
	for (unsigned i = 0; i < s.size(); ++i) {
		if (s[i] == ' ') {
			whitespace.push_back(i);
		}
	}
	vector<string> keywords;
	unsigned k = 0;
	for (unsigned i = 0; i < whitespace.size(); ++i) {
		keywords.push_back(s.substr(k, whitespace[i] - k));
		k = whitespace[i] + 1;
	}
	keywords.push_back(s.substr(k));
	return keywords;
}

int main()
{
	int n, m;
	cin >> n;   // <= 10^4
	getchar();
	string input;
	for (int i = 0; i < n; ++i) {
		getline(cin, input);
		books[i].id = input;
		getline(cin, input);
		books[i].title = input;
		getline(cin, input);
		books[i].author = input;
		getline(cin, input);
		books[i].key_words = get_keywords(input);
		getline(cin, input);
		books[i].publisher = input;
		cin >> books[i].year;
		getchar();
	}
	cin >> m;
	getchar();
	int format;
	string query;
	vector<string> queried_books;
	for (int i = 0; i < m; ++i) {
		scanf_s("%d: ", &format);
		getline(cin, query);
		queried_books.clear();
		switch (format) {
		case 1:
			for (int j = 0; j < n; ++j) {
				if (query == books[j].title) {
					queried_books.push_back(books[j].id);
				}
			}
			break;
		case 2:
			for (int j = 0; j < n; ++j) {
				if (query == books[j].author) {
					queried_books.push_back(books[j].id);
				}
			}
			break;
		case 3:
			for (int j = 0; j < n; ++j) {
				for (unsigned k = 0; k < books[j].key_words.size(); ++k) {
					if (query == books[j].key_words[k]) {
						queried_books.push_back(books[j].id);
						break;
					}
				}
			}
			break;
		case 4:
			for (int j = 0; j < n; ++j) {
				if (query == books[j].publisher) {
					queried_books.push_back(books[j].id);
				}
			}
			break;
		case 5:
			int year = stoi(query);
			for (int j = 0; j < n; ++j) {
				if (year == books[j].year) {
					queried_books.push_back(books[j].id);
				}
			}
			break;
		}
		sort(queried_books.begin(), queried_books.end());
		cout << format << ": " << query << endl;
		if (queried_books.size() == 0) {
			cout << "Not Found" << endl;
		}
		else {
			for (unsigned j = 0; j < queried_books.size(); ++j) {
				cout << queried_books[j] << endl;
			}
		}
	}
} 

#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

int n;

void go(vector<vector<char>>& v, int y, int x, int level, int pos) {
	if (pos == 4) {
		for (int i = 0; i < pow(3, level); i++) {
			for (int j = 0; j < pow(3, level); j++) {
				v[y + i][x + j] = '.';
			}
		}
		return;
	}
	if (level == 1) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				v[y + i][x + j] = '#';
				if (i==1 && j==1)	v[y + i][x + j] = '.';
			}
		}
		return;
	}
	for (int i = 0; i < 9; i++) {
		go(v, y + (i/3) * pow(3, level - 1), x + (i % 3) * pow(3, level - 1), level - 1, i);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	if (n == 0) {
		cout << '#';
		return 0;
	}
	vector<vector<char>> v(pow(3, n), vector<char>(pow(3, n)));
	go(v, 0, 0, n, -1);
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			cout << v[i][j];
		}
		cout << '\n';
	}
	return 0;
}

/*
	정수 n<=6이 주어진다.

	분할정복
*/

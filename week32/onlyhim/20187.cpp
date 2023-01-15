#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int k, h;

int convert(int val, bool isLeftRight) {
	if (isLeftRight) {
		if (val == 0)	return 1;
		if (val == 1)	return 0;
		if (val == 2)	return 3;
		if (val == 3)	return 2;
	}
	else {
		if (val == 0)	return 2;
		if (val == 1)	return 3;
		if (val == 2)	return 0;
		if (val == 3)	return 1;
	}
}

void go(vector<vector<int>>& ans, vector<char>& v, int idx, int x1, int x2, int y1, int y2) {
	if (idx == k * 2) {
		ans[x1][y1] = h;
		return;
	}
	if (v[idx] == 'R') {
		int nextX = (x1 + x2) / 2 + 1;
		go(ans, v, idx + 1, nextX, x2, y1, y2);

		int idx2 = 0;
		for (int i = y1; i <= y2; i++) {
			for (int j = x1; j < nextX; j++) {
				ans[i][j] = convert(ans[i][x2 - idx2++], 1);
			}
		}
	}
	else if (v[idx] == 'L') {
		int nextX = (x1 + x2) / 2;
		go(ans, v, idx + 1, x1, nextX, y1, y2);

		int idx2 = 0;
		for (int i = y1; i <= y2; i++) {
			for (int j = nextX+1; j <= x2; j++) {
				ans[i][j] = convert(ans[i][nextX - idx2++], 1);
			}
		}
	}
	else if (v[idx] == 'D') {
		int nextY = (y1 + y2) / 2 + 1;
		go(ans, v, idx + 1, x1, x2, nextY, y2);

		int idx2 = 0;
		for (int i = y1; i < nextY; i++) {
			for (int j = x1; j <= x2; j++) {
				ans[i][j] = convert(ans[y2 - idx2++][j], 1);
			}
		}
	}
	else if (v[idx] == 'U') {
		int nextY = (y1 + y2) / 2;
		go(ans, v, idx + 1, x1, x2, y1, nextY);

		int idx2 = 0;
		for (int i = nextY + 1; i <= y2; i++) {
			for (int j = x1; j <= x2; j++) {
				ans[i][j] = convert(ans[nextY - idx2++][j], 0);
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> k;
	vector<char> v(k*2);
	for (int i = 0; i < k * 2; i++)	cin >> v[i];
	vector<vector<int>> ans(1 << k, vector<int>(1 << k));
	cin >> h;
	go(ans, v, 0, 0, (1 << k) - 1, 0, (1 << k) - 1);
	for (int i = 0; i < 1 << k; i++) {
		for (int j = 0; j < 1 << k; j++) {
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}

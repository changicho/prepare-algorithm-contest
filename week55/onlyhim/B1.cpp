#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define TREE '^'
#define EMPTY '.'

int n, m;
int goy[4] = { -1, 0, 1, 0 };
int gox[4] = { 0, -1, 0, 1 };

bool judge(int r, int c) {
	return r >= 0 && c >= 0 && r < n && c < m;
}

void dfs(vector<vector<char>>& v, int y, int x) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + goy[i];
		int nx = x + gox[i];
		cnt += judge(ny, nx) && v[ny][nx] == TREE;
	}
	if (cnt < 2) {
		for (int i = 0; i < 4 && cnt < 2; i++) {
			int ny = y + goy[i];
			int nx = x + gox[i];
			if (judge(ny, nx) && v[ny][nx] == EMPTY) {
				v[ny][nx] = TREE;
				dfs(v, ny, nx);
				cnt++;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, r, c;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> r >> c;
		n = r, m = c;
		vector<vector<char>> v(r, vector<char>(c));
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> v[i][j];
			}
		}
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (v[i][j] == TREE)	dfs(v, i, j);
			}
		}
		int ans = 1, cnt = 0;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (v[i][j] == TREE) {
					cnt = 0;
					for (int k = 0; k < 4; k++) {
						int ny = i + goy[k], nx = j + gox[k];
						cnt += judge(ny, nx) && v[ny][nx] == TREE;
					}
					if (cnt < 2) ans = 0;
				}
			}
		}
		string ss = ans == 1 ? "Possible" : "Impossible";
		cout << "Case #" << i << ": " << ss << '\n';
		if (ans == 1) {
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					cout << v[i][j];
				}
				cout << '\n';
			}
		}
	}
}

/*
2차원 binary 배열 v가 주어진다(v[i] = 0 or 1)
v[i] = 1인 경우 인접한 상하좌우에서 v[i] = 1인 경우가 최소 2개가 되도록 v를 변경하려 한다.
불가능하면 0을 리턴, 가능하면 1을 리턴하고 그 경우를 아무거나 출력한다.

v[i]=1인 경우 dfs를 돌린다.
dfs에서는 인접한 v[i]=1인 갯수를 세고, 그 갯수가 2 이하이면 v[i]=1로 바꾸고 다시 재귀로 dfs를 돌린다.
r,c가 충분히 작고 v[i]=0 -> 1인경우만 dfs가 돌아가므로 가능하다.
O(V+E = 10^4) / O(RC)
*/

#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <set>
#include <cmath>
using namespace std;

int n, Y, X;

bool judge(int y, int x) {
	return y <= Y && x <= X;
}

void go(vector<pair<int, int>>& v, vector<vector<int>>& visit, vector<int>& used) {
	int curY = -1, curX = -1;
	for (int i = 1; i <= Y; i++) {
		for (int j = 1; j <= X; j++) {
			if (!visit[i][j]) {
				curY = i;
				curX = j;
				break;
			}
		}
		if (curY != -1)	break;
	}
	if (curY == -1 && curX == -1) {
		cout << "Yes\n";
		exit(0);
	}

	for (int bidx = 0; bidx < n; bidx++) {
		if (used[bidx])	continue;
		for (int rot = 0; rot < 2; rot++) {
			int isFit = 1, distY, distX;

			if (rot == 0)	distY = v[bidx].first, distX = v[bidx].second;
			else distY = v[bidx].second, distX = v[bidx].first;
			
			if (!judge(curY + distY - 1, curX + distX - 1))	continue;
			for (int nextY = curY; nextY <= curY + distY - 1; nextY++) {
				for (int nextX = curX; nextX <= curX + distX - 1; nextX++) {
					if (visit[nextY][nextX])	isFit = 0;
				}
			}
			if (isFit) {
				for (int nextY = curY; nextY <= curY + distY - 1; nextY++) {
					for (int nextX = curX; nextX <= curX + distX - 1; nextX++) {
						visit[nextY][nextX] = bidx + 1;
					}
				}
				used[bidx] = 1;
				go(v, visit, used);
				used[bidx] = 0;
				for (int nextY = curY; nextY <= curY + distY; nextY++) {
					for (int nextX = curX; nextX <= curX + distX; nextX++) {
						visit[nextY][nextX] = 0;
					}
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> Y >> X;
	vector<pair<int, int>> v(n);
	vector<vector<int>> visit(Y + 3, vector<int>(X + 3, 0));
	vector<int> used(n, 0);
	for (int i = 0; i < n; i++)	cin >> v[i].first >> v[i].second;
	go(v, visit, used);
	cout << "No\n";
	return 0;
}

/*
	2차원 좌표평면에서 n개의 블록조각을 회전 or 대칭시켜 모두 채울수 있는지?

	현재 위치(i,j)를 가장 왼쪽 상단의 시작점이라 할때, 회전하거나 대칭시켜면 (i+x, j+y) or (i+y, j+x)로 2가지 경우가 존재한다.
	
	dfs를 수행하면서 현재 위치의 방문여부를 확인하고, 방문한 적이 없으면 현재 위치에서 가용한 블록이 있는지 확인한다.

	https://atcoder.jp/contests/abc345/submissions/51914384
*/

#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <set>
#include <unordered_map>
#include <queue>
using namespace std;

int goy[4] = { 1, -1, 0, 0 };
int gox[4] = { 0,0,1, -1 };

struct point
{
	int y;
	int x;
	int e;
	bool operator< (const point &a) const
	{
		if (e != a.e) return e > a.e;
		else if (x != a.x) return x > a.x;
		else return y > a.y;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int h, w, n, stY, stX, enY, enX;
	cin >> h >> w;
	vector<vector<char>> v(h + 1, vector<char>(w + 1));
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> v[i][j];
			if (v[i][j] == 'S')	stY = i, stX = j;
			if (v[i][j] == 'T')	enY = i, enX = j;
		}
	}
	vector<vector<int>> visit(h + 1, vector<int>(w + 1, -1));
	vector<vector<int>> med(h + 1, vector<int>(w + 1, 0));
	cin >> n;
	for (int i = 0; i < n; i++) {
		int y, x, val;
		cin >> y >> x >> val;
		med[y][x] = val;
	}
	//set<point> q;
	priority_queue<point> q;
	q.push({ stY, stX, med[stY][stX] });
	while (!q.empty()) {
		point qtop = q.top();
		q.pop();
		int cy = qtop.y, cx = qtop.x, ccost = qtop.e;
		if (cy == enY && cx == enX) {
			cout << "Yes";
			return 0;
		}
		if (ccost == 0)	continue;
		visit[cy][cx] = max(ccost, visit[cy][cx]);
		for (int i = 0; i < 4; i++) {
			int ny = cy + goy[i], nx = cx + gox[i];
			if (ny < 1 || ny > h || nx < 1 || nx > w || v[ny][nx] == '#')	continue;
			int ncost;
			if (med[ny][nx]) {
				ncost = max(ccost - 1, med[ny][nx]);
			}
			else {
				ncost = ccost-1;
			}
			if (visit[ny][nx] >= ccost)	continue;
			visit[ny][nx] = ccost;
			q.push({ ny, nx, ncost  });
		}
	}
	cout << "No";
	return 0;
}

/*
	2차원 평면에서 i,j -> I,J로 이동하려고 한다.상하좌우로 이동가능하며 에너지가 1씩 감소한다.
	만약 이동하려는 곳에 med이 있으면 현재 에너지를 그 med값으로 변경 가능하다. I,J로 이동이 가능한가?

	visit[i][j] = (i, j)에 도착했을 때 최대 에너지 -> 
	1. 이동하려는 곳에 med가 없으면 현재 비용을 소모하여 이동한다.
	2. 이동하려는 곳에 med가 있으면 (현재 비용 -1, med) 중 최대값을 현재 비용으로 가정한다.
	3. visit[ny][nx]가 이미 현재비용보다 크면 이동하는 것이 손해.
	4. visit값 갱신하고 q push
	5. queue를 쓰면 TLE

	priority_queue 쓰면 TLE, set쓰면 pass??
*/

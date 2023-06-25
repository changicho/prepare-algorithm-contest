#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct node {
	node(int Y, int X, int V) : y(Y), x(X), val(V) {}
	int y, x, val;
};

struct cmp {
	bool operator()(node a, node b) {
		if (a.val == b.val) {
			if (a.y == b.y)	return a.x > b.x;
			return a.y > b.y;
		}
		return a.val > b.val;
	}
};

int goy[4] = { 1, -1, 0, 0 };
int gox[4] = { 0,0,1, -1 };
int judgeY[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int judgeX[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

int convert(char a) {
	return a == 'E' ? 0 : a == 'P' ? 1 : 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<char>> v(n, vector<char>(m));
	vector<vector<bool>> visit(n, vector<bool>(m, 0));
	priority_queue<node, vector<node>, cmp> pq;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
			if (v[i][j] == 'S') {
				pq.push(node(i, j, 0));
				visit[i][j] = 1;
			}
		}
	}
	int ans = 0;
	while (!pq.empty()) {
		node cur = pq.top();
		pq.pop();
		int curY = cur.y, curX = cur.x, curV = cur.val;
		if (v[cur.y][cur.x] == 'E')	break;
		int cost = v[curY][curX] == 'P' ? -3 : 0;
		for (int i = 0; i < 8 && v[curY][curX] != 'S'; i++) {
			int ny = curY + judgeY[i], nx = curX + judgeX[i];
			if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
				if (v[ny][nx] == 'P')	cost++;
			}
		}
		ans += cost;
		for (int i = 0; i < 4; i++) {
			int ny = curY + goy[i], nx = curX + gox[i];
			if (ny >= 0 && ny < n && nx >= 0 && nx < m && visit[ny][nx] == 0) {
				visit[ny][nx] = 1;
				pq.push(node(ny, nx, convert(v[ny][nx])));
			}
		}
	}
	cout << max(ans, 0) << '\n';
}

#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <set>
#include <cmath>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <climits>
#include <tuple>
using namespace std;

int goy[4] = { 1, -1, 0, 0 };
int gox[4] = { 0, 0, 1, -1 };
int dp[505][505][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, dy, dx;
    cin >> n >> m;
	vector<vector<char>> v(n, vector<char>(m));
    vector<vector<vector<int>>> dp(
        505, vector<vector<int>>(505, vector<int>(2, 1e9))
    );

    queue<vector<int>> q;
    for (int i=0; i < n; i++) {
        for (int j=0; j < m; j++) {
            cin >> v[i][j];
            if (v[i][j] == 'S') q.push({ i, j, 0, 0 });
            if (v[i][j] == 'G') dy = i, dx = j;
		}
	}
    int ans = 1e9;
    while (!q.empty()) {
        vector<int> cur = q.front();
        q.pop();
        int cy = cur[0], cx = cur[1], cost = cur[2], cstat = cur[3];
        if (cy == dy && cx == dx)   ans = min(ans, cost);

        for (int i = 0; i < 4; i++) {
            int ny = cy + goy[i], nx = cx + gox[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m || v[ny][nx] == '#') continue;
            if (cstat == 0 && v[ny][nx] == 'x') continue;
            if (cstat == 1 && v[ny][nx] == 'o') continue;
            if (dp[ny][nx][cstat] <= cost + 1) continue;

            dp[ny][nx][cstat] = cost + 1;
            if (v[ny][nx] == '?') {
                q.push({ ny, nx, cost + 1, !cstat });
            }
            else
                q.push({ ny, nx, cost + 1, cstat });
        }
    }

    if (ans == 1e9) cout << -1;
    else cout << ans;

    return 0;
}

/*
* 스위치를 2번 누르면 원복이므로 최대 1번
* visit[i][j][k] = 현재 위치 (i,j)에서 스위치 상태가 k일때의 최소 이동횟수
* 
*/

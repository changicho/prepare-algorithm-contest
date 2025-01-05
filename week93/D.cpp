#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <set>
#include <cmath>
#include <queue>
using namespace std;

int n,m,sty, stx, dsy, dsx;

int goy[2][2] = { {-1, 1}, {0, 0} };
int gox[2][2] = { {0, 0}, {-1, 1} };
int dp[1003][1003][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cnt = 0;
    cin >> n >> m;
    vector<vector<char>> v(n+3, vector<char>(m+3));
    for (int i = 0; i < 1003; i++)  for (int j = 0; j < 1003; j++)  dp[i][j][0] = dp[i][j][1] = 1e9;
    priority_queue<vector<int>> pq;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
            if (v[i][j] == 'S') sty = i, stx = j;
            else if (v[i][j] == 'G') dsy = i, dsx = j;
        }
    }

    pq.push({ 0, sty, stx, 0 });
    pq.push({ 0, sty, stx, 1 });
    dp[sty][stx][0] = 0;
    dp[sty][stx][1] = 0;

    while (!pq.empty()) {
        vector<int> cur = pq.top();
        pq.pop();
        int curCost = -cur[0], cy = cur[1], cx = cur[2], cDir = cur[3];
        if (cy == dsy && cx == dsx) 
            return -curCost;

        int nDir = !cDir;
        for (int i = 0; i < 2; i++) {
            int ny = cy + goy[nDir][i], nx = cx + gox[nDir][i];
            if (ny < 1 || nx < 1 || ny > n || nx > m || v[ny][nx] == '#' || dp[ny][nx][nDir] <= curCost + 1)   continue;
            dp[ny][nx][nDir] = curCost + 1;
            pq.push({ -(curCost + 1), ny, nx, nDir});
        }
    }

    return -1;
}

/*
*/

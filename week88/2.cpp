#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;

int n, m;
int goy[4] = { 1, -1, 0, 0 };
int gox[4] = { 0,0,1, -1 };

int go(vector<vector<int>>& v, vector<vector<int>>& visit, int y, int x) {
    int ret = 1;
    visit[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = goy[i] + y, nx = gox[i] + x;
        if (ny < 0 || nx < 0 || ny >= n || nx >= m || visit[ny][nx] || v[ny][nx] != 1) continue;
        ret += go(v, visit, ny, nx);
    }
    return ret;
}

void go2(vector<vector<int>>& v, vector<int>& visit, vector<int>& chk, int y, int x, int oils) {
    if (visit[x] == 0)  chk[x] += oils;
    visit[x] = 1;
    v[y][x] = -1;
    for (int i = 0; i < 4; i++) {
        int ny = goy[i] + y, nx = gox[i] + x;
        if (ny < 0 || nx < 0 || ny >= n || nx >= m || v[ny][nx] != 1) continue;
        go2(v, visit, chk, ny, nx, oils);
    }
}

int solution(vector<vector<int>> v) {
    int ans = 0;
    n = v.size(), m = v[0].size();
    vector<vector<int>> visit(n, vector<int>(m, 0));
    vector<int> cnt(m, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] && visit[i][j] == 0) {
                int numOil = go(v, visit, i, j);
                vector<int> visitColumn(m, 0);
                go2(v, visitColumn, cnt, i, j, numOil);
            }
        }
    }
    for (int i = 0; i < m; i++) ans = max(ans, cnt[i]);
    return ans;
}

/*
  bfs 1번돌고 oil 갯수를 계산하고, 1번 더 돌아서 column마다 얻을 수 있는 oil 갯수를 누적한다. 
  O(n+m) / O(nm)
*/

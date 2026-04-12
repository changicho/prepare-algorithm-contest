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
#include <iomanip>
#include <array>
#include <bit>
#include <cmath>

using namespace std;

struct node {
    int y, x, dir;
};

int h, w;
int goy[4] = { 1, -1, 0, 0 };
int gox[4] = { 0, 0, 1, -1 };
char gogo[4] = { 'D', 'U', 'R', 'L' };
string ans;
bool isend;
bool visit[1005][1005][5];
node parent[1005][1005][5];

bool chk(int y, int x) {
    return y >= 0 && x >= 0 && y < h && x < w;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> h >> w;
	vector<vector<char>> v(h, vector<char>(w));
	queue<vector<int>> q;


    int sty, stx, ly, lx, ld;
    isend = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> v[i][j];
            if (v[i][j] == 'S') {
                q.push({ i, j, 0, 0});
			}
        }
    }

    while (!q.empty()) {
        vector<int> cur = q.front();
        q.pop();

        int cy = cur[0], cx = cur[1], cd = cur[2], cost = cur[3];
        int ny, nx;

        if (cost > 5000000 || isend)
            continue;
        if (v[cy][cx] == 'G') {
            isend = 1;
            ly = cy, lx = cx, ld = cd;
            continue;
        }

        if (v[cy][cx] == 'S' || v[cy][cx] == '.') {
            for (int i = 0; i < 4; i++) {
                ny = cy + goy[i], nx = cx + gox[i];
                if (chk(ny, nx) && visit[ny][nx][i] == 0) {
                    parent[ny][nx][i] = { cy, cx, cd };
                    visit[ny][nx][i] = 1;
                    q.push({ ny, nx, i, cost+1 });
                }
            }
        }
        else if (v[cy][cx] == 'o') {
            ny = cy + goy[cd], nx = cx + gox[cd];
            if (chk(ny, nx) && visit[ny][nx][cd] == 0) {
                parent[ny][nx][cd] = { cy, cx, cd };
                visit[ny][nx][cd] = 1;
                q.push({ ny, nx, cd, cost + 1 });
            }
        }
        else if (v[cy][cx] == 'x') {
            for (int i = 0; i < 4; i++) {
                if (i == cd)    continue;
                ny = cy + goy[i], nx = cx + gox[i];
                if (chk(ny, nx) && visit[ny][nx][i] == 0) {
                    parent[ny][nx][i] = { cy, cx, cd };
                    visit[ny][nx][i] = 1;
                    q.push({ ny, nx, i, cost + 1 });
                }
            }
        }
    }

    if (isend) {
        cout << "Yes\n";
        while (1) {
            ans += gogo[ld];
            struct node cur = parent[ly][lx][ld];
            if (v[cur.y][cur.x] == 'S') break;
            ly = cur.y;
            lx = cur.x;
            ld = cur.dir;
        }
        for (int i = ans.size() - 1; i >= 0; i--)   cout << ans[i];
    }
    else
        cout << "No\n";

    return 0;
}
 
/*
* 정수배열 v가 주어진다
* v[i]는 -1씩 1번의 연산
* 
* 
*/

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

using namespace std;

int n, m;
int popcount(uint32_t x) {
    int cnt = 0;
    while (x) {
        cnt += x & 1;   // 마지막 비트가 1이면 +1
        x >>= 1;        // 오른쪽으로 1비트 시프트
    }
    return cnt;
}


int go(vector<int>& v, vector<vector<int>>& dp, vector<vector<bool>>& black, int y, int prvstat, int maxstat) {
    if (y == n) return 0;
    int& ret = dp[y][prvstat];
    if (ret != -1)  return ret;

    ret = 1e9;

    for (int curstat = 0; curstat < maxstat; curstat++) {
        // 내가 만드려는 2x2 stat중 all black이 있는 경우 continue
        if (y > 0 && black[prvstat][curstat] == 0)  continue;
        // 입력으로 주어진 배열의 현재 상태(=v[y])와 내가 전환하려는 상태(=curstat)에서 white->black으로 전환하는 경우가 있으면 continue
        if ((v[y] & curstat) != curstat)    continue;

        // 몇개의 cell을 black으로 바꿀지? = 1인 비트 갯수 세기
        int cost = popcount(v[y] ^ curstat);
        ret = min(ret, go(v, dp, black, y + 1, curstat, maxstat) + cost);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++) {
            string str;
            cin >> str;
            for (int j = 0; j < m; j++) if (str[j] == '#')   v[i] |= (1 << j);
        }
        int maxstat = (1 << m);
        // allow[i][j] = 현재 행과 다음 행의 상태가 각각 i, j일 때, 2x2 all black subrid가 있으면 allow[i][j] = 0
        vector<vector<bool>> allow(maxstat, vector<bool>(maxstat, 1));
        for (int i = 0; i < maxstat; i++) {
            for (int j = 0; j < maxstat; j++) {
                for (int k = 0; k + 1 < m; k++) {
                    bool y1 = (i >> k) & 1, y2 = (i >> (k + 1)) & 1;
                    bool x1 = (j >> k) & 1, x2 = (j >> (k + 1)) & 1;
                    if (y1 && y2 && x1 && x2) {
                        allow[i][j] = 0;
                        break;
                    }
                }
            }
        }
        //dp[i][s] = 현재 행이 i이고 상태가 s일 때 조건을 만족하는 최소 연산 횟수
        // s = 2 ^ m인 cell의 상태
        vector<vector<int>> dp(n, vector<int>(maxstat, -1));
        go(v, dp, allow, 0, 0, maxstat);
        cout << dp[0][0] << '\n';
    }

    return 0;
}

/*
n*m의 2차원 배열이 주어진다. 이 배열은 black or white로 구성된다. 
1번의 연산으로 black<->white로 전환 가능하다.
모든 2x2의 subgrid중 최소 1개의 grid가 white임을 만족하기 위한 최소 연산 횟수는?

그리디 반례 (정답-3)
#####
#####
#####



1. allow 테이블을 생성한다. 이를 통해 순회시 현재 상태 + 다음 상태가 2x2 black subgrid가 있는지 빠르게 확인 가능
2. 각 행마다 순회하면서 현재 상태 + 다음상태가 2x2 black subgrid가 없는 경우, 연산 횟수를 더해가면서 dp 배열 생성


*/

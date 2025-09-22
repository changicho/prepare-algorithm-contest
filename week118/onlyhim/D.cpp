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

using namespace std;

int goy[4][4] = { {-1, -1, 0, 0}, {-1, -1, 0, 0}, {0, 0, 1, 1}, {0, 0, 1, 1} };
int gox[4][4] = { {-1, 0, 0, -1}, {1, 0, 0, 1}, {-1, 0, 0, -1}, {1, 0, 0, 1} };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
		vector<vector<char>> v(n, vector<char>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
				cin >> v[i][j];
            }
        }
        vector<vector<int>> dp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int cy = i, cx = j;
                int blackcnt = 0;
                for (int k = 0; k < 4; k++) {
                    bool areagood = 1;
                    int black = 0;
                    for (int l = 0; l < 4; l++) {
                        int ny = cy + goy[k][l], nx = cx + gox[k][l];
                        if (ny < 0 || nx < 0 || ny >= n || nx >= m) { areagood = 0; continue; }
                        if (v[ny][nx] == '#')   black++;
                    }
                    if (areagood && black == 4)   blackcnt++;
                }
                int convPos = (i << 4) | j;
                if (blackcnt) dp.push_back({ blackcnt, i, j });
            }
        }
        int ans = 0;
        while (dp.size()) {
            sort(dp.begin(), dp.end(), greater<>());
            if (dp[0][0] == 0)   break;
            int y = dp[0][1], x = dp[0][2];
            ans++;
            for (int i = 0; i < dp.size(); i++) {
                int ny = dp[i][1], nx = dp[i][2];
                if (y - 1 <= ny && y + 1 >= ny && x - 1 <= nx && x + 1 >= nx)   dp[i][0]= 0;
            }
        }
        cout << ans<<'\n';
    }

    return 0;
}
 
/*
* 현재 위치를 x,y라 할 때 x,y를 포함하는 2x2 그리드 4개중 모두 black인 갯수를 확인
* 이 갯수를 내림차순 정렬하여 greedy하게 black으로 바꿔나감
* WA
*/

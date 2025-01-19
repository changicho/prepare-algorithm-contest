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

int goy[2][2] = { {-1, 1}, {0, 0} };
int gox[2][2] = { {0, 0}, {-1, 1} };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, m, ans;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> m;
        ans = m*4;
        vector<pair<int, int>> v(n);
        for (int j = 0; j < n; j++) cin >> v[j].first >> v[j].second;
        for (int j = 1; j < n; j++) {
            ans += m * 4;
            if (v[j].first >= m || v[j].second >= m)  continue;
            ans -= (m - v[j].first) * 2;
            ans -= (m - v[j].second) * 2;
        }
        cout << ans << '\n';
    }
    return 0;
}

/*
1. 모든 square의 지름을 더한다 (m*4)
2. 이동을 통해 중복 영역이 발생하는 부분의 지름을 뺀다.
*/

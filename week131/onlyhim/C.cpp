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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, t, lastClose, val, ans = 0;
    cin >> n >> t;
    lastClose = 0;
    if (n == 0) {
                cout << t << '\n';
				return 0;
    }
    for (int i = 0; i < n; i++) {
        cin >> val;
        if (lastClose == 0) {
            ans += val;
            lastClose = val;
        }
        else {
            if (lastClose + 100 <= val) {
				ans += val - lastClose - 100;
                lastClose = val;
            }
        }
    }
    if (lastClose + 100 <= t) {
        ans += t - lastClose - 100;
    }
    cout << ans << '\n';
    return 0;
}
 
/*
* val을 최근 방문 시점이라 하자. 
* 마지막 close+100 <= val이면 정답에 더해간다
* 
*/

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

    int n;
    cin >> n;
	vector<int> v(n);
    map<int, int> dp;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
	}

    for (int i = 0; i < n; i++) {
		dp[v[i]] = max(0, dp[v[i] - 1] + 1);
    }

    int ans = 0;
    for (auto i : dp) {
        ans = max(ans, i.second);
	}
    cout << ans << "\n";
	return 0;
}
 
/*
주어진 정수 배열에서 v[i+1] = v[i]+1인 subsequence의 max길이를 계산해라
dp 점화식 dp[v[i]] = max(0, dp[v[i] - 1] + 1);
*/

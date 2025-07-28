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
using namespace std;

void go(vector<string>& v, vector<string>& dp, string str, int cnt) {
    if (cnt == 0) {
        dp.push_back(str);
        return;
    }

    for (int i = 0; i < v.size(); i++) {
        go(v, dp, str + v[i], cnt - 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k, x;
    cin >> n >> k >> x;
    vector<string> v(n);
    vector<string> dp;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    go(v, dp, "", k);
    sort(dp.begin(), dp.end());
    cout << dp[x-1];

    return 0;
}

/*
* n^k <= 10^5이므로, 전부 만들어서 정렬하면 O(nlogn)
*/

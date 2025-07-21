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

int go(int visit, string& str, vector<int>& dp, int n, int idx) {
    if (visit == ((1 << n) - 1)) {
        return 1;
    }
    int& ret = dp[visit];
    if (ret != -1)  return ret;
    
    ret = 0;
    for (int i = 0; i < n; i++) {
        if (visit & (1 << i)) continue;
        int cur = (visit) | (1 << i);
        if (str[cur] == '1')    continue;

        ret |= go(cur, str, dp, n, i);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;
    cin >> t;
    while (t--) {
        string str;
        cin >> n >> str;
        str = '0' + str;
        int visit = 0;
        vector<int> dp((1 << n), -1);
        int ans = go(visit, str, dp, n, -1);
        if (ans)    cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}

/*
* n<=18, |s| <= 10^5, t<=10^4
* dp[i] = visit 상태가 i일때의 값
*/

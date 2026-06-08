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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, m;
    cin >> n >> k >> m;
    vector<pair<int, int>> v(n);
    set<int> sets;
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        int c, val;
        cin >> c >> val;
        v[i] = {val, c};
    }
    sort(v.begin(), v.end());
    for (int i = n - 1; i >= 0 && m; i--) {
        if (sets.find(v[i].second) == sets.end()) {
            sets.insert(v[i].second);
            m--;
            k--;
            ans += v[i].first;
			v[i].first = 0;
        }
    }
    for (int i = n - 1; i >= 0 && k; i--) {
        if (v[i].first > 0) {
            k--;
			ans += v[i].first;
        }
    }
    cout << ans;
    return 0;

}
 
/*
*

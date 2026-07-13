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

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<pair<int, int>> queries(m);
    for (int i = 0; i < m; ++i) {
        cin >> queries[i].first >> queries[i].second;
    }

    set<int> visited_rows;
    set<int> visited_cols;
    int ans = 0;

    for (int i = m - 1; i >= 0; --i) {
        int r = queries[i].first;
        int c = queries[i].second;

        if (visited_rows.find(r) == visited_rows.end() && visited_cols.find(c) == visited_cols.end()) {
            ans++;
        }

        visited_rows.insert(r);
        visited_cols.insert(c);
    }

    cout << ans << "\n";

    return 0;
}
 
/*
* 뒤에서부터 순회하면서 한번도 등장하지 않은 r,c인 경우만 끝까지 살아남을 수 있다.
* O(n)
*/

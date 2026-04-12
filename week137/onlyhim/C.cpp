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
int ans;

void go(vector<int>& v, double cur, int point, int idx) {
    if (idx == v.size()) {
        ans = max(ans, point);
        return;
    }
    if (cur < 0 && cur + v[idx] >= 0)  go(v, cur + v[idx], point + 1, idx + 1);
	else go(v, cur + v[idx], point, idx + 1);

    if (cur > 0 && cur - v[idx] <= 0)  go(v, cur - v[idx], point + 1, idx + 1);
    else go(v, cur - v[idx], point, idx + 1);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> v(n);
    ans = 0;
    for (int i = 0; i < n; i++) {
		cin >> v[i];
    }
    go(v, 0.5, 0, 0);
	cout << ans;

    return 0;
}
 
/*
*/

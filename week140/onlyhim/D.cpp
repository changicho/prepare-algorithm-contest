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
    
    long long n, k, l,r, ans;
    cin >> n >> k;
    vector<long long> v(n+1);
    ans = -1;
    l = 1e18, r = -1;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        l = min(l, v[i]);
        r = max(r, v[i] + (i * k));
    }
    while (l <= r) {
        long long mid = (l + r) / 2;
        long long cnt = k;
        int i = 1;
        for (i = 1; i <= n && cnt >= 0; i++) {
            if (v[i] >= mid)    continue;
            long long q = mid - v[i];
            cnt -= q % i == 0 ? q / i : q / i + 1;
        }
        if (i >= n && cnt >= 0) {
            ans = max(ans, mid);
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << ans << '\n';
    return 0;

}
 
/*
* 이분탐색으로 연산 종료 후에 v[i]의 최소값이 조건을 만족하는지 확인한다.
* O(nlogk)
* 
*/

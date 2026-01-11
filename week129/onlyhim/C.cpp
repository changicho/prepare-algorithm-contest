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

    int t;
    cin >> t;
    while (t--) {
        long long ans = 0, cur;
        int n, w;
        cin >> n >> w;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
		int w2 = w * 2;
        vector<long long> group(w2, 0);
        for (int i=0; i<n; i++) {
			group[i % w2] += v[i];
		}

        for (int i = 0; i < w; i++) ans += group[i];
        cur = ans;
        for (int i = 1; i < w2; i++) {
            cur -= group[i - 1];
            cur += group[(i + w - 1) % w2];
            ans = min(ans, cur);
        }

        cout << ans << '\n';
    }

    return 0;
}
 
/*
* 임의의 양수 x를 고르고 (i+x) / 2w 의 나머지가 w보다 작은 i의 sum(c[i])가 최소인 경우
* 0~w-1씩 연속된 그룹을 고른다.
* 
* 1씩 증가하므로, 나머지 값은 항상 circular하게 변한다.(0 -> 1 -> ... -> w-1 -> 0 -> ...)
* 
*/

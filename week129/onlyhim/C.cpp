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
* 임의의 양수 x를 고르고 (i+x) / 2w 의 나머지가 w보다 작은 i의 sum(c[i])가 최소인 경우를 구해라

8 2
1 10 10 1 1 10 10 1
일 때, w=2, 2w = 4이므로
나머지는 0,1,2,3중 1개이고 나머지 0,1일 때가 선택된다.
배열의 값이 1,2,3... 이므로 나머지는 항상 +1씩 증가한다.
x를 자유롭게 선택할 수 있다 = 그룹을 슬라이딩하면서 선택할 수 있다.

group0: positions 4, 8 → costs 1+1 = 2
group1: positions 1, 5 → 1+1 = 2
group2: positions 2, 6 → 10+10 = 20
group3: positions 3, 7 → 10+10 = 20

0	2+2 = 4     --> 1,4,5,8 선택
1	2+20 = 22   --> 1,2,5,6 선택
2	20+20 = 40  --> 2,3,6,7 선택
3	20+2 = 22   --> 3,4,7,8 선택

*
*/

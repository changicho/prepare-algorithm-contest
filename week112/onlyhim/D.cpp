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

long long min_mod_sum(vector<int>& a, vector<int>& b, int m) {
    multiset<int> ms(a.begin(), a.end());
    long long total = 0;

    for (int i = 0; i < b.size(); ++i) {
        int target = (m - b[i]) % m;
        auto it = ms.lower_bound(target);

        if (it == ms.end()) {
            // 가장 작은 값 사용
            it = ms.begin();
        }

        total += (*it + b[i]) % m;
        ms.erase(it);
    }
    return total;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        vector<int> b(n);

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i <n; i++) cin >> b[i];
        long long ans = min_mod_sum(a, b, m);
        cout << ans << '\n';

    }


    return 0;
}

/*
a는 재배열, b는 고정이다. a[i] + b[i] % m 의 최소값을 그리디 하게 찾는다.
a를 오름차순 정렬시키고, m - b[i] % m를 a에서 이분탐색으로 찾는다.
즉
m = 10, b[i] = 3 일 때 7이 가장 작은값
m = 10, b[i] = 15 일 때 5가 가장 작은값
O(nlogn)에 해결 가능
*/

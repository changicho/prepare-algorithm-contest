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
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
	vector<int> cnt(n, 0);
    vector<int> psum(n, 0);
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        cnt[x]++;
        cnt[y+1]--;
	}
    psum[0] = cnt[0];
    for (int i = 1; i < n; i++) {
		psum[i] += psum[i - 1] + cnt[i];
    }
    string ans;
    for (int i=0; i < n; i++) {
        if (psum[i] % 2 == 0) {
			ans += s[i];
        } else {
            ans += t[i];
        }
	}
    cout << ans << "\n";
    return 0;
}

/*
* 현재 위치를 a[i]라 할 때, a[i]의 swap 횟수가 홀수면 b[i], 짝수면 그대로 a[i]이다.
* 따라서 각 인덱스별 swap 횟수를 계산해놓는다.
* 
*/

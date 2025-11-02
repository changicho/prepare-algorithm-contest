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

	long long ans = 0;
    int n, a, b;
    cin >> n >> a >> b;
    string str;
    cin >> str;
	str = " " + str; // 1-indexed
    vector<int> psumA(n + 1, 0);
    vector<int> psumB(n + 1, 0);
    for (int i=1; i<=n; i++) {
        psumA[i] = psumA[i - 1];
        psumB[i] = psumB[i - 1];
        if (str[i] == 'a') psumA[i]++;
		else if (str[i] == 'b') psumB[i]++;
	}
   
    for (int i=1; i<=n; i++) {
        int l = i, r = n;
        int r1 = 1e9, r2 = -1;
        while (l<=r) {
            int m = (l + r) / 2;
            if (psumA[m] - psumA[i - 1] >= a) {
                r1 = min(r1, m);
                r = m - 1;
            }
            else l = m + 1;
        }
        l = i, r = n;
        while (l <= r) {
            int m = (l + r) / 2;
            if (psumB[m] - psumB[i - 1] < b) {
                r2 = max(r2, m);
                l = m + 1;
            }
            else 
                r = m - 1;
        }
		ans += max(0, r2 - r1 + 1);
	}
    cout << ans;
    return 0;
}
 
/*
* v[l..r]의 문자 a의 갯수가 A와 같거나 크다
* v[l..r]의 문자 b의 갯수가 B보다 작다
* 
* 모든 l에 대해 각각 가능한 r의 갯수를 더한다
* 1. v[l..r]에서 a의 갯수 >= A를 만족하는 최소 r인 r1
* 2. v[l..r]에서 b의 갯수 < B를 만족하는 최대 r인 r2
* ans += max(0, r2 - r1 + 1)
* 
*/

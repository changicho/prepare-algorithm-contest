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
    cin.tie(nullptr);

    long long ans = 0;
    int n, L, R;
	cin >> n >> L >> R;
    string str;
    cin >> str;
    vector<vector<int>> v(26);

    for (int i = 0; i < n; i++)
        v[str[i] - 'a'].push_back(i);

    for (int c = 0; c < 26; c++) {
        auto& vec = v[c];

        for (int i = 0; i < vec.size(); i++) {
            int left = vec[i] + L;
            int right = vec[i] + R;

            auto l = lower_bound(vec.begin(), vec.end(), left);
            auto r = upper_bound(vec.begin(), vec.end(), right);

            ans += r - l;
        }
    }

    cout << ans << "\n";
    return 0;
}
 
/*
소문자 문자열 s, 정수 l,r이 주어진다.
s[i] = s[j]이고, l <= |j-i| <= r인 경우의 수를 계산해라

v[i] = s[i]가 등장한 위치의 vector
v는 이미 순서대로 정렬되어 있으므로, 이분탐색으로 갯수만큼 카운팅한다.
*/

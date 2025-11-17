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
using ll = long long;

ll mod_norm(ll a, ll m) {
    ll r = a % m;
    if (r < 0) r += m;
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    long long X, Y;
    cin >> N >> X >> Y;
    vector<long long> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];

    ll d = Y - X;
    ll r = mod_norm(v[0] * X, d);
    for (int i = 1; i < N; i++) {
        if (mod_norm(v[i] * X, d) != r) {
            cout << -1 << "\n";
            return 0;
        }
    }

    ll L = LLONG_MIN, R = LLONG_MAX;
    for (int i = 0; i < N; i++) {
        ll low = v[i] * X;
        ll high = v[i] * Y;
        L = max(L, low);
        R = min(R, high);
    }

    // 최대 K <= R with K % d == r
    ll delta = mod_norm(R - r, d); // 0..d-1
    ll K = R - delta;
    if (K < L) {
        cout << -1 << "\n";
        return 0;
    }

    // compute total large candies
    long long totalLarge = 0;
    for (int i = 0; i < N; i++) {
        totalLarge += (K - v[i] * X) / d;
    }
    cout << totalLarge << "\n";
    return 0;
}

/*
* 작은사탕, 큰사탕의 무게 a,b가 주어진다.
* 정수 배열 v[i] = x라 한다.
1. (작은사탕 갯수 + 큰사탕 갯수) = x
2. x= y+z라 할 때, a * y + b * z가 모든 v[i]=x에서 같아야 한다.
위 조건을 만족하는 경우중 큰사탕의 갯수가 가장 많은 경우를 계산해라

a=6,b=8
v[i] = 11,10,13
v[0] = 4/7, 4*6+7*8 = 80
v[1] = 0/10, 10*8 = 80
v[2] = 12/1, 12*6+1*8 = 80
답은 7+10+1 = 18

총 무게를 W, 각 아이의 사탕 갯수를 s[i],b[i]라 할때
1. s[i] = v[i] - b[i]
2, W = s[i]*a + b[i]*b 
     = (v[i] - b[i])* a + b[i]*b 
     = b[i]*(b-a) + v[i]*a
여기서 b[i]를 옮기면
3. b[i] = (W - v[i]*a) / (b-a)
b[i]가 양의 정수이므로 (W - v[i]*a) / (b-a)가 나누어 떨어져야 한다
W-v[i]*a = 0 (mod b-a)이므로 W를 (b-a)로 나눈 나머지가 v[i]*a 로 나눈 나머지와 같아야 함
이러한 W는 가장 큰 1개만 존재해야 하므로 가장 큰 W = v[i] * b아래로 찾는다.

*/

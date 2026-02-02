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
        long long ans = 0;
        int n, minVal = 1e9;
        cin >> n;
        vector<int> v(n);
        vector<int> lft(n);
        vector<int> rgt(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        lft[0] = v[0];
        for (int i = 1; i < n; i++) {
            lft[i] = min(lft[i - 1] + 1, v[i]);
        }
        rgt[n-1] = v[n-1];
        for (int i = n - 2; i >= 0; i--) {
            rgt[i] = min(rgt[i + 1] + 1, v[i]);
        }

        for (int i = 0; i < n; i++) ans += v[i] - min(lft[i], rgt[i]);

        cout << ans << '\n';
    }


    return 0;
}

/*
* 정수배열 v가 주어진다.
* 1번의 연산으로 v[i] -= 1을 할 수 있다.
* 인접한 | v[i] - v[i+1] | <= 1이 될 수 있는 최소 연산 횟수를 계산해라
* 
* v[i]는 항상 감소해야 한다. 따라서
* 1. 최소 값을 찾는다
* 2. 최소 값 인접한 값을 v[i]+1로 맞춘다.
* 3. 다시 최소 값을 찾는다
* 
* 반례
1
5
3 10 1 10 3

연산의 횟수를 최소화 하기 위해, v[i]는 최대로 유지해야 한다.
왼쪽->오른쪽 순회, 오른쪽->왼쪽 순회하면서 생기는 최소값을 찾는다.
*/

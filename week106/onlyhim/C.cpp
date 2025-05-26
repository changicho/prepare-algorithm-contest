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

void go() {
    int n;
    cin >> n;
    vector<int> l(n), r(n), v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++) cin >> l[i] >> r[i];

    int curleft = 0;
    vector<int> last;
    for (int i = 0; i < n; i++) {
        if (v[i] == -1) last.push_back(i);
        else curleft += v[i];

        while (curleft < l[i]) {
            if (last.empty()) {
                cout << "-1\n";
                return;
            }
            v[last.back()] = 1;
            last.pop_back();
            curleft++;
        }

        while (curleft + last.size() > r[i]) {
            if (last.empty()) {
                cout << "-1\n";
                return;
            }
            v[last.back()] = 0;
            last.pop_back();
        }
    }
        for (auto i : v)    cout << max(0, i) << ' ';
        cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        go();
    }

    return 0;
}

/*
* 정수배열 v가 주어진다.v[i] = 0, 1, -1중 하나이며 -1은 0or1로 변경할 수 있다.
* 정수 sum은 v[i]의 누적 합이다. (sum += v[i])
* n개의 정수쌍 l,r가 주어진다. l[i] <= sum <= r[i]를 모두 만족하는 경우가 존재하는가?
* 
* 조건 1. 현재 left >= l[i]를 만족해야 한다.
*/

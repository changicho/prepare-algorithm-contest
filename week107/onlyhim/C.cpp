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
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, val, ans = 0, last;
        cin >> n;
        vector<int> v;
        for (int i = 0; i < n; i++) {
            cin >> val;
            if (!v.empty()) {
                if (v.back() == val || (v.size() >= 2 && v[v.size() - 2] + 1 == v.back() && v.back() + 1 == val))    v.pop_back();
            }
            v.push_back(val);
        }
        
        last = v[0];
        for (int i = 1; i < v.size(); i++) {
            if (last + 1 < v[i]) {
                ans++;
            }
            last = v[i];
        }
        cout << ans +1 << '\n';
    }

    return 0;
}

/*
    v[i] == v[i+1]인 경우, 항상 새로운 배열이 추가될 수 없으므로 제거한다.
    v[i] + 1 == v[i+1] && v[i+1] + 1 == v[i+2] 인 경우 v[i+1]을 제거한다.

*/

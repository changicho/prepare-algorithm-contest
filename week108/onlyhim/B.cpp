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

    int t = 1;
    
    while (t--) {
        int n, q, val;
        cin >> n >> q;
        vector<int> v(n + 1, 0);
        for (int i = 0; i < q; i++) {
            cin >> val;
            if (val == 0) {
                int mins = 1e9, idx=1;
                for (int j = 1; j <= n; j++) {
                    if (mins > v[j]) {
                        mins = v[j];
                        idx = j;
                    }
                }
                v[idx]++;
                cout << idx << ' ';
            }
            else {
                v[val]++;
                cout << val << ' ';
            }
        }
    }

    return 0;
}

/*
    우선순위; 1. 값이 작을수록 2. 인덱스가 작을수록
    O(nq) / O(n)
*/

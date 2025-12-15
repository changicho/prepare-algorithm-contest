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

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, ans = 0;
        cin >> n;
        string str;
        cin >> str;
        bool isContZero = 0;
        int candidate = 0;
        for (int i = 0;i < 2 * n - 1; i++) {
            int idx = i % n;
            if (str[idx] == '0') {
                if (isContZero) {
                    candidate++;
                }
                else {
                    isContZero = 1;
                    candidate = 1;
                }
            }
            else {
                isContZero = 0;
                candidate = 0;
            }
            
            ans = max(ans, candidate);
        }
        cout << ans << '\n';
    }
    return 0;
}

/*
연속된 cyclie array의 0의 갯수를 찾는다.
O(n)
*/

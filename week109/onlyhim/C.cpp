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

    int n, m, val, ans = 0;
    cin >> n >> m;
    vector<int> flag(n + 1, 0);
    for (int i = 0; i < m; i++) {
        cin >> val;
        if (val == 1) {
            if (flag[val]) {
                if (flag[val + 1] == 0)   ans--;
            }
            else {
                if (flag[val + 1] == 0)   ans++;
            }
        }
        else if (val == n) {
            if (flag[val]) {
                if (flag[val - 1] == 0)   ans--;
            }
            else {
                if (flag[val - 1] == 0)   ans++;
            }
        }
        else {
            if (flag[val]) {
                if (flag[val + 1] && flag[val - 1]) {
                    ans++;
                }
                else if (!flag[val + 1] && !flag[val - 1]) {
                    ans--;
                }
            }
            else {
                if (flag[val + 1] && flag[val - 1]) {
                    ans--;
                }
                else if (!flag[val + 1] && !flag[val - 1]) {
                    ans++;
                }
            }
        }
        flag[val] = !flag[val];
        cout << ans << '\n';
    }
    return 0;
}

/*
    hash table에 있으면 (= black -> white)
    -> 양옆에 없으면 -1
    -> 하나만 있으면 +0
    -> 둘다 있으면 +1

    hash table에 없으면 (= white -> black)
    -> 양옆에 없으면 +1
    -> 하나만 있으면 +0
    -> 둘다 있으면 -1

*/

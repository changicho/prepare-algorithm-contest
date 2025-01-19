#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <set>
#include <cmath>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        vector<vector<int>> adj(n, vector<int>(n, 0));
        vector<int> ans(n);
        for (int i = 0; i < n; i++)    ans[i] = i;
        for (int j = 0; j < n; j++) {
            string str;
            cin >> str;
            for (int k = 0; k < n; k++) {
                adj[j][k] = str[k] - '0';
            }
        }
        sort(ans.begin(), ans.end(), [&](int a, int b) {
            if (adj[a][b] == 1) return a < b;
            else return a > b;
            });
        for (int i = 0; i < n; i++) cout << ans[i]+1 << ' ';
        cout << '\n';
    }
    return 0;
}

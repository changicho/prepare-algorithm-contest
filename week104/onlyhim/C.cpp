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
using namespace std;

void go(vector<int>& visit, vector<vector<int>>& adj, int cur) {
    visit[cur] = 1;
    for (int i = 0; i < adj[cur].size(); i++) {
        int next = adj[cur][i];
        if (visit[next] == 0)   go(visit, adj, next);
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin >> n>>m;
    if (m != n) {
        cout << "No\n";
        return 0;
    }
    vector<int> cnt(n, 0);
    vector<vector<int>> adj(n);
    vector<int> visit(n, 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        cnt[a]++, cnt[b]++;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    go(visit, adj, 0);
    for (int i = 0; i < n; i++) if (cnt[i] != 2 || visit[i] == 0) {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    return 0;
}

/*
    1. 각 정점의 degree = 2여야 한다.
    2. connected graph여야 한다.
    O(V+E) / O(V)
*/

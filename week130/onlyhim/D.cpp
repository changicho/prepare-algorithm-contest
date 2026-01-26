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

    int n, m, l, s, t;
    cin >> n >> m >> l >> s >> t;
    vector<vector<pair<int, int>>> adj(n);
    vector<vector<int>> dp(n, vector<int>(l+1, 0));
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        adj[a].push_back({ b, c });
    }
    priority_queue<vector<int>> pq;
    pq.push({ 0, 0, 0 });
    /*for (int i = 0; i < n; i++) {
        pq.push({ 0, i, 0, i });
    }*/
    set<int> ans;
    while (!pq.empty()) {
        vector<int> cur = pq.top();
        pq.pop();
        int curCost = cur[0], curV = cur[1], curEdge = cur[2];
        if (curCost > t)    continue;
        if (curEdge == l && curCost >= s) {
            ans.insert(curV);
            continue;
        }

        for (int i = 0; i < adj[curV].size(); i++) {
            int nextV = adj[curV][i].first, nextCost = adj[curV][i].second;
            if (curEdge + 1 > l) continue;
            //if (dp[curV][curEdge] + nextCost >= dp[nextV][curEdge + 1]) continue;
            /*if (dp[curV][curEdge] + nextCost > t)   continue;
            dp[nextV][curEdge + 1] = dp[curV][curEdge] + nextCost;*/
            pq.push({ curCost + nextCost, nextV, curEdge + 1 });
        }
    }
    
    for (auto i : ans)  cout << i + 1 << ' ';

    return 0;
}

/*
* 유향 그래프 g가 주어진다. n <= 10^5, m <= 10^5
* 각 edge에는 비용이 존재하고, out degree는 최대 4
* 다음 조건을 만족하는 모든 정점 x를 찾아라
* - 시작 정점이 1이고 도착이 x이며, 정확히 l개의 edge만 거친다. 중복 포함
* - 모든 비용의 합이 최소 S, 최대 T이다.
* 
* 도착 정점이 1이므로, 1을 큐에 넣고 역으로 탐색한다.
* 시간복잡도는 4^l
*/

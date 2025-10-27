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

    int n, m;
    string str;
    cin >> n >> m;
    vector<vector<int>> adj(n + 3);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cin >> str;

    queue<vector<int>> q;
    vector<pair<int, int>> best1(n, { 1e9, -1 }); 
    vector<pair<int, int>> best2(n, { 1e9, -1 });
    for (int i = 0; i < m; i++) {
        if (str[i] == 'S') {
            best1[i] = { 0, i };
            q.push({ i, i });
        }
    }
    while (!q.empty()) {
        vector<int> v = q.front();
        q.pop();
        int st = v[0], org = v[1];
        
        int cost;
        if (best1[st].second == org)    cost = best1[st].first + 1;
        else cost = best2[st].first + 1;
        
        for (int i = 0; i < adj[st].size(); i++) {
            int next = adj[st][i];
            if (best1[next].second == org && best1[next].first <= cost) continue;
            if (best2[next].second == org && best2[next].first <= cost) continue;

            if (best1[next].first > cost) {
                if (best1[next].second != org)  best2[next] = best1[next];
                best1[next] = { cost, org };
                q.push({ next, org });
            }
            else if (org != best1[next].second && cost < best2[next].first) {
                best2[next] = { cost, org };
                q.push({ next, org });
            }
        }

    }

    for (int i = 0; i < n; i++) {
        if (str[i] == 'D') {
            if (best2[i].first == 1e9)  cout << -1 << '\n';
            else cout << best1[i].first + best2[i].first << '\n';
        }
    }

    return 0;
}

/*
* 무방향 그래프 g가 주어진다.
* 각 정점은 Safe or Danger 중 1개로 입력으로 주어진다.
* 각 Danger 정점 x마다 A - x - B인 가장 짧은 비용의 경로를 계산해라. (A!=B, A,B는 모두 Safe 정점)
* 

* 큐에는 { 현재 정점, 출발 안전 정점 } 이 들어있다.
* 다중시작 bfs로 1번에 가능
*/

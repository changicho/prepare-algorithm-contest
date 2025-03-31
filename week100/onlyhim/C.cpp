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

int dfs(int node, int& edges, int& nodes, vector<vector<int>>& adj, vector<int>& visit) {
    visit[node] = true;
    nodes++;
    for (int neighbor : adj[node]) {
        edges++;
        if (!visit[neighbor]) {
            dfs(neighbor, edges, nodes, adj, visit);
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, a, b, ans = 0;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> visit(n + 1, 0);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (visit[i] == 0) {
            int nodes = 0, edges = 0;
            dfs(i, edges, nodes, adj, visit);
            edges /= 2;
            ans += (edges - (nodes - 1));
        }
    }
    cout << ans;
    return 0;
}

/*
* 무향그래프 g가 주어졌을 때, g를 forest로 만들기 위해 제거할 수 있는 edge의 최소 갯수
* forest = cycle을 포함하지 않은 그래프
* 
* 그래프 g가 forest인 경우 정점을 n개라 할 때, edge는 최대 n-1개이다.
* 특정 정점 x에서 dfs 순회시 (방문한 edge의 갯수 > 방문한 정점의 갯수 - 1)인 경우 cycle이 존재하므로, 이는 제거 가능하다.
* 무향그래프 이므로 edges /= 2
*/

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

    int n;
    cin >> n;
    vector<vector<int>> adj(n + 3);
    queue<int> q;
    vector<int> visit(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0) {
            q.push(i);
            visit[i] = 1;
        }
        else {
            adj[a].push_back(i);
            adj[b].push_back(i);
        }
    }
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < adj[cur].size(); i++) {
			int next = adj[cur][i];
            if (visit[next] == 0) {
                visit[next] = 1;
				q.push(next);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)    if (visit[i])   ans++;
    cout << ans;
    return 0;
}
 
/*
* 0 0이면 이미 배운 스킬
* 둘 중 1개만 배우면 되므로, out edge가 있는 그래프로 bfs -> O(V+E)
* 
*/

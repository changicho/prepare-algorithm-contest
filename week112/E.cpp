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
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, numAirport, timeAirport;
    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>(n));
    vector<int> airports(n, 0);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        adj[a][b] = adj[b][a] = c;
    }
    cin >> numAirport >> timeAirport;
    for (int i = 0; i < numAirport; i++) {
        int airport;
        cin >> airport;
        airport--;
        airports[i] = 1;
    }
    vector<int> visit(n, 0);
    for (int i = 0; i < n; i++) {
        if (visit[i])   continue;
        queue<int> q;

    }

    return 0;
}

/*
* 도시 a,b
* 쿼리 2; 모든 공항이 있는 정점을 push -> 
*/

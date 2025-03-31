#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <set>
#include <unordered_map>
#include <queue>
using namespace std;

long long ans, numVertexInComponent;

void dfs(vector<vector<int>>& edge, vector<bool>& visit, int cur) {
	if (visit[cur])	return;
	visit[cur] = 1;
	numVertexInComponent++;
	for (int i = 0; i < edge[cur].size(); i++) {
		int next = edge[cur][i];
		if (!visit[next]) {
			dfs(edge, visit, next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m,a,b;
	cin >> n>>m;
	vector<vector<int>> edge(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	vector<bool> visit(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			numVertexInComponent = 0;
			dfs(edge, visit, i);
			ans += (numVertexInComponent) * (numVertexInComponent - 1) / 2;
		}
	}
	cout << ans - m << endl;
	return 0;
}

/*
	정점 갯수가 n인 무향그래프와 m개의 edges가 주어진다. (n,m<=10^5)
	정점 a,b와 b,c가 연결되어 있고 a,c가 연결되어 있지 않은 경우를 찾아 a,c의 edge를 추가 할 때, 추가 가능한 최대 edge 갯수를 계산해라
	
	모든 컴포넌트에서 현재 연결된 edge에서 몇 개의 edge를 더 추가할 수 있는지에 대한 문제로 변형할 수 있다.
	트리를 구성하는 컴포넌트의 정점 갯수를 k라 할 때, 최소 edge 수는 k-1이고 최대 edge 수는 k * (k-1) /2 이다.
	따라서 dfs로 각 컴포넌트의 정점 갯수를 구하고 max edge를 답에 더해나간 후 초반에 주어진 edge 갯수를 뺀다.
*/

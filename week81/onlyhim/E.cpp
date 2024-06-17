#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;

void go(vector<int>& outEdges, vector<int>& visit, int vtx, int initVal) {
	if (visit[vtx] == initVal + 2)	return;
	if (visit[vtx] < initVal)	visit[vtx] = initVal;
	else visit[vtx]++;
	go(outEdges, visit, outEdges[vtx], initVal);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	long long ans = 0;
	cin >> n;
	vector<int> outEdges(n+1);
	vector<vector<int>> inEdges(n + 1);
	vector<int> visit(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> outEdges[i];
		inEdges[outEdges[i]].push_back(i);
	}
	int initVal = 1;
	for (int i = 1; i <= n; i++) {
		if (inEdges[i].size() == 0 && visit[i] == 0) {
			go(outEdges, visit, i, initVal);
			unordered_set<int> cycle;
			for (int i = 1; i <= n; i++) {
				if (visit[i] == initVal + 2) {
					cycle.insert(i);
				}
			}
			queue<pair<int, int>> q;
			for (auto i : cycle) {
				ans += cycle.size();
				visit[i] = cycle.size();
			}
			for (auto i : cycle) {
				for (int j = 0; j < inEdges[i].size(); j++) {
					if (cycle.find(inEdges[i][j]) == cycle.end())	q.push({ inEdges[i][j], i });
				}
			}
			while (!q.empty()) {
				int qsz = q.size();
				while (qsz--) {
					int cur = q.front().first;
					int prev = q.front().second;
					q.pop();
					visit[cur] = visit[prev] + 1;
					ans += visit[cur];
					for (auto i : inEdges[cur]) {
						q.push({ i, cur });
					}

				}
			}
		}
		initVal++;
	}
	for (int i = 1; i <= n; i++)	if (visit[i] == 0)	ans++;
	cout << ans;
	return 0;
}

/*
	edge수가 n이므로 최소 1개의 사이클이 존재한다. 
	1. 사이클을 구성하는 정점 집합을 찾는다.
	2. 1의 사이클을 구성하는 정점을 향하는 edge가 있는 정점을 찾는다. 이 정점은 cycle 갯수 + 1 만큼의 정점을 방문가능하다.
	3.
	4. 1~3을 모든 컴포넌트에 대해 반복한다.

*/

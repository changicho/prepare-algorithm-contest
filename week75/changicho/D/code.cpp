#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

long long answer = 0;
vector<vector<int>> graph;
vector<bool> visited;

long long nodeCount = 0;

void recursive(int node, int parent, set<pair<int, int>>& visitedEdges) {
  visited[node] = true;
  nodeCount++;

  for (int& next : graph[node]) {
    if (next == parent) continue;

    visitedEdges.insert({min(node, next), max(node, next)});

    if (visited[next]) continue;

    recursive(next, node, visitedEdges);
  }
}

long long solution(int n, vector<pair<int, int>> edges) {
  graph.resize(n + 1);
  visited.resize(n + 1, false);

  for (auto& edge : edges) {
    graph[edge.first].push_back(edge.second);
    graph[edge.second].push_back(edge.first);
  }

  for (int node = 1; node <= n; node++) {
    if (visited[node]) continue;

    set<pair<int, int>> visitedEdges;

    nodeCount = 0;

    recursive(node, -1, visitedEdges);

    long long fullCount = (long long)nodeCount * (nodeCount - 1) / 2;
    long long alreadyCount = (long long)visitedEdges.size();

    // cout << "haha " << nodeCount << " " << alreadyCount << endl;

    answer += fullCount - alreadyCount;
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N, M;
  cin >> N >> M;

  vector<pair<int, int>> AB(M);
  for (int i = 0; i < M; i++) {
    cin >> AB[i].first >> AB[i].second;
  }

  long long answer = solution(N, AB);

  cout << answer << endl;

  return 0;
}
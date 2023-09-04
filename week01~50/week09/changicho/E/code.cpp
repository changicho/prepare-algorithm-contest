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

int getCycleLength(int node, vector<vector<int>> &graph,
                   vector<bool> &visited) {
  visited[node] = true;

  for (int &next : graph[node]) {
    if (visited[next]) continue;

    return getCycleLength(next, graph, visited) + 1;
  }
  return 1;
}

bool solution(vector<pair<int, int>> &dominos) {
  int size = dominos.size();
  vector<vector<int>> graph(size + 1);
  vector<bool> visited(size + 1);

  for (pair<int, int> &d : dominos) {
    int a = d.first, b = d.second;

    graph[a].push_back(b);
    graph[b].push_back(a);

    if (graph[a].size() > 2 || graph[b].size() > 2) return false;
  }

  for (int node = 1; node <= size; node++) {
    if (visited[node]) continue;

    int length = getCycleLength(node, graph, visited);
    if (length % 2 == 1) return false;
  }

  return true;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;
  for (int testCase = 1; testCase <= T; testCase++) {
    int N;
    cin >> N;
    vector<pair<int, int>> dominos(N);
    for (int i = 0; i < N; i++) {
      cin >> dominos[i].first >> dominos[i].second;
    }

    bool answer = solution(dominos);
    if (answer) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}
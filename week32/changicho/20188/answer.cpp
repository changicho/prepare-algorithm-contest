#include <algorithm>
#include <climits>
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

const int MAX = 1e9 + 1;

vector<vector<int>> graph;
vector<int> parents;
vector<int> depths;
vector<int> childCounts;  // 해당 노드가 루트인 서브트리의 노드의 갯수
vector<bool> visited;  // 방문 여부

void calcInit(int node, int depth) {
  if (visited[node]) return;
  visited[node] = true;

  depths[node] = depth;
  childCounts[node] = 1;
  for (int &next : graph[node]) {
    if (visited[next]) continue;
    parents[next] = node;
    calcInit(next, depth + 1);
    childCounts[node] += childCounts[next];
  }

  visited[node] = false;
}

long long countCases(int size) { return 1LL * (size - 1) * size / 2; }

long long solution(int n) {
  // initialize
  calcInit(1, 0);

  long long ret = 0;
  // 각 간선이 포함되는 경우의 수
  for (int node = 1; node <= n; node++) {
    ret += 1LL * childCounts[node] * (n - childCounts[node]);
  }

  // 각 서브트리에서 루트까지 더해야 하는 경우 계산
  for (int node = 1; node <= n; node++) {
    long long now = countCases(childCounts[node]);

    for (int &next : graph[node]) {
      if (next == parents[node]) continue;

      now -= countCases(childCounts[next]);
    }
    ret += now * depths[node];
  }
  return ret;
}

void init() {}

void clear() {}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // // decimal point
  // cout << fixed;
  // cout.precision(8);

  init();

  // freopen("./input.txt", "r", stdin);

  int N;
  cin >> N;

  graph.resize(N + 1);
  parents.resize(N + 1);
  depths.resize(N + 1);
  childCounts.resize(N + 1);
  visited.resize(N + 1);
  for (int i = 0; i < N - 1; i++) {
    int from, to;
    cin >> from >> to;

    graph[from].push_back(to);
    graph[to].push_back(from);
  }

  long long answer = solution(N);

  cout << answer << "\n";

  return 0;
}

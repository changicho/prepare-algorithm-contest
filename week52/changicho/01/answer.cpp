#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

struct Edge {
  int from, to;
};

vector<int> parents;
int componentCount = 0;

int find(int node) {
  if (node == parents[node]) return node;
  return parents[node] = find(parents[node]);
}

void merge(int a, int b) {
  a = find(a), b = find(b);
  if (a == b) return;
  if (a > b) swap(a, b);

  parents[b] = a;
  componentCount--;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M;
  cin >> N >> M;

  if (M == 0) {
    cout << "0" << endl;
    return 0;
  }

  vector<vector<int>> graph(N + 1);
  vector<int> inDegrees(N + 1);
  parents.resize(N + 1);
  for (int node = 1; node <= N; node++) {
    parents[node] = node;
  }
  componentCount = N;

  for (int i = 0; i < M; i++) {
    int from, to;
    cin >> from >> to;

    // if (from == to) continue;
    graph[from].emplace_back(to);
    graph[to].emplace_back(from);
    inDegrees[from]++;
    inDegrees[to]++;
    merge(from, to);
  }

  unordered_map<int, int> componentOddCounts;
  for (int node = 1; node <= N; node++) {
    int key = find(node);

    if (inDegrees[node] % 2 == 1) {
      componentOddCounts[key]++;
    }
  }
  // trim single no edge node
  for (int node = 1; node <= N; node++) {
    if (graph[node].size() == 0) {
      componentCount--;
    }
  }

  int answer = 0;
  if (componentCount == 1) {
    // cout<<"single"<<endl;
    int needs = componentOddCounts[1] / 2;

    answer += needs;
    cout << answer << endl;
    return 0;
  }

  for (auto &it : componentOddCounts) {
    int key = it.first, val = it.second;
    // cout<<key<<" "<<val<<endl;
    int needs = val / 2;

    answer += max(needs - 2, 0);
  }
  // cout<<componentCount<<endl;
  answer += componentCount;

  cout << answer << endl;

  return 0;
}
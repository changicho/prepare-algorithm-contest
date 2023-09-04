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

// time :

int costs[250001];

struct Edge {
  int from, to, cost;

  bool operator<(const Edge &b) const { return cost > b.cost; }
};

int solution(int n, vector<int> &a) {
  vector<vector<Edge>> graph(n);

  // for (int i = 0; i < n - 1; i++) {
  //   int from = i, to = i + 1;
  //   graph[from].push_back({from, to, 1});
  //   graph[to].push_back({to, from, 1});
  // }

  vector<int> indexes(n + 1);
  for (int i = 0; i < n; i++) {
    indexes[a[i]] = i;
  }

  stack<int> stk, trash;
  for (int i = 0; i < n; i++) {
    while (!stk.empty() && a[stk.top()] < a[i]) {
      int from = stk.top(), to = i;

      graph[from].push_back({from, to, 1});

      trash.push(stk.top());
      stk.pop();
    }

    if (!stk.empty()) {
      int to = stk.top(), from = i;

      graph[from].push_back({from, to, 1});
    }

    stk.push(i);
  }

  for (int node = 0; node < n; node++) {
    for (Edge &e : graph[node]) {
      cout << e.from + 1 << " " << e.to + 1 << " " << e.cost << endl;
    }
  }
  cout << endl;

  priority_queue<Edge> pq;

  for (int i = 0; i < n; i++) {
    costs[i] = n + 2;
  }
  costs[0] = 0;

  pq.push({-1, 0, 0});
  while (!pq.empty()) {
    Edge cur = pq.top();
    pq.pop();

    // cout << cur.from + 1 << " " << cur.to + 1 << " " << cur.cost << endl;

    for (Edge next : graph[cur.to]) {
      int new_val = costs[cur.to] + next.cost;
      int before_val = costs[next.to];

      if (new_val < before_val) {
        costs[next.to] = new_val;
        pq.push({next.from, next.to, new_val});
      }
    }
  }

  // for (int &c : costs) {
  //   cout << c << " ";
  // }
  // cout << endl;

  return costs[n - 1];
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;

  for (int testCase = 1; testCase <= T; testCase++) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    int ret = solution(n, a);
    cout << ret;
    cout << "\n";
  }

  return 0;
}
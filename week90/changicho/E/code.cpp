#include <algorithm>
#include <cmath>
#include <functional>
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

vector<int> solution(int n, vector<vector<int>> &queries) {
  vector<int> parent(n + 1);
  vector<int> color(n + 1);
  vector<int> size(n + 1);
  vector<int> consequence(n + 1);

  for (int i = 1; i <= n; i++) {
    parent[i] = i;
    size[i] = 1;
    consequence[i] = 1;
    color[i] = i;
  }

  function<int(int)> find = [&](int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
  };

  auto merge = [&](int from, int to) {
    from = find(from);
    to = find(to);
    if (from == to) {
      return;
    }

    parent[from] = to;
    consequence[to] += consequence[from];
  };

  function<void(int, int)> changeColor = [&](int i, int newColor) {
    i = find(i);
    int beforeColor = color[i];
    color[i] = newColor;
    size[beforeColor] -= consequence[i];
    size[newColor] += consequence[i];
  };

  vector<int> answer;
  for (vector<int> &query : queries) {
    int command = query[0];

    if (command == 1) {
      int i = query[1], newColor = query[2];

      if (color[find(i)] == newColor) {
        continue;
      }

      int prev = i - 1 >= 1 ? find(i - 1) : -1;
      int next = i + 1 <= n ? find(i + 1) : -1;

      changeColor(i, newColor);

      if (prev != -1 && newColor == color[prev]) {
        merge(i, prev);
      }
      if (next != -1 && newColor == color[next]) {
        merge(next, i);
      }

      // for (int i = 1; i <= n; i++) {
      //   cout << color[find(i)] << ' ';
      // }
      // cout << endl;
      // for (int i = 1; i <= n; i++) {
      //   cout << consequence[i] << ' ';
      // }
      // cout << endl;
      // for (int i = 1; i <= n; i++) {
      //   cout << size[i] << ' ';
      // }
      // cout << endl;

      // cout << endl;

    } else if (command == 2) {
      int target = query[1];
      answer.push_back(size[color[find(target)]]);
    }
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./input.txt", "r", stdin);

  int N, Q;
  cin >> N >> Q;
  vector<vector<int>> queries(Q);
  for (int i = 0; i < Q; i++) {
    int a, b, c;
    cin >> a;

    queries[i].push_back(a);

    if (a == 1) {
      cin >> b >> c;
      queries[i].push_back(b);
      queries[i].push_back(c);
    } else if (a == 2) {
      cin >> b;
      queries[i].push_back(b);
    }
  }

  vector<int> answer = solution(N, queries);

  for (int &a : answer) {
    cout << a << '\n';
  }
  cout << endl;

  return 0;
}
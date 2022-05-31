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

// time : 1h

pair<int, int> recursive(int size, int index, int &count, vector<bool> &colors,
                         vector<vector<int>> &childrens) {
  pair<int, int> cur = {0, 0};

  for (int &child : childrens[index]) {
    pair<int, int> before = recursive(size, child, count, colors, childrens);

    cur.first += before.first;
    cur.second += before.second;
  }

  if (colors[index]) {
    cur.first += 1;
  } else {
    cur.second += 1;
  }

  if (cur.first == cur.second) count++;

  return cur;
}

int solution(int size, vector<bool> &colors, vector<vector<int>> &childrens) {
  int count = 0;

  recursive(size, 1, count, colors, childrens);

  return count;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;

  for (int testCase = 1; testCase <= T; testCase++) {
    int N;
    cin >> N;

    vector<bool> colors(N + 1);
    vector<vector<int>> childrens(N + 1);

    for (int i = 2; i <= N; i++) {
      int parent;
      cin >> parent;

      childrens[parent].push_back(i);
    }

    string line;
    cin >> line;

    for (int i = 1; i <= N; i++) {
      colors[i] = line[i - 1] == 'W';
    }

    int ret = solution(N, colors, childrens);

    cout << ret << "\n";
  }

  return 0;
}
#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

vector<int> solution(int size, vector<int> &diff,
                     vector<pair<int, int>> &height) {
  int cur = 0;
  stack<int> stk;
  for (int i = 0; i < size; i++) {
    int left = height[i].first;
    int right = height[i].second;

    if (diff[i] == -1) {
      stk.push(i);
    } else {
      cur += diff[i];
    }

    while (cur < left) {
      if (stk.empty()) {
        return {-1};
      }

      int idx = stk.top();
      stk.pop();
      diff[idx] = +1;
      cur += 1;
    }

    while (cur + stk.size() > right) {
      if (stk.empty()) {
        return {-1};
      }

      int idx = stk.top();
      stk.pop();
      diff[idx] = 0;
    }
  }

  for (int &d : diff) {
    if (d == -1) d = 0;
  }

  return diff;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;
  for (int test = 1; test <= T; test++) {
    int N;
    cin >> N;

    vector<int> D(N);
    for (int i = 0; i < N; i++) {
      cin >> D[i];
    }

    vector<pair<int, int>> H(N);
    for (int i = 0; i < N; i++) {
      cin >> H[i].first >> H[i].second;
    }

    vector<int> answer = solution(N, D, H);

    // cout << answer << endl;
    // cout << (answer ? "Yes" : "No") << endl;
    for (auto &line : answer) {
      cout << line << " ";
    }
    cout << endl;
  }

  return 0;
}
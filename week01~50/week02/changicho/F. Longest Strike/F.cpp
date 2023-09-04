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

// time : 30min

pair<int, int> solution(vector<int> &arr, int k) {
  int left = -1, right = -1;

  map<int, int> counts;

  for (int &n : arr) {
    counts[n]++;
  }

  vector<int> keys;
  for (auto &it : counts) {
    if (it.second >= k) keys.push_back(it.first);
  }

  if (keys.empty()) return {-1, -1};
  if (keys.size() == 1) return {keys.front(), keys.front()};

  vector<int> dp(keys.size(), 1);
  for (int i = 1; i < keys.size(); i++) {
    if (keys[i] - 1 == keys[i - 1]) {
      dp[i] = dp[i - 1] + 1;
    }
  }

  int maximum = 0;
  for (int &d : dp) {
    maximum = max(d, maximum);
  }

  for (int i = 0; i < dp.size(); i++) {
    if (dp[i] != maximum) continue;

    left = keys[i] - dp[i] + 1;
    right = keys[i];
  }

  return {left, right};
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;

  for (int testCase = 1; testCase <= T; testCase++) {
    int N, K;
    cin >> N >> K;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
      cin >> arr[i];
    }

    pair<int, int> ret = solution(arr, K);

    if (ret.first == -1) {
      cout << ret.first;
    } else {
      cout << ret.first << " " << ret.second;
    }
    cout << "\n";
  }

  return 0;
}
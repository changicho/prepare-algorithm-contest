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

// time : 1hour
long long solution(int n, int m, vector<int>& s, vector<int>& k) {
  unordered_map<int, vector<int>> indexes;
  for (int i = 0; i < m; i++) {
    int idx = k[i];
    indexes[idx].push_back(i);
  }

  vector<vector<long long>> dp(n, vector<long long>(m, -1));
  for (int& i : indexes[s[0]]) {
    dp[0][i] = 0;
  }
  for (int index = 1; index < n; index++) {
    for (int& cursor : indexes[s[index]]) {
      for (int& beforeCursor : indexes[s[index - 1]]) {
        long long nextCost =
            dp[index - 1][beforeCursor] + abs(beforeCursor - cursor);

        if (dp[index][cursor] == -1) {
          dp[index][cursor] = nextCost;
        } else {
          dp[index][cursor] = min(dp[index][cursor], nextCost);
        }
      }
    }
  }

  long long answer = n * m;
  for (long long val : dp[n - 1]) {
    if (val == -1) continue;
    answer = min(answer, val);
  }
  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  //   freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;
  for (int testCase = 1; testCase <= T; testCase++) {
    int N, M;

    cin >> N;
    vector<int> S(N);
    for (int i = 0; i < N; i++) {
      cin >> S[i];
    }
    cin >> M;
    vector<int> K(M);
    for (int i = 0; i < M; i++) {
      cin >> K[i];
    }

    long long answer = solution(N, M, S, K);
    cout << "Case #" << testCase << ": " << answer << "\n";
  }

  return 0;
}
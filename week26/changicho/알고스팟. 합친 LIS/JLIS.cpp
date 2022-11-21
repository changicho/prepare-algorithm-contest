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

int jLIS(int idx1, int idx2, vector<int> &first, vector<int> &second,
         vector<vector<int>> &dp) {
  if (dp[idx1 + 1][idx2 + 1] != -1) return dp[idx1 + 1][idx2 + 1];

  long long a = (idx1 == -1 ? INT_MIN : first[idx1]);
  long long b = (idx2 == -1 ? INT_MIN : second[idx2]);

  long long maximum = max(a, b);

  int ret = 0;
  for (int next1 = idx1 + 1; next1 < first.size(); next1++) {
    if (maximum < first[next1]) {
      ret = max(ret, jLIS(next1, idx2, first, second, dp) + 1);
    }
  }
  for (int next2 = idx2 + 1; next2 < second.size(); next2++) {
    if (maximum < second[next2]) {
      ret = max(ret, jLIS(idx1, next2, first, second, dp) + 1);
    }
  }
  return dp[idx1 + 1][idx2 + 1] = ret;
}

int solution(vector<int> &first, vector<int> &second) {
  vector<vector<int>> dp(102, vector<int>(102, -1));

  return jLIS(-1, -1, first, second, dp);
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("./input.txt", "r", stdin);

  int C;
  cin >> C;

  for (int testCase = 1; testCase <= C; testCase++) {
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M);

    for (int i = 0; i < N; i++) {
      cin >> A[i];
    }
    for (int i = 0; i < M; i++) {
      cin >> B[i];
    }

    int answer = solution(A, B);

    cout << answer << "\n";
  }

  return 0;
}

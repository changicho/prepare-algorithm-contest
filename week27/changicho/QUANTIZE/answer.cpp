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

int getScore(int start, int end, vector<int> &sum, vector<int> &sqSum) {
  int tmpSum = sum[end] - (start == 0 ? 0 : sum[start - 1]);
  int tmpSq = sqSum[end] - (start == 0 ? 0 : sqSum[start - 1]);

  int mid = int(0.5 + (double)tmpSum / (end - start + 1));

  int res = tmpSq - 2 * mid * tmpSum + mid * mid * (end - start + 1);

  return res;
}

int recursive(int start, int part, vector<vector<int>> &dp, vector<int> &sum,
              vector<int> &sqSum) {
  int size = sum.size();

  if (start == size) return 0;
  if (part == 0) return 1e9;

  if (dp[start][part] != -1) return dp[start][part];
  dp[start][part] = 1e9;
  for (int i = 1; i + start <= size; i++) {
    int curScore = recursive(start + i, part - 1, dp, sum, sqSum) +
                   getScore(start, start + i - 1, sum, sqSum);

    dp[start][part] = min(dp[start][part], curScore);
  }
  return dp[start][part];
}

long long solution(vector<int> &nums, int variety) {
  int size = nums.size();

  vector<int> sum(size, 0), sqSum(size, 0);
  vector<vector<int>> dp(size, vector<int>(variety + 1, -1));

  sort(nums.begin(), nums.end());
  sum[0] = nums[0];
  sqSum[0] = nums[0] * nums[0];

  for (int i = 1; i < size; i++) {
    sum[i] = (sum[i - 1] + nums[i]);
    sqSum[i] = sqSum[i - 1] + (nums[i] * nums[i]);
  }

  int answer = recursive(0, variety, dp, sum, sqSum);
  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("./input.txt", "r", stdin);

  int C;
  cin >> C;

  for (int testCase = 1; testCase <= C; testCase++) {
    int N, S;
    cin >> N >> S;

    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
      cin >> nums[i];
    }

    long long answer = solution(nums, S);

    cout << answer << "\n";
  }

  return 0;
}

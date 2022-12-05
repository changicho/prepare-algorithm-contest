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

int getScore(int start, int end, vector<int> &prefixSums,
             vector<int> &prefixSquareSums) {
  int tmpSum = prefixSums[end] - (start == 0 ? 0 : prefixSums[start - 1]);
  int tmpSq =
      prefixSquareSums[end] - (start == 0 ? 0 : prefixSquareSums[start - 1]);

  int mid = int(0.5 + (double)tmpSum / (end - start + 1));

  int res = tmpSq - 2 * mid * tmpSum + mid * mid * (end - start + 1);

  return res;
}

int recursive(int index, int part, vector<vector<int>> &dp,
              vector<int> &prefixSums, vector<int> &prefixSquareSums) {
  int size = prefixSums.size();

  if (index == size) return 0;
  if (part == 0) return 1e9;

  if (dp[index][part] != -1) return dp[index][part];
  dp[index][part] = 1e9;
  for (int i = 1; i + index <= size; i++) {
    int curScore =
        recursive(index + i, part - 1, dp, prefixSums, prefixSquareSums) +
        getScore(index, index + i - 1, prefixSums, prefixSquareSums);

    dp[index][part] = min(dp[index][part], curScore);
  }
  return dp[index][part];
}

long long solution(vector<int> &nums, int parts) {
  int size = nums.size();

  vector<int> prefixSums(size, 0), prefixSquareSums(size, 0);
  vector<vector<int>> dp(size, vector<int>(parts + 1, -1));

  sort(nums.begin(), nums.end());
  prefixSums[0] = nums[0];
  prefixSquareSums[0] = nums[0] * nums[0];

  for (int i = 1; i < size; i++) {
    prefixSums[i] = (prefixSums[i - 1] + nums[i]);
    prefixSquareSums[i] = prefixSquareSums[i - 1] + (nums[i] * nums[i]);
  }

  int answer = recursive(0, parts, dp, prefixSums, prefixSquareSums);
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

#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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

const int MAX = 1e9 + 1;

int dp[51][51];
int answer = INT_MAX;

int recursive(int left, int right, vector<int>& nums) {
  if (left > right) return 0;
  int& res = dp[left][right];
  if (res != -1) return res;

  res = max(nums[left] - recursive(left + 1, right, nums),
            nums[right] - recursive(left, right - 1, nums));
  if (right - left + 1 >= 2) {
    res = max(res, -recursive(left + 2, right, nums));
    res = max(res, -recursive(left, right - 2, nums));
  }
  return res;
}

int solution(vector<int>& nums) {
  answer = INT_MAX;
  memset(dp, -1, sizeof(dp));

  int size = nums.size();

  int answer = recursive(0, size - 1, nums);
  return answer;
}

void init() {}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // // decimal point
  // cout << fixed;
  // cout.precision(8);

  init();

  freopen("./input.txt", "r", stdin);

  int C;
  cin >> C;

  for (int testCase = 1; testCase <= C; testCase++) {
    int N;
    cin >> N;

    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
      cin >> nums[i];
    }

    auto answer = solution(nums);
    cout << answer;
    cout << "\n";
  }

  return 0;
}

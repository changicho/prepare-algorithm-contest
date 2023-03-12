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

class Solution {
 private:
  const int MOD = 1e9 + 7;

  bool isPossible(int target, int count, int mark) {
    int maxScore = count * mark;
    if (target > maxScore || target % mark != 0) return false;

    return true;
  }

 public:
  int waysToReachTarget(int target, vector<vector<int>>& types) {
    // dp[index][score]; // until index, case of make score
    // dp[i][score] = dp[i-1][score] + dp[i-1][score - s] + (cur s count) ...

    int size = types.size();
    int dp[51][1001] = {
        0,
    };

    for (int i = 0; i < size; i++) {
      for (int score = 1; score <= target; score++) {
        if (isPossible(score, types[i][0], types[i][1])) {
          dp[i][score] = 1;
        }

        // ignore invalid case
        for (int diff = 0; i - 1 >= 0 && diff < score; diff += types[i][1]) {
          if (!isPossible(diff, types[i][0], types[i][1])) continue;

          dp[i][score] += dp[i - 1][score - diff];
          dp[i][score] %= MOD;
        }
      }
    }

    return dp[size - 1][target];
  }
};
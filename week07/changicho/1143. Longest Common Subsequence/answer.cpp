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

class Solution {
 public:
  int longestCommonSubsequence(string text1, string text2) {
    int n = text1.length(), m = text2.length();

    vector<vector<int>> dp(n, vector<int>(m));

    if (text1[0] == text2[0]) dp[0][0] = 1;
    for (int i = 1; i < n; i++) {
      if (dp[i - 1][0] == 1 || text1[i] == text2[0]) dp[i][0] = 1;
    }
    for (int i = 1; i < m; i++) {
      if (dp[0][i - 1] == 1 || text1[0] == text2[i]) dp[0][i] = 1;
    }

    for (int y = 1; y < n; y++) {
      for (int x = 1; x < m; x++) {
        if (text1[y] == text2[x]) {
          dp[y][x] = dp[y - 1][x - 1] + 1;
        } else {
          dp[y][x] = max(dp[y - 1][x], dp[y][x - 1]);
        }
      }
    }

    return dp[n - 1][m - 1];
  }
};
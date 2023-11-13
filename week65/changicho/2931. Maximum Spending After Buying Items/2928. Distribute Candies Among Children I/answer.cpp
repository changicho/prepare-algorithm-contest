#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sort
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  long long maxSpending(vector<vector<int>>& values) {
    int rows = values.size(), cols = values[0].size();

    vector<int> board(rows * cols);
    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        board[y * cols + x] = values[y][x];
      }
    }
    sort(board.begin(), board.end());

    long long answer = 0, dist = 1;
    for (int& b : board) {
      answer += dist * b;
      dist++;
    }
    return answer;
  }
};
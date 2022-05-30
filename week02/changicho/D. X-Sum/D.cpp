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

// time : 15min

bool isFine(int rows, int cols, int y, int x) {
  if (y < 0 || rows <= y) return false;
  if (x < 0 || cols <= x) return false;
  return true;
}

int getScore(vector<vector<int>> &board, int y, int x) {
  int rows = board.size(), cols = board.front().size();
  int size = min(rows, cols);

  int score = board[y][x];
  for (int i = 1; i < size; i++) {
    if (isFine(rows, cols, y - i, x - i)) score += board[y - i][x - i];
    if (isFine(rows, cols, y + i, x - i)) score += board[y + i][x - i];
    if (isFine(rows, cols, y - i, x + i)) score += board[y - i][x + i];
    if (isFine(rows, cols, y + i, x + i)) score += board[y + i][x + i];
  }
  return score;
}

int getXSum(vector<vector<int>> &board) {
  int rows = board.size(), cols = board.front().size();

  int maximum = 0;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      int curScore = getScore(board, y, x);

      maximum = max(maximum, curScore);
    }
  }
  return maximum;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;

  for (int testCase = 1; testCase <= T; testCase++) {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> board(N, vector<int>(M));
    for (int y = 0; y < N; y++) {
      for (int x = 0; x < M; x++) {
        cin >> board[y][x];
      }
    }

    int ret = getXSum(board);

    cout << ret << "\n";
  }

  return 0;
}
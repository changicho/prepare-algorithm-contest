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

int solution(vector<vector<int>> &board) {
  int grassCount = 0;
  for (int y = 0; y < 2; y++) {
    for (int x = 0; x < 2; x++) {
      if (board[y][x] != 0) grassCount++;
    }
  }

  if (grassCount == 4) return 2;
  if (grassCount > 0) return 1;
  return 0;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;

  for (int testCase = 1; testCase <= T; testCase++) {
    vector<vector<int>> board(2, vector<int>(2, 0));

    for (int y = 0; y < 2; y++) {
      for (int x = 0; x < 2; x++) {
        cin >> board[y][x];
      }
    }

    int answer = solution(board);
    cout << answer << "\n";
  }

  return 0;
}
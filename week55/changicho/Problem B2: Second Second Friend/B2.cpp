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

struct Axis {
  int y, x;
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int getAvailableFriends(vector<std::string> &grid, int y, int x) {
  int rows = grid.size(), cols = grid[0].size();

  int count = 0;
  for (Axis &dir : dirs) {
    Axis next = {y + dir.y, x + dir.x};

    if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols) continue;
    if (grid[next.y][next.x] == '#') continue;

    count++;
  }
  return count;
}

vector<string> solution(int rows, int cols, vector<string> &board) {
  vector<vector<bool>> hasTrees(rows, vector<bool>(cols, false));
  vector<vector<int>> counts(rows, vector<int>(cols, 0));
  queue<Axis> q;

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (board[y][x] == '#') continue;

      if (board[y][x] == '^') {
        hasTrees[y][x] = true;
      } else {
        board[y][x] = '^';
      }

      counts[y][x] = getAvailableFriends(board, y, x);
      if (counts[y][x] < 2) {
        q.push({y, x});
      }
    }
  }

  while (!q.empty()) {
    Axis cur = q.front();
    q.pop();

    if (hasTrees[cur.y][cur.x]) {
      return {};
    }
    board[cur.y][cur.x] = '.';

    for (Axis &dir : dirs) {
      Axis next = {cur.y + dir.y, cur.x + dir.x};

      if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
        continue;
      if (board[next.y][next.x] == '#') continue;

      counts[next.y][next.x]--;
      if (counts[next.y][next.x] >= 2) continue;

      counts[next.y][next.x] = 0;
      q.push(next);
    }
  }

  return board;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;
  for (int testCase = 1; testCase <= T; testCase++) {
    int R, C;
    cin >> R >> C;
    vector<string> board(R);

    for (int y = 0; y < R; y++) {
      cin >> board[y];
    }

    vector<string> answer = solution(R, C, board);

    cout << "Case #" << testCase << ": ";

    if (answer.size() == 0) {
      cout << "Impossible\n";
    } else {
      cout << "Possible\n";

      for (int y = 0; y < R; y++) {
        cout << answer[y] << "\n";
      }
    }
  }

  return 0;
}
#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
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

bool checkExactlyOneBlack(int y, int x, vector<string> &board) {
  int rows = board.size(), cols = board[0].size();
  int count = 0;
  for (auto &dir : dirs) {
    int ny = y + dir.y;
    int nx = x + dir.x;
    if (ny < 0 || ny >= rows || nx < 0 || nx >= cols) {
      continue;
    }
    if (board[ny][nx] == '#') {
      count++;
    }
  }
  return count == 1;
}

auto solution(int rows, int cols, vector<string> &board) {
  vector<vector<bool>> visited(rows, vector<bool>(cols, false));
  vector<vector<int>> counts(rows, vector<int>(cols, 0));

  queue<Axis> q;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (board[y][x] == '#') {
        q.push({y, x});
      }
    }
  }

  while (!q.empty()) {
    int size = q.size();

    vector<Axis> nexts;
    while (size--) {
      Axis cur = q.front();
      q.pop();

      for (auto &dir : dirs) {
        int ny = cur.y + dir.y;
        int nx = cur.x + dir.x;
        if (ny < 0 || ny >= rows || nx < 0 || nx >= cols) {
          continue;
        }
        if (board[ny][nx] == '#') {
          continue;
        }

        counts[ny][nx]++;

        if (visited[ny][nx]) {
          continue;
        }
        visited[ny][nx] = true;
        nexts.push_back({ny, nx});
      }
    }

    for (auto &next : nexts) {
      if (counts[next.y][next.x] == 1) {
        board[next.y][next.x] = '#';
        q.push(next);
      }
    }
  }

  // for (string &line : board) {
  //   cout << line << endl;
  // }
  // cout << endl;

  int answer = 0;

  for (string &line : board) {
    for (char &c : line) {
      if (c == '#') answer++;
    }
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int H, W;
  cin >> H >> W;

  vector<string> board(H);

  for (int i = 0; i < H; i++) {
    cin >> board[i];
  }

  auto answer = solution(H, W, board);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}
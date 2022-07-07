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

struct Status {
  Axis axis;
  int cost;
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool isPossible(vector<vector<int>> &costs, int value) {
  int rows = costs.size(), cols = costs.front().size();
  int LIMIT = rows + cols + 1;
  int maxSum = -LIMIT, minSum = LIMIT, maxDiff = -LIMIT, minDiff = LIMIT;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (costs[y][x] <= value) continue;
      maxSum = max(maxSum, y + x);
      minSum = min(minSum, y + x);
      maxDiff = max(maxDiff, y - x);
      minDiff = min(minDiff, y - x);
    }
  }

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      int cur = 0;
      cur = max(cur, abs(maxSum - (y + x)));
      cur = max(cur, abs(minSum - (y + x)));
      cur = max(cur, abs(maxDiff - (y - x)));
      cur = max(cur, abs(minDiff - (y - x)));

      if (cur <= value) return true;
    }
  }
  return false;
}

int minimumDistance(int rows, int cols, vector<vector<bool>> &board) {
  vector<vector<int>> costs(rows, vector<int>(cols, rows + cols + 1));

  queue<Status> q;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (board[y][x] == true) {
        q.push({{y, x}, 0});
        costs[y][x] = 0;
      }
    }
  }

  while (!q.empty()) {
    Status cur = q.front();
    q.pop();

    for (Axis &dir : dirs) {
      Axis next = {cur.axis.y + dir.y, cur.axis.x + dir.x};
      if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
        continue;
      if (costs[next.y][next.x] <= cur.cost + 1) continue;
      costs[next.y][next.x] = cur.cost + 1;

      q.push({next, cur.cost + 1});
    }
  }

  int maxCost = 0;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      maxCost = max(maxCost, costs[y][x]);
    }
  }

  int answer = maxCost;
  int left = 0, right = maxCost;
  while (left < right) {
    int mid = left + (right - left) / 2;

    if (isPossible(costs, mid)) {
      answer = mid;
      right = mid;
    } else {
      left = mid + 1;
    }
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;

  for (int testCase = 1; testCase <= T; testCase++) {
    int R, C;
    cin >> R >> C;

    vector<string> lines(R);
    vector<vector<bool>> board(R, vector<bool>(C, false));
    for (int i = 0; i < R; i++) {
      cin >> lines[i];
    }

    for (int y = 0; y < R; y++) {
      for (int x = 0; x < C; x++) {
        if (lines[y][x] == '1') {
          board[y][x] = true;
        }
      }
    }

    int answer = minimumDistance(R, C, board);

    cout << "Case #" << testCase << ": " << answer << "\n";
  }

  return 0;
}
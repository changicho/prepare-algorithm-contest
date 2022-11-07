#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Axis {
  int y, x;
};

// bishop's dir
Axis dirs[4] = {{+1, +1}, {-1, -1}, {+1, -1}, {-1, +1}};

int answers[16] = {0,  1,   0,   0,    2,     10,    4,      40,
                   92, 352, 724, 2680, 14200, 73712, 365596, 2279184};

bool canLocate(int y, int x, int size, bool board[16][16]) {
  for (int i = 0; i < size; i++) {
    if (board[i][x]) return false;
  }

  for (Axis &dir : dirs) {
    Axis cur = {y, x};

    for (int i = 0; i < size; i++) {
      cur.y += dir.y;
      cur.x += dir.x;

      if (cur.y < 0 || cur.y >= size || cur.x < 0 || cur.x >= size) break;
      if (board[cur.y][cur.x]) return false;
    }
  }

  return true;
}

void recursive(int y, int x, int size, int &count, bool board[16][16]) {
  if (y == size) {
    count++;
    return;
  }

  for (int x = 0; x < size; x++) {
    if (board[y][x]) continue;
    if (!canLocate(y, x, size, board)) continue;

    board[y][x] = true;
    recursive(y + 1, x, size, count, board);
    board[y][x] = false;
  }
}

int solution(int size) {
  int count = 0;

  bool board[16][16] = {
      false,
  };

  recursive(0, 0, size, count, board);

  return count;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./input.txt", "r", stdin);

  int N;
  cin >> N;

  int answer = solution(N);

  cout << answer << "\n";

  return 0;
}
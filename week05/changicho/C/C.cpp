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

// time : 22min
struct Axis {
  int y, x;
};

Axis dirs[4] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

Axis solution(vector<string> &board) {
  Axis axis = {0, 0};

  for (int y = 1; y < 7; y++) {
    for (int x = 1; x < 7; x++) {
      if (board[y][x] != '#') continue;

      bool isAnswer = true;
      for (Axis &d : dirs) {
        Axis next = {y + d.y, x + d.x};

        if (next.y < 0 || next.y >= 8 || next.x < 0 || next.x >= 8) continue;
        if (board[next.y][next.x] == '.') isAnswer = false;
      }

      if (isAnswer) return {y, x};
    }
  }
  return axis;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;

  for (int testCase = 1; testCase <= T; testCase++) {
    vector<string> board(8);
    for (int y = 0; y < 8; y++) {
      cin >> board[y];
    }

    // for (string &line : board) {
    //   cout << line << endl;
    // }
    // cout << endl;

    Axis ret = solution(board);

    cout << ret.y + 1 << " " << ret.x + 1 << "\n";
  }

  return 0;
}
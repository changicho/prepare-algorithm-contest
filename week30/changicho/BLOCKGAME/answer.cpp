#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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

const int MAX = 1e9 + 1;

vector<vector<vector<char>>> blocks{{{1, 1}, {1, 0}}, {{1, 1}, {0, 1}},
                                    {{0, 1}, {1, 1}}, {{1, 0}, {1, 1}},
                                    {{1, 1}, {0, 0}}, {{1, 0}, {1, 0}}};
char dp[1 << 25];

int convert(int y, int x) { return 1 << (5 * y + x); }

bool recursive(char board[6][6], int state) {
  char &ret = dp[state];
  if (ret != -1) return ret;

  ret = 0;

  // 맵 체크
  for (int r = 0; r < 5; r++) {
    for (int c = 0; c < 5; c++) {
      for (vector<vector<char>> &block : blocks) {
        bool canBuild = true;

        for (int k = 0; k < 2 && canBuild; k++) {
          for (int l = 0; l < 2; l++) {
            if (board[r + k][c + l] == '#' && block[k][l]) {
              canBuild = false;
              break;
            }
          }
        }

        if (canBuild) {
          int ns = state;
          for (int k = 0; k < 2 && canBuild; k++) {
            for (int l = 0; l < 2; l++) {
              if (block[k][l]) {
                board[r + k][c + l] = '#';
                ns |= convert(r + k, c + l);
              }
            }
          }

          ret = !recursive(board, ns);

          for (int k = 0; k < 2 && canBuild; k++) {
            for (int l = 0; l < 2; l++) {
              if (block[k][l]) {
                board[r + k][c + l] = '.';
              }
            }
          }

          if (ret) return ret;
        }
      }
    }
  }

  return ret;
}

bool solution(char board[6][6]) {
  int bit = 0;
  for (int y = 0; y < 5; y++) {
    for (int x = 0; x < 5; x++) {
      if (board[y][x] == '#') {
        bit |= convert(y, x);
      }
    }
  }

  bool answer = recursive(board, bit);

  return answer;
}

void init() { memset(dp, -1, sizeof(dp)); }

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // // decimal point
  // cout << fixed;
  // cout.precision(8);

  freopen("./input.txt", "r", stdin);

  int C;
  cin >> C;

  init();

  for (int testCase = 1; testCase <= C; testCase++) {
    char board[6][6] = {0};
    for (int y = 0; y < 5; y++) {
      for (int x = 0; x < 5; x++) {
        scanf(" \n%c", &board[y][x]);
      }
      board[y][5] = '#';
      board[5][y] = '#';
    }
    board[5][5] = '#';

    bool answer = solution(board);
    cout << (answer ? "WINNING" : "LOSING");
    cout << "\n";
  }

  return 0;
}

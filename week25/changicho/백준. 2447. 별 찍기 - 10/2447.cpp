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

void recursive(Axis start, Axis end, vector<string> &board) {
  int third = (end.y - start.y) / 3;
  if (third == 1) {
    for (int y = start.y; y < end.y; y++) {
      for (int x = start.x; x < end.x; x++) {
        board[y][x] = '*';
      }
    }
    board[start.y + 1][start.x + 1] = ' ';
    return;
  }

  for (int y = start.y; y < end.y; y += third) {
    for (int x = start.x; x < end.x; x += third) {
      if (y == start.y + third && x == start.x + third) continue;

      recursive({y, x}, {y + third, x + third}, board);
    }
  }
}

vector<string> solution(int size) {
  vector<string> board(size, string(size, ' '));

  recursive({0, 0}, {size, size}, board);

  return board;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("./input.txt", "r", stdin);

  int N;
  cin >> N;

  vector<string> answer = solution(N);
  for (string &line : answer) {
    cout << line << "\n";
  }

  return 0;
}
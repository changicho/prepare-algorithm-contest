#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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

// use brute force
// time : O((R * C)^2)
// space : O(R * C)
struct Axis {
  int y, x;

  const bool operator==(const Axis &b) { return y == b.y && x == b.x; }
  const bool operator!=(const Axis &b) { return y != b.y || x != b.x; }
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int solution(vector<vector<int>> maze) {
  int rows = maze.size(), cols = maze[0].size();

  Axis red, redEnd, blue, blueEnd;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      switch (maze[y][x]) {
        case 1: {
          red = {y, x};
          break;
        }
        case 2: {
          blue = {y, x};
          break;
        }
        case 3: {
          redEnd = {y, x};
          break;
        }
        case 4: {
          blueEnd = {y, x};
        }
      }
    }
  }

  int answer = INT_MAX;

  bool redVisited[4][4] = {
      false,
  };
  bool blueVisited[4][4] = {
      false,
  };
  redVisited[red.y][red.x] = true;
  blueVisited[blue.y][blue.x] = true;

  function<void(Axis, Axis, int)> recursive = [&](Axis red, Axis blue,
                                                  int step) {
    if (step > answer) return;

    if (red == redEnd && blue == blueEnd) {
      answer = min(answer, step);
      return;
    }

    vector<Axis> redNexts, blueNexts;
    for (Axis &dir : dirs) {
      if (red == redEnd) {
        redNexts.push_back(red);
        break;
      }
      Axis next = {red.y + dir.y, red.x + dir.x};

      if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
        continue;
      if (maze[next.y][next.x] == 5) continue;
      if (redVisited[next.y][next.x]) continue;

      redNexts.push_back(next);
    }
    for (Axis &dir : dirs) {
      if (blue == blueEnd) {
        blueNexts.push_back(blue);
        break;
      }
      Axis next = {blue.y + dir.y, blue.x + dir.x};

      if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
        continue;
      if (maze[next.y][next.x] == 5) continue;
      if (blueVisited[next.y][next.x]) continue;

      blueNexts.push_back(next);
    }

    for (Axis &redNext : redNexts) {
      for (Axis &blueNext : blueNexts) {
        if (redNext == blueNext) continue;
        if (blueNext == red && redNext == blue) continue;

        redVisited[redNext.y][redNext.x] = true;
        blueVisited[blueNext.y][blueNext.x] = true;

        recursive(redNext, blueNext, step + 1);

        redVisited[redNext.y][redNext.x] = false;
        blueVisited[blueNext.y][blueNext.x] = false;
      }
    }
  };

  recursive(red, blue, 0);

  return answer == INT_MAX ? 0 : answer;
}
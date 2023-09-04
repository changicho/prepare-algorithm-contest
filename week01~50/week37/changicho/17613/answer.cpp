#include <algorithm>
#include <climits>
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

const int MAX = 1e9 + 1;

int jumpPoints[31];

int getJumps(int position) {
  for (int jumps = 0; jumps < 31; ++jumps) {
    if (jumpPoints[jumps] > position) return jumps - 1;
  }
  return 0;
}

int calculate(int n) { return 1 + n * (n + 1) / 2; }

int divide(int left, int right, int jumps) {
  if (!left && !right) return jumps;
  int idx;
  int nextRight = right;
  int curJumps = 0;

  while (true) {
    idx = getJumps(nextRight);
    if (jumpPoints[idx] <= left) break;

    if (jumpPoints[idx] * 2 == nextRight) {
      curJumps = max(curJumps, calculate(idx));
    } else {
      curJumps = max(curJumps, divide(0, nextRight - jumpPoints[idx], idx));
    }
    nextRight = jumpPoints[idx] - 1;
  }
  curJumps = max(curJumps, divide(left - jumpPoints[idx], nextRight - jumpPoints[idx], idx));
  return curJumps + jumps;
}

int solution(int left, int right) { return divide(left, right, 0); }

void init() {
  jumpPoints[0] = 0;
  jumpPoints[1] = 1;
  for (int i = 2; i < 31; i++) {
    jumpPoints[i] = 2 * jumpPoints[i - 1] + 1;
  }
}

void clear() {}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // // decimal point
  // cout << fixed;
  // cout.precision(8);

  init();

  // freopen("./input.txt", "r", stdin);
  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    int x, y;
    cin >> x >> y;

    int answer = solution(x, y);
    cout << answer;
    cout << "\n";
  }

  return 0;
}

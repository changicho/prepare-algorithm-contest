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

int lengths[51] = {
    0,
};

char expand(const string &dragonCurve, int generation, int position) {
  if (generation == 0) return dragonCurve[position];

  for (char c : dragonCurve) {
    if (c == 'X' || c == 'Y') {
      if (position >= lengths[generation]) {
        position -= lengths[generation];
        continue;
      }

      string next = c == 'X' ? "X+YF" : "FX-Y";

      return expand(next, generation - 1, position);
    } else if (position > 0) {
      position--;
    } else {
      return c;
    }
  }
  return '?';
}

string solution(int generation, int position, int length) {
  string answer = "";
  for (int i = 0; i < length; i++) {
    answer += expand("FX", generation, (position - 1) + i);
  }
  return answer;
}

void init() {
  lengths[0] = 1;
  for (int i = 1; i <= 50; i++) {
    lengths[i] = min(MAX, lengths[i - 1] * 2 + 2);
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // // decimal point
  // cout << fixed;
  // cout.precision(8);

  init();

  freopen("./input.txt", "r", stdin);

  int C;
  cin >> C;

  for (int testCase = 1; testCase <= C; testCase++) {
    int N, P, L;
    cin >> N >> P >> L;

    string answer = solution(N, P, L);
    cout << answer;
    cout << "\n";
  }

  return 0;
}

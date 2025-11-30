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

struct Cloud {
  int u, d, l, r;
};

vector<int> solution(int size, vector<Cloud>& clouds) {
  vector<vector<int>> diffs(2002, vector<int>(2002, 0));
  vector<vector<int>> keyDiffs(2002, vector<int>(2002, 0));

  for (int i = 0; i < size; i++) {
    int key = i + 1;
    Cloud& cloud = clouds[i];

    diffs[cloud.u][cloud.l] += 1;
    diffs[cloud.u][cloud.r + 1] -= 1;
    diffs[cloud.d + 1][cloud.l] -= 1;
    diffs[cloud.d + 1][cloud.r + 1] += 1;

    keyDiffs[cloud.u][cloud.l] += key;
    keyDiffs[cloud.u][cloud.r + 1] -= key;
    keyDiffs[cloud.d + 1][cloud.l] -= key;
    keyDiffs[cloud.d + 1][cloud.r + 1] += key;
  }

  for (int y = 1; y <= 2000; y++) {
    for (int x = 1; x <= 2000; x++) {
      diffs[y][x] += diffs[y][x - 1];
      keyDiffs[y][x] += keyDiffs[y][x - 1];
    }
  }
  for (int y = 1; y <= 2000; y++) {
    for (int x = 1; x <= 2000; x++) {
      diffs[y][x] += diffs[y - 1][x];
      keyDiffs[y][x] += keyDiffs[y - 1][x];
    }
  }

  vector<int> answer(size, 0);
  int remain = 0;
  for (int y = 1; y <= 2000; y++) {
    for (int x = 1; x <= 2000; x++) {
      if (diffs[y][x] == 0) {
        remain++;
      } else if (diffs[y][x] == 1) {
        int key = keyDiffs[y][x];
        answer[key - 1]++;
      }
    }
  }
  for (int i = 0; i < size; i++) {
    answer[i] += remain;
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N;
  cin >> N;

  vector<Cloud> clouds(N);
  for (int i = 0; i < N; i++) {
    cin >> clouds[i].u >> clouds[i].d >> clouds[i].l >> clouds[i].r;
  }

  auto answer = solution(N, clouds);

  // cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  for (auto& line : answer) {
    cout << line << "\n";
  }
  cout << endl;

  return 0;
}
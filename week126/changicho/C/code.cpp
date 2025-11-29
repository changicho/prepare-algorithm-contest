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

struct Goal {
  int time;
  long long low, high;
};

auto solution(int size, int h, vector<Goal>& goals) {
  bool answer = true;

  int previousTime = 0;
  long long currentLow = h;
  long long currentHigh = h;

  for (Goal& goal : goals) {
    int timeDiff = goal.time - previousTime;

    currentLow -= timeDiff;
    currentHigh += timeDiff;

    bool isOverlap = currentLow <= goal.high && goal.low <= currentHigh;

    if (!isOverlap) {
      answer = false;
      break;
    }

    currentLow = max(currentLow, goal.low);
    currentHigh = min(currentHigh, goal.high);

    previousTime = goal.time;
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;

  for (int tc = 1; tc <= T; tc++) {
    int N, H;

    cin >> N >> H;

    vector<Goal> goals(N);
    for (int i = 0; i < N; i++) {
      cin >> goals[i].time >> goals[i].low >> goals[i].high;
    }

    auto answer = solution(N, H, goals);

    // cout << answer << endl;
    cout << (answer ? "Yes" : "No") << endl;
    // for (auto &line : answer) {
    //   cout << line << "\n";
    // }
    // cout << endl;
  }

  return 0;
}
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

  int before = 0;
  long long low = h;
  long long high = h;

  for (Goal& goal : goals) {
    int timeDiff = goal.time - before;

    low -= timeDiff;
    high += timeDiff;

    bool isOverlap = low <= goal.high && goal.low <= high;

    if (!isOverlap) {
      answer = false;
      break;
    }

    low = max(low, goal.low);
    high = min(high, goal.high);

    before = goal.time;
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
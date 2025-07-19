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

struct Action {
  long long give;
  long long receive;
};

long long solution(long long n, int actionSize, vector<Action> &actions) {
  long long answer = 0;

  sort(actions.begin(), actions.end(), [](const Action &a, const Action &b) {
    if (a.give == b.give) {
      return a.receive > b.receive;
    }
    return a.give < b.give;
  });

  // for (int i = 0; i < actionSize; i++) {
  //   cout << actions[i].give << " " << actions[i].receive << endl;
  // }

  // cout << endl;

  function<int(long long)> findIndex = [&](long long value) {
    int left = 0, right = actionSize;

    int ret = -1;
    while (left < right) {
      int mid = left + (right - left) / 2;

      if (actions[mid].give <= value) {
        ret = mid;
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return ret;
  };

  // choose optimal give is smaller than n
  // and give - receive is maximum

  vector<int> optimalGive(actionSize);
  optimalGive[0] = 0;
  for (int i = 1; i < actionSize; i++) {
    long long diff = actions[i].give - actions[i].receive;
    long long beforeDiff =
        actions[optimalGive[i - 1]].give - actions[optimalGive[i - 1]].receive;

    if (diff < beforeDiff) {
      optimalGive[i] = i;
    } else {
      optimalGive[i] = optimalGive[i - 1];
    }
  }

  // for (int i = 0; i < actionSize; i++) {
  //   cout << optimalGive[i] << endl;
  // }
  // cout << endl;
  // return 0;

  while (n >= actions[0].give) {
    int targetIndex = findIndex(n);
    if (targetIndex == -1) break;

    int choose = optimalGive[targetIndex];
    long long targetGive = actions[choose].give;
    long long targetReceive = actions[choose].receive;

    // cout << n << endl;
    // cout << targetGive << " " << targetReceive << endl;

    long long diff = targetGive - targetReceive;

    long long count = 1 + (n - targetGive) / diff;
    answer += count;

    n -= count * diff;

    // cout << n << endl;
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);
  long long N;
  int M;
  cin >> N >> M;

  vector<Action> actions(M);

  for (int i = 0; i < M; i++) {
    cin >> actions[i].give >> actions[i].receive;
  }

  long long answer = solution(N, M, actions);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}
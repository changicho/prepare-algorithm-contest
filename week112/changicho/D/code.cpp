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

long long solution(int n, int m, vector<int> &a, vector<int> &b) {
  long long answer = 0;

  unordered_map<int, int> count;
  vector<int> remains;
  for (int &num : a) {
    num %= m;
    count[num]++;
  }

  // greedy one pass
  for (int &num : b) {
    num %= m;

    int target = (m - num + m) % m;

    if (count[target] > 0) {
      count[target]--;
      if (count[target] == 0) {
        count.erase(target);
      }
    } else {
      remains.push_back(num);
    }
  }

  multiset<int> remainsB;
  for (auto [num, cnt] : count) {
    for (int i = 0; i < cnt; i++) {
      remainsB.insert(num);
    }
  }

  sort(remains.begin(), remains.end(), greater<int>());

  int size = remains.size();
  for (int i = 0; i < size; i++) {
    // remains[i] + remainsB[i] > m;
    // smallest remainsB[i];
    long long target = ((remains[i] - m) % m) * -1;

    auto it = remainsB.lower_bound(target);
    if (it == remainsB.end()) {
      it = remainsB.begin();
    }

    answer += (remains[i] + *it) % m;
    remainsB.erase(it);

    // cout << remains[i] << " " << target << " " << *it << endl;
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

  for (int test = 0; test < T; test++) {
    int N, M;
    cin >> N >> M;

    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
      cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
      cin >> B[i];
    }

    long long answer = solution(N, M, A, B);

    cout << answer << endl;
    // cout << (answer ? "Yes" : "No") << endl;
    // for (auto &line : answer) {
    //   cout << line << "\n";
    // }
    // cout << endl;
  }

  return 0;
}
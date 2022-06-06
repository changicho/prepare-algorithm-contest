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

// time : 10min

vector<int> solution(vector<int> &shoes) {
  int size = shoes.size();
  unordered_map<int, vector<int>> counts;

  for (int i = 0; i < size; i++) {
    int cur = shoes[i];
    counts[cur].push_back(i);
  }
  // edge case
  vector<int> ret(size);
  for (auto &it : counts) {
    if (it.second.size() == 1) return {};

    queue<int> q;
    for (int &i : it.second) {
      q.push(i);
    }
    // shift
    q.push(q.front());
    q.pop();

    for (int &i : it.second) {
      ret[i] = q.front() + 1;
      q.pop();
    }
  }

  return ret;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;

  for (int testCase = 1; testCase <= T; testCase++) {
    int N;

    cin >> N;

    vector<int> shoes(N);
    for (int i = 0; i < N; i++) {
      cin >> shoes[i];
    }

    vector<int> ret = solution(shoes);

    if (ret.empty()) {
      cout << "-1";
    } else {
      for (int &n : ret) {
        cout << n << " ";
      }
    }
    cout << "\n";
  }

  return 0;
}
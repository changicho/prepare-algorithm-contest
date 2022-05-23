// 1h

#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

struct Ant {
  int pos, index;
  bool isRight;
};

vector<int> fallOrder(vector<Ant> ants, int length) {
  int size = ants.size();
  sort(ants.begin(), ants.end(), [](Ant &a, Ant &b) { return a.pos < b.pos; });

  // brute force
  vector<pair<int, int>> result;  // time : index;

  for (int i = 0; i < size; i++) {
    int pos = ants[i].pos;
    int index = ants[i].index;
    bool isRight = ants[i].isRight;
    int time = isRight ? length - pos : pos;

    queue<int> q;
    if (isRight) {
      for (int next = i + 1; next < size; next++) {
        q.push(ants[next].index);
        if (ants[next].isRight == isRight) {
          continue;
        }

        index = q.front();
        q.pop();
      }
    } else {
      for (int next = i - 1; next >= 0; next--) {
        q.push(ants[next].index);
        if (ants[next].isRight == isRight) {
          continue;
        }

        index = q.front();
        q.pop();
      }
    }

    result.push_back({time, index});
  }

  sort(result.begin(), result.end());

  vector<int> res;

  for (pair<int, int> &p : result) {
    res.push_back(p.second);
  }
  return res;
}

void init() {}

int main() {
  std::ios_base::sync_with_stdio(false);

  //   freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;

  init();

  for (int testCase = 1; testCase <= T; testCase++) {
    int N, L;

    cin >> N >> L;

    vector<Ant> D(N);

    for (int i = 0; i < N; i++) {
      int pos, dir;
      cin >> pos >> dir;

      D[i].index = i + 1;
      D[i].isRight = (dir == 1);
      D[i].pos = pos;
    }

    vector<int> res = fallOrder(D, L);

    cout << "Case #" << testCase << ": ";
    for (int &i : res) {
      cout << i << " ";
    }
    cout << "\n";
  }

  return 0;
}
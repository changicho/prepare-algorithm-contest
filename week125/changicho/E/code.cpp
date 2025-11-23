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

struct Data {
  int maximum;
  int y, x;

  const bool operator<(const Data& d) const { return maximum > d.maximum; }
};

bool hasDuplicate(vector<int>& arr) {
  unordered_set<int> us;
  for (int& v : arr) {
    if (us.count(v)) {
      return true;
    }
    us.insert(v);
  }
  return false;
}

vector<vector<int>> solution(int rows, int cols, vector<int>& rowMax,
                             vector<int>& colMax) {
  if (hasDuplicate(rowMax) || hasDuplicate(colMax)) {
    return {};
  }
  vector<vector<int>> answer(rows, vector<int>(cols, 0));

  vector<bool> usable(rows * cols + 1, true);

  for (int x = 0; x < cols; x++) {
    for (int y = 0; y < rows; y++) {
      if (rowMax[y] == colMax[x]) {
        if (!usable[rowMax[y]]) {
          return {};
        }

        answer[y][x] = rowMax[y];
        usable[rowMax[y]] = false;
      }
    }
  }

  // fill col max's in y
  for (int x = 0; x < cols; x++) {
    for (int y = 0; y < rows; y++) {
      if (!usable[colMax[x]]) continue;
      if (answer[y][x] != 0) continue;
      if (colMax[x] > rowMax[y]) continue;

      answer[y][x] = colMax[x];
      usable[colMax[x]] = false;
      break;
    }
  }
  // fill row max's in x
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (!usable[rowMax[y]]) continue;
      if (answer[y][x] != 0) continue;
      if (rowMax[y] > colMax[x]) continue;

      answer[y][x] = rowMax[y];
      usable[rowMax[y]] = false;
      break;
    }
  }

  priority_queue<Data> pq;

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (answer[y][x] == 0) {
        pq.push({min(rowMax[y], colMax[x]), y, x});
      }
    }
  }

  int num = 1;
  while (!pq.empty()) {
    Data cur = pq.top();
    pq.pop();

    while (num <= rows * cols && !usable[num]) {
      num++;
    }

    if (num > cur.maximum) {
      return {};
    }
    answer[cur.y][cur.x] = num;
    usable[num] = false;
  }

  // last check
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (answer[y][x] == 0) {
        return {};
      }
      if (answer[y][x] > rowMax[y] || answer[y][x] > colMax[x]) {
        return {};
      }
    }
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
    int N, M;
    cin >> N >> M;

    vector<int> X(N), Y(M);

    for (int i = 0; i < N; i++) {
      cin >> X[i];
    }
    for (int j = 0; j < M; j++) {
      cin >> Y[j];
    }

    auto answer = solution(N, M, X, Y);

    if (answer.size() == 0) {
      cout << "No" << endl;
      continue;
    }
    cout << "Yes" << endl;

    for (int y = 0; y < N; y++) {
      for (int x = 0; x < M; x++) {
        cout << answer[y][x] << " ";
      }
      cout << "\n";
    }
    cout << endl;

    // cout << answer << endl;
    // cout << (answer ? "Yes" : "No") << endl;
    // for (auto &line : answer) {
    //   cout << line << "\n";
    // }
    // cout << endl;
  }

  return 0;
}
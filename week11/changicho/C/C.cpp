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

// time :
bool canFill(int rows, int cols, vector<int> colors) {
  bool overThree = false;
  long long filledCols = 0;

  for (int &color : colors) {
    int curCols = color / rows;

    if (curCols >= 3) overThree = true;
    if (curCols >= 2) filledCols += curCols;
  }

  if (filledCols < cols) return false;

  if (cols % 2 == 1 && overThree) return true;
  if (cols % 2 == 0) return true;
  return false;
}

bool solution(int n, int m, int k, vector<int> colors) {
  return canFill(n, m, colors) || canFill(m, n, colors);
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;
  for (int testCase = 1; testCase <= T; testCase++) {
    int N, M, K;
    cin >> N >> M >> K;

    vector<int> C(K);
    for (int i = 0; i < K; i++) {
      cin >> C[i];
    }

    bool answer = solution(N, M, K, C);
    cout << (answer ? "Yes" : "No") << "\n";
  }

  return 0;
}
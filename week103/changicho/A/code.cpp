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

bool solution(int n) { return n % 2 == 1; }

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N;
  cin >> N;

  for (int test = 1; test <= N; test++) {
    int K;
    cin >> K;
    int answer = solution(K);

    // cout << answer << "\n";
    cout << (answer ? "YES" : "NO") << endl;
  }
  cout << endl;

  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}
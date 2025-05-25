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

bool solution(string &s) {
  int size = s.size();
  int count = 0;
  for (int i = 0; i < size; i++) {
    if (s[i] == '(') {
      count++;
    } else if (s[i] == ')') {
      count--;
    }

    if (count == 0 && i != size - 1) {
      return true;
    }
  }

  return false;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;
  for (int test = 1; test <= T; test++) {
    string S;
    cin >> S;

    bool answer = solution(S);

    // cout << answer << endl;
    cout << (answer ? "YES" : "NO") << endl;
    // for (auto &line : answer) {
    //   cout << line << "\n";
    // }
    // cout << endl;
  }

  return 0;
}
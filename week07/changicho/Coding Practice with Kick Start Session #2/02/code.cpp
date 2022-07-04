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

// It is an empty string, or:
// It has the form (S), where S is a balanced string, or:
// It has the form S1S2, where S1 is a balanced string and S2 is a balanced
// string.
long getMaximumBalancedSubstrings(int L, int R) {
  int size = min(L, R);
  // edge case overflow
  long maximumBalancedSubstrings = (long)(size) * (size + 1) / 2;

  return maximumBalancedSubstrings;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;

  for (int testCase = 1; testCase <= T; testCase++) {
    int L, R;
    cin >> L >> R;
    long answer = getMaximumBalancedSubstrings(L, R);

    cout << "Case #" << testCase << ": " << answer << "\n";
  }

  return 0;
}
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

long long MOD = 1e9 + 7;

bool leapfrog(string &line) {
  int size = line.size();

  int countBeta = count(line.begin(), line.end(), 'B');
  int countPoint = count(line.begin(), line.end(), '.');

  return (countBeta >= countPoint || countBeta >= 2) && countPoint > 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("input.txt", "r", stdin);
  // freopen("leapfrog_ch_2_input.txt", "r", stdin);

  int T;
  cin >> T;
  for (int testCase = 1; testCase <= T; testCase++) {
    string L;
    cin >> L;

    auto answer = leapfrog(L);
    cout << "Case #" << testCase << ": " << (answer ? "Y" : "N") << "\n";
  }

  return 0;
}
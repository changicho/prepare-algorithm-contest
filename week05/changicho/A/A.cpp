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

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;

  for (int testCase = 1; testCase <= T; testCase++) {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int count = 0;
    if (B > A) count++;
    if (C > A) count++;
    if (D > A) count++;

    cout << count;
    cout << "\n";
  }

  return 0;
}